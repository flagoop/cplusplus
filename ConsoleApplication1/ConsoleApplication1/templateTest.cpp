#include "stdafx.h"
#include "templateTest.h"

ostream & operator<<(ostream & os, const clsTmp1 & obj)
{
	// TODO: �ڴ˴����� return ���
	os <<"clsTmp1: "<< obj.i << endl;
	return os;
}
