#include "stdafx.h"
#include "templateTest.h"
#include "test.h"


ostream & operator<<(ostream & os, const clsTmp1 & obj)
{
	// TODO: �ڴ˴����� return ���
	os << "operator<<(ostream & os, const clsTmp1 & obj): " << obj.i << endl;
	
	return os;
}

template<typename T>
ostream & operator<<(ostream & os, const clsTemplateTest1<T>& obj)
{
	// TODO: �ڴ˴����� return ���
	os << "operator<<(ostream & os, const clsTemplateTest1<clsTmp1>& obj): "<< obj.val << endl;
	return os;
}
