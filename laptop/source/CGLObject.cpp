#include "CGLObject.h"

CGLObject::CGLObject()
{
	ZeroMemory( &Mesh, sizeof(sMesh) );
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

void CGLObject::ToggleSelect()
{
	m_bSelected = !m_bSelected;
}
