#pragma once
#include "pch.h"
enum class KEY_STATE
{
	NONE,	// �ƹ��͵� �ƴ� ����
	TAP,	// ���� ����
	HOLD,	// ������ �ִ� ����
	AWAY,	// �� ����
};
enum class KEY
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	Q,
	W,
	E,
	R,
	T,
	Y,
	U,
	I,
	O,
	P,
	A,
	S,
	D,
	F,
	G,
	Z,
	X,
	C,
	V,
	B,
	ALT,
	LSHIFT,
	SPACE,
	CTRL,
	ENTER,
	ESC,
	
	LAST,
};
struct tKeyInfo
{
	KEY_STATE	eState;	// Ű�� ���°�
	bool		bPrevPush;	// ���� �����ӿ��� ����
};

class CKeyMgr
{
	SINGLE(CKeyMgr);
private:

	vector<tKeyInfo> m_vecKey;

public:
	void init();
	void update();
	KEY_STATE GetKeyState(KEY _eKey)
	{
		return m_vecKey[(int)_eKey].eState;
	}
};

