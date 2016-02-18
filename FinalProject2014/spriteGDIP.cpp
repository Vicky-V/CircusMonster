////////////////////////////////////////////////////////////////////////////////////////////////////
// file:	spriteGDIP.cpp
//
// summary:	Implements the sprite GDI+ class
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "spriteGDIP.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Constructor. </summary>
///
/// <remarks>	Tony Davidson, 2014-03-30. </remarks>
///
/// <param name="imageFileName">	Filename of the image file. </param>
/// <param name="leftPosition"> 	The left position. </param>
/// <param name="topPosition">  	The top position. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

CTransSprite::CTransSprite(wstring imageFileName, int leftPosition, int topPosition ) 
	: m_LeftPosition(leftPosition), m_TopPosition(topPosition)

{
	GdiplusStartup(& m_GdiplusToken, & m_GdiplusStartupInput, NULL);	// start GDI+

	std::unique_ptr<Image> backgroundImagePtr = std::make_unique <Image>(imageFileName.c_str());

	m_Height = backgroundImagePtr->GetHeight();
	m_Width = backgroundImagePtr->GetWidth();

	// transfer to a 32bpp PARGB bitmap for performance reasons only
	m_PerformanceBMP = std::make_unique <Bitmap>(m_Width, m_Height, PixelFormat32bppPARGB);

	Graphics graphics(m_PerformanceBMP.get());

	graphics.DrawImage(backgroundImagePtr.get(), 0, 0, m_Width, m_Height);

	GetCurrentRect();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destructor. </summary>
///
/// <remarks>	Tony Davidson, 2014-03-30. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

CTransSprite::~CTransSprite()
{
	if (m_PerformanceBMP)
	{
		m_PerformanceBMP = nullptr;
	}
	GdiplusShutdown(m_GdiplusToken); // shut down GDI+
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Draws the sprite to the given hdc. </summary>
///
/// <remarks>	Tony Davidson, 2014-03-30. </remarks>
///
/// <param name="hdc">	The hdc. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void CTransSprite::Draw(HDC hdc)
{	
	std::unique_ptr<Graphics> graphics = std::make_unique<Graphics>(hdc);
//	Gdiplus::Graphics * graphics = Gdiplus::Graphics::FromHDC(hdc);
	// Best settings for performance versus quality
	graphics->SetCompositingMode( CompositingModeSourceOver );
	graphics->SetCompositingQuality( CompositingQualityHighSpeed );
	graphics->SetSmoothingMode( SmoothingModeNone );
	graphics->SetPixelOffsetMode( PixelOffsetModeHalf );
	graphics->SetInterpolationMode( InterpolationModeNearestNeighbor );

	graphics->DrawImage(m_PerformanceBMP.get(), m_LeftPosition, m_TopPosition);

	graphics->Flush();  
//	delete graphics;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Calculates and returns the current rectangle occupied by the sprite. </summary>
///
/// <remarks>	Tony Davidson, 2014-03-30. </remarks>
///
/// <returns>	The current rectangle. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

RECT CTransSprite::GetCurrentRect()
{
	m_CurrentRect.left = m_LeftPosition;
	m_CurrentRect.top = m_TopPosition;
	m_CurrentRect.right =  m_CurrentRect.left + m_Width;
	m_CurrentRect.bottom = m_CurrentRect.top + m_Height;

	return m_CurrentRect;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Is the incoming point inside the current sprite rectangle. </summary>
///
/// <remarks>	Tony Davidson, 2014-03-30. </remarks>
///
/// <param name="incoming">	[in,out] The incoming. </param>
///
/// <returns>	true if point is in the current rectangle, false if not. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

BOOL CTransSprite::Hit(POINT & incoming)
{
	GetCurrentRect();
	return  PtInRect(&m_CurrentRect, incoming);
}