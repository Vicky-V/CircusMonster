#include "Shoot.h"

CShoot::CShoot(const HWND windowHandle,  const unsigned short shellRadius, const LOGPEN & pen, const LOGBRUSH & brush, unsigned short speed)
: m_ShellRadius(shellRadius), m_Pen(pen), m_Brush(brush), m_Speed(speed)
{
	GetClientRect(windowHandle, &m_Rect);
	m_ClientWindowWidth = m_Rect.right - m_Rect.left;
	m_ClientWindowHeight = m_Rect.bottom - m_Rect.top;
	/*m_ShellDirection.x = m_Speed;
	m_ShellDirection.y = 0;*/
}

void  CShoot::draw(HDC hdc, WPARAM wParam, bool &shootingMode)
//shooting mode variable was initially for two fireballs at a time, but it doesn't work well and I just keep it here in case I'll be able to fix it in a distant future
//actually, you'll be able to see a lot of code, which was intended to be facilitating "two fireballs mode", but I didn't have time and patience to make it work...
{
	int size = 0;
	while (size != m_ShellLocationList.size())
	{
		if (m_NumberOfShells_old==0)//if a new shell was drawn
		{


			switch (wParam)
			{

			case 'W':
				m_ShellDirection.x = 0;
				m_ShellDirection.y = -m_Speed;
				m_NumberOfShells_old = 1;
				// update shell position
				//wParam_previous = wParam;
				//shootingMode = false;
				break;
			case 'A':
				m_ShellDirection.x = -m_Speed;
				m_ShellDirection.y = 0;
				m_NumberOfShells_old = 1;
				//shootingMode = false;
				//wParam_previous = wParam;
				break;
			case 'S':
				m_ShellDirection.x = 0;
				m_ShellDirection.y = m_Speed;
				m_NumberOfShells_old = 1;
				//shootingMode = false;
				//wParam_previous = wParam;
				break;
			case 'D':
				m_ShellDirection.x = m_Speed;
				m_ShellDirection.y = 0;
				m_NumberOfShells_old = 1;
				//shootingMode = false;
				//wParam_previous = wParam;
				break;

			}
		}
		m_ShellLocationList[size].x += m_ShellDirection.x;
		m_ShellLocationList[size].y += m_ShellDirection.y;	
		if (!PtInRect(&m_Rect, m_ShellLocationList[size])) // rect contains the client rectangle
		{
			m_ShellLocationList.erase(m_ShellLocationList.begin());
		}
		else // draw shell
		{
			m_Start.x =m_ShellLocationList[size].x - m_ShellRadius;
			m_Start.y =m_ShellLocationList[size].y - m_ShellRadius;

			m_End.x =m_ShellLocationList[size].x + m_ShellRadius;
			m_End.y = m_ShellLocationList[size].y + m_ShellRadius;

			drawShell(hdc);
			size++; // Next in list.
		}
	}

	//NO MORE RELEVANT

	//static WPARAM wParam_previous;
	//int size = 0;
	////static int oldDirection_index;
	//while( size != m_ShellLocationList.size() )
	//{
	//	//if it is not the first time character shoots
	//	
	//	/*if (wParam_previous != 0)
	//	{*/
	//		//if the direction and the number of fireballs have changed and Space key was pressed
	//		//if (wParam != wParam_previous&& m_NumberOfShells_old!=m_ShellLocationList.size()&&shootingMode)
	//		//if (wParam != wParam_previous&&m_ShellLocationList.size()!=1)//&& shootingMode)
	//		if (m_ShellLocationList.size()!=1)
	//		{
	//			//oldDirection_index = m_ShellLocationList.size()-1;//"remember" the number of the fireball which should fly in a different direction
	//			//m_ShellDirection_old = m_ShellDirection;//save the previous direction for the other fireballs
	//			switch (wParam)
	//			{
	//			case 'W':
	//				m_ShellDirection.x = 0;
	//				m_ShellDirection.y = -m_Speed;
	//				// update shell position
	//				//wParam_previous = wParam;
	//				//shootingMode = false;
	//				break;
	//			case 'A':
	//				m_ShellDirection.x = -m_Speed;
	//				m_ShellDirection.y = 0;
	//				//shootingMode = false;
	//				//wParam_previous = wParam;
	//				break;
	//			case 'S':
	//				m_ShellDirection.x = 0;
	//				m_ShellDirection.y = m_Speed;
	//				//shootingMode = false;
	//				//wParam_previous = wParam;
	//				break;
	//			case 'D':
	//				m_ShellDirection.x = m_Speed;
	//				m_ShellDirection.y = 0;
	//				//shootingMode = false;
	//				//wParam_previous = wParam;
	//				break;

	//			}
	//		}
	//	/*}
	//	else
	//	{
	//		*/
	//		//switch (wParam)
	//		//{
	//		//case 'W':
	//		//	m_ShellDirection.x = 0;
	//		//	m_ShellDirection.y =  - m_Speed;
	//		//	//m_ShellLocationList[size] = m_ShellDirection;// update shell position
	//		//	wParam_previous = wParam;
	//		//	//shootingMode = false;
	//		//	break;
	//		//case 'A':
	//		//	m_ShellDirection.x =  - m_Speed;
	//		//	m_ShellDirection.y = 0;
	//		//	//m_ShellLocationList[size] = m_ShellDirection;
	//		//	wParam_previous = wParam;
	//		//	//shootingMode = false;
	//		//	break;
	//		//case 'S':
	//		//	m_ShellDirection.x = 0;
	//		//	m_ShellDirection.y = m_Speed;
	//		//	//m_ShellLocationList[size] = m_ShellDirection;
	//		//	wParam_previous = wParam;
	//		//	//shootingMode = false;
	//		//	break;
	//		//case 'D':
	//		//	m_ShellDirection.x = m_Speed;
	//		//	m_ShellDirection.y = 0;
	//		//	//m_ShellLocationList[size] = m_ShellDirection;
	//		//	wParam_previous = wParam;
	//		//	//shootingMode = false;
	//		//	break;
	//		//}
	//	//}
	//	/*if (size >= oldDirection_index)
	//	{*/
	//		m_ShellLocationList[size].x += m_ShellDirection.x;
	//		m_ShellLocationList[size].y += m_ShellDirection.y;
	//	/*}
	//	else
	//	{
	//		m_ShellLocationList[size].x += m_ShellDirection_old.x;
	//		m_ShellLocationList[size].y += m_ShellDirection_old.y;
	//	}
	//	*/
	//	if( !PtInRect(&m_Rect, m_ShellLocationList[size]) ) // rect contains the client rectangle
	//	{
	//		m_ShellLocationList.erase(m_ShellLocationList.begin()+size);
	//		//oldDirection_index -= 1;
	//		
	//	}
	//	else // draw shell
	//	{
	//		m_Start.x = m_ShellLocationList[size].x - m_ShellRadius;
	//		m_Start.y = m_ShellLocationList[size].y - m_ShellRadius;

	//		m_End.x = m_ShellLocationList[size].x + m_ShellRadius;
	//		m_End.y = m_ShellLocationList[size].y + m_ShellRadius;

	//		drawShell(hdc);
	//		size++; // Next in list.
	//	}
	//}
	//shootingMode = false;
}

unsigned int CShoot::GetNumberOfShells()
{
	return m_ShellLocationList.size();
}

void CShoot::Fire(POINT point)
{
	m_NumberOfShells_old = 0;
	m_ShellLocationList.push_back(point);
}

BOOL CShoot::HitTest(RECT & targetRect, bool eraseShell)
{
	int size = 0;
	while( size != m_ShellLocationList.size() )
	{
		if( PtInRect(&targetRect, m_ShellLocationList[size]) ) // rect contains the client rectangle
		{
			if(eraseShell)
			{
				m_ShellLocationList.erase(m_ShellLocationList.begin()+size);
			}
			return true;
		}
		size++;
	}
	return false;
}
