#ifndef _BACKBUFFER_H
#define _BACKBUFFER_H

#include <windows.h>

class CBackBuffer
{
protected:
	HWND m_WindowHandle;

	int m_Width;
	int m_Height;

	HDC m_HDC;

	HBITMAP m_SurfaceBitmap;
	HBITMAP m_PreviousBitmap;

	LOGBRUSH m_BackgroundBrush;
	HBRUSH m_BackgroundBrushHandle;

public:
	CBackBuffer(HWND windowHandle, int width, int height, COLORREF backgroundColour = 0x00FFFFFF);
	~CBackBuffer();

	void Present();
	void ClearSurface();
	void SetBackgroundColour(COLORREF backgroundColour);

	HDC GetHDC()				{ return m_HDC; }
	int GetWidth()				{ return m_Width; }
	int GetHeight()				{ return m_Height; }
	HBITMAP GetSurfaceHandle()	{ return m_SurfaceBitmap; }
};

#endif // _BACKBUFFER_H