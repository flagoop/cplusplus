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
	//WaitForMultipleObjects(2, h, TRUE, INFINITE); //�о����������߳�A B�Ļ���
	//������Զ �Ȳ�������ΪAB�߳��õĶ���while(true) ����ѭ�������˺�Ĵ���λ���ִ�в�����
	//g_hEventA = CreateEvent(NULL, false, TRUE, NULL);
	//g_hEventB = CreateEvent(NULL, false, FALSE, NULL);

	cout << "master Thread.\n";

	CloseHandle(h[0]);
	CloseHandle(h[1]);

	system("pause");
	return 0;
}