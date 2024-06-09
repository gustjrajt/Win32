#include "pch.h"
#include "CCore.h"
#include "CObject.h"
#include "CTimeMgr.h"
#include "CKeyMgr.h"


CCore::CCore()
:m_hwnd(0)
,m_ptResolution{}
,m_hdc(0)
{
	
}

CCore::~CCore() {
	ReleaseDC(m_hwnd, m_hdc);
}

CObject g_obj;


int CCore::init(HWND _hwnd, POINT _ptResolution)
{
	m_hwnd = _hwnd;
	m_ptResolution = _ptResolution;

	//�ػ󵵿� �°� ������ ũ�� ����
	RECT rect = { 0, 0, _ptResolution.x,_ptResolution.y };
	// �׵θ�, ������, ������ ũ�� ��� ����� ũ�� ����
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, true);
	SetWindowPos(m_hwnd, nullptr, 100, 100, rect.right - rect.left, rect.bottom - rect.top, 0);

	m_hdc = GetDC(m_hwnd);

	g_obj.SetPos(Vec2(float(m_ptResolution.x / 2), float(m_ptResolution.y / 2)));
	g_obj.SetScale(Vec2( 100,100 ));
	CTimeMgr::GetInst()->init();
	CKeyMgr::GetInst()->init();

	return S_OK;

	//return S_OK;
}


void CCore::progress()
{
	CTimeMgr::GetInst()->update();
	update();

	render();
	// �׸���
	
}

HWND CCore::GetMainHwnd()
{
	return m_hwnd;
}

void CCore::update()
{
	Vec2 vPos = g_obj.m_vPos;
	float dDT = CTimeMgr::GetInst()->GetfDT();
	//���� ���°� �Ӹ� �ƴ϶� ���� ���±���(�����ִ��� ��)
	if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		vPos.y += dDT * 300.;
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000) {
		vPos.y -= dDT * 300.;
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		vPos.x -= dDT*300.;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		vPos.x += dDT*300.;
	}
	g_obj.SetPos(vPos);
}

void CCore::render()
{
	Vec2 vPos = g_obj.GetPos();
	Vec2 vScale = g_obj.GetScale();
	Rectangle(m_hdc
		, vPos.x - vScale.x / 2.f
		, vPos.y - vScale.y / 2.f
		, vPos.x + vScale.x / 2.f
		, vPos.y + vScale.y / 2.f
	);
}
