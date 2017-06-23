#ifndef CGLBOX_H
#define CGLBOX_H

#include "CGLObject.h"

class CGLBox : public CGLObject
{
private:
	msMesh Mesh;
	void ComputeMesh();
	void ComputeMinMax();

	vec3_f min;
	vec3_f max;

	float m_fWidth, m_fHeight, m_fDepth;
	float m_fRotX, m_fRotY, m_fRotZ;
	float m_fPanX, m_fPanY, m_fPanZ;
protected:
public:
	CGLBox();
	CGLBox( float fWidth, float fHeight, float fDepth );
	~CGLBox();

	void Render(GLenum mode);
	void DrawGizmo();

	void SetCoords( float fWidth, float fHeight, float fDepth );
	float GetWidth() {return m_fWidth;};
	float GetHeight() {return m_fHeight;};
	float GetDepth() {return m_fDepth;};

	void SetRotation( float fRotX, float fRotY, float fRotZ );
	float GetRotX() {return m_fRotX;};
	float GetRotY() {return m_fRotY;};
	float GetRotZ() {return m_fRotZ;};

	void SetTranslation( float fPanX, float fPanY, float fPanZ );
	float GetPanX() {return m_fPanX;};
	float GetPanY() {return m_fPanY;};
	float GetPanZ() {return m_fPanZ;};

	void Scale( float fScaleX, float fScaleY, float fScaleZ );
};
#endif