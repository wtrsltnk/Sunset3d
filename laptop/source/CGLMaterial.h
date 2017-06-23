#ifndef CGLMATERIAL_H
#define CGLMATERIAL_H

#include "CGLObject.h"
#include <stdio.h>

class CGLMaterial
{
private:
	sMaterial m_Material;
	GLuint	texture;


	AUX_RGBImageRec *LoadBMP(char *Filename);
	void LoadTexture();
protected:
public:
	CGLMaterial();
	~CGLMaterial();

	void Use();

	void SetAmbient(float r, float g, float b, float a);
	void SetDiffuse(float r, float g, float b, float a);
	void SetSpecular(float r, float g, float b, float a);
	void SetEmissive(float r, float g, float b, float a);

	vec4_f* GetAmbient() { return &m_Material.Ambient; };
	vec4_f* GetDiffuse() { return &m_Material.Diffuse; };
	vec4_f* GetSpecular() { return &m_Material.Specular; };
	vec4_f* GetEmissive() { return &m_Material.Emissive; };

	void SetShininess(float shininess);
	void SetTransparency(float transparency);

	float GetShininess() { return m_Material.fShininess; };
	float GetTransparency() { return m_Material.fTransparency; };

	void SetName(char name[MAX_NAME]);
	void SetDiffuseTexture(char texture[MAX_PATH]);
	void SetAlphaTexture(char texture[MAX_PATH]);

	char* GetName() { return m_Material.szName; };
	char* GetDiffuseTexture() { return m_Material.szDiffuseTexture; };
	char* GetAlphaTexture() { return m_Material.szAlphaTexture; };
};
#endif