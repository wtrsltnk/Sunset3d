#ifndef CGLSCENE_H
#define CGLSCENE_H

#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>

#include "CGLMesh.h"
#include "CGLBox.h"

#define MAX_OBJECTS 512

class CGLScene
{
private:

	DWORD ptrs[MAX_OBJECTS];

protected:
public:
	CGLScene();
	~CGLScene();

	void Render(GLenum mode);
	int AddObject( CGLObject* pObject );
	void RemObject( int index );

	void PickRects(int x, int y);
	void ProcessHits(GLint hits, GLuint buffer[]);

	CGLObject* GetObject( int index );
};
#endif
