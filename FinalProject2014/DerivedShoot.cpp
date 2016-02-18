#include "DerivedShoot.h"

// create a constructor for both derived classes and pass all the arguments to the base class constructor
// using an initialization list

// Crete a draw method for each shell by creating one of the derived shapes and then use the draw method of the shape
// the Draw method you create will have an hdc as an argument which you pass to the shape draw method

CRoundShell::CRoundShell(const HWND windowHandle, const unsigned short shellRadius, const LOGPEN & pen, const LOGBRUSH & brush, unsigned short speed) 
																										:CShoot(windowHandle,shellRadius,pen,brush,speed)//base class contstructor is initialized here
{

}

void CRoundShell::drawShell(HDC hdc)
{
	CEllipse shell(m_Pen, m_Brush, m_Start, m_End);
	shell.Draw(hdc);
}

CSquareShell::CSquareShell(const HWND windowHandle, const unsigned short shellRadius, const LOGPEN & pen, const LOGBRUSH & brush, unsigned short speed)
:CShoot(windowHandle, shellRadius, pen, brush, speed)//base class contstructor is initialized here
{

}

void CSquareShell::drawShell(HDC hdc)
{
	CRectangle shell(m_Pen, m_Brush, m_Start, m_End);
	shell.Draw(hdc);
}