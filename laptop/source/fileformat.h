#ifndef FILEFORMAT_H
#define FILEFORMAT_H

typedef float vec3_f[3];
typedef float vec4_f[4];

typedef int vec3_i[3];
typedef int vec4_i[4];

#define MAX_NAME             32
//#define MS_MAX_PATH             256

typedef enum {
    eSelected = 1, eSelected2 = 2, eHidden = 4, eDirty = 8, eAveraged = 16, eUnused = 32
} flag;

typedef struct sVertex
{
    flag        nFlags;
    vec3_f      Vertex;
    float       u, v;
    char        nBoneIndex;
} sVertex;

typedef struct sTriangle
{
    int			nFlags;
    int			nVertexIndices[3];
    int			nNormalIndices[3];
    vec3_f		Normal;
    byte        nSmoothingGroup;
} sTriangle;

typedef struct sMesh
{
    byte        nFlags;
    char        szName[MAX_NAME];
    char        nMaterialIndex;
    
    int			nNumVertices;
    sVertex*	pVertices;

    int			nNumNormals;
    vec3_f*		pNormals;

    int			nNumTriangles;
    sTriangle*	pTriangles;
} sMesh;

typedef struct sMaterial
{
    int         nFlags;
    char        szName[MAX_NAME];
    vec4_f      Ambient;
    vec4_f      Diffuse;
    vec4_f      Specular;
    vec4_f      Emissive;
    float       fShininess;
    float       fTransparency;
    char        szDiffuseTexture[MAX_PATH];
    char        szAlphaTexture[MAX_PATH];
    int         nName;
} sMaterial;
#endif