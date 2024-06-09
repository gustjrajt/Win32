#pragma once
#include "pch.h"
class CObject
{
public:
	Vec2	m_vPos;
	Vec2	m_vScale;
public:
	void SetPos(Vec2 _vPos) { m_vPos = _vPos; }
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }
	Vec2 GetPos();
	Vec2 GetScale();

public:
	CObject();
	~CObject();
};

