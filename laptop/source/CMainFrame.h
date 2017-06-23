#ifndef CMAINFRAME_H
#define CMAINFRAME_H

#include "CWin.h"
#include "resource.h"

#include "CGLWindow.h"
#include "CGLCamera.h"
#include "CGLLight.h"
#include "CGLScene.h"
#include "CGLMaterial.h"

#define GL_WINDOW_ONE		1
#define GL_WINDOW_TWO		2
#define GL_WINDOW_THREE		3
#define GL_WINDOW_FOUR		4
#define GL_WINDOW_FIVE		5

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

	HWND		m_hCombo;
public:
	CMainFrame();
	~CMainFrame();

	LRESULT MsgProc(HWND, UINT, WPARAM, LPARAM);

	void GLInit();
	friend void GLRender( CGLWindow* pWindow, VOID* pMain );
	friend void GLSelect( CGLWindow* pWindow, VOID* pMain, RECT* pRC );
	void GLResize(int nX, int nY);
	void GLKill();

	void FullRedraw();
};

#endif
