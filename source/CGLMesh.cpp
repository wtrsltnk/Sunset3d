#include "CGLMesh.h"
#include <fstream>

CGLMesh::CGLMesh()
{
	cClassType = "mesh";

	Mesh.nNumVertices = 3;
	Mesh.pVertices = new msVertex[3];

	Mesh.pVertices[0].Vertex[0] = -1.0f;
	Mesh.pVertices[0].Vertex[1] = -1.0f;
	Mesh.pVertices[0].Vertex[2] =  0.0f;

	Mesh.pVertices[1].Vertex[0] =  1.0f;
	Mesh.pVertices[1].Vertex[1] = -1.0f;
	Mesh.pVertices[1].Vertex[2] =  0.0f;

	Mesh.pVertices[2].Vertex[0] =  0.0f;
	Mesh.pVertices[2].Vertex[1] =  1.0f;
	Mesh.pVertices[2].Vertex[2] =  0.0f;

	Mesh.nNumTriangles = 1;
	Mesh.pTriangles = new msTriangle;

	Mesh.pTriangles->nVertexIndices[0] = 0;
	Mesh.pTriangles->nVertexIndices[1] = 1;
	Mesh.pTriangles->nVertexIndices[2] = 2;

	ComputeMinMax();
}

CGLMesh::~CGLMesh()
{
}

void CGLMesh::ComputeMinMax()
{
	min[0] = 99999.99f;
	min[1] = 99999.99f;
	min[2] = 99999.99f;
	max[0] = -99999.99f;
	max[1] = -99999.99f;
	max[2] = -99999.99f;

	for ( int i = 0; i < Mesh.nNumVertices; i++ )
	{
		if ( Mesh.pVertices[i].Vertex[0] <= min[0] )
			min[0] = Mesh.pVertices[i].Vertex[0];
		if ( Mesh.pVertices[i].Vertex[1] <= min[1] )
			min[1] = Mesh.pVertices[i].Vertex[1];
		if ( Mesh.pVertices[i].Vertex[2] <= min[2] )
			min[2] = Mesh.pVertices[i].Vertex[2];

		if ( Mesh.pVertices[i].Vertex[0] >= max[0] )
			max[0] = Mesh.pVertices[i].Vertex[0];
		if ( Mesh.pVertices[i].Vertex[1] >= max[1] )
			max[1] = Mesh.pVertices[i].Vertex[1];
		if ( Mesh.pVertices[i].Vertex[2] >= max[2] )
			max[2] = Mesh.pVertices[i].Vertex[2];
	}
}

void CGLMesh::Render(GLenum mode)
{
	glPushMatrix();										// Bewaard e huidige matrix in de stack

	
	if ( m_bSelected )
	{
		DrawGizmo();
	}

	// Loop alle mtriangles in de Mesh af
	for ( int i = 0; i < Mesh.nNumTriangles; i++ )
	{
		// Vraag een pointer naar de triangle op
		msTriangle* pTriangle = &Mesh.pTriangles[i];

		glBegin(GL_TRIANGLES);							// Start met het teken van triangles
		for ( int j = 0; j < 3; j++ )
		{
			// Vraag een pointer naar de vertex op
			msVertex* pVertex = &Mesh.pVertices[pTriangle->nVertexIndices[j]];
			glVertex3fv(pVertex->Vertex);					// Teken de vertex in de opgegeven vector
		}
		glEnd();										// Einde teken van triangles
	}
	glPopMatrix();										// Haal de vorige matrix weer op uit de stack

}

void CGLMesh::DrawGizmo()
{
	glDisable(GL_LIGHTING);
	glBegin(GL_LINES);

		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(min[0]-0.02f, min[1]-0.02f, min[2]-0.02f);
		glVertex3f(max[0]+0.02f, min[1]-0.02f, min[2]-0.02f);

		glVertex3f(min[0]-0.02f, min[1]-0.02f, min[2]-0.02f);
		glVertex3f(min[0]-0.02f, max[1]+0.02f, min[2]-0.02f);

		glVertex3f(min[0]-0.02f, min[1]-0.02f, min[2]-0.02f);
		glVertex3f(min[0]-0.02f, min[1]-0.02f, max[2]+0.02f);

		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(max[0]+0.02f, max[1]+0.02f, max[2]+0.02f);
		glVertex3f(min[0]-0.02f, max[1]+0.02f, max[2]+0.02f);

		glVertex3f(max[0]+0.02f, max[1]+0.02f, max[2]+0.02f);
		glVertex3f(max[0]+0.02f, min[1]-0.02f, max[2]+0.02f);

		glVertex3f(max[0]+0.02f, max[1]+0.02f, max[2]+0.02f);
		glVertex3f(max[0]+0.02f, max[1]+0.02f, min[2]-0.02f);

	glEnd();
	glEnable(GL_LIGHTING);
}
