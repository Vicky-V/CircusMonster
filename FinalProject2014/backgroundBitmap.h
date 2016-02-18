#pragma once

#include <windows.h>
#include <string>

using std::wstring;

class CBackgroundBitmap
{
protected:

	HBITMAP m_PreviousBitmapHandle;
	HBITMAP m_BackgroundBitmap;

	int m_Width; 
	int m_Height;
	int m_LeftPosition;
	int m_TopPosition;

public:
	CBackgroundBitmap( wstring imageFileName, int leftPosition  , int topPosition    );

	~CBackgroundBitmap();

	void Draw(HDC hdc);

	int GetWidth()		  { return m_Width; }
	int GetHeight()		  { return m_Height; }
	int GetTopPosition()  { return m_TopPosition; }
	int GetLeftPosition() { return m_LeftPosition; }

	void SetLeftPosition(int position) { m_LeftPosition = position; }
	void SetTopPosition(int position)  { m_TopPosition = position; }
};