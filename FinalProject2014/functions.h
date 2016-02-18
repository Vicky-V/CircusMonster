#ifndef functions_h
#define functions_h

#include <windows.h>
#include <windowsx.h>
#include <vector>
#include <memory>
#include <sstream>
#include <fstream>
#include<algorithm>
#include "shape.h"
#include "DerivedShapes.h"
#include "backgroundBitmap.h"
#include "spriteGDIP.h"
#include "sprite.h"
#include "characterClass.h"
#include "RandomNumberGenerator.h"
//#include "objectClass.h"
#include "DerivedShoot.h"
#include "soundclass.h"

using namespace std;

void ToWstring(const string line, wstring &wline);
bool ReadFileContents(vector <string> & fileNames);
bool ReadFileContents(vector <string> & fileNames, const string & playlistName);

void DisplayText(HDC hdc, int &speechBoxPositionX, int &speechBoxPositionY, const vector <string> &speechList,
	WPARAM wParam_previous, mainCharacter &JakeTheJanitor, int &speechLineNumber, bool &speechSystem, bool &speechMode, 
	bool &puzzleSolved, const unsigned short Time, bool &Finished, bool &gameFinal,unsigned short &score, bool &puzzleMode);
void UpdateGameObjects(short &moveX, short &moveY, vector <unique_ptr <CShape>> &shapeList,
	const bool walkingMode, vector <unique_ptr <CTransSprite>> &spriteList,
	mainCharacter &JakeTheJanitor, unsigned short &score, const WPARAM &wParam,
	const int windowHeight, const int windowWidth, const unsigned short blockedAreaSize_top,
	const unsigned short blockedAreaSize_sides, bool &speechMode, bool& cutSceneOver, bool &puzzleMode,
	short &directionAngle, bool &readNumber, unsigned short &playerPassword, const unsigned short password, 
	bool &puzzleSolved, bool &shootingMode, CSound &backgroundMusic, bool &changesAssigned, const unsigned short Time,const bool gameFinal);
void CreateGameObjects(LOGPEN thePen, LOGBRUSH theBrush, CPrecisionPoint &startPoint, CPrecisionPoint &endPoint,
	const int windowHeight, const int windowWidth, vector <unique_ptr <CShape>> &shapeList, unique_ptr <CShape> &shapePtr,
	const unsigned short turretRadius, const unsigned short gunLength, const unsigned short gunWidth,
	const unsigned short tankWidth, const unsigned short tankLength, const CPrecisionPoint gameObjectPosition,
	const COLORREF GREEN, const COLORREF BLACK, const COLORREF GRAY, const COLORREF BLUE, const COLORREF RED,
	vector <unique_ptr <CTransSprite>> &spriteList, vector <unique_ptr <CBackgroundBitmap>> &backgroundList, 
	mainCharacter &JakeTheJanitor, unique_ptr <CShoot> &Fireball, const HWND windowHandle, const unsigned short shellRadius);
void DrawGameObjects(HDC hdc, vector <unique_ptr <CShape>> &shapeList, vector <unique_ptr <CBackgroundBitmap>> &backgroundList,
	vector <unique_ptr <CTransSprite>> &spriteList, bool &walkingMode, bool &gameStarted,
	const unsigned int animationStatus, mainCharacter &JakeTheJanitor, unique_ptr <CShoot> &Fireball,
	const WPARAM wParam, bool &shootingMode, const unsigned short score, unsigned short time, bool puzzleMode, bool &puzzleSolved, bool &gameFinal, bool &speechMode);
void GameObjectCollision(unique_ptr <CShoot> &Fireball, vector <unique_ptr <CTransSprite>> &spriteList, const WPARAM wParam,
	const int windowHeight, const int windowWidth, const unsigned short blockedAreaSize_top, const unsigned short blockedAreaSize_sides,
	mainCharacter &JakeTheJanitor, unsigned short &score, bool &shootingMode, bool &changesAssigned, bool &cutSceneOver);

template <typename T>
wstring ToString(const T & numericDatatype)
{
	wstringstream theStringsStream;
	theStringsStream << numericDatatype;
	return theStringsStream.str();
};

#endif