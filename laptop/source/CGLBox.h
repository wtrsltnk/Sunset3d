#ifndef CGLBOX_H
#define CGLBOX_H

#include "CGLObject.h"

class CGLBox : public CGLObject
{
private:
	sMesh Mesh;
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
	void SetRotation( float fRotX, float fRotY, float fRotZ );
	void SetTranslation( float fPanX, float fPanY, float fPanZ );
	void Scale( float fScaleX, float fScaleY, float fScaleZ );
};
#endif