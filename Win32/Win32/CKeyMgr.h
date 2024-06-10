#pragma once
#include "pch.h"
enum class KEY_STATE
{
	NONE,	// 아무것도 아닌 상태
	TAP,	// 누른 시점
	HOLD,	// 누르고 있는 상태
	AWAY,	// 뗀 시점
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
	KEY_STATE	eState;	// 키의 상태값
	bool		bPrevPush;	// 이전 프레임에서 상태
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

