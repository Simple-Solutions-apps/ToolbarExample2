/*-------------------------------------------
  Copyright Simple Solutions, 2022
  Revised: 2022/06/12 20:39
-------------------------------------------*/

//standard includes
#include <windows.h>
#include <commctrl.h>
#include <fileapi.h>

//custom includes
#include "..\include\resources.h"
#include "..\include\controls.h"
#include "..\include\callbacks.h"


LRESULT CALLBACK WndProc(HWND sWinClass, UINT sMsg, WPARAM wParam, LPARAM lParam)
{
	switch(sMsg)
	{
		case WM_CREATE:
			{	
				//attempt to create controls			
				if(CreateControls(sWinClass) != 0)
				{
					return FALSE;
				}
			}	
			break;

		case WM_SIZE:
			break;

		case WM_CLOSE:
			DestroyWindow(sWinClass);
			break;

		case WM_DESTROY:
			PostQuitMessage(0);
			break;

		case WM_CTLCOLORSTATIC:
			SetBkColor((HDC) wParam, RGB(255, 255, 255));
			SetTextColor((HDC) wParam, RGB(0, 0, 0));
			return (LRESULT) GetStockObject(DC_BRUSH);
			break;

		case WM_CTLCOLOREDIT:
			SetBkColor((HDC) wParam, RGB(255, 255, 255));
			SetTextColor((HDC) wParam, RGB(0, 0, 0));
			return (LRESULT) GetStockObject(DC_BRUSH);
			break;

		case WM_CTLCOLORLISTBOX:
			SetBkColor((HDC) wParam, RGB(255, 255, 255));
			SetTextColor((HDC) wParam, RGB(0, 0, 0));
			return (LRESULT) GetStockObject(DC_BRUSH);
			break;

		case WM_COMMAND:
			break;
			
		default:
			return DefWindowProc(sWinClass, sMsg, wParam, lParam);
	}
		return FALSE;
}