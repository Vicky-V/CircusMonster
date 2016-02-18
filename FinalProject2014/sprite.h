#pragma once

#include <windows.h>
#include <string>

using std::wstring;

class CSprite
{
protected:

	HBITMAP m_PreviousBitmapHandle;
	HBITMAP m_Mask;
	HBITMAP m_Sprite;
	HINSTANCE m_ApplicationInstance;

	int m_Width; 
	int m_Height;
	int m_LeftPosition;
	int m_TopPosition;

	RECT m_CurrentRect;

public:

	CSprite(HINSTANCE applicationInstance, int imageResourceID, int maskResourceID, int leftPosition , int topPosition);
	CSprite(HINSTANCE applicationInstance, wstring imageFileName, wstring maskFileName, int leftPosition, int topPosition);
	~CSprite();

	void Draw(HDC hdc);
	
	RECT GetCurrentRect();

	int GetTopPosition()				{ return m_TopPosition; }
	int GetLeftPosition()				{ return m_LeftPosition; }
	int GetWidth()						{ return m_Width; }
	int GetHeight()						{ return m_Height; }
	
	void SetTopPosition(int position)	{ m_TopPosition = position; }
	void SetLeftPosition(int position)	{ m_LeftPosition = position; }



	BOOL Hit(POINT & incoming);
};