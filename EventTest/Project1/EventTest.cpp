#include <iostream>
#include <windows.h>
#include <process.h>

using namespace std;

HANDLE	g_hEventA, g_hEventB;

UINT __stdcall ThreadA(LPVOID lpParam)
{
	while (true)
	{
		//WaitForSingleObject(g_hEventA, INFINITE);
		cout << "Thread A runnig.\n";
		//SetEvent(g_hEventB);
		Sleep(1000);
	}
	return 0;
}
UINT __stdcall ThreadB(LPVOID lpParam)
{
	while (true)
	{
		//WaitForSingleObject(g_hEventB, INFINITE);
		cout << "Thread B runnig.\n";
		//SetEvent(g_hEventA);
		Sleep(1000);
	}


	return 0;
}

int main()
{
	HANDLE h[2];
	h[0] = (HANDLE)_beginthreadex(NULL, 0, ThreadA, NULL, 0, NULL);
	h[1] = (HANDLE)_beginthreadex(NULL, 0, ThreadB, NULL, 0, NULL);
	//WaitForMultipleObjects(2, h, TRUE, INFINITE); //感觉交叉运行线程A B的话，
	//这里永远 等不到（因为AB线程用的都是while(true) 无限循环）。此后的代码段基本执行不到了
	//g_hEventA = CreateEvent(NULL, false, TRUE, NULL);
	//g_hEventB = CreateEvent(NULL, false, FALSE, NULL);

	cout << "master Thread.\n";

	CloseHandle(h[0]);
	CloseHandle(h[1]);

	system("pause");
	return 0;
}