#include "functions.h"


/*****************************************
Date:	 April 13, 2014
Arguments:  const string line, wstring &wline
Return: void
Description: This function converts string to wstring. It is necessary for outputting text from string vector during gameplay.

*****************************************/
void ToWstring(const string line, wstring &wline)
{
	
	for (int i = 0; i < line.length(); ++i)
		wline += wchar_t(line[i]);

	//const wchar_t* your_result = wline.c_str();
}

/*****************************************
Date:	 April 13, 2014
Arguments:  HDC hdc,int &speechBoxPositionX, int &speechBoxPositionY, const vector <string> &speechList, 
	WPARAM wParam_previous, mainCharacter &JakeTheJanitor, int &speechLineNumber, bool &speechSystem, bool &speechMode, 
	bool &puzzleSolved, const unsigned short Time, bool &Finished, bool &gameFinal
Return: void
Description: This function is used to display text during cutscenes.

"*"  - beginning of the system message
"*" + "/" - ending of the system message
":" - check the time for a certain ending
"/" - ending of a cutscene

*****************************************/
void DisplayText(HDC hdc,int &speechBoxPositionX, int &speechBoxPositionY, const vector <string> &speechList, 
	WPARAM wParam_previous, mainCharacter &JakeTheJanitor, int &speechLineNumber, bool &speechSystem, bool &speechMode, 
	bool &puzzleSolved, const unsigned short Time, bool &Finished, bool &gameFinal,  unsigned short &score, bool &puzzleMode)
{

	wstring line = L"";
	

	if (speechList[speechLineNumber] == "*")
	{
			speechBoxPositionX = 200;
			speechBoxPositionY = 50;
			speechLineNumber++;
			//speechSystem = true;
			//ToWstring(speechList[speechLineNumber], line);
			//TextOut(hdc, speechBoxPositionX, speechBoxPositionY, line.c_str(), line.size());
			//speechMode = true;
		}
	if (speechList[speechLineNumber] == "*/")
		{
			speechBoxPositionX = JakeTheJanitor.GetLeftPosition(wParam_previous) -40;
			speechBoxPositionY = JakeTheJanitor.GetTopPosition(wParam_previous) - 20;
		    speechLineNumber++;


		}
		/*ToWstring(speechList[speechLineNumber], line);
		TextOut(hdc, speechBoxPositionX, speechBoxPositionY, line.c_str(), line.size());*/
		//speechMode = true;
	
	if (speechList[speechLineNumber] == ":")
	{
		if (Time != 0 && !puzzleSolved)
		{
			speechLineNumber++;
		}
		else
		{
			if (puzzleSolved)
			{
				speechLineNumber += 2;
			}
			else
			{
				speechLineNumber = speechList.size() - 6;
				

			}
		}
	}
	if (speechList[speechLineNumber] == "&")
	{

		speechMode = false;
		Finished = true;

	}
	if (speechList[speechLineNumber] == "/")
	{
		speechLineNumber++;
		//speechOnHold = false;

		speechMode = false;
		if (score==12)
		{
			puzzleMode = true;
			score++;
		}
	}
	else
	{
		if (!puzzleSolved&&Time==0&&!gameFinal)//
		{
			speechLineNumber = speechList.size() - 6;
			
			gameFinal = true;
		}
	
		if (speechBoxPositionX != 200 && speechBoxPositionY != 50)
		{
			speechBoxPositionX = JakeTheJanitor.GetLeftPosition(wParam_previous) - 40;
			speechBoxPositionY = JakeTheJanitor.GetTopPosition(wParam_previous) - 20;
		}
		ToWstring(speechList[speechLineNumber], line);
		TextOut(hdc, speechBoxPositionX, speechBoxPositionY, line.c_str(), line.size());
		speechMode = true;
	}
}

/*****************************************
Date:	 April 13, 2014
Arguments:  const short angle
Return: int
Description: Returns a number selected by a player based on the current angle

*****************************************/
int GetLockNumber(const short angle)
{
	if (fmod((angle - 360), 360) == 0)
	{
		return 10000;
	}
	if (fmod((angle - 45),360)==0)
	{
		return 1;
	}
	if (fmod((angle - 90), 360)==0)
	{
		return 2;
	}
	if (fmod((angle - 135), 360) == 0)
	{
		return 3;
	}
	if (fmod((angle - 180), 360) == 0)
	{
		return 4;
	}
	if (fmod((angle - 225), 360) == 0)
	{												
		return 5;									
	}												
	if (fmod((angle - 270), 360) == 0)
	{
		return 6;
	}
	if (fmod((angle - 315), 360) == 0)
	{
		return 7;
	}
}

//function created by Tony Davidson
/*****************************************
Date:	 April 12, 2014
Arguments:
Return: bool
Description: Reads file contents from character_speech.txt

This function is used to load dialogues.

*****************************************/
bool ReadFileContents(vector <string> & fileNames)
{
	ifstream openfile("character_speech.txt");		// Open the file identified by the text
	if (openfile.is_open())					// make sure the file is open
	{
		string line = "";
		

		for (unsigned short c = 0; !openfile.eof(); c++) // stop the loop when the End Of File is reached
		{
			getline(openfile, line);		// Read the next line from the file and store it in a string
		
			fileNames.push_back(line);
			
		}
		openfile.close();					// Close the file
	}
	else
	{
		return false;						// unable to open file so return false
	}
	return true;

}

//an overloaded version of the previous function
bool ReadFileContents(vector <string> & fileNames, const string & playlistName)
{
	ifstream openfile(playlistName);		// Open the file identified by the text
	if (openfile.is_open())					// make sure the file is open
	{
		string line = "";
		for (unsigned short c = 0; !openfile.eof(); c++) // stop the loop when the End Of File is reached
		{
			getline(openfile, line);		// Read the next line from the file and store it in a string
			//if (line != "")					// ignore empty lines
			//{
			fileNames.push_back(line);
			//}
		}
		openfile.close();					// Close the file
	}
	else
	{
		return false;						// unable to open file so return false
	}
	return true;

}

void UpdateGameObjects(short &moveX, short &moveY, vector <unique_ptr <CShape>> &shapeList,
	const bool walkingMode, vector <unique_ptr <CTransSprite>> &spriteList, 
	mainCharacter &JakeTheJanitor, unsigned short &score, const WPARAM &wParam, 
	const int windowHeight, const int windowWidth,const unsigned short blockedAreaSize_top, 
	const unsigned short blockedAreaSize_sides, bool &speechMode, bool& cutSceneOver, bool &puzzleMode, 
	short &directionAngle, bool &readNumber, unsigned short &playerPassword, 
	const unsigned short password, bool &puzzleSolved, bool &shootingMode, CSound &backgroundMusic, 
	bool &changesAssigned, const unsigned short Time, const bool gameFinal)
{
	
	static int oldDirectionAngle;

	//if waiting for Enter to be pressed during puzzle mode
	if (readNumber)
	{
		//add number to a playerPassword
		if (playerPassword == 0)
		{
			playerPassword = GetLockNumber(directionAngle);
			readNumber = false;
		}
		else if (playerPassword <=9 && playerPassword > 0)
		{
			playerPassword = GetLockNumber(directionAngle) * 10 + playerPassword;
			readNumber = false;
		}
		else if (playerPassword <= 99 && playerPassword >= 11)
		{
			playerPassword = GetLockNumber(directionAngle) * 100 + playerPassword;
			readNumber = false;
		}
		else if (playerPassword <= 999 && playerPassword >= 111)
		{
			playerPassword = GetLockNumber(directionAngle) * 1000 + playerPassword;
			readNumber = false;
		}
		//if 0 was pressed, exit the puzzle mode with negative result
		else if (playerPassword > 10000)
		{
			puzzleMode = false;
			readNumber = false;
		}
		//if passwords match
		if (playerPassword == password)
		{
			puzzleMode = false;//exit puzzle mode
			if (Time != 0)
			{
			puzzleSolved = true;//with a positive result
			backgroundMusic.Stop();
			backgroundMusic.ChangeSound("Circus Monster - Music box.mp3", true);
			backgroundMusic.Play();

			}
			else
			{
				puzzleSolved = false;
				playerPassword = 0;
				
			}
			readNumber = false;
		}
		//if player's passwords is incorrect, exit the puzzle mode with negative result
		else if (playerPassword >= 1111 && playerPassword != password)
		{
			puzzleMode = false;
			readNumber = false;
			
		}
	}
	//if the score is equal to 3,7 or 12 and nothing has been done yet
	if ((score == 3||score==7||score==12)&&(!cutSceneOver&&!changesAssigned))
	{
		//start displaying cutscene with text
		speechMode = true;
		cutSceneOver = true;
		changesAssigned = false;

		//if score = 7, change music ('cause monsters appear :) )
		if (score == 7)
		{
			backgroundMusic.Stop();
			backgroundMusic.ChangeSound("MonsterFight.mp3", true);
		}
		//if score =12, load puzzle mode and start a cutscene
		if (score == 12)
		{
			//score++;
			//puzzleMode = true;
			speechMode = true;
			changesAssigned = true;
		}
		
		
	}
	//if the score is equal to any other number or the cutscene is over or the changes were assigned
	else
	{
		switch (score)
		{
		case 3:
			if (cutSceneOver&&!changesAssigned)
			{
			
				//cutSceneOver = false;
			
			changesAssigned = true;
			shootingMode = true;

			}
			break;
		case 7:
		{
			if (cutSceneOver&&!changesAssigned)
			{
				
				//changing the sprite of the garbage
				int oldX;
				int oldY;
				oldX = spriteList[3]->GetLeftPosition();
				oldY = spriteList[3]->GetTopPosition();
				
				auto monster_ptr = make_unique <CTransSprite>(L"monster64.png", oldX, oldY);
				spriteList[3] = move(monster_ptr);
				
				backgroundMusic.Play();
				changesAssigned = true;
			}
		}
				  
			break;
		/*case 12:
			if (cutSceneOver&&!changesAssigned)
			{

			score++;
			puzzleMode = true;
			speechMode = true;
			changesAssigned = true;
			}
			break;*/
		}

		//if puzzle is not displayed
		if (!puzzleMode&&!gameFinal)//&&!puzzleSolved
		{
			if (spriteList[3] != nullptr)
			{
				//if charatcer steps over the garbage
				if (spriteList[3]->Hit(JakeTheJanitor.positionAsPoint))
				{
					
					score++;
					changesAssigned = false;
					cutSceneOver = false;
					do
					{
						//creating random coordinates 
						RandomNumberGenerator randomX(blockedAreaSize_sides + 32, windowWidth - blockedAreaSize_sides - 32);
						RandomNumberGenerator randomY(blockedAreaSize_top + 32, windowHeight - blockedAreaSize_top - 32);
						int topPosition;
						randomY.Generate(topPosition);
						randomY.GetCurrentRandomNumber(topPosition);
						int leftPosition;
						randomX.Generate(leftPosition);
						randomX.GetCurrentRandomNumber(leftPosition);
						spriteList[3]->SetLeftPosition(leftPosition);
						spriteList[3]->SetTopPosition(topPosition);



					} while (spriteList[3]->GetLeftPosition() == JakeTheJanitor.GetLeftPosition(wParam) && spriteList[3]->GetTopPosition() == JakeTheJanitor.GetTopPosition(wParam));

				}
			}
			return;//nothing to update
		}
		//if a shape wasn't moved and the angle stayed the same
		if (moveX == 0 && moveY == 0&&oldDirectionAngle==directionAngle)
		{
			return;
		}
		else
		{
			
			for (const auto &shape : shapeList)
			{

				shape->MoveX(moveX);
				shape->MoveY(moveY);
				shape->Rotate(directionAngle);
			}
			//reset
			moveX = 0;
			moveY = 0;
			oldDirectionAngle = directionAngle;
		}
	}
}
void DrawGameObjects(HDC hdc, vector <unique_ptr <CShape>> &shapeList, vector <unique_ptr <CBackgroundBitmap>> &backgroundList,
	vector <unique_ptr <CTransSprite>> &spriteList, bool &walkingMode, bool &gameStarted,
	const unsigned int animationStatus, mainCharacter &JakeTheJanitor, unique_ptr <CShoot> &Fireball,
	const WPARAM wParam, bool &shootingMode, const unsigned short score, unsigned short time, bool puzzleMode, bool &puzzleSolved, bool &gameFinal, bool &speechMode)//use pointers here
{
	if (!puzzleMode)//if puzzle is not displayed
	{
		if (puzzleSolved&!speechMode&&time!=0)//if puzzle is solved correctly
		{
			//draw UNLOCKED and nothing else
			backgroundList[3]->Draw(hdc);
			TextOut(hdc, 500, 500, L" Press Enter to continue... ",28);
			//gameFinal = true;
			return;			
			
		}
		else //if puzzle is NOT solved correctly
		{
			if (!gameFinal&&score==13)//if it's not the closing cutscene yet and the score was updated to the highest one 
			{
				//draw "FAILED" and be ready to display a puzzle if there is time left + draw nothing else
				if (time != 0)
				{

					puzzleMode = true;
					backgroundList[4]->Draw(hdc);
					TextOut(hdc, 500, 500, L" Press Enter to continue... ", 28);
					return;
				}
				//draw "FAILED" and go to the closing cutscene + draw nothing else
				else if (!speechMode)
				{
					backgroundList[4]->Draw(hdc);
					TextOut(hdc, 500, 500, L" Press Enter to continue... ", 28);
					
					gameFinal = true;
					return;
				}
			}
			//if it is time for closing cutscene, draw a normal background
			else if (gameFinal)
			{
				backgroundList[0]->Draw(hdc);

			}

		}
		
	
		//draw a normal background
		if (backgroundList[0] != nullptr)
		{
			backgroundList[0]->Draw(hdc);
		}
		
		//draw garbage sprite
		if (spriteList[3] != nullptr)
		{
			spriteList[3]->Draw(hdc);
		}

		//draw animated character
		if (walkingMode&gameStarted)
		{
			if (spriteList[animationStatus] != nullptr)
			{
				spriteList[animationStatus]->Draw(hdc);

			}

		}
		else
		{
			if (spriteList[2] != nullptr)
			{
				spriteList[2]->Draw(hdc);


			}

		}

		//draw a fireball
		if (Fireball != nullptr)
		{

			Fireball->draw(hdc, wParam, shootingMode);
		}
		wstring ScoreAsText = L"Score: " + ToString((int)score);
		
		TextOut(hdc, 200, 30, ScoreAsText.c_str(), ScoreAsText.size());
		
	}
	else//if puzzle is displayed
	{
		if (!speechMode)//if text is not displayed
		{
			//draw puzzle image
			if (backgroundList[2] != nullptr)
			{
				backgroundList[2]->Draw(hdc);
			}
			for (const auto & shape : shapeList)
			{
				shape->Draw(hdc);
			}
		}
		
	}
	//display time
	wstring TimeAsText = L"Time: " + ToString((int)time);
	TextOut(hdc, 750, 30, TimeAsText.c_str(), TimeAsText.size());
}
	


void CreateGameObjects(LOGPEN thePen, LOGBRUSH theBrush, CPrecisionPoint &startPoint, CPrecisionPoint &endPoint,
	const int windowHeight, const int windowWidth, vector <unique_ptr <CShape>> &shapeList, unique_ptr <CShape> &shapePtr,
	const unsigned short turretRadius, const unsigned short gunLength, const unsigned short gunWidth,
	const unsigned short tankWidth, const unsigned short tankLength, const CPrecisionPoint gameObjectPosition,
	const COLORREF GREEN, const COLORREF BLACK, const COLORREF GRAY, const COLORREF BLUE, const COLORREF RED,
	vector <unique_ptr <CTransSprite>> &spriteList, vector <unique_ptr <CBackgroundBitmap>> &backgroundList, mainCharacter &JakeTheJanitor, 
	unique_ptr <CShoot> &Fireball, const HWND windowHandle, const unsigned short shellRadius)
{
	//loading all sprites to a character class
	JakeTheJanitor.SetCharacterLeft_normal(L"MainChar_left_n.png", 200, 500);
	JakeTheJanitor.SetCharacterLeft_walking(L"MainChar_left_w.png", 200, 500);
	JakeTheJanitor.SetCharacterRight_normal(L"MainChar_right_n.png", 200, 500);
	JakeTheJanitor.SetCharacterRight_walking(L"MainChar_right_w.png", 200, 500);
	JakeTheJanitor.SetCharacterUp_normal(L"MainChar_up_n.png", 200, 500);
	JakeTheJanitor.SetCharacterUp_walking(L"MainChar_up_w.png", 200, 500);
	JakeTheJanitor.SetCharacterDown_normal(L"MainChar_down_n.png", 200, 500);
	JakeTheJanitor.SetCharacterDown_walking(L"MainChar_down_w.png", 200, 500);
	//placing one sprite into a spriteList vector so that there is something to draw 
	JakeTheJanitor.SwapSpritesLeft(spriteList, 2);
	//setting initial position
	JakeTheJanitor.SetPosition(200, 500);

	//creating a unique pointer to a sprite (auto is used to set the type automatically)
	auto sp_ptr_garbage = make_unique <CTransSprite>(L"garbage32x32.png", 500, 400);
	//moving the ownership of the pointer
	spriteList.push_back(move(sp_ptr_garbage));

	auto bg_ptr = make_unique <CBackgroundBitmap>(L"level_bg.bmp", 0, 0);
	auto pause_ptr = make_unique <CBackgroundBitmap>(L"bg_paused.bmp", 0, 0);
	auto lock_ptr = make_unique <CBackgroundBitmap>(L"lock.bmp", 0, 0);
	auto unlocked_ptr = make_unique <CBackgroundBitmap>(L"unlocked.bmp", 0, 0);
	auto failed_ptr = make_unique <CBackgroundBitmap>(L"failed.bmp", 0, 0);
	auto final_ptr = make_unique <CBackgroundBitmap>(L"finished.bmp", 0, 0);
	backgroundList.push_back(move(bg_ptr));
	backgroundList.push_back(move(pause_ptr));
	backgroundList.push_back(move(lock_ptr));
	backgroundList.push_back(move(unlocked_ptr));
	backgroundList.push_back(move(failed_ptr));
	backgroundList.push_back(move(final_ptr));


	//creating a shell
	thePen.lopnColor = BLACK;
	theBrush.lbColor = RED;
	Fireball = make_unique <CRoundShell>(windowHandle, shellRadius, thePen, theBrush,5);
	

	theBrush.lbStyle = BS_SOLID;
	thePen.lopnStyle = PS_SOLID;

	thePen.lopnWidth.x = 1;
	thePen.lopnWidth.y = 1;

	////draw a big rectangle
	//startPoint.x = 0;
	//startPoint.y = 0;

	//endPoint.x = windowWidth;
	//endPoint.y = windowHeight;

	//thePen.lopnColor = GREEN;
	//theBrush.lbColor = GREEN;

	//shapePtr = std::make_unique<CRectangle>(thePen, theBrush, startPoint, endPoint);

	//shapeList.push_back(std::move(shapePtr));


	//draw ellipse

	thePen.lopnColor = GRAY;
	theBrush.lbColor = GRAY;

	startPoint.x = gameObjectPosition.x - turretRadius;
	startPoint.y = gameObjectPosition.y - turretRadius;

	endPoint.x = gameObjectPosition.x + turretRadius;
	endPoint.y = gameObjectPosition.y + turretRadius;

	shapePtr = std::make_unique<CEllipse>(thePen, theBrush, startPoint, endPoint);

	shapeList.push_back(std::move(shapePtr));

	//draw rectangle
	thePen.lopnColor = BLACK;
	theBrush.lbColor = GRAY;

	startPoint.x = gameObjectPosition.x - tankWidth;
	startPoint.y = gameObjectPosition.y - tankLength;

	endPoint.x = gameObjectPosition.x + tankWidth;
	endPoint.y = gameObjectPosition.y + tankLength;

	shapePtr = std::make_unique<CRectangle>(thePen, theBrush, startPoint, endPoint);

	shapeList.push_back(std::move(shapePtr));//shapePrt is set to nullpt, ownership is reassigned to shapeList
	//draw the thing that points to numbers on a lock (no idea how it is called)
	thePen.lopnColor = BLACK;
	theBrush.lbColor = BLACK;

	thePen.lopnWidth.x = gunWidth;
	thePen.lopnWidth.y = gunWidth;

	startPoint.x = gameObjectPosition.x;
	startPoint.y = gameObjectPosition.y;

	endPoint.x = gameObjectPosition.x;
	endPoint.y = gameObjectPosition.y - gunLength;

	shapePtr = std::make_unique<CLine>(thePen, theBrush, startPoint, endPoint);

	shapeList.push_back(std::move(shapePtr));
}

void GameObjectCollision(unique_ptr <CShoot> &Fireball, vector <unique_ptr <CTransSprite>> &spriteList, const WPARAM wParam, 
	const int windowHeight, const int windowWidth, const unsigned short blockedAreaSize_top, const unsigned short blockedAreaSize_sides, 
	mainCharacter &JakeTheJanitor, unsigned short &score, bool &shootingMode,  bool &changesAssigned, bool &cutSceneOver)
{
	if (0 == Fireball->GetNumberOfShells())
	{
		return;//nothing to collide with
	}
	if (Fireball->HitTest(spriteList[3]->GetCurrentRect())&&spriteList[3]!=nullptr)
	{
		score++;
		changesAssigned = false;
		cutSceneOver = false;
		do
		{
			//generate a random position
			RandomNumberGenerator randomX(blockedAreaSize_sides + 32, windowWidth - blockedAreaSize_sides - 32);
			RandomNumberGenerator randomY(blockedAreaSize_top + 32, windowHeight - blockedAreaSize_top - 32);
			int topPosition;
			randomY.Generate(topPosition);
			randomY.GetCurrentRandomNumber(topPosition);
			int leftPosition;
			randomX.Generate(leftPosition);
			randomX.GetCurrentRandomNumber(leftPosition);
			spriteList[3]->SetLeftPosition(leftPosition);
			spriteList[3]->SetTopPosition(topPosition);

		} while (spriteList[3]->GetLeftPosition() == JakeTheJanitor.GetLeftPosition(wParam) && spriteList[3]->GetTopPosition() == JakeTheJanitor.GetTopPosition(wParam));

	}
}