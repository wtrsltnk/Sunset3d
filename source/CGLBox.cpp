#include "CGLBox.h"

CGLBox::CGLBox()
{
	cClassType = "box";

	// Standaard rotation van de BOX
	this->m_fRotX = 0.0f;
	this->m_fRotY = 0.0f;
	this->m_fRotZ = 0.0f;

	// Standaard translation van de BOX
	this->m_fPanX = 0.0f;
	this->m_fPanY = 0.0f;
	this->m_fPanZ = 0.0f;

	// Standaard Afmetingen van de BOX
	this->m_fWidth = 1.0f;
	this->m_fHeight = 1.0f;
	this->m_fDepth = 1.0f;

	ComputeMesh();
}

CGLBox::CGLBox( float fWidth, float fHeight, float fDepth )
{
	cClassType = "box";

	// Standaard rotation van de BOX
	this->m_fRotX = 0.0f;
	this->m_fRotY = 0.0f;
	this->m_fRotZ = 0.0f;

	// Standaard translation van de BOX
	this->m_fPanX = 0.0f;
	this->m_fPanY = 0.0f;
	this->m_fPanZ = 0.0f;

	// User aangegeven Afmetingen van de BOX
	this->m_fWidth = fWidth;
	this->m_fHeight = fHeight;
	this->m_fDepth = fDepth;

	ComputeMesh();
}

CGLBox::~CGLBox()
{
}

void CGLBox::ComputeMesh()
{
	Mesh.nNumVertices = 8;
	Mesh.pVertices = new msVertex[Mesh.nNumVertices];

	Mesh.pVertices[0].Vertex[0] =  m_fHeight/2;
	Mesh.pVertices[0].Vertex[1] =  m_fWidth/2;
	Mesh.pVertices[0].Vertex[2] = -m_fDepth/2;
	Mesh.pVertices[0].u = 0.0f;
	Mesh.pVertices[0].v = 1.0f;

	Mesh.pVertices[1].Vertex[0] =  m_fHeight/2;
	Mesh.pVertices[1].Vertex[1] = -m_fWidth/2;
	Mesh.pVertices[1].Vertex[2] = -m_fDepth/2;
	Mesh.pVertices[0].u = 1.0f;
	Mesh.pVertices[0].v = 0.0f;

	Mesh.pVertices[2].Vertex[0] = -m_fHeight/2;
	Mesh.pVertices[2].Vertex[1] =  m_fWidth/2;
	Mesh.pVertices[2].Vertex[2] = -m_fDepth/2;
	Mesh.pVertices[0].u = 0.0f;
	Mesh.pVertices[0].v = 0.0f;

	Mesh.pVertices[3].Vertex[0] = -m_fHeight/2;
	Mesh.pVertices[3].Vertex[1] = -m_fWidth/2;
	Mesh.pVertices[3].Vertex[2] = -m_fDepth/2;
	Mesh.pVertices[0].u = 0.0f;
	Mesh.pVertices[0].v = 1.0f;

	Mesh.pVertices[4].Vertex[0] =  m_fHeight/2;
	Mesh.pVertices[4].Vertex[1] =  m_fWidth/2;
	Mesh.pVertices[4].Vertex[2] =  m_fDepth/2;
	Mesh.pVertices[0].u = 1.0f;
	Mesh.pVertices[0].v = 0.0f;

	Mesh.pVertices[5].Vertex[0] =  m_fHeight/2;
	Mesh.pVertices[5].Vertex[1] = -m_fWidth/2;
	Mesh.pVertices[5].Vertex[2] =  m_fDepth/2;
	Mesh.pVertices[0].u = 0.0f;
	Mesh.pVertices[0].v = 0.0f;

	Mesh.pVertices[6].Vertex[0] = -m_fHeight/2;
	Mesh.pVertices[6].Vertex[1] =  m_fWidth/2;
	Mesh.pVertices[6].Vertex[2] =  m_fDepth/2;
	Mesh.pVertices[0].u = 0.0f;
	Mesh.pVertices[0].v = 1.0f;

	Mesh.pVertices[7].Vertex[0] = -m_fHeight/2;
	Mesh.pVertices[7].Vertex[1] = -m_fWidth/2;
	Mesh.pVertices[7].Vertex[2] =  m_fDepth/2;
	Mesh.pVertices[0].u = 1.0f;
	Mesh.pVertices[0].v = 0.0f;

	Mesh.nNumNormals = 6;
	Mesh.pNormals = new vec3_f[Mesh.nNumNormals];

	// Voor
	Mesh.pNormals[0][0] =  0.0f;
	Mesh.pNormals[0][1] =  0.0f;
	Mesh.pNormals[0][2] =  -1.0f;

	// Achter
	Mesh.pNormals[1][0] =  0.0f;
	Mesh.pNormals[1][1] =  0.0f;
	Mesh.pNormals[1][2] =  1.0f;

	// Rechts
	Mesh.pNormals[2][0] = -1.0f;
	Mesh.pNormals[2][1] =  0.0f;
	Mesh.pNormals[2][2] =  0.0f;

	// Links
	Mesh.pNormals[3][0] =  1.0f;
	Mesh.pNormals[3][1] =  0.0f;
	Mesh.pNormals[3][2] =  0.0f;

	// Boven
	Mesh.pNormals[4][0] =  0.0f;
	Mesh.pNormals[4][1] =  1.0f;
	Mesh.pNormals[4][2] =  0.0f;

	// Onder
	Mesh.pNormals[5][0] =  0.0f;
	Mesh.pNormals[5][1] = -1.0f;
	Mesh.pNormals[5][2] =  0.0f;

	Mesh.nNumTriangles = 12;
	Mesh.pTriangles = new msTriangle[Mesh.nNumTriangles];

	// Voor
	Mesh.pTriangles[0].nVertexIndices[0] = 0;
	Mesh.pTriangles[0].nVertexIndices[1] = 1;
	Mesh.pTriangles[0].nVertexIndices[2] = 2;
	//
	Mesh.pTriangles[0].nNormalIndices[0] = 0;
	Mesh.pTriangles[0].nNormalIndices[1] = 0;
	Mesh.pTriangles[0].nNormalIndices[2] = 0;


	Mesh.pTriangles[1].nVertexIndices[0] = 1;
	Mesh.pTriangles[1].nVertexIndices[1] = 3;
	Mesh.pTriangles[1].nVertexIndices[2] = 2;
	//
	Mesh.pTriangles[1].nNormalIndices[0] = 0;
	Mesh.pTriangles[1].nNormalIndices[1] = 0;
	Mesh.pTriangles[1].nNormalIndices[2] = 0;


	// Achter
	Mesh.pTriangles[2].nVertexIndices[0] = 6;
	Mesh.pTriangles[2].nVertexIndices[1] = 5;
	Mesh.pTriangles[2].nVertexIndices[2] = 4;
	//
	Mesh.pTriangles[2].nNormalIndices[0] = 1;
	Mesh.pTriangles[2].nNormalIndices[1] = 1;
	Mesh.pTriangles[2].nNormalIndices[2] = 1;


	Mesh.pTriangles[3].nVertexIndices[0] = 6;
	Mesh.pTriangles[3].nVertexIndices[1] = 7;
	Mesh.pTriangles[3].nVertexIndices[2] = 5;
	//
	Mesh.pTriangles[3].nNormalIndices[0] = 1;
	Mesh.pTriangles[3].nNormalIndices[1] = 1;
	Mesh.pTriangles[3].nNormalIndices[2] = 1;


	// Rechts
	Mesh.pTriangles[10].nVertexIndices[0] = 2;
	Mesh.pTriangles[10].nVertexIndices[1] = 3;
	Mesh.pTriangles[10].nVertexIndices[2] = 6;
	//
	Mesh.pTriangles[10].nNormalIndices[0] = 2;
	Mesh.pTriangles[10].nNormalIndices[1] = 2;
	Mesh.pTriangles[10].nNormalIndices[2] = 2;


	Mesh.pTriangles[11].nVertexIndices[0] = 6;
	Mesh.pTriangles[11].nVertexIndices[1] = 3;
	Mesh.pTriangles[11].nVertexIndices[2] = 7;
	//
	Mesh.pTriangles[11].nNormalIndices[0] = 2;
	Mesh.pTriangles[11].nNormalIndices[1] = 2;
	Mesh.pTriangles[11].nNormalIndices[2] = 2;


	// Links
	Mesh.pTriangles[8].nVertexIndices[0] = 4;
	Mesh.pTriangles[8].nVertexIndices[1] = 5;
	Mesh.pTriangles[8].nVertexIndices[2] = 0;
	//
	Mesh.pTriangles[8].nNormalIndices[0] = 3;
	Mesh.pTriangles[8].nNormalIndices[1] = 3;
	Mesh.pTriangles[8].nNormalIndices[2] = 3;


	Mesh.pTriangles[9].nVertexIndices[0] = 0;
	Mesh.pTriangles[9].nVertexIndices[1] = 5;
	Mesh.pTriangles[9].nVertexIndices[2] = 1;
	//
	Mesh.pTriangles[9].nNormalIndices[0] = 3;
	Mesh.pTriangles[9].nNormalIndices[1] = 3;
	Mesh.pTriangles[9].nNormalIndices[2] = 3;


	// Boven
	Mesh.pTriangles[4].nVertexIndices[0] = 6;
	Mesh.pTriangles[4].nVertexIndices[1] = 0;
	Mesh.pTriangles[4].nVertexIndices[2] = 2;
	//
	Mesh.pTriangles[4].nNormalIndices[0] = 4;
	Mesh.pTriangles[4].nNormalIndices[1] = 4;
	Mesh.pTriangles[4].nNormalIndices[2] = 4;


	Mesh.pTriangles[5].nVertexIndices[0] = 4;
	Mesh.pTriangles[5].nVertexIndices[1] = 0;
	Mesh.pTriangles[5].nVertexIndices[2] = 6;
	//
	Mesh.pTriangles[5].nNormalIndices[0] = 4;
	Mesh.pTriangles[5].nNormalIndices[1] = 4;
	Mesh.pTriangles[5].nNormalIndices[2] = 4;


	// Onder
	Mesh.pTriangles[6].nVertexIndices[0] = 3;
	Mesh.pTriangles[6].nVertexIndices[1] = 1;
	Mesh.pTriangles[6].nVertexIndices[2] = 7;
	//
	Mesh.pTriangles[6].nNormalIndices[0] = 5;
	Mesh.pTriangles[6].nNormalIndices[1] = 5;
	Mesh.pTriangles[6].nNormalIndices[2] = 5;


	Mesh.pTriangles[7].nVertexIndices[0] = 7;
	Mesh.pTriangles[7].nVertexIndices[1] = 1;
	Mesh.pTriangles[7].nVertexIndices[2] = 5;
	//
	Mesh.pTriangles[7].nNormalIndices[0] = 5;
	Mesh.pTriangles[7].nNormalIndices[1] = 5;
	Mesh.pTriangles[7].nNormalIndices[2] = 5;


	vec3_t angles = {m_fRotX, m_fRotY, m_fRotZ};
	vec3_t trans = {m_fPanX, m_fPanY, m_fPanZ};
	float RotMatrix[3][4], PanMatrix[3][4];

	// Rotatie matrix en Translatie matrix berekenen
	AngleMatrix(angles, RotMatrix);
	TransMatrix(trans, PanMatrix);

	// Alle Vertices Transleren en Roteren
	for ( int i = 0; i < Mesh.nNumVertices; i++ )
	{
		vec3_t pNew;
		VectorRotate(Mesh.pVertices[i].Vertex, RotMatrix, pNew);
		VectorTransform(pNew, PanMatrix, Mesh.pVertices[i].Vertex);
	}
	ComputeMinMax();
}

void CGLBox::ComputeMinMax()
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

void CGLBox::Render(GLenum mode)
{		
	glPushMatrix();										// Bewaar de huidige matrix in de stack

	if ( m_bSelected )
	{
		DrawGizmo();
	}

	// Loop alle mpTriangles in de Mesh af
	for ( int i = 0; i < Mesh.nNumTriangles; i++ )
	{
		// Vraag een pointer naar de triangle op
		msTriangle* pTriangle = &Mesh.pTriangles[i];

		glBegin(GL_TRIANGLES);							// Start met het teken van pTriangles
		for ( int j = 0; j < 3; j++ )
		{
			msVertex* pVertex;
			vec3_f* pNormal;

			// Vraag een pointer naar de vertex en normal op
			pVertex = &Mesh.pVertices[pTriangle->nVertexIndices[j]];
			pNormal = &Mesh.pNormals[pTriangle->nNormalIndices[j]];

			// Teken Vertex met Normal
			glNormal3fv(*pNormal);						// Gebruik de normal in de opgegeven vector
			glTexCoord2f(pVertex->u, pVertex->v);		// Set de UV waarden
			glVertex3fv(pVertex->Vertex);				// Teken de vertex in de opgegeven vector
		}
		glEnd();										// Einde teken van pTriangles
	}
	glPopMatrix();										// Haal de vorige matrix weer op uit de stack

}

void CGLBox::DrawGizmo()
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

void CGLBox::SetCoords( float fWidth, float fHeight, float fDepth )
{
	// Nieuwe afmetingen invoeren
	this->m_fWidth = fWidth;
	this->m_fHeight = fHeight;
	this->m_fDepth = fDepth;

	ComputeMesh();
}

void CGLBox::SetRotation( float fRotX, float fRotY, float fRotZ )
{
	// Nieuwe Rotations invoeren
	this->m_fRotX = fRotX;
	this->m_fRotY = fRotY;
	this->m_fRotZ = fRotZ;

	ComputeMesh();
}

void CGLBox::SetTranslation( float fPanX, float fPanY, float fPanZ )
{
	// Nieuwe Translations invoeren
	this->m_fPanX = fPanX;
	this->m_fPanY = fPanY;
	this->m_fPanZ = fPanZ;

	ComputeMesh();
}

void CGLBox::Scale( float fScaleX, float fScaleY, float fScaleZ )
{
	// Nieuwe Afmetingen berekenen uit scalings factor
	this->m_fWidth *= fScaleX;
	this->m_fHeight *= fScaleY;
	this->m_fDepth *= fScaleZ;

	ComputeMesh();
}