#ifndef CGLOBJECT_H
#define CGLOBJECT_H

#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>

#include "fileformat.h"
#include "inc/mathlib.h"

#define GIZMO_OFFSET 0.02f

class CGLObject
{
private:
protected:
	sMesh Mesh;
	bool m_bSelected;

public:
	CGLObject();
	~CGLObject();
	void SetName( char* newname );
	char* GetName();

	void ToggleSelect();

	virtual void Render(GLenum mode) = 0;
};
#endif
