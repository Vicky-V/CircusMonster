////////////////////////////////////////////////////////////////////////////////////////////////////
// file:	backgroundBitmap.cpp
//
// summary:	Implements the background bitmap class
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "backgroundBitmap.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>
/// constructor that creates a background bitmap which has been loaded from an external file.
/// </summary>
///
/// <remarks>	Tony Davidson, 2014-03-30. </remarks>
///
/// <param name="imageFileName">	Filename of the image file. </param>
/// <param name="leftPosition"> 	The left position. </param>
/// <param name="topPosition">  	The top position. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

CBackgroundBitmap::CBackgroundBitmap( wstring imageFileName,  int leftPosition, int topPosition)
	: m_LeftPosition(leftPosition), m_TopPosition(topPosition)
{
	m_BackgroundBitmap = (HBITMAP) LoadImage (0 , imageFileName.c_str(),	IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

	BITMAP bitmap = {};
	GetObject(m_BackgroundBitmap, sizeof(BITMAP), &bitmap);
	m_Width  = bitmap.bmWidth;
	m_Height = bitmap.bmHeight;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destructor. </summary>
///
/// <remarks>	Tony Davidson, 2014-03-30. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

CBackgroundBitmap::~CBackgroundBitmap()
{
	if (m_BackgroundBitmap) 
	{
		DeleteObject (m_BackgroundBitmap);
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Draws the bitmap to the given hdc. </summary>
///
/// <remarks>	Tony Davidson, 2014-03-30. </remarks>
///
/// <param name="hdc">	The hdc. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void CBackgroundBitmap::Draw(HDC hdc)
{
	HDC bitmapHDC = CreateCompatibleDC(NULL);

	m_PreviousBitmapHandle = (HBITMAP) SelectObject(bitmapHDC,m_BackgroundBitmap);

	BitBlt(hdc,m_LeftPosition,m_TopPosition,m_Width,m_Height,bitmapHDC,0,0,SRCCOPY);
	
	// clean up
	SelectObject(bitmapHDC, m_PreviousBitmapHandle);
	DeleteDC(bitmapHDC);
}






