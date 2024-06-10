#pragma once
#include "pch.h"
class CCore
{
	SINGLE(CCore);
private:
	HWND	m_hwnd;			//���� ������ �ڵ�
	POINT	m_ptResolution;	//���� ������ �ػ�
	HDC		m_hdc;			//���� ������ HDC

	HBITMAP	m_hBit;
	HDC		m_memDC;
public:
	int init(HWND _hwnd, POINT _ptResolution)
	{
		m_hwnd = _hwnd;
		m_ptResolution = _ptResolution;

		//�ػ󵵿� �°� ������ ũ�� ����
		RECT rect = { 0, 0, _ptResolution.x,_ptResolution.y };
		// �׵θ�, ������, ������ ũ�� ��� ����� ũ�� ����
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, true);
		SetWindowPos(m_hwnd, nullptr, 100, 100, rect.right - rect.left, rect.bottom - rect.top, 0);

		m_hdc = GetDC(m_hwnd);
		m_hBit = CreateCompatibleBitmap(m_hdc, m_ptResolution.x, m_ptResolution.y);
		m_memDC = CreateCompatibleDC(m_hdc);
		HBITMAP hOldBit = (HBITMAP)SelectObject(m_memDC, m_hBit);
		DeleteObject(hOldBit);

		g_obj.SetPos(Vec2(float(m_ptResolution.x / 2), float(m_ptResolution.y / 2)));
		g_obj.SetScale(Vec2(100, 100));
		CTimeMgr::GetInst()->init();
		CKeyMgr::GetInst()->init();
		CSceneMgr::GetInst()->init();

		return S_OK;

		//return S_OK;
	}
	void progress();
	HWND GetMainHwnd();
private:
	void update();
	void render();
};

