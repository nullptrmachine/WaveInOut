/* ██████╗  █████╗ ███████╗████████╗███████╗██████╗	 */
/* ██╔══██╗██╔══██╗██╔════╝╚══██╔══╝██╔════╝██╔══██╗ */
/* ██████╔╝███████║███████╗   ██║   █████╗  ██║  ██║ */
/* ██╔═══╝ ██╔══██║╚════██║   ██║   ██╔══╝  ██║  ██║ */
/* ██║     ██║  ██║███████║   ██║   ███████╗██████╔╝ */
/* ╚═╝     ╚═╝  ╚═╝╚══════╝   ╚═╝   ╚══════╝╚═════╝	 */

#ifndef _WAVE_H
#define _WAVE_H

#pragma once

#include <windows.h>

#include <iostream>
#include <list>

#include <mmsystem.h>

class WaveIn {
public:
	WaveIn();
	~WaveIn();

	BOOL open(int channels, int freq, int bits, HWND hWnd);
	void close();
	BOOL addBuffer(size_t size);
	BOOL start();

private:
	HWAVEIN hWaveIn;
	WAVEFORMATEX wfex;
	std::list<void*> waveHeaders;
};

class WaveOut {
public:
	WaveOut();
	~WaveOut();

	BOOL open(int channels, int freq, int bits, HWND hWnd, int deviceID = WAVE_MAPPER);
	void close();
	void play(const char* buf, size_t size);

private:
	HWAVEOUT hWaveOut;
	WAVEFORMATEX wfex;
};

#endif
