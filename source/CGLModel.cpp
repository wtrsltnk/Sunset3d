#include "CGLModel.h"

CGLModel::CGLModel()
{
	cClassType = "model";

	m_pVertices = NULL;
	m_pTriangles = NULL;
	m_pGroups = NULL;
	m_pMaterials = NULL;
	m_pJoints = NULL;
}

CGLModel::~CGLModel()
{
	ClearModel();
}

void CGLModel::ClearModel()
{
	if ( m_pVertices )
	{
		delete m_pVertices;
		m_pVertices = NULL;
	}
	if ( m_pTriangles )
	{
		delete m_pTriangles;
		m_pTriangles = NULL;
	}
	if ( m_pGroups )
	{
		delete m_pGroups;
		m_pGroups = NULL;
	}
	if ( m_pMaterials )
	{
		delete m_pMaterials;
		m_pMaterials = NULL;
	}
	if ( m_pJoints )
	{
		delete m_pJoints;
		m_pJoints = NULL;
	}
}

void CGLModel::Render(GLenum mode)
{
}