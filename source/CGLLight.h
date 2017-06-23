#ifndef CGLLIGHT_H
#define CGLLIGHT_H

#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>

#define on true
#define off false

class CGLLight
{
private:
	static int lightCount;

	float m_fAmbient[4];
	float m_fDiffuse[4];
	float m_fSpecular[4];
	float m_fPosition[4];

	int lightNum;
protected:
public:
	CGLLight();
	~CGLLight();

	void Initialize();

	void SetAmbient(float r, float g, float b, float w);
	void SetDiffuse(float r, float g, float b, float w);
	void SetSpecular(float r, float g, float b, float w);
	void SetPosition(float x, float y, float z, float w);

	void SwitchLight(bool onoff);
};
#endif
