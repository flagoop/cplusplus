#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

BOOL FindFirst(DWORD dwValue);//��Ŀ����̿ռ���в���
BOOL FindNext(DWORD dwValue);//��Ŀ��ռ����2��3��4��������

//�������ݵĵ�ַ�б�
DWORD g_arList[1024];
int g_nListCnt;//��Ч�ĵ�ַ����
HANDLE g_hProcess;// Ŀ����̵ľ��

void ShowList();//�������н�����ʾ��

//�������������޸�Ŀ����̵�ֵ
BOOL WriteMemory(DWORD dwAddr, DWORD dwValue);
int main(void) {
	//���ȣ����ǿ���ͨ��CreatePorcess�����ǵ�Ŀ�����Testor.exe������
	//�������ҾͿ��Է���Testor���̿ռ���
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
	//���ȣ�������Ҫ����ǰ��memchange�������һ��Ŀ��ֵ��
	//�������Ŀ��ֵ���������ȶ�
	int iVal;
	printf("��������Ҫ�޸ĵı�����ֵ\n");
	scanf("%d", &iVal);
	//���е�һ�β���
	FindFirst(iVal);
	//���н�����ʾ
	ShowList();

	while (g_nListCnt > 1) {
		printf("����һ��������Ҫ�޸ĵı�����ֵ\n");
		scanf("%d", &iVal);
		//������һ������
		FindNext(iVal);
		ShowList();
	}
	//ϣ���û����޸ĵ�����ֵ���룬���ǽ����޸��滻
	printf("Ŀ���ַ��%p\n", g_arList[0]);
	printf("������������\n");
	scanf("%d", &iVal);

	//д������ֵ���޸����
	if (WriteMemory(g_arList[0], iVal)) {
		printf("�޸ĳɹ�");
	}
	system("pause");
	return 0;
}

BOOL CompareAPage(DWORD dwBaseAddr, DWORD dwValue) {
	BYTE arBytes[4096];
	if (!::ReadProcessMemory(g_hProcess, (LPVOID)dwBaseAddr, arBytes, 4096, NULL))
		return FALSE;
	//��ǰҳ����Զ�
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
	//����һ����Ч��ַ����
	int nOrgCnt = g_nListCnt;
	g_nListCnt = 0;

	BOOL bRet = FALSE;//�ٶ�����ʧ��
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