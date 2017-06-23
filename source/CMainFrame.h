#ifndef CMAINFRAME_H
#define CMAINFRAME_H

#include "CWin.h"
#include "resource.h"

#include "CGLWindow.h"
#include "CGLCamera.h"
#include "CGLLight.h"
#include "CGLScene.h"
#include "CGLMaterial.h"

#include "controls/GUI.h"
#include "CPanel.h"

#define GL_WINDOW_ONE		1
#define GL_WINDOW_TWO		2
#define GL_WINDOW_THREE		3
#define GL_WINDOW_FOUR		4
#define GL_WINDOW_FIVE		5

#define CP_OBJECT_LIST		1
#define CP_BOX_WIDTH		2
#define CP_BOX_HEIGHT		3
#define CP_BOX_DEPTH		4
#define CP_BOX				5

class CMainFrame : public CWin
{
private:
	CGLWindow* m_pGLWindow1;
	CGLWindow* m_pGLWindow2;
	CGLWindow* m_pGLWindow3;
	CGLWindow* m_pGLWindow4;

	CGLCamera	m_Camera1;
	CGLCamera	m_Camera2;
	CGLCamera	m_Camera3;
	CGLCamera	m_Camera4;

	CGLLight	m_Light;

	CGLScene	m_Scene;

	CGLMaterial m_Mat;

	CList*		m_pList;
	CEdit*		m_pBoxWidth;
	CEdit*		m_pBoxHeight;
	CEdit*		m_pBoxDepth;

	CPanel*		m_pBoxPanel;
public:
	CMainFrame();
	~CMainFrame();

	LRESULT MsgProc(HWND, UINT, WPARAM, LPARAM);

	void GLInit();
	friend void GLRender( CGLWindow* pWindow, VOID* pMain );

	void GLResize(int nX, int nY);
	void GLKill();

	void SceneInit();
	void CPanelInit();
	void CPanelSize(int nX, int nY);
	void CPanelBox(bool show);
	void FullRedraw();
};

#endif
