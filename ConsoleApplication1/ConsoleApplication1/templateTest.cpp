#include "stdafx.h"
#include "templateTest.h"
#include "test.h"



int clsTmp5::i = 10;

template	class clstmp4<string>; //������cpp�ļ��е�externָ����<string>���͵�ģ��ʵ��ֻ�ڴ�cpp�ļ������� ��������
//ÿ������ clstmp4<string>������ļ��е�������һ��ģ��ʵ��

ostream & operator<<(ostream & os, const clsTemplateFriend1 & obj)
{
	// TODO: �ڴ˴����� return ���
	os << "operator<<(ostream & os, const clsTmp1 & obj): " << obj.i << endl;
	
	return os;

}


ostream & operator<<(ostream & os, clsTmp5 &obj)
{
	// TODO: �ڴ˴����� return ���
	//os << "clsTmp5::operator<<()" << endl;
	os << &obj << endl;
	return os;
}

bool	funtmp1(const clsTmp3 &v1, const clsTmp3 &v2)
{
	if (v1 < v2)
	{
		return 1;
	}
	return 0;
}

template<typename T>
ostream & operator<<(ostream & os, const clsTemplateTest1<T>& obj)
{
	// TODO: �ڴ˴����� return ���
	os << "operator<<(ostream & os, const clsTemplateTest1<clsTmp1>& obj): "<< obj.val << endl;
	return os;
}

