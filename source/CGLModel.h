#ifndef CGLMODEL_H
#define CGLMODEL_H

#include "CGLObject.h"
#include "inc/ms3dspec.h"

class CGLModel : public CGLObject
{
private:
	ms3d_vertex_t*		m_pVertices;
	ms3d_triangle_t*	m_pTriangles;
	ms3d_group_t*		m_pGroups;
	ms3d_material_t*	m_pMaterials;
	ms3d_joint_t*		m_pJoints;
protected:
public:
	CGLModel();
	~CGLModel();

	void ClearModel();
	bool LoadModel();
	bool LoadASCIModel();

	void Render(GLenum mode);
};
#endif