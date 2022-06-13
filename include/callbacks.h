/*-------------------------------------------
  Copyright Simple Solutions, 2022
  Revised: 2022/06/12 20:47
-------------------------------------------*/

//standard includes
#include <windows.h>

//conditional header guard wrapper to avoid processing more than once
#ifndef CALLBACKS_H
	#define CALLBACKS_H

	LRESULT CALLBACK WndProc(HWND sHdlWinMain, UINT sMsg, WPARAM wParam, LPARAM lParam);

//end wrapper
#endif