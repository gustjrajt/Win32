#pragma once
#include "pch.h"
class CCore
{
	SINGLE(CCore);
private:
	HWND	m_hwnd;			//���� ������ �ڵ�
	POINT	m_ptResolution;	//���� ������ �ػ�
	HDC		m_hdc;
public:
	int init(HWND _hwnd, POINT _ptResolution);
	void progress();
	HWND GetMainHwnd();
private:
	void update();
	void render();
};

