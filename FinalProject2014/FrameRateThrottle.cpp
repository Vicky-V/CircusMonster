////////////////////////////////////////////////////////////////////////////////////////////////////
// file:	FrameRateThrottle.cpp
//
// summary:	Implements the frame rate throttle class
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "FrameRateThrottle.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>
/// GetTickCount() returns the number of milliseconds that have passed since the system was
/// booted.
/// </summary>
///
/// <remarks>	Tony Davidson, 2014-04-07. </remarks>
///
/// <param name="FPS">		   	The FPS. </param>
/// <param name="windowHandle">	Handle of the window. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

CFrameRateThrottle::CFrameRateThrottle(unsigned int FPS, HWND windowHandle) 
	: m_FPS(FPS), m_WindowHandle(windowHandle), m_Period(0), m_SpareTime(0), m_CurrentTickCount(GetTickCount()),
	m_StartTime(GetTickCount()), m_EndTime(0), m_ElapsedTime(0), m_FrameCount(0), m_FrameRate(0)
{
	m_Period = (unsigned int)((float)1000 / FPS + 0.5f);	// Note: cast to float to get decimal value and add 0.5 to round up. period = the time for 1 frame
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>
/// Updates the time and returns the delta between the new time and the previous time.
/// </summary>
///
/// <remarks>	Tony Davidson, 2014-04-07. </remarks>
///
/// <param name="sleep">	true to sleep. </param>
///
/// <returns>	An int. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

unsigned int CFrameRateThrottle::Throttle(bool sleep)
{
	m_EndTime = m_StartTime;
	m_StartTime = GetTickCount();

	m_CurrentTickCount += m_Period;
	m_SpareTime = m_CurrentTickCount - GetTickCount();

	if( m_SpareTime >= 0  && sleep == true) 
	{
		Sleep( m_SpareTime );
	}

	CalculateFrameRate();
	return m_SpareTime;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Sets frame rate. </summary>
///
/// <remarks>	Tony Davidson, 2014-04-07. </remarks>
///
/// <param name="FPS">	The FPS. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void CFrameRateThrottle::SetFrameRate(unsigned int FPS)
{
	m_FPS = FPS;
	m_Period = (unsigned int) ((float) 1000 / FPS + 0.5f);
	m_CurrentTickCount = GetTickCount();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Calculates the frame rate. </summary>
///
/// <remarks>	Tony Davidson, 2014-04-07. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void CFrameRateThrottle::CalculateFrameRate()
{
	// increment the frame count
	m_FrameCount++;

	// calculate how much time has passed since the last frame
	m_ElapsedTime += (m_StartTime - m_EndTime);

	if (m_ElapsedTime >= 1000.0 && m_WindowHandle) //if 1 second ( 1000 ms) has elapsed
	{
		m_FrameRate = m_FrameCount;// store current frame rate in data member
		static std::wstring output = L"";
		output = L"Frames Per Second = ";
		output += ToString(m_FrameRate);
		SetWindowText(m_WindowHandle, output.c_str());
		m_FrameCount = 0;
		m_ElapsedTime = 0;
	}
}
