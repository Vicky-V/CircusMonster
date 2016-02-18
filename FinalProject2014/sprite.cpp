// Tips on how to create a sprite and a sprite mask using Photoshop:

// the mask is a monochrome bitmap (using Photoshop once you only have a black and white image of your sprite change mode to gray scale 
// then choose mode>duotone then select Monotone. Then mode>bitmap and finally select "Save As" and choose a 1 bit bitmap)

// Remember you are using black for the areas you want transparent

// Important: The sprite image must use white in the same areas that are black in the mask, so the background of the sprite should be white

#include "sprite.h"

CSprite::CSprite(HINSTANCE applicationInstance, int imageResourceID, int maskResourceID, int leftPosition, int topPosition ) 
	: m_ApplicationInstance(applicationInstance), m_LeftPosition(leftPosition), m_TopPosition(topPosition)
	
{
	m_Sprite = (HBITMAP) LoadImage (m_ApplicationInstance, MAKEINTRESOURCE (imageResourceID),	IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);

	m_Mask = (HBITMAP) LoadImage (m_ApplicationInstance, 	MAKEINTRESOURCE (maskResourceID),	IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);

	BITMAP bitmap = {};
	GetObject(m_Sprite, sizeof(BITMAP), &bitmap);
	m_Width  = bitmap.bmWidth;
	m_Height = bitmap.bmHeight;

	GetCurrentRect();
}

CSprite::CSprite(HINSTANCE applicationInstance, wstring imageFileName, wstring maskFileName, int leftPosition, int topPosition)
: m_ApplicationInstance(applicationInstance), m_LeftPosition(leftPosition), m_TopPosition(topPosition)

{

//	m_BackgroundBitmap = (HBITMAP)LoadImage(0, imageFileName.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);


	m_Sprite = (HBITMAP)LoadImage(m_ApplicationInstance, imageFileName.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

	m_Mask = (HBITMAP)LoadImage(m_ApplicationInstance, maskFileName.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE );

	BITMAP bitmap = {};
	GetObject(m_Sprite, sizeof(BITMAP), &bitmap);
	m_Width = bitmap.bmWidth;
	m_Height = bitmap.bmHeight;

	GetCurrentRect();
}

CSprite::~CSprite()
{
	if (m_Sprite) 
	{
		DeleteObject (m_Sprite);
	}
	if (m_Mask) 
	{
		DeleteObject (m_Mask);
	}
}

void CSprite::Draw(HDC hdc)
{
	// create a compatible DC in memory
	HDC bitmapHDC = CreateCompatibleDC(0);
	//put the  mask bitmap into the bitmapHDC
	HBITMAP	previousBitmapHandle = (HBITMAP)SelectObject(bitmapHDC,m_Mask);

	// first we BitBlt the mask using a logical OR operation ( OR = SRCPAINT)  then BitBlt the sprite using an AND (SRCAND) operation
	// the OR of the black mask bits (all zero bits) with a background pixel will only show the background pixel
	// This is because when the black (transparent) part of our colour image is combined with the data on the destination using OR, 
	// the result is that the data is untouched, because any value combined with 0 using the OR operation is left unaffected.
	// However the OR of the white mask bits (all one bits) with a background pixel will show a white pixel.
	// This happens because the rest of our colour image isn't black, and if the destination also isn't black,
	// then we get a combination of the source and destination colours
	// the end result is a white image shaped like the sprite.
	
	// Summary:
	// When you use a logical OR: 
	// With a black mask pixel (all zero bits) or'd with a background pixel will give back the background pixel. 
	// With a white mask pixel (all one bits) or'd with a background pixel will give a white pixel. 
	// Therefore after using BitBlt with the mask using an OR (SRCPAINT) raster operation, the result is have a white shape of our sprite foreground 
	// cut out of the background the background.

	BitBlt(hdc,m_LeftPosition,m_TopPosition,m_Width,m_Height,bitmapHDC,0,0,SRCPAINT);

	// now put the sprite bitmap into the bitmapHDC
	SelectObject(bitmapHDC,m_Sprite);

	// Note that an AND of a white sprite pixel (which are all ones) with a background pixel will show the background pixel
	// Remember the background of the sprite is white so everywhere there is white in the sprite the background will show through.
	// The AND of a pixel that is not white in the sprite with the white (all ones) background (the shape shown above) will show the sprite pixel
	// this is result we are looking for.
	
	// Summary:
	// When you use a logical AND: 
	// With a white sprite pixel (all ones) AND'ed with a background pixel will retain the background pixel. 
	// With a non-white sprite pixel AND'ed with the white (all ones) background (the all white sprite foreground) will show the sprite pixel. 
	// The end result is the sprite superimposed on the background.

	// The end result is the sprite superimposed on the background:
	BitBlt(hdc,m_LeftPosition,m_TopPosition, m_Width,m_Height,bitmapHDC,0,0,SRCAND);

	//  clean up
	SelectObject(bitmapHDC,previousBitmapHandle);
	DeleteDC(bitmapHDC);

}

RECT CSprite::GetCurrentRect()
{
	m_CurrentRect.left = m_LeftPosition;
	m_CurrentRect.top = m_TopPosition;
	m_CurrentRect.right =  m_CurrentRect.left + m_Width;
	m_CurrentRect.bottom = m_CurrentRect.top + m_Height;

	return m_CurrentRect;
}

BOOL CSprite::Hit(POINT & incoming)
{
	GetCurrentRect();
	return  PtInRect(&m_CurrentRect, incoming);
}