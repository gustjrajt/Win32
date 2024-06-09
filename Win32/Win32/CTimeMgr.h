#pragma once
#include "pch.h"
class CTimeMgr
{
	SINGLE(CTimeMgr);
private:
	//���� ( CurCount - PrevCount )/ Frequency �� deltaTime��
	// 1�ʿ� ������ �Ÿ��� Deltatime�� ���������� �����ð��� �̵��ϴ°Ÿ��� ������ ������ �� ����

	LARGE_INTEGER	m_llPrevCount;
	LARGE_INTEGER	m_llCurCount;
	LARGE_INTEGER	m_llFrequency;
	double			m_dAcc;
	double			m_dDT; // ������ ���� �ð���
	UINT			m_iCallCount;
	UINT			m_iFPS;
public:
	void init();
	void update();
	float GetfDT();
};

