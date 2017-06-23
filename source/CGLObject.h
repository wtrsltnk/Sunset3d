#ifndef CGLOBJECT_H
#define CGLOBJECT_H

#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>

#include "inc/fileformat.h"
#include "inc/mathlib.h"

class CGLObject
{
private:
protected:
	msMesh Mesh;
	bool m_bSelected;

    const char* cClassType;

public:
	CGLObject();
	~CGLObject();
	void SetName( char* newname );
	char* GetName();
    const char* GetClassType();

	void ToggleSelect();
	void SetSelect(bool select);

	virtual void Render(GLenum mode) = 0;
};
#endif
