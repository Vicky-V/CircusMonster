// create two new shell objects that use the CShoot object as the base class.
#pragma once

#include"shoot.h"

class CRoundShell : public CShoot //this is a derived class which inherits public methods of base class CShoot (private members of the base class cannot be accessed)
{
protected:
	void drawShell(HDC hdc);
public:
	CRoundShell(const HWND windowHandle, const unsigned short shellRadius, const LOGPEN & pen, const LOGBRUSH & brush, unsigned short speed = 1);


};

class CSquareShell : public CShoot//this is a derived class which inherits public methods of base class CShoot (private members of the base class cannot be accessed)
{
protected:
	void drawShell(HDC hdc);
public:
	CSquareShell(const HWND windowHandle, const unsigned short shellRadius, const LOGPEN & pen, const LOGBRUSH & brush, unsigned short speed = 1);

};





