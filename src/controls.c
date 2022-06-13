/*-------------------------------------------
  Copyright Simple Solutions, 2022
  Revised: 2022/06/12 19:43
-------------------------------------------*/

//standard includes
#include <windows.h>
#include <commctrl.h>

//custom includes
#include "..\include\controls.h"
#include "..\include\resources.h"

int CreateControls(HWND sHdlWinMain)
{
	//declarations
	TBBUTTON sbButtonsToAdd[TB_BTN_COUNT]; //Container for three buttons
	HWND sToolBar;
	HMODULE vModInstHandle;
	HIMAGELIST sImageList;
	HBITMAP sBitmap;
	int iBitmapIndex;

	//attempt to create this module instance handle
	vModInstHandle = GetModuleHandle(NULL);

	//verify if module instance handle was created correctly
	if(vModInstHandle == NULL)
	{
		MessageBox(sHdlWinMain, "Could not create module instance handle.", "Error", MB_OK | MB_ICONERROR);
		return __LINE__;
	}

	//attempt to create toolbar 
	sToolBar = CreateWindowEx(0, "ToolbarWindow32", NULL,
	CCS_ADJUSTABLE | WS_BORDER | WS_CHILD | WS_VISIBLE | TBSTYLE_FLAT,
	0, 0, 0, 0, sHdlWinMain, (HMENU) IDC_MAIN_TOOLBAR, vModInstHandle, NULL);

	//verify if toolbar was created correctly
	if(sToolBar == NULL)
	{
		MessageBox(sHdlWinMain, "Could not create toolbar.", "Error", MB_OK | MB_ICONERROR);
		return __LINE__;
	}

	//attempt to create bitmap
	sBitmap = (HBITMAP) LoadImage(vModInstHandle, MAKEINTRESOURCE(IDB_TBBITMAP_LARGE_COLOR), IMAGE_BITMAP,
	TB_BTN_BITMAP_W, TB_BTN_BITMAP_H, LR_CREATEDIBSECTION);

	//verify if bitmap was added to image list correctly
	if(sBitmap == NULL)
	{
		MessageBox(sHdlWinMain, "Could not create bitmap.", "Error", MB_OK | MB_ICONERROR);
		return __LINE__;
	}

	//attempt to create image list
	sImageList = ImageList_Create(TB_BTN_BITMAP_H, TB_BTN_BITMAP_H, ILC_COLOR32,
	(TB_BTN_BITMAP_W / TB_BTN_BITMAP_H), (TB_BTN_BITMAP_W / TB_BTN_BITMAP_H));

	//verify if image list was created correctly
	if(sImageList == NULL)
	{
		MessageBox(sHdlWinMain, "Could not create image list.", "Error", MB_OK | MB_ICONERROR);
		return __LINE__;
	}
	
	//attempt to add bitmap to image list
	iBitmapIndex = ImageList_Add(sImageList, sBitmap, NULL);

	//verify if bitmap was added to image list correctly
	if(iBitmapIndex == -1)
	{
		MessageBox(sHdlWinMain, "Could not add bitmap to image list.", "Error", MB_OK | MB_ICONERROR);
		return __LINE__;
	}
	
	//define functionality for buttons
	ZeroMemory(sbButtonsToAdd, sizeof(sbButtonsToAdd));
    sbButtonsToAdd[0].iBitmap = MAKELONG(0, 0);
    sbButtonsToAdd[0].fsState = TBSTATE_ENABLED;
    sbButtonsToAdd[0].fsStyle = TBSTYLE_BUTTON;
    sbButtonsToAdd[0].idCommand = IDC_MAIN_TOOLBAR_FILE_NEW;
	sbButtonsToAdd[0].iString = "New File";

    sbButtonsToAdd[1].iBitmap = MAKELONG(1, 0);
    sbButtonsToAdd[1].fsState = TBSTATE_ENABLED;
    sbButtonsToAdd[1].fsStyle = TBSTYLE_BUTTON;
    sbButtonsToAdd[1].idCommand = IDC_MAIN_TOOLBAR_FILE_OPEN;
	sbButtonsToAdd[1].iString = "Open File";

	sbButtonsToAdd[2].iBitmap = 0;
    sbButtonsToAdd[2].fsState = TBSTATE_ENABLED;
    sbButtonsToAdd[2].fsStyle = TBSTYLE_SEP;
    sbButtonsToAdd[2].idCommand =0;

    sbButtonsToAdd[3].iBitmap = MAKELONG(2, 0);
    sbButtonsToAdd[3].fsState = TBSTATE_ENABLED;
    sbButtonsToAdd[3].fsStyle = TBSTYLE_BUTTON;
    sbButtonsToAdd[3].idCommand = IDC_MAIN_TOOLBAR_FILE_SAVETXT;
	sbButtonsToAdd[3].iString = "Save as text";

    sbButtonsToAdd[4].iBitmap = MAKELONG(3, 0);
    sbButtonsToAdd[4].fsState = TBSTATE_ENABLED;
    sbButtonsToAdd[4].fsStyle = TBSTYLE_BUTTON;
    sbButtonsToAdd[4].idCommand = IDC_MAIN_TOOLBAR_FILE_SAVEBAT;
	sbButtonsToAdd[4].iString = "Save as batch";

	sbButtonsToAdd[5].iBitmap = 0;
    sbButtonsToAdd[5].fsState = TBSTATE_ENABLED;
    sbButtonsToAdd[5].fsStyle = TBSTYLE_SEP;
    sbButtonsToAdd[5].idCommand =0;

	sbButtonsToAdd[6].iBitmap = MAKELONG(4, 0);
    sbButtonsToAdd[6].fsState = TBSTATE_ENABLED;
    sbButtonsToAdd[6].fsStyle = TBSTYLE_BUTTON;
    sbButtonsToAdd[6].idCommand = IDC_MAIN_TOOLBAR_SVC_OPEN;
	sbButtonsToAdd[6].iString = "Open Services";

	sbButtonsToAdd[7].iBitmap = MAKELONG(5, 0);
    sbButtonsToAdd[7].fsState = TBSTATE_ENABLED;
    sbButtonsToAdd[7].fsStyle = TBSTYLE_BUTTON;
    sbButtonsToAdd[7].idCommand = IDC_MAIN_TOOLBAR_ABOUT;
	sbButtonsToAdd[7].iString = "About";

	//send messages to toolbar (apply definitions)
	SendMessage(sToolBar, TB_BUTTONSTRUCTSIZE, (WPARAM)sizeof(TBBUTTON), 0); //Send the TB_BUTTONSTRUCTSIZE message (for backward compatibility)
	//SendMessage(sToolBar, CCM_SETVERSION, (WPARAM) 5, 0); //enable multiple image lists (versions <5)
	SendMessage(sToolBar, TB_SETIMAGELIST, 0, (LPARAM) sImageList); //add bitmap to toolbar
	SendMessage(sToolBar, TB_ADDBUTTONS, TB_BTN_COUNT, (LPARAM) &sbButtonsToAdd); //add buttons to toolbar
	SendMessage(sToolBar, TB_AUTOSIZE, 0, 0); //resize buttons on toolbar

	//show toolbar
	ShowWindow(sToolBar, TRUE);
}