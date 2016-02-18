/***************************************************************************************

Title:	   	Final Project
Course: 	GAM1509 Game Development 2
Section:  	2
Author:  	Viktoriya Voinova
Date:	   	March 24, 2014

Description: 	

Project setup:

 

Create a new Win32 empty project. Add a new cpp file to your project labelled WinMain.cpp. Copy the provided Win32 game template source code from the Final Project folder located on the public drive, then paste it into the WinMain.cpp file.

 

The DerivedShapes and the shape header and cpp files from assignment 7 must be copied into your project folder (in the same location as your WinMain.cpp file) and then included in your project. This will give you access to the 3 shape objects we previously created during this course.

 

Once the subject has been covered in class the backbuffer header and cpp files must be copied into your project folder (in the same location as your WinMain.cpp file) and then included in your project. This will give you access to the back buffer drawing technology.

 

The FMOD Sound Class and support files must also be added to your project. Follow the instructions in the Final Project folder located on the public drive.

 

User Interface and Resources:

 

A menu will be created, loaded and attached to the main window. The menu will have the following functionality as a minimum requirement; however additional menu items can be added as needed:

 

Game > Exit

 

Frame Rate > Normal 50 FPS Frame Rate > Minimum 25 FPS Frame Rate > Maximum 100 FPS

 

Help > About

 

The menu items must be checked when selected and uncheck previous selections. Each menu item must perform its required task correctly.

 

Add a Message Box to the Help>About message handler that outputs the game name, version number and student name.

 

An icon, created by the student, will be loaded and used for the main window icon.

 

Code Required:

 

The game loop should only contain function/method calls except for very basic functionality such as pausing the game. Reading the source code inside the game loop should easily describe what is taking place. In other words the function/method calls are named appropriately. This should read like an index in a book.

 

All functions except for WinMain and WinProc must be located in separate header and cpp file(s). Only the WinMain and WinProc functions are to be located in the WinMain cpp file.

 

Each source cpp file should only contain the global variables it uses. Pass variables that are used in more than 1 cpp file as arguments to the functions in another cpp file that require them. Remember to pass using const whenever possible and pass by reference whenever possible/required.

Note: Only one extern is allowed and this can only be used for a single unique_ptr.

 

At least 1 class, with at least 1 added constructor, 1 data member and 1 method, will be created by the student and used in this project.

 

At least 1 STL algorithm must be used in this project. This must also be fully documented.

 

The program will contain a global variable for a LOGPEN and a LOGBRUSH. These two objects will be used to draw on the client window.

 

The program will contain a global COLORREF variables containing colours that will be used for the CShape derived objects. Create as many of these variables as you need.

 

You must modify the global variables to create a window that is at least 1024 x 768, starts up located at an X and Y coordinate that is different from the template default values. The window class name will be set to “Final Project GAM-1509” and the window title will be set to the student’s full name. Note this can change during game play.

 

The window style should be set to WS_OVERLAPPED | WS_SYSMENU | WS_VISIBLE to prevent resizing and to make sure there are no minimize and maximize buttons.

 

The game will contain a function/method that calculates and outputs the current frame rate in 1 second intervals based on the menu setting for frame rate. The calculations will be made using the C++ 11 chrono library technology. This will be covered in class. The frame rate will be displayed in the window caption bar. The frame rate will be fixed using the following values:

 

Frame Rate > Normal 50 FPS

 

Frame Rate > Minimum 25 FPS

 

Frame Rate > Maximum 100 FPS

 

Inside the game loop two point objects, CPrecisionPoint startPoint and CPrecisionPoint endPoint will be created and used to draw shape objects contained in the DerivedShapes cpp file.

 

Each cycle of the game loop must erase the previous screen data

 

An object (game object) that contains at least 1 instance of the Cline, CEllipse and CRectangle derived shape objects and will be drawn during each cycle of the game loop.

 

This game object must form some kind of game object such as a vehicle, character, flying object, logo etc. The object will be drawn using the pen, brush and CPrecisionPoint objects.

 

The game object must also be able to move around the client area in a minimum of 4 directions (up, down, left, right) using the four keyboard arrow keys. The game object will be re-drawn in its new position with each cycle of the game loop.

 

 

At least one sprite, created using a bitmap mask, or using a transparent sprite must be created and used as a game object in your game. The sprite must move inside the game window using keyboard control and/or timer movement.

 

The game object or sprite must have a least 1 additional capability such as firing or throwing a weapon, this capability must be activated using the space bar. Once activated the movement the results of the action must be tracked and updated during each cycle of the game loop.

 

At least one game object or sprite must be able to rotate a part or all of itself. Rotation will be controlled by the keyboard or game A.I.

 

Each keyboard press of the arrow and space bar keys must play a sound file using the FMOD sound class and background music must also be played. Each sound should be relevant to the activity taking place.

 

A CBackBufferobject, created as a unique_ptr using make_unique, will be used for all game drawing in order to remove flicker.

 

A CFrameRateThrottle object, created as a unique_ptr using make_unique, will be used for all controlling the games frame rate.

 

Your game will include will use polymorphism to draw the CShape derived objects. A CShape object pointer, created as a unique_ptr using make_unique, will be used a base class pointer that holds the address of all the dynamically created shapes. An std::vector of CShape unique_ptr will be used to hold all the shapes created and used in your game.  

NOTE: As unique_ptr is the sole owner of a derived object C++ 11 move semantics will be used to push the CShape object pointer onto the std::vector shape list. This must be fully documented.

 

During the development of this project a base class object will be provided. This object must be used as a base class to derive two additional objects both of which implement a virtual method to implement drawing. This will be covered during class.

 

Features:

 

Your game must keep score.

Your game must provide a pause feature.

Your game must be able to restart without having to exit the application.

Your game must play background music and contain sound effects.

 

 

Optional:

 

The basic project described above can be greatly modified to include multiple game objects and include any desired form of game play. However the basic requirements must be included.

Creativity is encouraged and welcomed!

 

NOTE: Remember to read the final project assignment rubric.

 

As always make sure you include the required comment header information, comment your code and use descriptive variable names.

 

NOTE: All code created for this project, unless supplied by the instructor, must be the original work of the student this is not a group project.

 

Due: April 15, 2014 at midnight

*****************************************************************************************/


#include <windows.h>
#include <windowsx.h>			// Contains Macro APIs, window message crackers, and control APIs
#include <string>
#include <memory>
#include <vector>
#include<algorithm>

#include "soundclass.h"
#include "functions.h"
#include "resource.h"
#include "DerivedShapes.h"
#include "backbuffer.h"
#include "backgroundBitmap.h"
#include "spriteGDIP.h"
#include "FrameRateThrottle.h"
#include "sprite.h"
#include "DerivedShoot.h"
//#include "objectClass.h"

using std::wstring;
using std::vector;
using std::unique_ptr;

/*
	
	Graphics&characters belong to Viktoriya Voinova

	Ending theme for a full ending: Vocaloids - Circus Monster (music box)

	Shooting sound created using Bxfr

	Other soundtracks taken from http://opengameart.org/content/generic-8-bit-jrpg-soundtrack


*/

//Apparently, this version of the game crashes when two buttons are pressed at the same time. 
//I think it happens due to the fact that I swap different pointers from character class and spriteList vector inside the case statements, 
//so when two buttons are pressed both sets of sprites' pointers for animation are swapped at the same time using the same spriteList and it gives an error.



#pragma region GLOBAL_VARIABLES
// Store global handles to the main window, application and menu

HWND windowHandle = 0;
HINSTANCE applicationInstance = 0;
HMENU mainMenuHandle = 0;

// Set the initial position of your window
int windowXPosition = 100;
int windowYPosition = 100;

int windowWidth = 1000;
int windowHeight = 750;

int windowClientWidth = 0;
int windowClientHeight = 0;

const wstring windowTitle = L"GAM1509 Standard Windows Game Template";
const wstring windowClassName = L"GAM1509 Standard Windows Game Template Class";

//Game Objects

LOGPEN thePen;
LOGBRUSH theBrush;
CPrecisionPoint startPoint;
CPrecisionPoint endPoint;

CPrecisionPoint gameObjectPosition;

const COLORREF BLACK=RGB(0,0,0);
const COLORREF GRAY = RGB(50, 50, 50);
const COLORREF WHITE = RGB(255, 255, 255);
const COLORREF RED = RGB(255, 0, 0);
const COLORREF GREEN = RGB(0, 255, 0);
const COLORREF BLUE = RGB(0, 0, 255);

short speed = 5;
short acceleration = 5;
short moveX = 0;
short moveY = 0;
short directionAngle = 0;

mainCharacter JakeTheJanitor;
//objectForGathering garbageMonster;

const unsigned short shellRadius = 6;
unique_ptr <CShoot> Fireball = nullptr;

vector <string> speechList;


//Shape variables

unique_ptr <CShape> shapePtr = nullptr;
vector <unique_ptr <CShape>> shapeList;

//constants

//#define TANKBASE 0
//#define TANKTURRET TANKBASE +1
//#define TANKGUN TANKBASE +2

const unsigned short turretRadius = 186;
const unsigned short gunLength = 225;
const unsigned short gunWidth = 10;
const unsigned short tankWidth = 40;
const unsigned short tankLength = 80;

const unsigned short blockedAreaSize_top = 160;
const unsigned short blockedAreaSize_sides = 170;

//variables for animation and game's statuses
const unsigned int mainTimer = 1;
const unsigned int levelTimer = 2;

bool gameStarted = false;
bool gameFinal = false;
bool walkingMode = false;
bool shootingMode = false;
bool Paused = false;
bool Finished = false;
bool Restart = false;
bool speechMode = true;
bool speechSystem = false;
bool cutSceneOver = true;
bool puzzleMode = false;
bool readNumber = false;
bool puzzleSolved = false;
bool changesAssigned = false;
bool updatingInput = false;

//other game variables
unsigned short password=4162;
unsigned short playerPassword = 0;
unsigned short Score = 0;
unsigned short Time = 120;
unsigned short frameRate;


int speechBoxPositionX = 200;
int speechBoxPositionY = 50;
int speechLineNumber = 0;

unsigned int animationStatus = 0;//0 - no sprite at all, 1 - change to normal sprite, 2 - change to "walking" sprite
WPARAM wParam_previous='W';
WPARAM movementDirection = ' ';



//vectors for bitmaps and sprites
vector <unique_ptr <CBackgroundBitmap>> backgroundList; //this is a vector of unique pointers, each one pointing to a specific background image
vector <unique_ptr <CTransSprite>> spriteList(3);//a list of sprites to be animated

//sound

CSound backgroundMusic("01 - Opening.mp3", true);//background music
CSound FireSound("fireball.mp3", false);//shooting sound

#pragma endregion GLOBAL_VARIABLES

void UpdateInput(WPARAM key, bool keyIsDown)
{
	
	if (keyIsDown)
	{

		if (!speechMode&&!puzzleMode)//if not in puzzle mode or it's not a cutscene
		{

			if (!gameStarted)//if no key has been pressed yet
			{
				JakeTheJanitor.SwapSpritesLeft(spriteList, 2);//making spriteList empty and ready for animation
			}
			if (walkingMode == false && gameStarted)//if the spriteList is empty
			{
				//swap sprites based on direction
				switch (wParam_previous)
				{
				case 'W':
					JakeTheJanitor.SwapSpritesUp(spriteList, 2);
					break;
				case 'A':
					JakeTheJanitor.SwapSpritesLeft(spriteList, 2);
					break;
				case 'S':
					JakeTheJanitor.SwapSpritesDown(spriteList, 2);
					break;
				case 'D':
					JakeTheJanitor.SwapSpritesRight(spriteList, 2);
					break;
				}
			}
			walkingMode = true;
			gameStarted = true;
			
			switch (key)
			{
			case 'W':
				movementDirection = 'W';
				break;
			case 'A':
				movementDirection = 'A';
				break;
			case 'S':
				movementDirection = 'S';
				break;
			case 'D':
				movementDirection = 'D';
				break;
			}

			if (spriteList[0] == nullptr && spriteList[1] == nullptr)//checking if pointers are pointing to something or not
			{
				switch (key)
				{
				case 'W':
					JakeTheJanitor.SwapSpritesUp(spriteList);
					break;
				case 'A':
					JakeTheJanitor.SwapSpritesLeft(spriteList);
					break;
				case 'S':
					JakeTheJanitor.SwapSpritesDown(spriteList);
					break;
				case 'D':
					JakeTheJanitor.SwapSpritesRight(spriteList);
					break;
				}
			}

			if (!JakeTheJanitor.HitBackground(spriteList, key, windowWidth, windowHeight,	//check if blocked area was hit or not
				blockedAreaSize_top, blockedAreaSize_sides))
			{
				
				for (int c = 0; c >= 0 && c < 3; c++)//decrease Y position for all current sprites in spriteList
				{
					switch (key)
					{
					case 'W':
						if (spriteList[c] != nullptr)
						{
							spriteList[c]->SetTopPosition(spriteList[c]->GetTopPosition() - speed);

						}
						break;
					case 'A':
						if (spriteList[c] != nullptr)
						{
							spriteList[c]->SetLeftPosition(spriteList[c]->GetLeftPosition() - speed);

						}
						break;
					case 'S':
						if (spriteList[c] != nullptr)
						{
							spriteList[c]->SetTopPosition(spriteList[c]->GetTopPosition() + speed);

						}
						break;
					case 'D':
						if (spriteList[c] != nullptr)
						{
							spriteList[c]->SetLeftPosition(spriteList[c]->GetLeftPosition() + speed);

						}
						break;
					}


				}
			}
		}
		
		return;
	}
	else if (movementDirection==key)
	{
		if (!speechMode&&!puzzleMode)//if it's not the cutscene and the puzzle mode is off
		{

			walkingMode = false;
			movementDirection = ' ';
			switch (key)
			{
			case 'W':
				JakeTheJanitor.SwapSpritesUp(spriteList);//place the sprites back to the character data members
				break;
			case 'A':
				JakeTheJanitor.SwapSpritesLeft(spriteList);
				break;
			case 'S':
				JakeTheJanitor.SwapSpritesDown(spriteList);
				break;
			case 'D':
				JakeTheJanitor.SwapSpritesRight(spriteList);
				break;
			}
			
			if (JakeTheJanitor.HitBackground(spriteList, key, windowWidth, windowHeight, blockedAreaSize_top, blockedAreaSize_sides))//hit check
			{
				
				switch (key)
				{
				case 'W':
					JakeTheJanitor.SetPosition(JakeTheJanitor.GetLeftPosition(key), blockedAreaSize_top + 1);//set position 1 pixel away from the blocked area
					break;
				case 'A':
					JakeTheJanitor.SetPosition(blockedAreaSize_sides + 1, JakeTheJanitor.GetTopPosition(key));//set position 1 pixel away from the blocked area
					break;
				case 'S':
					JakeTheJanitor.SetPosition(JakeTheJanitor.GetLeftPosition(key), windowHeight- blockedAreaSize_top - 1);//set position 1 pixel away from the blocked area
					break;
				case 'D':
					JakeTheJanitor.SetPosition(windowWidth - blockedAreaSize_sides - 1, JakeTheJanitor.GetTopPosition(key));//set position 1 pixel away from the blocked area
					break;
				}
			}
			else
			{
				switch (key)
				{
				case 'W':
					JakeTheJanitor.SetPosition(JakeTheJanitor.GetLeftPosition(key), JakeTheJanitor.GetTopPosition(key) - speed);//set position normally
					break;
				case 'A':
					JakeTheJanitor.SetPosition(JakeTheJanitor.GetLeftPosition(key)-speed, JakeTheJanitor.GetTopPosition(key));
					break;
				case 'S':
					JakeTheJanitor.SetPosition(JakeTheJanitor.GetLeftPosition(key), JakeTheJanitor.GetTopPosition(key)+speed);
					break;
				case 'D':
					JakeTheJanitor.SetPosition(JakeTheJanitor.GetLeftPosition(key)+speed, JakeTheJanitor.GetTopPosition(key));
					break;
				}
			}

			JakeTheJanitor.positionAsPoint.x = JakeTheJanitor.GetLeftPosition(key) + 32;
			JakeTheJanitor.positionAsPoint.y = JakeTheJanitor.GetTopPosition(key) + 32;
			switch (key)
			{
			case 'W':
				JakeTheJanitor.SwapSpritesUp(spriteList,2);//place the sprites back to the character data members
				break;
			case 'A':
				JakeTheJanitor.SwapSpritesLeft(spriteList,2);
				break;
			case 'S':
				JakeTheJanitor.SwapSpritesDown(spriteList,2);
				break;
			case 'D':
				JakeTheJanitor.SwapSpritesRight(spriteList,2);
				break;
			}
			wParam_previous = key;
			updatingInput = false;
		}
	}
}

// The windows procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_GAME_EXIT:
			DestroyWindow(hwnd);
			return 0;
		case ID_GAME_RESTART:
			Restart = true;
			return 0;
		case ID_HELP_ABOUT:
			MessageBox(hwnd, L"The Game(c) version 0.1 by Viktoriya Voinova", L"About", MB_OK);
			return 0;
		case ID_FRAMERATE_MINIMUM25FPSFRAMERATE:
			frameRate = 25;
			CheckMenuRadioItem(mainMenuHandle, ID_FRAMERATE_NORMAL50FPSFRAMERATE,
				ID_FRAMERATE_MAXIMUM100FPS, ID_FRAMERATE_MINIMUM25FPSFRAMERATE, MF_BYCOMMAND);
			return 0;
		case ID_FRAMERATE_NORMAL50FPSFRAMERATE:
			CheckMenuRadioItem(mainMenuHandle, ID_FRAMERATE_NORMAL50FPSFRAMERATE,
				ID_FRAMERATE_MAXIMUM100FPS, ID_FRAMERATE_NORMAL50FPSFRAMERATE, MF_BYCOMMAND);
			frameRate = 50;
			return 0;
		case ID_FRAMERATE_MAXIMUM100FPS:
			CheckMenuRadioItem(mainMenuHandle, ID_FRAMERATE_NORMAL50FPSFRAMERATE,
				ID_FRAMERATE_MAXIMUM100FPS, ID_FRAMERATE_MAXIMUM100FPS, MF_BYCOMMAND);
			frameRate = 100;
			return 0;
		}
	case WM_KEYUP:
		switch (wParam)
		{
		case VK_DOWN:

			speed = 5;
			return 0;
		case VK_UP:

			speed = 5;
			return 0;
		case VK_LEFT:

			speed = 5;
			return 0;
		case VK_RIGHT:

			speed = 5;
			return 0;
		case 'W':
			UpdateInput('W', false);

			return 0;
		case 'S':
			UpdateInput('S', false);

			return 0;
		case 'A':
			UpdateInput('A', false);

			return 0;
		case 'D':
			UpdateInput('D', false);

			return 0;
		}
		return 0;

	case WM_KEYDOWN:
		switch (LOWORD(wParam))
		{
		case VK_LEFT:
			directionAngle -= 45;
			return 0;
		case VK_RIGHT:
			directionAngle += 45;
			return 0;
		
		//transparent sprite commands
		
		/*
			KEY IDEAS FOR ANIMATION ALGORITHM

			All sprites for animation are loaded into a character class, which contains specific data members for each sprite.
			spriteList vector is used as a "container" for the sprites to be displayed.
			Sprites are loaded into a character class as unqiue pointers, so I use a function, which swaps the pointers from character class and spriteList.
			The first two elements of spriteList vector are sprites that are used for displaying a walking character, the third one is used when no key is pressed.
			When the direction changes, all sprites from spriteList are swapped again so that the vector is ready for another set of sprites.

		*/
		case 'W':
			if (!updatingInput || movementDirection == 'W')
			{
				updatingInput = true;
				UpdateInput('W', true);
			}
			
			return 0;
		case 'S':
			if (!updatingInput || movementDirection == 'S')
			{
				updatingInput = true;
				UpdateInput('S', true);
			}
			
			return 0;
		case 'A':
			if (!updatingInput || movementDirection == 'A')
			{
				updatingInput = true;
				UpdateInput('A', true);
			}
			
			return 0;
		case 'D':
			if (!updatingInput || movementDirection == 'D')
			{
				updatingInput = true;
				UpdateInput('D', true);
			}
			
			return 0;
		case 'P':
			if (Paused)
			{
				Paused = false;
			}
			else
			{
				Paused = true;
			}
			return 0;
		case VK_SPACE:
			if (!speechMode&&!puzzleMode&&shootingMode)
			{

				if (Fireball->GetNumberOfShells() == 0)
				{
					//shootingMode = true;
					POINT temp;
					temp.x = JakeTheJanitor.positionAsPoint.x;
					temp.y = JakeTheJanitor.positionAsPoint.y - 32;

					Fireball->Fire(temp);
					FireSound.Play();
				};
			}
			
			return 0;
		
		case VK_RETURN:
			if (speechMode)//if cutscene is on, continue to the next line
			{
				speechLineNumber++;
				updatingInput = false;
				
			}
			else if (puzzleMode)
			{
				readNumber = true;
				
			}
			else if (puzzleSolved)
			{
				//puzzleSolved = true;
				//puzzleMode = false;
				speechMode = true;

				gameFinal = true;
				JakeTheJanitor.SetPosition(500, 500);
				//speechLineNumber = speechList.size() - 4;
			}
			else 
			{
				if (playerPassword != 0)
				{

					puzzleMode = true;
					playerPassword = 0;
				}
			}
			return 0;
		
		}
		return 0;
	
	case WM_TIMER:
		if (wParam == mainTimer)
		{

			if (walkingMode)
			{
			
				if (animationStatus == 1)
				{
					animationStatus = 0;
				}
				else
				{
					animationStatus = 1;
				}
			
			}
		}
		if (wParam == levelTimer&&!Paused&&!speechMode)
		{
			if (Time != 0)
			{
				Time--;

			}
			else
			{
				puzzleSolved = false;
				puzzleMode = false;
				gameFinal = false;
				speechMode = true;
			}
			
		}
		
		

		return 0;
	case WM_CREATE:
	{
					  if (mainMenuHandle)
					  {
						  EnableMenuItem(mainMenuHandle, ID_GAME_EXIT, MF_ENABLED);
						  EnableMenuItem(mainMenuHandle, ID_GAME_RESTART, MF_ENABLED);
						  EnableMenuItem(mainMenuHandle, ID_FRAMERATE_NORMAL50FPSFRAMERATE, MF_ENABLED);
						  EnableMenuItem(mainMenuHandle, ID_FRAMERATE_MINIMUM25FPSFRAMERATE, MF_ENABLED);
						  EnableMenuItem(mainMenuHandle, ID_FRAMERATE_MAXIMUM100FPS, MF_ENABLED);
						  EnableMenuItem(mainMenuHandle, ID_HELP_ABOUT, MF_ENABLED);

						  CheckMenuRadioItem(mainMenuHandle, ID_FRAMERATE_NORMAL50FPSFRAMERATE, ID_FRAMERATE_MAXIMUM100FPS, ID_FRAMERATE_NORMAL50FPSFRAMERATE, MF_BYCOMMAND);
						  frameRate = 50;
					  }
					  gameObjectPosition.x = windowWidth / 2;
					  gameObjectPosition.y = windowHeight / 2;
					  backgroundMusic.Play();
					  SetTimer(hwnd, mainTimer, 300, 0);
					  SetTimer(hwnd, levelTimer, 1000, 0);
					  bool success = ReadFileContents(speechList);
					  speechLineNumber = 0;
					  if (!success)
					  {
						  MessageBox(windowHandle, L"Error!", L"An error occured when reading from a text file. Application will be closed.",MB_OK);
						  DestroyWindow(hwnd);
					  }

	}

		return 0;



	case WM_DESTROY: // Destroy the window must always be included
			KillTimer(hwnd, mainTimer);
			backgroundMusic.Stop();
			PostQuitMessage(0);
			
		return 0;

	}
	// send the messages we don't handle to default window procedure
	return DefWindowProc(hwnd, msg, wParam, lParam);
}




int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR cmdLine, int showCmd)
{
	// Save handle to application instance global variable.
	applicationInstance = hInstance;

	WNDCLASSEX wc = {};

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hIconSm = 0;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = applicationInstance;

	wc.hIcon = LoadIcon(applicationInstance, MAKEINTRESOURCE(IDI_ICON1));
 	wc.hCursor = LoadCursor(0, IDC_ARROW);

	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
 	wc.lpszMenuName = nullptr;
	wc.lpszClassName = windowClassName.c_str();

	RegisterClassEx(&wc);

	//*****************************************************************************************
	// load the menu if you have one:
	mainMenuHandle = LoadMenu(applicationInstance, MAKEINTRESOURCE(IDR_MENU1));
	//*****************************************************************************************

	// Create the window
	windowHandle = CreateWindowEx(WS_EX_ACCEPTFILES,
		windowClassName.c_str(),
		windowTitle.c_str(),
		WS_OVERLAPPED | WS_SYSMENU | WS_VISIBLE,
		windowXPosition,
		windowYPosition,
		windowWidth,
		windowHeight,
		0,
		mainMenuHandle,
		applicationInstance, nullptr);

	if (!windowHandle)
	{
		MessageBox(0, L"CreateWindow Failed", L"Application Error Message", 0);
		return -1;
	}

	ShowWindow(windowHandle, showCmd);

	UpdateWindow(windowHandle);

	CreateGameObjects(thePen, theBrush, startPoint, endPoint,
		windowHeight, windowWidth, shapeList, shapePtr,
		turretRadius, gunLength, gunWidth,
		tankWidth, tankLength, gameObjectPosition,
		GREEN, BLACK, GRAY, BLUE, RED, spriteList, backgroundList, JakeTheJanitor, Fireball, windowHandle, shellRadius);

	//HDC hdc = GetDC(windowHandle);//set up a connection to a video card

	CBackBuffer theBackBuffer(windowHandle, windowWidth, windowHeight, GREEN);

	HDC hdc = theBackBuffer.GetHDC();

	CFrameRateThrottle frameRateThrottle(50, windowHandle);

	// Enter the message loop - quit when a WM_QUIT message is received
	MSG msg = {};

	while (true) // infinite loop, we break when we get a WM_QUIT message
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))//addressing specifically to message "list"
		{
			if (msg.message == WM_QUIT)
			{
				break;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else    // enter the game loop
		{
			if (!Paused&&!Restart&&!Finished)
			{
				if (speechMode && (speechLineNumber < speechList.size())) //if text should be displayed and it's not the end of the file
				{
					//NO UPDATING AND COLLISION DETECTION
					DrawGameObjects(hdc, shapeList, backgroundList, spriteList, walkingMode, gameStarted, animationStatus, 
						JakeTheJanitor, Fireball, wParam_previous, shootingMode, Score, Time, puzzleMode, puzzleSolved,gameFinal, speechMode);
					DisplayText(hdc,speechBoxPositionX,speechBoxPositionY,speechList,wParam_previous,JakeTheJanitor,speechLineNumber, speechSystem, 
						speechMode, puzzleSolved, Time, Finished, gameFinal, Score, puzzleMode);

				}
				else
				{
					UpdateGameObjects(moveX, moveY, shapeList, walkingMode, spriteList, JakeTheJanitor, Score, wParam_previous, windowHeight, windowWidth,
										blockedAreaSize_top, blockedAreaSize_sides, speechMode, cutSceneOver, puzzleMode, directionAngle, readNumber, playerPassword, 
										password, puzzleSolved, shootingMode, backgroundMusic, changesAssigned, Time, gameFinal);
					GameObjectCollision(Fireball, spriteList, wParam_previous, windowHeight, windowWidth, blockedAreaSize_top, blockedAreaSize_sides, JakeTheJanitor, Score, shootingMode, changesAssigned, cutSceneOver);
					DrawGameObjects(hdc, shapeList, backgroundList, spriteList, walkingMode, gameStarted, animationStatus, JakeTheJanitor,
									Fireball, wParam_previous, shootingMode, Score, Time, puzzleMode, puzzleSolved, gameFinal, speechMode);

				}
			}
			else
			{
				if (Paused)
				{
				backgroundList[1]->Draw(hdc);//draw "PAUSED"
				}
				if (Finished)
				{
					backgroundList[5]->Draw(hdc);//draw "THE END"
				}
				if (Restart)
				{
					//demonstrating the use of stl algorithms by creating the vector of integer values and searching for elements >= 0 (if true, output message)
					//it is a huge overkill here, though.
					vector <int>myInts{ 1,1, -1 };//
					//an stl algorithm which uses nameless function LAMBDA which returns true if at least one element of a vector is equal to or bigger than 0
					if (any_of(myInts.begin(), myInts.end(), [](int i){return i >= 0; }))
					{
						MessageBox(windowHandle, L"Game Restarted", L"Game Restarted", MB_OK);
					}
					//resetting game variables
					gameStarted = false;
					gameFinal = false;
					walkingMode = false;
					shootingMode = false;
					Paused = false;
					Finished = false;
					Restart = false;
					speechMode = true;
					speechSystem = false;
					cutSceneOver = false;
					puzzleMode = false;
					readNumber = false;
					puzzleSolved = false;
					updatingInput = false;
					movementDirection = ' ';
					//celaning up the vectors and pointers
					Fireball = nullptr;
					spriteList.pop_back();
					for (auto &c : spriteList)
					{
						c = nullptr;
					}
					backgroundList.erase(backgroundList.begin(), backgroundList.end());
					shapeList.erase(shapeList.begin(), shapeList.end());
					//some more variables
					speechBoxPositionX = 200;
					speechBoxPositionY = 50;
					speechLineNumber = 0;
					animationStatus = 0;
					playerPassword = 0;
					Score = 0;
					Time = 120;
					backgroundMusic.ChangeSound("01 - Opening.mp3", true);
					backgroundMusic.Play();
					//creating the objects once again
					CreateGameObjects(thePen, theBrush, startPoint, endPoint,
						windowHeight, windowWidth, shapeList, shapePtr,
						turretRadius, gunLength, gunWidth,
						tankWidth, tankLength, gameObjectPosition,
						GREEN, BLACK, GRAY, BLUE, RED, spriteList, backgroundList, JakeTheJanitor, Fireball, windowHandle, shellRadius);
				}
				
				
			}
			
				//back
				//Back Buffer removes flicker and Frame Rate Throttle sets the framerate
				theBackBuffer.Present();
				frameRateThrottle.Throttle();
				frameRateThrottle.SetFrameRate(frameRate);
				//theBackBuffer.ClearSurface();

			
		}
	}
	//clean up
	//ReleaseDC(windowHandle, hdc);

	// Return exit code to Windows
	return (int)msg.wParam;
}






