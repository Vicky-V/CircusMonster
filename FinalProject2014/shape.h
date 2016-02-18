#ifndef _SHAPE_H
#define _SHAPE_H

#include <windows.h>
//include statements for the added functions to work
#include <memory>
#include <vector>
#include <cmath>//for rotation functions


class CPrecisionPoint
{
public:
	double x;
	double y;
};

class CShape
{
protected://was changed to protected so that draw funcitons could access the data memebrs
	HPEN m_Pen;
	HBRUSH m_Brush;
	HPEN m_PreviousPen;
	HBRUSH m_PreviousBrush;
	CPrecisionPoint m_Start;
	CPrecisionPoint m_End;

public:
	CShape(const LOGPEN & pen, const LOGBRUSH & brush, const CPrecisionPoint start, const CPrecisionPoint end);
	~CShape();						

	void SetStartingPoint(const CPrecisionPoint & start) { m_Start = start; }
	void SetEndingPoint(const CPrecisionPoint & end) { m_End = end;	}

	virtual void Draw(HDC hdc)=0;//pure virtual method (it never exists, so it's assigned to 0 in order to be compiled) 
	//It is decided dynamically which one of the methods from the derived classes to use basing on the object type
	virtual void Rotate(short angle) = 0;//pure virtual method

	void MoveX(double amount)
	{
		m_Start.x += amount;
		m_End.x += amount;
	}

	void MoveY(double amount)
	{
		m_Start.y += amount;
		m_End.y += amount;
	}

	double GetStartingPointX() { return m_Start.x; };
	double GetStartingPointY() { return m_Start.y; };
	double GetEndingPointX() { return m_End.x; };
	double GetEndingPointY() { return m_End.y; };

	CPrecisionPoint GetStartingPoint() { return m_Start; };
	CPrecisionPoint GetEndingPoint() { return m_End; };
	
};

#endif /




