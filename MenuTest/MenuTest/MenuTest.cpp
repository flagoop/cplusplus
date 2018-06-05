
#include <windows.h>
#include "resource.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	char szClassName[] = "mainClass";


	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(wcex);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpszClassName = szClassName;
	wcex.lpfnWndProc = WndProc;
	wcex.hInstance = hInstance;
	wcex.hIcon = ::LoadIcon(hInstance, (LPSTR)IDI_APP);
	wcex.hIconSm = NULL;
	wcex.hCursor = ::LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)::GetStockObject(WHITE_BRUSH);
	wcex.lpszMenuName =(LPCSTR) IDR_Typer;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;

	::RegisterClassEx(&wcex);

	HWND hWnd = ::CreateWindowEx(0, szClassName, "Menu Test", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL,
		hInstance, NULL);


	if (NULL == hWnd)
	{
		::MessageBox(hWnd, "createWindow faild.", "Error", MB_OK);
		return -1;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	MSG msg;
	while (::GetMessage(&msg, NULL, 0, 0))
	{
		::TranslateMessage(&msg);
		::DispatchMessage(&msg);
	}

	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		::PostQuitMessage(0);
		break;
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case ID_FILE_EXIT:
			//::PostQuitMessage(0);
			::SendMessage(hWnd, WM_CLOSE, 0, 0);
			break;
		default:
			break;
		}
	}
		return 0;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

