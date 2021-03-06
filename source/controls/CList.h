#ifndef CLIST_H
#define CLIST_H

#include <windows.h>
#include <commctrl.h>
#include <string>
#include "CControl.h"
using namespace std;

class CList : public CControl
{
private:
public:
	CList( HINSTANCE, HWND, int, int, int, int, int );
	CList( HINSTANCE, HWND );

	void create( void );
	void create( DWORD );
	void create( DWORD, DWORD );

	int addItem( string );
	void setItemData( int, int );
	int getItemData( int );
	int getSelectedData();
	bool remItem( int );
	string getItem( int );
};
#endif
