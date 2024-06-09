#include "pch.h"
#include "CObject.h"

Vec2 CObject::GetPos()
{
	return m_vPos;
}

Vec2 CObject::GetScale()
{
	return m_vScale;
}

CObject::CObject()
:m_vPos{}
, m_vScale{}
{
}

CObject::~CObject()
{
}
