#include "CGLObject.h"

CGLObject::CGLObject()
{
	cClassType = "object";

	ZeroMemory( &Mesh, sizeof(msMesh) );
	m_bSelected = false;
}

CGLObject::~CGLObject()
{
}

void CGLObject::SetName( char* newname )
{
	// Sla de nieuwe naam van het object op
	if ( &Mesh )
	{
		strcpy(Mesh.szName, newname);
	}
}

char* CGLObject::GetName()
{
	// Geef de naam van het object terug
	return Mesh.szName;
}

const char* CGLObject::GetClassType()
{
	// Geef de naam van het object terug
	return cClassType;
}

void CGLObject::ToggleSelect()
{
	m_bSelected = !m_bSelected;
}

void CGLObject::SetSelect(bool select)
{
	m_bSelected = select;
}
