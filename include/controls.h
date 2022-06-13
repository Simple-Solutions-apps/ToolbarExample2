/*-------------------------------------------
  Copyright Simple Solutions, 2022
  Revised: 2022/06/12 20:27
-------------------------------------------*/

//conditional header guard wrapper to avoid processing more than once
#ifndef CONTROLLS_H
	#define CONTROLLS_H

	//Controls
	
	//tool bar
	#define IDC_MAIN_TOOLBAR 1100
	#define TB_BTN_COUNT 8
	#define TB_BTN_BITMAP_H 24
	#define TB_BTN_BITMAP_W 144

	//Command IDs for toolbar
	#define IDC_MAIN_TOOLBAR_FILE_NEW 1101
	#define IDC_MAIN_TOOLBAR_FILE_OPEN 1102
	#define IDC_MAIN_TOOLBAR_FILE_SAVETXT 1103
	#define IDC_MAIN_TOOLBAR_FILE_SAVEBAT 1104
	#define IDC_MAIN_TOOLBAR_SVC_OPEN 1105
	#define IDC_MAIN_TOOLBAR_ABOUT 1106

	//prototypes
	int CreateControls(HWND sHdlWinMain);

//end of wrapper
#endif