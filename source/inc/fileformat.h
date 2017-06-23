#ifndef FILEFORMAT_H
#define FILEFORMAT_H

typedef float vec3_f[3];
typedef float vec4_f[4];

typedef int vec3_i[3];
typedef int vec4_i[4];


/**********************************************************************
 *
 * Constants
 *
 **********************************************************************/

#define MS_MAX_NAME             32
#define MS_MAX_PATH             256



/**********************************************************************
 *
 * Types
 *
 **********************************************************************/

#ifndef byte
typedef unsigned char byte;
#endif /* byte */

#ifndef word
typedef unsigned short word;
#endif /* word */

typedef float   msVec4[4];
typedef float   msVec3[3];
typedef float   msVec2[2];

/* msFlag */
typedef enum {
    eSelected = 1, eSelected2 = 2, eHidden = 4, eDirty = 8, eAveraged = 16, eUnused = 32
} msFlag;

/* File header */
typedef struct msHeader
{
	char m_ID[10];
	int m_version;
} msHeader;

/* msVertex */
typedef struct msVertex
{
    byte        nFlags;
    msVec3      Vertex;
    float       u, v;
    char        nBoneIndex;
} msVertex;

/* msTriangle */
typedef struct
{
    word        nFlags;
    word        nVertexIndices[3];
    word        nNormalIndices[3];
    msVec3      Normal;
    byte        nSmoothingGroup;
} msTriangle;

/* msMesh */
typedef struct msMesh
{
    byte        nFlags;
    char        szName[MS_MAX_NAME];
    char        nMaterialIndex;
    
    word        nNumVertices;
    word        nNumAllocedVertices;
    msVertex*   pVertices;

    word        nNumNormals;
    word        nNumAllocedNormals;
    msVec3*     pNormals;

    word        nNumTriangles;
    word        nNumAllocedTriangles;
    msTriangle* pTriangles;
} msMesh;

/* msMaterial */
typedef struct msMaterial
{
    int         nFlags;
    char        szName[MS_MAX_NAME];
    msVec4      Ambient;
    msVec4      Diffuse;
    msVec4      Specular;
    msVec4      Emissive;
    float       fShininess;
    float       fTransparency;
    char        szDiffuseTexture[MS_MAX_PATH];
    char        szAlphaTexture[MS_MAX_PATH];
    int         nName;
} msMaterial;

/* msPositionKey */
typedef struct msPositionKey
{
    float       fTime;
    msVec3      Position;
} msPositionKey;

/* msRotationKey */
typedef struct msRotationKey
{
    float   fTime;
    msVec3  Rotation;
} msRotationKey;

/* msBone */
typedef struct msBone
{
    int             nFlags;
    char            szName[MS_MAX_NAME];
    char            szParentName[MS_MAX_NAME];
    msVec3          Position;
    msVec3          Rotation;

    int             nNumPositionKeys;
    int             nNumAllocedPositionKeys;
    msPositionKey*  pPositionKeys;

    int             nNumRotationKeys;
    int             nNumAllocedRotationKeys;
    msRotationKey*  pRotationKeys;
} msBone;

/* msModel */
typedef struct msModel
{
    int         nNumMeshes;
    int         nNumAllocedMeshes;
    msMesh*     pMeshes;

    int         nNumMaterials;
    int         nNumAllocedMaterials;
    msMaterial* pMaterials;

    int         nNumBones;
    int         nNumAllocedBones;
    msBone*     pBones;

    int         nFrame;
    int         nTotalFrames;

    msVec3      Position;
    msVec3      Rotation;
} msModel;

#endif