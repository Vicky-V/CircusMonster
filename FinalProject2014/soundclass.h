/********************************************************************

FMOD wrapper class v 1.11

Created by Tony Davidson

Date: November 10, 2013

Make sure to include the following libraries when using this technology:

Release/TDSoundlib.lib
Debug/TDSoundlib.lib
fmod/fmodex_vc.lib

You add the libraries to the Input property of the Linker sections in the Configuration Properties area 
of your project properties

Read FMOD Instructions.txt in the resource folder for details on using this class

*********************************************************************/

#ifndef _SOUNDCLASS_H
#define _SOUNDCLASS_H

#include <iostream>
#include <string>
#include <sstream>
#include "fmod/fmod.hpp"
#include "fmod/fmod_errors.h"

using namespace std;

class CSound
{
protected:

	static unsigned int  m_TotalSounds;
	static FMOD::System *	m_System;
	
	FMOD::Sound *	m_Sound;
	FMOD::Channel * m_Channel;
	FMOD_RESULT		m_Result;

	string			m_FileName;
	string			m_Error;
	unsigned int	m_Length;
	unsigned int	m_Time;
	bool			m_Loop;
	
	bool CleanUp();
	bool Update();
	bool Init();
	void ErrorState();

public:
	CSound();
	CSound(const string & fileName,  bool loop = false);
	~CSound();
	
	bool Play();
	bool Stop();
	bool Pause();
	bool GetPause();

	bool ChangeSound(const string & fileName,  bool loop = false);

	unsigned int	GetTotalSounds();
	unsigned int	GetPosition();
	unsigned int	GetLength();
	
	int				GetVolume();
	bool			GetMute();
	bool			GetLoop();
	bool			GetPlaying();
	string			GetFormattedPosition();
	string			GetFormattedLength();
	string			GetLastError();
	float			GetCPUUtilization();

	void			SetVolume(const int & volume);
	void			SetMute(bool mute = true);
	void			SetLoop(bool loop = false);
	
};

#endif