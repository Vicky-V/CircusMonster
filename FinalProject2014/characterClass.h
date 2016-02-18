#pragma once

#include <windows.h>
#include <windowsx.h>
#include <vector>
#include <memory>
#include <string>
#include "shape.h"
#include "DerivedShapes.h"
#include "backgroundBitmap.h"
#include "spriteGDIP.h"

using namespace std;

class mainCharacter
{
private:
	unique_ptr <CTransSprite> m_CharacterLeft_walking=nullptr;
	unique_ptr <CTransSprite> m_CharacterLeft_normal=nullptr;
	unique_ptr <CTransSprite> m_CharacterRight_walking=nullptr;
	unique_ptr <CTransSprite> m_CharacterRight_normal=nullptr;
	unique_ptr <CTransSprite> m_CharacterUp_walking=nullptr;
	unique_ptr <CTransSprite> m_CharacterUp_normal=nullptr;
	unique_ptr <CTransSprite> m_CharacterDown_walking=nullptr;
	unique_ptr <CTransSprite> m_CharacterDown_normal=nullptr;
	
public:
	
	mainCharacter();

	void SetPosition(const int x, const int y);

	int GetTopPosition(WPARAM wParam);
	int GetLeftPosition(WPARAM wParam);

	string GetDirection();

	bool HitBackground(vector <unique_ptr <CTransSprite>> &spriteList, WPARAM wParam, const int windowWidth, const int windowHeight, 
		const unsigned short blockedAreaSize_top, const unsigned short blockedAreaSize_bottom);

	
	POINT positionAsPoint;
	RECT GetRectangle(WPARAM wParam);
	
	
	void SetCharacterLeft_walking(wstring name, int x, int y );
	void SetCharacterLeft_normal(wstring name, int x, int y);
	void SetCharacterRight_walking(wstring name, int x, int y);
	void SetCharacterRight_normal(wstring name, int x, int y);
	void SetCharacterUp_walking(wstring name, int x, int y);
	void SetCharacterUp_normal(wstring name, int x, int y);
	void SetCharacterDown_walking(wstring name, int x, int y);
	void SetCharacterDown_normal(wstring name, int x, int y);


	//void Move(WPARAM wParam);
	

	void SwapSpritesLeft(vector <unique_ptr <CTransSprite>> &spriteList);
	void SwapSpritesLeft(vector <unique_ptr <CTransSprite>> &spriteList, const unsigned short index);

	void SwapSpritesRight(vector <unique_ptr <CTransSprite>> &spriteList);
	void SwapSpritesRight(vector <unique_ptr <CTransSprite>> &spriteList, const unsigned short index);

	void SwapSpritesUp(vector <unique_ptr <CTransSprite>> &spriteList);
	void SwapSpritesUp(vector <unique_ptr <CTransSprite>> &spriteList, const unsigned short index);

	void SwapSpritesDown(vector <unique_ptr <CTransSprite>> &spriteList);
	void SwapSpritesDown(vector <unique_ptr <CTransSprite>> &spriteList, const unsigned short index);
};

