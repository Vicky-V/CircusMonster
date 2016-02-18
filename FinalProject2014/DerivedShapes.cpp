// ADD your 3 new derived shape class constructors definitions and Draw method definitions here

// Remember to call the base class constructor for each new shape class
#include "DerivedShapes.h"




// Sample code to draw each of the 3 new shapes:

// NOTE that ALL Draw methods MUST be passed an HDC. For example: Draw(HDC hdc). 
// This HDC comes from the WM_PAINT message handler.


CRectangle::CRectangle(const LOGPEN & pen, const LOGBRUSH & brush, const CPrecisionPoint start, const CPrecisionPoint end)//new class constructor from the header file
																								:CShape(pen, brush, start, end)//base constructor
{

}
CLine::CLine(const LOGPEN & pen, const LOGBRUSH & brush, const CPrecisionPoint start, const CPrecisionPoint end) : CShape(pen, brush, start, end)
{

}
CEllipse::CEllipse(const LOGPEN & pen, const LOGBRUSH & brush, const CPrecisionPoint start, const CPrecisionPoint end) : CShape(pen, brush, start, end)
{

}



// The Line shape Draw Method sample:


void CLine::Draw(HDC hdc)
{
// Select the current pen and brush.
m_PreviousPen = (HPEN)SelectObject(hdc, m_Pen);
m_PreviousBrush = (HBRUSH)SelectObject(hdc, m_Brush);
// Draw the line.
MoveToEx(hdc, (int)m_Start.x, (int)m_Start.y, 0);
LineTo(hdc, (int)m_End.x, (int)m_End.y);
// Restore the old pen and brush.
SelectObject(hdc, m_PreviousPen);
SelectObject(hdc, m_PreviousBrush);
}

/*****************************************
Date:	 April 10, 2014
Arguments:short angle
Return: void
Description: Rotation of a line around the center, depending on the angle passed to the function

*****************************************/
void CLine::Rotate(const short angle)
{
	//calculating radius
	unsigned int radius = (int)sqrt(pow(m_Start.x - m_End.x, 2) + pow(m_Start.y - m_End.y, 2));
	//resetting line to its original position
	m_End.x = m_Start.x;
	m_End.y = m_Start.y-radius;
	//converting from polar to cartesian coordinates
	double x = radius * sin(angle*3.1415926 / 180);
	double y = radius * cos(angle*3.1415926 / 180);
	//incrementing the ending point values by the new coordinates 
	m_End.x += x+1;
	m_End.y += radius-(y+1);
}

// The Rectangle shape Draw Method sample:


void CRectangle::Draw(HDC hdc)
{
// Select the current pen and brush.
m_PreviousPen = (HPEN)SelectObject(hdc, m_Pen);
m_PreviousBrush = (HBRUSH)SelectObject(hdc, m_Brush);
// Draw the rectangle.
Rectangle(hdc, (int)m_Start.x, (int)m_Start.y, (int)m_End.x, (int)m_End.y);

// Restore the old pen and brush.
SelectObject(hdc, m_PreviousPen);
SelectObject(hdc, m_PreviousBrush);
}

void CRectangle::Rotate(short angle)
{
	//No implementation for this yet
}

// The Ellipse shape Draw Method sample:


void  CEllipse::Draw(HDC hdc)
{
// Select the current pen and brush.
m_PreviousPen = (HPEN)SelectObject(hdc, m_Pen);
m_PreviousBrush = (HBRUSH)SelectObject(hdc, m_Brush);
// Draw the ellipse.
Ellipse(hdc, (int)m_Start.x, (int)m_Start.y, (int)m_End.x, (int)m_End.y);
// Restore the old pen and brush.
SelectObject(hdc, m_PreviousPen);
SelectObject(hdc, m_PreviousBrush);
}

void CEllipse::Rotate(short angle)
{
	//This one also empty.
	//Though there is no point in rotating a circle
}