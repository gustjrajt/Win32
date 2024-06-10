#include "pch.h"
#include "CCore.h"
#include "CObject.h"
#include "CTimeMgr.h"
#include "CKeyMgr.h"
#include "CSceneMgr.h"

CCore::CCore()
:m_hwnd(0)
,m_ptResolution{}
,m_hdc(0)
,m_hBit(0)
,m_memDC(0)
{
	
}

CCore::~CCore() {
	ReleaseDC(m_hwnd, m_hdc);
	
	DeleteDC(m_memDC);
	DeleteObject(m_hBit);
}

CObject g_obj;


void CCore::progress()
{
	CTimeMgr::GetInst()->update();
	CKeyMgr::GetInst()->update();
	update();

	render();
	// 그리기
	
}

HWND CCore::GetMainHwnd()
{
	return m_hwnd;
}

void CCore::update()
{


	Vec2 vPos = g_obj.m_vPos;
	float dDT = CTimeMgr::GetInst()->GetfDT();
	//눌린 상태값 뿐만 아니라 현재 상태까지(눌려있는중 등)
	if (CKeyMgr::GetInst()->GetKeyState(KEY::DOWN) == KEY_STATE::TAP) {
		vPos.y += 300.;
	}
	if (CKeyMgr::GetInst()->GetKeyState(KEY::UP) == KEY_STATE::TAP) {
		vPos.y -= 300.;
	}
	if (CKeyMgr::GetInst()->GetKeyState(KEY::LEFT) == KEY_STATE::TAP) {
		vPos.x -= 300.;
	}
	if (CKeyMgr::GetInst()->GetKeyState(KEY::RIGHT) == KEY_STATE::TAP) {
		vPos.x += 300.;
	}
	g_obj.SetPos(vPos);
}

void CCore::render()
{
	Vec2 vPos = g_obj.GetPos();
	Vec2 vScale = g_obj.GetScale();
	
	
	Rectangle(m_memDC
		, vPos.x / 2.f - vScale.x / 2.f
		, vPos.y / 2.f - vScale.y / 2.f
		, vPos.x / 2.f + vScale.x / 2.f
		, vPos.y / 2.f + vScale.y / 2.f
	);

	BitBlt(m_hdc, 0, 0, m_ptResolution.x, m_ptResolution.y, m_memDC, 0, 0, SRCCOPY);

	Rectangle(m_memDC
		, -1
		, -1
		, m_ptResolution.x + 1
		, m_ptResolution.y + 1
	);
}
