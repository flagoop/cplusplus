#include "stdafx.h"
#include "templateTest.h"
#include "test.h"


ostream & operator<<(ostream & os, const clsTemplateFriend1 & obj)
{
	// TODO: 在此处插入 return 语句
	os << "operator<<(ostream & os, const clsTmp1 & obj): " << obj.i << endl;
	
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
	// TODO: 在此处插入 return 语句
	os << "operator<<(ostream & os, const clsTemplateTest1<clsTmp1>& obj): "<< obj.val << endl;
	return os;
}

