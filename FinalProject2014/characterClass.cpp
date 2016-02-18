#include "characterClass.h"

//a default constructor
mainCharacter::mainCharacter()
{

}

/*****************************************
Date:	 April 10, 2014
Arguments:wstring name, int x, int y
Return: void
Description: Loads character sprite

*****************************************/
void mainCharacter::SetCharacterLeft_walking(wstring name, int x, int y)
{
	m_CharacterLeft_walking = make_unique <CTransSprite>(name, x, y);
}
/*****************************************
Date:	 April 10, 2014
Arguments:wstring name, int x, int y
Return: void
Description: Loads character sprite

*****************************************/
void mainCharacter::SetCharacterLeft_normal(wstring name, int x, int y)
{
	m_CharacterLeft_normal = make_unique <CTransSprite>(name, x, y);
}
/*****************************************
Date:	 April 10, 2014
Arguments:wstring name, int x, int y
Return: void
Description: Loads character sprite

*****************************************/
void mainCharacter::SetCharacterRight_walking(wstring name, int x, int y)
{
	m_CharacterRight_walking = make_unique <CTransSprite>(name, x, y);
}
/*****************************************
Date:	 April 10, 2014
Arguments:wstring name, int x, int y
Return: void
Description: Loads character sprite

*****************************************/
void mainCharacter::SetCharacterRight_normal(wstring name, int x, int y)
{
	m_CharacterRight_normal = make_unique <CTransSprite>(name, x, y);
}
/*****************************************
Date:	 April 10, 2014
Arguments:wstring name, int x, int y
Return: void
Description: Loads character sprite

*****************************************/
void mainCharacter::SetCharacterUp_walking(wstring name, int x, int y)
{
	m_CharacterUp_walking = make_unique <CTransSprite>(name, x, y);
}
/*****************************************
Date:	 April 10, 2014
Arguments:wstring name, int x, int y
Return: void
Description: Loads character sprite

*****************************************/
void mainCharacter::SetCharacterUp_normal(wstring name, int x, int y)
{
	m_CharacterUp_normal = make_unique <CTransSprite>(name, x, y);
}
/*****************************************
Date:	 April 10, 2014
Arguments:wstring name, int x, int y
Return: void
Description: Loads character sprite

*****************************************/
void mainCharacter::SetCharacterDown_walking(wstring name, int x, int y)
{
	m_CharacterDown_walking = make_unique <CTransSprite>(name, x, y);
}
/*****************************************
Date:	 April 10, 2014
Arguments:wstring name, int x, int y
Return: void
Description: Loads character sprite

*****************************************/
void mainCharacter::SetCharacterDown_normal(wstring name, int x, int y)
{
	m_CharacterDown_normal = make_unique <CTransSprite>(name, x, y);
}

//SWAP LEFT
/*****************************************
Date:	 April 10, 2014
Arguments:vector <unique_ptr <CTransSprite>> &spriteList
Return: void
Description:Places sprites to aspriteList vector for displaying

*****************************************/
void mainCharacter::SwapSpritesLeft(vector <unique_ptr <CTransSprite>> &spriteList)
{
	//spriteList[0].swap(m_CharacterLeft_normal);
	spriteList[0].swap(m_CharacterLeft_normal);
	spriteList[1].swap(m_CharacterLeft_walking);
	
}
/*****************************************
Date:	 April 10, 2014
Arguments:
Return: void
Description:Places sprites to aspriteList vector for displaying (overloaded version, which puts normal sprite to a preferred position inside the vector) 

*****************************************/
void mainCharacter::SwapSpritesLeft(vector <unique_ptr <CTransSprite>> &spriteList, const unsigned short index)
{
	spriteList[index].swap(m_CharacterLeft_normal);
}

//SWAP RIGHT
/*****************************************
Date:	 April 10, 2014
Arguments:vector <unique_ptr <CTransSprite>> &spriteList
Return: void
Description:Places sprites to aspriteList vector for displaying

*****************************************/
void mainCharacter::SwapSpritesRight(vector <unique_ptr <CTransSprite>> &spriteList)
{
	spriteList[0].swap(m_CharacterRight_normal);
	spriteList[1].swap(m_CharacterRight_walking);
}
/*****************************************
Date:	 April 10, 2014
Arguments:
Return: void
Description:Places sprites to aspriteList vector for displaying (overloaded version, which puts normal sprite to a preferred position inside the vector) 

*****************************************/
void mainCharacter::SwapSpritesRight(vector <unique_ptr <CTransSprite>> &spriteList, const unsigned short index)
{
	spriteList[index].swap(m_CharacterRight_normal);
}

//SWAP UP
/*****************************************
Date:	 April 10, 2014
Arguments:vector <unique_ptr <CTransSprite>> &spriteList
Return: void
Description:Places sprites to aspriteList vector for displaying

*****************************************/
void mainCharacter::SwapSpritesUp(vector <unique_ptr <CTransSprite>> &spriteList)
{
	spriteList[0].swap(m_CharacterUp_normal);
	spriteList[1].swap(m_CharacterUp_walking);
}
/*****************************************
Date:	 April 10, 2014
Arguments:
Return: void
Description: Places sprites to aspriteList vector for displaying (overloaded version, which puts normal sprite to a preferred position inside the vector) 

*****************************************/
void mainCharacter::SwapSpritesUp(vector <unique_ptr <CTransSprite>> &spriteList, const unsigned short index)
{
	spriteList[index].swap(m_CharacterUp_normal);
}

//SWAP DOWN
/*****************************************
Date:	 April 10, 2014
Arguments:vector <unique_ptr <CTransSprite>> &spriteList
Return: void
Description:Places sprites to aspriteList vector for displaying

*****************************************/
void mainCharacter::SwapSpritesDown(vector <unique_ptr <CTransSprite>> &spriteList)
{
	spriteList[0].swap(m_CharacterDown_normal);
	spriteList[1].swap(m_CharacterDown_walking);
}
/*****************************************
Date:	 April 10, 2014
Arguments:vector <unique_ptr <CTransSprite>> &spriteList, const unsigned short index
Return: void
Description: Places sprites to aspriteList vector for displaying (overloaded version, which puts normal sprite to a preferred position inside the vector) 

*****************************************/
void mainCharacter::SwapSpritesDown(vector <unique_ptr <CTransSprite>> &spriteList, const unsigned short index)
{
	spriteList[index].swap(m_CharacterDown_normal);
}

/*****************************************
Date:	 April 10, 2014
Arguments:const int x,const int y
Return: void
Description: Sets all avaliable character sprites to a given position 

*****************************************/
void mainCharacter::SetPosition(const int x,const int y)
{
	if (m_CharacterLeft_normal != nullptr&m_CharacterLeft_walking != nullptr)
	{
		m_CharacterLeft_walking->SetLeftPosition(x);
		m_CharacterLeft_walking->SetTopPosition(y);

		m_CharacterLeft_normal->SetLeftPosition(x);
		m_CharacterLeft_normal->SetTopPosition(y);
	}

	if (m_CharacterRight_normal != nullptr&m_CharacterRight_walking != nullptr)
	{
		m_CharacterRight_walking->SetLeftPosition(x);
		m_CharacterRight_walking->SetTopPosition(y);

		m_CharacterRight_normal->SetLeftPosition(x);
		m_CharacterRight_normal->SetTopPosition(y);

	}

	if (m_CharacterUp_normal != nullptr & m_CharacterUp_walking != nullptr)
	{

		m_CharacterUp_normal->SetLeftPosition(x);
		m_CharacterUp_normal->SetTopPosition(y);

		m_CharacterUp_walking->SetLeftPosition(x);
		m_CharacterUp_walking->SetTopPosition(y);
	}

	if (m_CharacterDown_normal != nullptr & m_CharacterDown_walking!=nullptr)
	{
		m_CharacterDown_normal->SetLeftPosition(x);
		m_CharacterDown_normal->SetTopPosition(y);

		m_CharacterDown_walking->SetLeftPosition(x);
		m_CharacterDown_walking->SetTopPosition(y);

	}
}

/*****************************************
Date:	 April 10, 2014
Arguments:WPARAM wParam
Return: int
Description: Gets the Y coordinate of the character sprite basing on current direction

*****************************************/
int mainCharacter::GetTopPosition(WPARAM wParam)
{
	switch (wParam)
	{
	case 'W':
		return m_CharacterUp_walking->GetTopPosition();
	case 'A':
		return m_CharacterLeft_walking->GetTopPosition();
	case 'S':
		return m_CharacterDown_walking->GetTopPosition();
	case 'D':
		return m_CharacterRight_walking->GetTopPosition();

	}

}
/*****************************************
Date:	 April 10, 2014
Arguments:WPARAM wParam
Return: int
Description: Gets the X coordinate of the character sprite basing on current direction

*****************************************/
int mainCharacter::GetLeftPosition(WPARAM wParam)
{
	switch (wParam)
	{
	case 'W':
		return m_CharacterUp_walking->GetLeftPosition();
	case 'A':
		return m_CharacterLeft_walking->GetLeftPosition();
	case 'S':
		return m_CharacterDown_walking->GetLeftPosition();
	case 'D':
		return m_CharacterRight_walking->GetLeftPosition();

	}
}

/*****************************************
Date:	 April 10, 2014
Arguments:vector <unique_ptr <CTransSprite>> &spriteList, WPARAM wParam, const int windowWidth, const int windowHeight,
	const unsigned short blockedAreaSize_top, const unsigned short blockedAreaSize_sides
Return: bool
Description: Checks if the character has hit the blocked area of the level

*****************************************/
bool mainCharacter::HitBackground(vector <unique_ptr <CTransSprite>> &spriteList, WPARAM wParam, const int windowWidth, const int windowHeight,
	const unsigned short blockedAreaSize_top, const unsigned short blockedAreaSize_sides)
{
	if (spriteList[0] == nullptr || spriteList[1]==nullptr)
	{
		if (mainCharacter::GetLeftPosition(wParam) >= blockedAreaSize_sides && mainCharacter::GetTopPosition(wParam) >= blockedAreaSize_top
			&& mainCharacter::GetLeftPosition(wParam) <= (windowWidth - blockedAreaSize_sides) && mainCharacter::GetTopPosition(wParam) <= (windowHeight - blockedAreaSize_top))

		{
				return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		if (spriteList[0]->GetLeftPosition() >= blockedAreaSize_sides && spriteList[0]->GetTopPosition() >= blockedAreaSize_top
			&& spriteList[0]->GetLeftPosition() <= (windowWidth - blockedAreaSize_sides) && spriteList[0]->GetTopPosition() <= (windowHeight - blockedAreaSize_top))
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}
/*****************************************
Date:	 April 10, 2014
Arguments:WPARAM wParam
Return: RECT
Description: Returns a RECT value based on current direction

*****************************************/
RECT mainCharacter::GetRectangle(WPARAM wParam)
{
	switch (wParam)
	{
	case 'W':
		return m_CharacterUp_walking->GetCurrentRect();
	case 'A':
		return m_CharacterLeft_walking->GetCurrentRect();
	case 'S':
		return m_CharacterDown_walking->GetCurrentRect();
	case 'D':
		return m_CharacterRight_walking->GetCurrentRect();
	}
}

/*****************************************
Date:	 July 7, 2015
Arguments: None
Return: string
Description: Returns a string value based on current direction

*****************************************/
string mainCharacter::GetDirection()
{
	//If one of the pointers below is equal to nullptr, it means the value was swapped and it 
	//can help to determine the current direction
	if (m_CharacterDown_normal == nullptr)
		return "Down";
	if (m_CharacterLeft_normal == nullptr)
		return "Left";
	if (m_CharacterRight_normal == nullptr)
		return "Right";
	if (m_CharacterUp_normal == nullptr)
		return "Up";
	return "None";
}




