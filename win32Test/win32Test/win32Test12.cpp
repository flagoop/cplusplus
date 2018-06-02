#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

BOOL FindFirst(DWORD dwValue);//对目标进程空间进行查找
BOOL FindNext(DWORD dwValue);//对目标空间进行2，3，4。。查找

//查找数据的地址列表
DWORD g_arList[1024];
int g_nListCnt;//有效的地址个数
HANDLE g_hProcess;// 目标进程的句柄

void ShowList();//用来进行交互显示的

//我们用来进行修改目标进程的值
BOOL WriteMemory(DWORD dwAddr, DWORD dwValue);
int main(void) {
	//首先，我们可以通过CreatePorcess把我们的目标进程Testor.exe拉起来
	//进而，我就可以访问Testor进程空间了
	char szFileName[] = "testor.exe";
	STARTUPINFO si ;
	memset(&si, 0, sizeof(si));
	PROCESS_INFORMATION pi;
	BOOL bRet = ::CreateProcess(
		NULL,
		szFileName,
		NULL,
		NULL,
		FALSE,
		CREATE_NEW_CONSOLE,
		NULL,
		NULL,
		&si,
		&pi
	);
	g_hProcess = pi.hProcess;
	//首先，我们需要将当前的memchange程序接收一个目标值，
	//并将这个目标值进行搜索比对
	int iVal;
	printf("请输入您要修改的变量数值\n");
	scanf("%d", &iVal);
	//进行第一次查找
	FindFirst(iVal);
	//进行交互显示
	ShowList();

	while (g_nListCnt > 1) {
		printf("请再一次输入您要修改的变量数值\n");
		scanf("%d", &iVal);
		//进行下一次搜索
		FindNext(iVal);
		ShowList();
	}
	//希望用户将修改的新数值输入，我们进行修改替换
	printf("目标地址是%p\n", g_arList[0]);
	printf("请输入新数据\n");
	scanf("%d", &iVal);

	//写入新数值，修改完毕
	if (WriteMemory(g_arList[0], iVal)) {
		printf("修改成功");
	}
	system("pause");
	return 0;
}

BOOL CompareAPage(DWORD dwBaseAddr, DWORD dwValue) {
	BYTE arBytes[4096];
	if (!::ReadProcessMemory(g_hProcess, (LPVOID)dwBaseAddr, arBytes, 4096, NULL))
		return FALSE;
	//当前页面可以读
	DWORD* pdw;
	for (int i = 0;i < (int)4 * 1024 - 3;i++) {
		pdw = (DWORD*)&arBytes[i];
		if (pdw[0] == dwValue) {
			if (g_nListCnt >= 1024)
				return FALSE;
			g_arList[g_nListCnt++] = dwBaseAddr + i;
		}
	}
	return TRUE;
}
BOOL FindFirst(DWORD dwValue) {
	const DWORD dwOneGB = 1024 * 1024 * 1024;
	const DWORD dwOnePage = 4 * 1024;
	if (g_hProcess == NULL)
		return FALSE;
	DWORD dwBase = 640 * 1024;
	BOOL bRet = FALSE;
	for (;dwBase < 2 * dwOneGB;dwBase += dwOnePage) {
		CompareAPage(dwBase, dwValue);
	}
	return TRUE;
}

BOOL FindNext(DWORD dwValue) {
	//保存一下有效地址个数
	int nOrgCnt = g_nListCnt;
	g_nListCnt = 0;

	BOOL bRet = FALSE;//假定查找失败
	DWORD dwReadValue;
	for (int i = 0;i < nOrgCnt;i++) {
		if (::ReadProcessMemory(g_hProcess, (LPVOID)g_arList[i],
			&dwReadValue, sizeof(DWORD), NULL)) {
			if (dwReadValue == dwValue) {
				g_arList[g_nListCnt++] = g_arList[i];
				bRet = TRUE;
			}
		}
	}
	return bRet;
}

void ShowList() {
	for (int i = 0;i < g_nListCnt;i++) {
		printf("%p\n", g_arList[i]);
	}
}

BOOL WriteMemory(DWORD dwAddr, DWORD dwValue) {

	return ::WriteProcessMemory(g_hProcess,(LPVOID)dwAddr,&dwValue,sizeof(DWORD),NULL);
}