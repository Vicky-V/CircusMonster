////////////////////////////////////////////////////////////////////////////////////////////////////
// file:	backbuffer.cpp
//
// summary:	Implements the back buffer class
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "backbuffer.h" 

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Constructor. </summary>
///
/// <remarks>	Tony Davidson, 2014-03-30. </remarks>
///
/// <param name="windowHandle">	   	Handle of the window. </param>
/// <param name="width">		   	The width. </param>
/// <param name="height">		   	The height. </param>
/// <param name="backgroundColour">	The background colour. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

CBackBuffer::CBackBuffer(HWND windowHandle, int width, int height, COLORREF backgroundColour)
	: m_WindowHandle(windowHandle),m_Width(width),m_Height(height)
{
	HDC BitmapDC = GetDC(windowHandle);
	// Create a memory device context 
	m_HDC = CreateCompatibleDC(BitmapDC);

	m_SurfaceBitmap = CreateCompatibleBitmap(BitmapDC, width, height);
	// Done with the DC
	ReleaseDC(windowHandle, BitmapDC);

	m_PreviousBitmap = (HBITMAP)SelectObject(m_HDC, m_SurfaceBitmap);

	m_BackgroundBrush.lbStyle = BS_SOLID;
	m_BackgroundBrush.lbColor = backgroundColour;

	m_BackgroundBrushHandle = CreateBrushIndirect( &m_BackgroundBrush );

	ClearSurface(); // paint the background
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destructor. </summary>
///
/// <remarks>	Tony Davidson, 2014-03-30. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

CBackBuffer::~CBackBuffer()
{
	DeleteObject(m_BackgroundBrushHandle);
	SelectObject(m_HDC, m_PreviousBitmap);
	DeleteObject(m_SurfaceBitmap);
	DeleteDC(m_HDC);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Clears the surface. </summary>
///
/// <remarks>	Tony Davidson, 2014-03-30. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void CBackBuffer::ClearSurface()
{
	HBRUSH previousBrush = (HBRUSH)SelectObject(m_HDC, m_BackgroundBrushHandle);
	// Clear the surface using a rectangle
	Rectangle(m_HDC, 0, 0, m_Width, m_Height);
	// Restore the original brush.
	SelectObject(m_HDC, previousBrush);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Sets background colour. </summary>
///
/// <remarks>	Tony Davidson, 2014-03-30. </remarks>
///
/// <param name="backgroundColour">	The background colour. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void CBackBuffer::SetBackgroundColour(COLORREF backgroundColour)
{
	DeleteObject(m_BackgroundBrushHandle); // remove the old brush

	m_BackgroundBrush.lbStyle = BS_SOLID;
	m_BackgroundBrush.lbColor = backgroundColour;

	m_BackgroundBrushHandle = CreateBrushIndirect( &m_BackgroundBrush );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Presents to the HDC. </summary>
///
/// <remarks>	Tony Davidson, 2014-03-30. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void CBackBuffer::Present()
{
	// Get a handle to the device context 
	HDC hdc = GetDC(m_WindowHandle);
	// BLIT the CBackBuffer contents over to the window client area.
	BitBlt(hdc, 0, 0, m_Width, m_Height, m_HDC, 0, 0, SRCCOPY);
	// Free the DC
	ReleaseDC(m_WindowHandle,hdc);
}

