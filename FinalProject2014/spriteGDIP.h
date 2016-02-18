#pragma once

// GDI+ sprite supports transparent PNG files

#include <windows.h>
#include <gdiplus.h>
#include <string>
#include <memory>

using namespace Gdiplus;

#pragma comment(lib, "gdiplus.lib") 

using std::wstring;

class CTransSprite
{
protected:
	std::unique_ptr<Bitmap> m_PerformanceBMP;

	GdiplusStartupInput m_GdiplusStartupInput;
	
	ULONG_PTR m_GdiplusToken;


	int m_Width; 
	int m_Height;
	int m_LeftPosition;
	int m_TopPosition;

	RECT m_CurrentRect;

public:

	CTransSprite(wstring imageFileName, int leftPosition , int topPosition);

	~CTransSprite();

	void Draw(HDC hdc);

	BOOL Hit(POINT & incoming);

	int GetWidth()		  { return m_Width; }
	int GetHeight()		  { return m_Height; }
	int GetTopPosition()  { return m_TopPosition; }
	int GetLeftPosition() { return m_LeftPosition; }
	
	RECT GetCurrentRect();

	void SetLeftPosition(int position) { m_LeftPosition = position; }
	void SetTopPosition(int position)  { m_TopPosition = position; }

};