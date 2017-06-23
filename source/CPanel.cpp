#include "CPanel.h"

//////////////////////////////////////////////////////////////////
// Koppeling WINDOW HANDLE(HWND) -> Klasse
//////////////////////////////////////////////////////////////////
LRESULT CALLBACK KindProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
{
	// Maak pointer aan om de pointer naar bijbehorend Object in te zetten
	CPanel *pPanel = 0; 

	// Is de window zojuist aan gemaakt?
	if( uMsg == WM_NCCREATE ) 
	{// Er is nog geen pointer naar bijbehorend Object beschiknaar in de WindowLong

		// Vraag een pointer naar het Object van de bij behorende klasse op uit
		// de lpCreateParams. Dit is de laatste parameter van de
		// CreateWindowEx() functie
		pPanel = reinterpret_cast<CPanel *>( ((LPCREATESTRUCT)lParam)->lpCreateParams );
		
		// Zet deze pointer naar dat bijbehorende Object in de WindowLong
		::SetWindowLong(hWnd, GWL_USERDATA, reinterpret_cast<long>( pPanel ));
	} 
	else
	{// Er is wel een pointer naar bijbehorend Object beschikbaar

		// Vraag de pointer naar het bijbehorende Object op uit de WindowLong
		pPanel = reinterpret_cast<CPanel *>( ::GetWindowLong(hWnd, GWL_USERDATA) ); 
	}

	// Roep de MessageHandler van bijbehorend Object aan
	return pPanel->KlasseProc( hWnd, uMsg, wParam, lParam ); 
}

/////////////////////////////////////
// Constructors / Destructors      //
/////////////////////////////////////
CPanel::CPanel( HINSTANCE hInstance, HWND hParent, int nID )
{
	this->m_hInstance			 = hInstance;
	this->m_hParent				 = hParent;
	this->m_nID					 = nID;

	this->m_dwWindowStyle		 = WS_VISIBLE | WS_CHILD;
	this->m_dwExWindowStyle		 = WS_EX_STATICEDGE;
	this->m_dwCreationFlags		 = SW_SHOW;
	this->m_hbrWindowColor		 = (HBRUSH)(COLOR_WINDOW);
	this->m_hIcon				 = ::LoadIcon( m_hInstance, (LPCTSTR)IDI_APPLICATION );

	this->m_rcDimension = new RECT;
	this->m_rcDimension->left	= 0;
	this->m_rcDimension->right	= 0;
	this->m_rcDimension->top	= 0;
	this->m_rcDimension->bottom	= 0;
}


CPanel::~CPanel()
{
}

//////////////////////////////////////////////////////////////////
// Klasse methoden
//////////////////////////////////////////////////////////////////
LRESULT CPanel::KlasseProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
{
	switch ( uMsg )
	{
	case WM_CREATE:
		break;
	}
	return ::DefWindowProc( hWnd, uMsg, wParam, lParam );
}

HWND CPanel::Create()
{
	WNDCLASSEX wcex;

	// Scherm Class informatie vullen
	wcex.cbSize = sizeof(WNDCLASSEX); 
	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)KindProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= m_hInstance;
	wcex.hIcon			= m_hIcon;
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= m_hbrWindowColor;
	wcex.lpszMenuName	= NULL;
	wcex.lpszClassName	= "Panel";
	wcex.hIconSm		= m_hIcon;

	// Scherm Class aanmaken
	::RegisterClassEx(&wcex);

	// Scherm maken
	m_hWnd = ::CreateWindowEx( m_dwExWindowStyle,"Panel", "", m_dwWindowStyle,
	  this->m_rcDimension->left, this->m_rcDimension->top, 
	  this->m_rcDimension->right, this->m_rcDimension->bottom, 
	  m_hParent, (HMENU)m_nID, m_hInstance, this );

	// Scherm tonen en verversen
	::ShowWindow( m_hWnd, m_dwCreationFlags );
	::UpdateWindow( m_hWnd );

	return m_hWnd;
}

void CPanel::Resize( RECT* rcDimension )
{
	this->m_rcDimension = rcDimension;

	// Scherm verplaatsen
	::MoveWindow( m_hWnd, this->m_rcDimension->left, this->m_rcDimension->top, this->m_rcDimension->right, this->m_rcDimension->bottom, TRUE );
}