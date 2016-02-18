#pragma once

#include <windows.h>
#include <sstream> 
#include <string> 

class CFrameRateThrottle
{
protected:
	
	unsigned int m_FPS;		// desired frame rate;
	HWND m_WindowHandle;
	
	unsigned int m_Period;  
	int m_SpareTime;
	unsigned long m_CurrentTickCount;
	unsigned long m_StartTime;
	unsigned long m_EndTime;

	unsigned int	m_FrameCount;
	unsigned int	m_FrameRate;
	unsigned int		m_ElapsedTime;

	void CalculateFrameRate();

	template <typename T>
	std::wstring ToString(const T & numericDataType)
	{
		std::wstringstream theStringStream;
		theStringStream << numericDataType;
		return theStringStream.str();
	}

public:

	CFrameRateThrottle(unsigned int FPS, HWND windowHandle);

	unsigned int Throttle(bool sleep = true);

	void SetFrameRate(unsigned int FPS);

};

