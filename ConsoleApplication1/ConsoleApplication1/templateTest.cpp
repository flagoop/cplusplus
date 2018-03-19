#include "stdafx.h"
#include "templateTest.h"

ostream & operator<<(ostream & os, const clsTmp1 & obj)
{
	// TODO: 在此处插入 return 语句
	os <<"clsTmp1: "<< obj.i << endl;
	return os;
}
