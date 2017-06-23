#ifndef CPANEL_H
#define CPANEL_H

#include <windows.h>
#include <stdio.h>

class CPanel
{
private:
protected:
	HINSTANCE							m_hInstance;
	HWND								m_hWnd, m_hParent;
	RECT*								m_rcDimension;
	int									m_nID;

	DWORD								m_dwWindowStyle;
	DWORD								m_dwExWindowStyle;
 	DWORD								m_dwCreationFlags;
	HBRUSH								m_hbrWindowColor;
	HICON								m_hIcon;
public:
	CPanel(HINSTANCE hInstance, HWND hParent, int nID);
	~CPanel(void);
	
	HWND Create();
	void Resize(RECT* rcDimension);

	LRESULT KlasseProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	void SetHandle(HWND hWnd) { m_hWnd = hWnd; };
};
#endif