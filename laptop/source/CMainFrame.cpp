#include "CMainFrame.h"
#include <tchar.h>

/////////////////////////////////////
// Constructors / Destructors      //
/////////////////////////////////////
CMainFrame::CMainFrame()
{
	this->m_dwWindowStyle	 = WS_OVERLAPPEDWINDOW;
	this->m_dwExWindowStyle	 = WS_EX_WINDOWEDGE;
	this->m_dwCreationFlags  = SW_SHOW;
	this->m_PosX			 = CW_USEDEFAULT;	
	this->m_PosY			 = CW_USEDEFAULT;	
	this->m_dwCreationWidth  = CW_USEDEFAULT;
	this->m_dwCreationHeight = CW_USEDEFAULT;
	this->m_hbrWindowColor	 = (HBRUSH)(COLOR_WINDOW);
	this->m_hIcon			 = LoadIcon(m_hInstance, MAKEINTRESOURCE(IDI_SUNSET));
	this->m_strWindowTitle	 = _T("Sunset 3D");
	this->m_hMenu			 = LoadMenu(m_hInstance, MAKEINTRESOURCE(IDR_MAINMENU));

	this->m_pGLWindow1		 = NULL;
	this->m_pGLWindow2		 = NULL;
	this->m_pGLWindow3		 = NULL;
	this->m_pGLWindow4		 = NULL;
}


CMainFrame::~CMainFrame()
{
}

/////////////////////////////////////
// Memberfuncties                  //
/////////////////////////////////////

LRESULT CMainFrame::MsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
		GLInit();
		break;

	case WM_SIZE:
		GLResize(LOWORD(lParam),HIWORD(lParam));
		break;

	case WM_QUIT:
		GLKill();
		break;
	}
	return CWin::MsgProc(hWnd, uMsg, wParam, lParam);
}







/////////////////////////////////////
// GL Functions                    //
/////////////////////////////////////
void CMainFrame::GLInit()
{
	m_pGLWindow1 = new CGLWindow(m_hInstance, m_hWnd, 10, 10, 100, 100, GL_WINDOW_ONE);
	m_pGLWindow1->Create();
	m_pGLWindow1->SetCamera(&m_Camera1);
	m_pGLWindow1->SetRender(GLRender, this);
	m_pGLWindow1->SetSelect(GLSelect, this);
	m_Light.Initialize();
	m_Light.SwitchLight(on);

	m_pGLWindow2 = new CGLWindow(m_hInstance, m_hWnd, 10, 10, 100, 100, GL_WINDOW_ONE);
	m_pGLWindow2->Create();
	m_pGLWindow2->SetCamera(&m_Camera2);
	m_pGLWindow2->SetRender(GLRender, this);
	m_pGLWindow2->SetSelect(GLSelect, this);
	m_Light.Initialize();
	m_Light.SwitchLight(on);

	m_pGLWindow3 = new CGLWindow(m_hInstance, m_hWnd, 10, 10, 100, 100, GL_WINDOW_ONE);
	m_pGLWindow3->Create();
	m_pGLWindow3->SetCamera(&m_Camera3);
	m_pGLWindow3->SetRender(GLRender, this);
	m_pGLWindow3->SetSelect(GLSelect, this);
	m_Light.Initialize();
	m_Light.SwitchLight(on);

	m_pGLWindow4 = new CGLWindow(m_hInstance, m_hWnd, 10, 10, 100, 100, GL_WINDOW_ONE);
	m_pGLWindow4->Create();
	m_pGLWindow4->SetCamera(&m_Camera4);
	m_pGLWindow4->SetRender(GLRender, this);
	m_pGLWindow4->SetSelect(GLSelect, this);
	m_Light.Initialize();
	m_Light.SwitchLight(on);

	m_Mat.SetAmbient(0.0f, 0.3f, 0.5f, 1.0f);
	m_Mat.SetDiffuse(0.5f, 0.5f, 0.5f, 1.0f);
	m_Mat.SetSpecular(0.3f, 0.3f, 0.3f, 1.0f);
	m_Mat.SetShininess(0.0f);
	m_Mat.SetDiffuseTexture("folder.bmp");

	int k = m_Scene.AddObject(new CGLBox);
	int l = m_Scene.AddObject(new CGLBox);
	int j = m_Scene.AddObject(new CGLMesh);
	m_Scene.RemObject(k);
	k = m_Scene.AddObject(new CGLBox);

	CGLBox* p = (CGLBox*)m_Scene.GetObject(l);
	p->SetCoords(2.0f, 2.0f, 2.0f);
	p->SetRotation(45.0f, 45.0f, 45.0f);
	p->SetTranslation(3.0f, 0.0f, -6.0f);

	p = (CGLBox*)m_Scene.GetObject(k);
	p->SetTranslation(-3.0f, 0.0f, 0.0f);

	FullRedraw();
}

void GLRender( CGLWindow* pWindow, VOID* pMain )
{
	CMainFrame* main = (CMainFrame*)pMain;

	pWindow->Use();
	pWindow->Start();
	{
		main->m_Mat.Use();
		main->m_Scene.Render(GL_RENDER);
	}
	pWindow->End();
}

void GLSelect( CGLWindow* pWindow, VOID* pMain, RECT* pRC )
{
	CMainFrame* main = (CMainFrame*)pMain;

	pWindow->Use();

	main->m_Scene.PickRects(pRC->top, pRC->left);
	main->FullRedraw();
	
}

void CMainFrame::GLResize(int nX, int nY)
{
	int nSize = 2;
	int nTop= 0;
	int nWidth = (nX/2)-(nSize*2);
	int nHeight = (nY/2)-(nSize*2)-(nTop/2);

	m_pGLWindow1->Resize(nSize, nSize+nTop,								nWidth, nHeight);
	m_pGLWindow2->Resize((nX-nWidth)-nSize, nSize+nTop,					nWidth, nHeight);
	m_pGLWindow3->Resize(nSize, (nY-nHeight)-nSize,						nWidth, nHeight);
	m_pGLWindow4->Resize((nX-nWidth)-nSize, (nY-nHeight)-nSize,			nWidth, nHeight);
}

void CMainFrame::GLKill()
{
	m_pGLWindow1->Kill();
	m_pGLWindow2->Kill();
	m_pGLWindow3->Kill();
	m_pGLWindow4->Kill();
}

void CMainFrame::FullRedraw()
{
	m_pGLWindow1->Use();
	m_pGLWindow1->Start();
	{
		m_Scene.Render(GL_RENDER);
	}
	m_pGLWindow1->End();

	m_pGLWindow2->Use();
	m_pGLWindow2->Start();
	{
		m_Scene.Render(GL_RENDER);
	}
	m_pGLWindow2->End();

	m_pGLWindow3->Use();
	m_pGLWindow3->Start();
	{
		m_Scene.Render(GL_RENDER);
	}
	m_pGLWindow3->End();

	m_pGLWindow4->Use();
	m_pGLWindow4->Start();
	{
		m_Scene.Render(GL_RENDER);
	}
	m_pGLWindow4->End();
}
