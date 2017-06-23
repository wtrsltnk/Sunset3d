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
		SceneInit();
		CPanelInit();
		break;

	case WM_SIZE:
		GLResize(LOWORD(lParam),HIWORD(lParam));
		CPanelSize(LOWORD(lParam),HIWORD(lParam));
		break;

	case WM_QUIT:
		GLKill();
		break;

	case WM_COMMAND:
		DWORD hi, lo;
		hi = HIWORD(wParam);
		lo = LOWORD(wParam);
		switch (lo)
		{
		case CP_OBJECT_LIST:
			switch (hi) 
			{ 
			case LBN_SELCHANGE:
				CGLObject* pObj;
				pObj = m_Scene.GetObject(m_pList->getSelectedData());
				pObj->ToggleSelect();
				if ( strcmp(pObj->GetClassType(), "box") == 0 )
				{
					CPanelBox(true);
					char tmp[64];

					sprintf(tmp, "%4.2f", ((CGLBox*)pObj)->GetWidth());
					m_pBoxWidth->setText(tmp);
					sprintf(tmp, "%4.2f", ((CGLBox*)pObj)->GetHeight());
					m_pBoxHeight->setText(tmp);
					sprintf(tmp, "%4.2f", ((CGLBox*)pObj)->GetDepth());
					m_pBoxDepth->setText(tmp);
				}
				else
				{
					CPanelBox(false);
				}
				FullRedraw();
				break;
			}
			break;
		case CP_BOX_WIDTH:
		case CP_BOX_HEIGHT:
		case CP_BOX_DEPTH:
			switch (HIWORD(wParam))
			{
			case EN_KILLFOCUS:
				CGLObject* pObj;
				pObj = m_Scene.GetObject(m_pList->getSelectedData());

				if ( strcmp(pObj->GetClassType(), "box") == 0 )
				{
					float w, h, d;

					w = (float)atof(m_pBoxWidth->getText().c_str());
					h = (float)atof(m_pBoxHeight->getText().c_str());
					d = (float)atof(m_pBoxDepth->getText().c_str());
					((CGLBox*)pObj)->SetCoords(w, h, d);
				}
				FullRedraw();
				break;
			}
			break;
		}
		break;
	}
	return CWin::MsgProc(hWnd, uMsg, wParam, lParam);
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

/////////////////////////////////////
// GL Functions                    //
/////////////////////////////////////
void CMainFrame::GLInit()
{
	m_pGLWindow1 = new CGLWindow(m_hInstance, m_hWnd, 10, 10, 100, 100, GL_WINDOW_ONE);
	m_pGLWindow1->Create();
	m_pGLWindow1->SetCamera(&m_Camera1);
	m_pGLWindow1->SetRender(GLRender, this);
	m_Light.Initialize();
	m_Light.SwitchLight(on);

	m_pGLWindow2 = new CGLWindow(m_hInstance, m_hWnd, 10, 10, 100, 100, GL_WINDOW_ONE);
	m_pGLWindow2->Create();
	m_pGLWindow2->SetCamera(&m_Camera2);
	m_pGLWindow2->SetRender(GLRender, this);
	m_Light.Initialize();
	m_Light.SwitchLight(on);

	m_pGLWindow3 = new CGLWindow(m_hInstance, m_hWnd, 10, 10, 100, 100, GL_WINDOW_ONE);
	m_pGLWindow3->Create();
	m_pGLWindow3->SetCamera(&m_Camera3);
	m_pGLWindow3->SetRender(GLRender, this);
	m_Light.Initialize();
	m_Light.SwitchLight(on);

	m_pGLWindow4 = new CGLWindow(m_hInstance, m_hWnd, 10, 10, 100, 100, GL_WINDOW_ONE);
	m_pGLWindow4->Create();
	m_pGLWindow4->SetCamera(&m_Camera4);
	m_pGLWindow4->SetRender(GLRender, this);
	m_Light.Initialize();
	m_Light.SwitchLight(on);
}

void CMainFrame::SceneInit()
{
	m_Mat.SetAmbient(0.0f, 0.3f, 0.5f, 1.0f);
	m_Mat.SetDiffuse(0.5f, 0.5f, 0.5f, 1.0f);
	m_Mat.SetSpecular(0.3f, 0.3f, 0.3f, 1.0f);
	m_Mat.SetShininess(0.0f);
	m_Mat.SetDiffuseTexture("H:\\mijndoc\\dot.bmp");

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

void CMainFrame::CPanelInit()
{

	m_pBoxPanel = new CPanel(m_hInstance, m_hWnd, CP_BOX);
	m_pBoxPanel->Create();

	m_pList = new CList(m_hInstance, m_hWnd, 0, 0, 100, 100, CP_OBJECT_LIST);
	m_pList->create(WS_EX_STATICEDGE);

	m_pBoxWidth = new CEdit(m_hInstance, m_hWnd, 0, 0, 100, 100, CP_BOX_WIDTH);
	m_pBoxWidth->create(WS_EX_STATICEDGE);

	m_pBoxHeight = new CEdit(m_hInstance, m_hWnd, 0, 0, 100, 100, CP_BOX_HEIGHT);
	m_pBoxHeight->create(WS_EX_STATICEDGE);

	m_pBoxDepth = new CEdit(m_hInstance, m_hWnd, 0, 0, 100, 100, CP_BOX_DEPTH);
	m_pBoxDepth->create(WS_EX_STATICEDGE);

	CPanelBox(false);

	for ( int i = 0; i < MAX_OBJECTS; i++ )
	{
		CGLObject* pObj = m_Scene.GetObject(i);
		if ( pObj )
		{
			char tmp[256];
			sprintf( tmp, "%s (%s)", pObj->GetName(), pObj->GetClassType());
			int index = m_pList->addItem(tmp);
			m_pList->setItemData(index, i);
		}
	}
}

void CMainFrame::GLResize(int nX, int nY)
{
	int nSize = 2;
	int nTop = 0;
	int nLeft = 60;
	int nWidth = (nX/2)-(nSize*2)-(nLeft/2);
	int nHeight = (nY/2)-(nSize*2)-(nTop/2);

	m_pGLWindow1->Resize(nSize, nSize+nTop,								nWidth-nLeft, nHeight);
	m_pGLWindow2->Resize((nX-nWidth)-nSize-nLeft*2, nSize+nTop,					nWidth-nLeft, nHeight);
	m_pGLWindow3->Resize(nSize, (nY-nHeight)-nSize,						nWidth-nLeft, nHeight);
	m_pGLWindow4->Resize((nX-nWidth)-nSize-nLeft*2, (nY-nHeight)-nSize,			nWidth-nLeft, nHeight);
}

void CMainFrame::CPanelSize(int nX, int nY)
{
	int nLeft = 168;

	RECT rcPanel;
	rcPanel.left = nX-nLeft-5;
	rcPanel.right = nLeft;
	rcPanel.top = nY-150;
	rcPanel.bottom = 100;

	m_pBoxPanel->Resize(&rcPanel);

	m_pList->resize(nX-nLeft-5, 2, nLeft, 300);

	m_pBoxWidth->resize(nX-nLeft-5, 305, nLeft, 20);

	m_pBoxHeight->resize(nX-nLeft-5, 330, nLeft, 20);

	m_pBoxDepth->resize(nX-nLeft-5, 355, nLeft, 20);
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
	
void CMainFrame::CPanelBox(bool show)
{
	m_pBoxWidth->hide(show);
	m_pBoxHeight->hide(show);
	m_pBoxDepth->hide(show);
}
