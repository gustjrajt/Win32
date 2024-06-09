#pragma once
#include "pch.h"
class CTimeMgr
{
	SINGLE(CTimeMgr);
private:
	//예상 ( CurCount - PrevCount )/ Frequency 가 deltaTime임
	// 1초에 움직일 거리에 Deltatime을 곱해줌으로 같은시간에 이동하는거리가 같도록 설정할 수 있음

	LARGE_INTEGER	m_llPrevCount;
	LARGE_INTEGER	m_llCurCount;
	LARGE_INTEGER	m_llFrequency;
	double			m_dAcc;
	double			m_dDT; // 프레임 간의 시간값
	UINT			m_iCallCount;
	UINT			m_iFPS;
public:
	void init();
	void update();
	float GetfDT();
};

