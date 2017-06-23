#include "CGLMaterial.h"

CGLMaterial::CGLMaterial()
{
	ZeroMemory(&m_Material, sizeof(m_Material));
}

CGLMaterial::~CGLMaterial()
{
}

void CGLMaterial::Use()
{
	glBindTexture(GL_TEXTURE_2D, texture);

	glMaterialfv(GL_FRONT, GL_AMBIENT, m_Material.Ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_Material.Diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, m_Material.Specular);
	glMaterialfv(GL_FRONT, GL_EMISSION, m_Material.Emissive);

	glMaterialf(GL_FRONT, GL_SHININESS, m_Material.fShininess);
}

void CGLMaterial::SetAmbient(float r, float g, float b, float a)
{
	m_Material.Ambient[0] = r;
	m_Material.Ambient[1] = g;
	m_Material.Ambient[2] = b;
	m_Material.Ambient[3] = a;
}

void CGLMaterial::SetDiffuse(float r, float g, float b, float a)
{
	m_Material.Diffuse[0] = r;
	m_Material.Diffuse[1] = g;
	m_Material.Diffuse[2] = b;
	m_Material.Diffuse[3] = a;
}

void CGLMaterial::SetSpecular(float r, float g, float b, float a)
{
	m_Material.Specular[0] = r;
	m_Material.Specular[1] = g;
	m_Material.Specular[2] = b;
	m_Material.Specular[3] = a;
}

void CGLMaterial::SetEmissive(float r, float g, float b, float a)
{
	m_Material.Emissive[0] = r;
	m_Material.Emissive[1] = g;
	m_Material.Emissive[2] = b;
	m_Material.Emissive[3] = a;
}

void CGLMaterial::SetShininess(float shininess)
{
	m_Material.fShininess = shininess;
}

void CGLMaterial::SetTransparency(float transparency)
{
	m_Material.fTransparency = transparency;
}

void CGLMaterial::SetName(char name[MAX_NAME])
{
	strcpy(m_Material.szName, name);
}

void CGLMaterial::SetDiffuseTexture(char texture[MAX_PATH])
{
	strcpy(m_Material.szDiffuseTexture, texture);
	LoadTexture();
}

void CGLMaterial::SetAlphaTexture(char texture[MAX_PATH])
{
	strcpy(m_Material.szAlphaTexture, texture);
}

void CGLMaterial::LoadTexture()
{
	AUX_RGBImageRec *TextureImage[1];

	memset(TextureImage,0,sizeof(void *)*1);

	if (TextureImage[0]=LoadBMP(m_Material.szDiffuseTexture))
	{
		glGenTextures(1, &texture);

		glBindTexture(GL_TEXTURE_2D, texture);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage[0]->sizeX, TextureImage[0]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);
	}

	if (TextureImage[0])
	{
		if (TextureImage[0]->data)
		{
			free(TextureImage[0]->data);
		}

		free(TextureImage[0]);
	}
}

AUX_RGBImageRec *CGLMaterial::LoadBMP(char *Filename)				// Loads A Bitmap Image
{
	FILE *File=NULL;									// File Handle

	if (!Filename)										// Make Sure A Filename Was Given
	{
		return NULL;									// If Not Return NULL
	}

	File=fopen(Filename,"r");							// Check To See If The File Exists

	if (File)											// Does The File Exist?
	{
		fclose(File);									// Close The Handle
		return auxDIBImageLoad(Filename);				// Load The Bitmap And Return A Pointer
	}

	return NULL;										// If Load Failed Return NULL
}
