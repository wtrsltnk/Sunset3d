#include "CGLLight.h"

int CGLLight::lightCount = 0;

CGLLight::CGLLight()
{
	// Standaard Ambient light opgeven
	m_fAmbient[0] = 1.0f;
	m_fAmbient[1] = 1.0f;
	m_fAmbient[2] = 1.0f;
	m_fAmbient[3] = 1.0f;

	// Standaard Diffuse light opgeven
	m_fDiffuse[0] = 0.2f;
	m_fDiffuse[1] = 0.2f;
	m_fDiffuse[2] = 0.2f;
	m_fDiffuse[3] = 1.0f;

	// Standaard Specular light opgeven
	m_fSpecular[0] = 0.0f;
	m_fSpecular[1] = 0.0f;
	m_fSpecular[2] = 0.0f;
	m_fSpecular[3] = 1.0f;

	// Standaard Position opgeven
	m_fPosition[0] = 1.0f;
	m_fPosition[1] = 0.0f;
	m_fPosition[2] = 5.0f;
	m_fPosition[3] = 1.0f;

	// Bewaar het light nummer van deze instantie
	lightNum = GL_LIGHT0 + lightCount;

	// Verhoog het aantal instanties van de klasse
	lightCount++;
}

CGLLight::~CGLLight()
{
	// Verlaag het aantal instanties van de klasse
	lightCount--;
}

void CGLLight::Initialize()
{
	// Initializeer de volgende onderdelen:

	// Ambient
	glLightfv(lightNum, GL_AMBIENT, m_fAmbient);
	// Diffuse
	glLightfv(lightNum, GL_DIFFUSE, m_fDiffuse);
	// Specular
	glLightfv(lightNum, GL_SPECULAR, m_fSpecular);
	// Position
	glLightfv(lightNum, GL_POSITION, m_fPosition);
}

void CGLLight::SetAmbient(float r, float g, float b, float w)
{
	// Nieuwe Ambient light opgeven
	m_fAmbient[0] = r;
	m_fAmbient[1] = g;
	m_fAmbient[2] = b;
	m_fAmbient[3] = w;

	// Verander Ambient
	glLightfv(lightNum, GL_AMBIENT, m_fAmbient);
}

void CGLLight::SetDiffuse(float r, float g, float b, float w)
{
	// Nieuwe Diffuse light opgeven
	m_fDiffuse[0] = r;
	m_fDiffuse[1] = g;
	m_fDiffuse[2] = b;
	m_fDiffuse[3] = w;

	// VErander Diffuse
	glLightfv(lightNum, GL_DIFFUSE, m_fDiffuse);
}

void CGLLight::SetSpecular(float r, float g, float b, float w)
{
	// Nieuwe Specular light opgeven
	m_fSpecular[0] = r;
	m_fSpecular[1] = g;
	m_fSpecular[2] = b;
	m_fSpecular[3] = w;

	// Verander Specular
	glLightfv(lightNum, GL_SPECULAR, m_fSpecular);
}

void CGLLight::SetPosition(float x, float y, float z, float w)
{
	// Nieuwe Position opgeven
	m_fPosition[0] = x;
	m_fPosition[1] = y;
	m_fPosition[2] = z;
	m_fPosition[3] = w;

	// Verander de Position
	glLightfv(lightNum, GL_POSITION, m_fPosition);
}

void CGLLight::SwitchLight(bool onoff)
{
	// Light aan of uit
	if ( onoff )
		glEnable(lightNum);						// Zet het licht aan
	else
		glDisable(lightNum);					// Zet het licht uit
}