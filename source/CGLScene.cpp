#include "CGLScene.h"
#include <stdio.h>

CGLScene::CGLScene()
{
	// Initialiseer de objecten in de scene op NULL
	ZeroMemory(ptrs, sizeof(ptrs));
}

CGLScene::~CGLScene()
{
	// Dealloceer het geheugen van de objecten in de scene
	for ( int i = 0; i < MAX_OBJECTS; i++ )
	{
		RemObject(i);
	}
}

void CGLScene::Render(GLenum mode)
{
	glEnable(GL_TEXTURE_2D);
	// Ieder object in de scene
	for ( int i = 0; i < MAX_OBJECTS; i++ )
	{
		// Is er een object in deze array?
		if ( ptrs[i] )
		{
			// Render het object
			((CGLObject*)ptrs[i])->Render(mode);
		}
	}
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
            if ( ptrs[i] == 0 )
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
		// Wijst de pointer naar gealloceerd geheugen?
		if ( ptrs[index] )
		{
			// Delete dat geheugen
            DWORD* pObj = (DWORD*)ptrs[index];
			delete pObj;
		}
		// Zet de pointer op NULL
        ptrs[index] = 0;
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
