#ifndef _SHOOT_H
#define _SHOOT_H

#include <windows.h>

#include <vector>

#include "DerivedShapes.h"

using std::vector;

class CShoot
{
protected:
	LOGPEN m_Pen;
	LOGBRUSH m_Brush;
	CPrecisionPoint m_Start;
	CPrecisionPoint m_End;
	long m_ClientWindowWidth;
	long m_ClientWindowHeight;
	unsigned short m_ShellRadius;
	RECT m_Rect;
	POINT m_ShellDirection;
	POINT m_ShellDirection_old;
	unsigned int m_NumberOfShells_old;
	vector<POINT> m_ShellLocationList;
	unsigned short m_Speed;

	virtual void drawShell(HDC hdc) = 0;			// Must make this a pure virtual member function (so that the correct methods in the derived classes will be accessed depending on the type of the object)

public:
	CShoot(const HWND windowHandle, const unsigned short shellRadius,const LOGPEN & pen, const LOGBRUSH & brush, unsigned short speed = 1);

	unsigned int GetNumberOfShells();

	void draw(HDC hdc, WPARAM wParam,bool &shootingMode);

	void Fire(POINT point);

	BOOL HitTest(RECT & targetRect,  bool eraseShell = true);

	
};


#endif // _SHOOT_H
