#include "CGLScene.h"
#include <stdio.h>

CGLScene::CGLScene()
{
	// Initialiseer de objecten in de scene op NULL
	ZeroMemory(ptrs, sizeof(ptrs));
}

CGLScene::~CGLScene()
{
}

void CGLScene::Render(GLenum mode)
{
	// Ieder object in de scene
	for ( int i = 0; i < MAX_OBJECTS; i++ )
	{
		// Is er een object in deze array?
		if ( ptrs[i] )
		{
			if (mode == GL_SELECT)
				glLoadName(i);
			// Render het object
			((CGLObject*)ptrs[i])->Render(mode);
		}
	}
	if (mode == GL_SELECT)
		glPopName();
}

void CGLScene::ProcessHits(GLint hits, GLuint buffer[])
{
	unsigned int j;
	GLint i;
	GLuint names, *ptr;
		
	char tmp[64];

	sprintf(tmp, "hits = %d\n", hits);
	//MessageBox(NULL, tmp, "test", MB_OK);
	ptr = (GLuint *) buffer;

	for (i = 0; i < hits; i++) { /* for each hit */
		names = *ptr;
		sprintf(tmp, " number of names for hit = %d\n", names); ptr++;
		sprintf(tmp, " z1 is %g;", (float) *ptr/0x7fffffff); ptr++;
		sprintf(tmp, " z2 is %g\n", (float) *ptr/0x7fffffff); ptr++;
		sprintf(tmp, " the name is ");

		for (j = 0; j < names; j++) { /* for each name */
			sprintf(tmp, " the name is %d ", *ptr);
			//MessageBox(NULL, tmp, "test", MB_OK);
			((CGLObject*)ptrs[*ptr])->ToggleSelect(); ptr++;
		}
	}
}
void CGLScene::PickRects(int x, int y)
{
	GLuint selectBuf[MAX_OBJECTS];
	GLint hits;
	GLint viewport[4];

	// Vraag de huidige viewport dimentie op
	glGetIntegerv(GL_VIEWPORT, viewport);

	// Selecteer een buffer voor hit afhandeling
	glSelectBuffer(MAX_OBJECTS, selectBuf);

	// Selectie mode aan zetten
	(void) glRenderMode(GL_SELECT);

	// Namen stack leegmaken
	glInitNames();
	glPushName(-1);

	// Projection matrix selecteren
	glMatrixMode(GL_PROJECTION);

	// Render in Select Matrix
	glPushMatrix();
		glLoadIdentity();

		/* create 5x5 pixel picking region near cursor location */
		gluPickMatrix((GLdouble) x, (GLdouble) (viewport[3] - y), 1.0, 1.0, viewport);

		gluPerspective( 45.0f, (float)viewport[2]/(float)viewport[3], 0.01f, 300.0f );

		Render(GL_SELECT);
	glPopMatrix();

	glFlush();

	// Afhandeling Hits
	hits = glRenderMode(GL_RENDER);
	ProcessHits(hits, selectBuf);
}

int CGLScene::AddObject( CGLObject* pObject )
{
	// is de pointer geldig?
	if ( pObject )
	{
		char tmp[64];

		for ( int i = 0; i < MAX_OBJECTS; i++ )
		{
			// Voeg de pointer toe aan de lijst
			// op een lege plek
			if ( ptrs[i] == NULL )
			{
				ptrs[i] = (DWORD)pObject;

				// Stel de naam van het nieuwe object samen
				sprintf(tmp, "object %2i", i+1);
				pObject->SetName( tmp );

				// return de plek waar het object in de array is gezet
				return i;
			}
		}
	}
	return -1;
}

void CGLScene::RemObject( int index )
{
	// is de index niet buiten het aantal objecten
	if ( index < MAX_OBJECTS )
	{
		ptrs[index] = NULL;
	}
}

CGLObject* CGLScene::GetObject( int index )
{
	// is de index niet buiten het aantal objecten
	if ( index < MAX_OBJECTS )
		// Geef het gevraagde object terug
		return ((CGLObject*)ptrs[index]);

	// Niet om terug te geven
	return NULL;
}