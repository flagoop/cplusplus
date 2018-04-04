#include "stdafx.h"
#include "templateTest.h"
#include "test.h"



int clsTmp5::i = 10;

template	class clstmp4<string>; //在其它cpp文件中的extern指明了<string>类型的模板实例只在此cpp文件中生成 ，不会在
//每个调用 clstmp4<string>对象的文件中单独产生一个模板实例

ostream & operator<<(ostream & os, const clsTemplateFriend1 & obj)
{
	// TODO: 在此处插入 return 语句
	os << "operator<<(ostream & os, const clsTmp1 & obj): " << obj.i << endl;
	
	return os;

}


ostream & operator<<(ostream & os, clsTmp5 &obj)
{
	// TODO: 在此处插入 return 语句
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
	// TODO: 在此处插入 return 语句
	os << "operator<<(ostream & os, const clsTemplateTest1<clsTmp1>& obj): "<< obj.val << endl;
	return os;
}

