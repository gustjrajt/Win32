#pragma once
#include "pch.h"
class CCore
{
	SINGLE(CCore);
private:
	HWND	m_hwnd;			//메인 윈도우 핸들
	POINT	m_ptResolution;	//메인 윈도우 해상도
	HDC		m_hdc;
public:
	int init(HWND _hwnd, POINT _ptResolution);
	void progress();
	HWND GetMainHwnd();
private:
	void update();
	void render();
};

