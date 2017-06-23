#ifndef CGLMESH_H
#define CGLMESH_H

#include "CGLObject.h"

class CGLMesh : public CGLObject
{
private:
	vec3_f min;
	vec3_f max;
protected:
public:
	CGLMesh();
	~CGLMesh();


	void ComputeMinMax();

	void Render(GLenum mode);
	void DrawGizmo();
};
#endif