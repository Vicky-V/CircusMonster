// ADD your 3 new derived shape classes here																				
#ifndef DERIVEDSHAPES_H 
#define DERIVEDSHAPES_H


#include "shape.h"

class CRectangle :public CShape //making a class + publically inheriting CShape class' methods and data memebers (public creates an "is a relationship")
{

public:
	CRectangle(const LOGPEN & pen, const LOGBRUSH & brush, const CPrecisionPoint start, const CPrecisionPoint end);//
	void Draw(HDC hdc);//public method for shape drawing (it polymorphic, which means it is decided during runtime which one of the other polymorphic methods to use (according to vtable))
	void Rotate(const short angle);//this is a public method for rotation(also polymorphic)
};

class CLine :public CShape
{
public:
	CLine(const LOGPEN & pen, const LOGBRUSH & brush, const CPrecisionPoint start, const CPrecisionPoint end);
	void Draw(HDC hdc);
	void Rotate(short direction);

};

class CEllipse :public CShape
{
public:
	CEllipse(const LOGPEN & pen, const LOGBRUSH & brush, const CPrecisionPoint start, const CPrecisionPoint end);
	void Draw(HDC hdc);
	void Rotate(short angle);

};

#endif