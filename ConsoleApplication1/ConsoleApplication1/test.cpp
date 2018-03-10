#include "stdafx.h"
#include "test.h"



allocator<string> clsStrVec::alloc;

size_t clsEmployee::szId2 = 0;

DateTest::DateTest(string s)
{
	size_t		pos=0;
	unsigned	data1;
	string		sub;
	cout << "s:" << s << endl;

	vector<string>	vecS{"january","february","march","april","may","june",
						"july","august","september","october","november","december"};

	//month
	string	subtmp;
	bool	dateValid = false;
	
	for (auto &e:vecS)
	{
		size_t	it,n=0;
		
		if ((it = s.find(e, pos)) != string::npos)
		{

			cout << "it:" << it << endl;
			subtmp = s.substr(it, size(e));
			sub = s.substr(size(subtmp));
			cout<<"1sub:"<<sub<<endl;
			if (!subtmp.empty())
			{
				pos = size(subtmp);
				cout << "pos:" << pos << endl;
			}
			cout << "subtmp:" << subtmp << endl;
			month=date_stoi(subtmp);

		}
	}

	//month
	if (pos == 0)
	{

		sub = s.substr(s.find_first_of("0123456789"));
		cout << "month sub:" << sub << endl;
		data1 = stoi(sub, &pos);
		cout << "month pos:" << pos << endl;
		month = data1;
	}
	
	//day
	auto it2 = sub.find_first_of("0123456789");
	cout << "it2:" << it2 << endl;
	sub=sub.substr(it2);
	cout << "day sub:" << sub << endl;
	data1 = stoi(sub, &pos);
	cout << "day pos:" << pos << endl;
	sub = sub.substr(pos);
	cout << "sub2:" << sub << endl;
	day = data1;

	//year
	sub = sub.substr(sub.find_first_of("0123456789"));
	cout <<"year sub:"<< sub << endl;
	data1 = stoi(sub, &pos);
	cout << "year pos:" << pos << endl;
	year = data1;
	
}

void f(const  clsNumbered &nb)
{
	cout << nb.iMysn << endl;
}

unsigned	date_stoi(string &s)
{
		if (s == "january")
		{
			return 1;
		}
		if (s == "february")
		{
			return 2;
		}
		if (s == "march")
		{
			return 3;
		}
		if (s == "april")
		{
			return 4;
		}
		if (s == "may")
		{
			return 5;
		}
		if (s == "july")
		{
			return 6;
		}
		if (s == "june")
		{
			return 7;
		}
		if (s == "august")
		{
			return 8;
		}
		if (s == "september")
		{
			return 9;
		}
		if (s == "october")
		{
			return 10;
		}
		if (s == "november")
		{
			return 11;
		}
		if (s == "december")
		{
			return 12;
		}
		return 0;
}

void clsTest1::pt()
{
	for (auto c:iArr)
	{
		cout << c << " ";
	}
	cout << endl;
}

clsTest2 & clsTest2::operator=(const clsTest2 & obj)
{
	// TODO: 在此处插入 return 语句
	auto newStr = new string(*obj.ps);
	delete	ps;
	ps = newStr;
	cout << "operator=" << endl;
	return	*this;
}

clsTest5 & clsTest5::operator=(const clsTest5 & obj)//这里的形参调用不会触发拷贝构造函数 因为&引用 
{
	// TODO: 在此处插入 return 语句
	cout << "operator=" << endl;
	auto newString = new string(*obj.ps);
	
	if (!--*iUse)	//指向等号左侧对象iuse的内存地址，并进行了值更新
	{
		//this->~clsTest5();
		delete ps;
		delete iUse;
		ps = nullptr;
		iUse = nullptr;
	}
	ps = newString;
	iUse = obj.iUse; //让iuse指向等号右侧的对象 并更新了新值 ，不和上面的等号左侧iuse内存地址冲突
	++*obj.iUse;

	return *this;
}

clsTest5::~clsTest5()
{
	cout << "~" << endl;

	if (!--*iUse)
	{
		delete ps;
		delete iUse;
		ps = nullptr;
		iUse = nullptr;
	}
}

void clsTest5::pt()
{

	//if (iUse) cout << "ps:" << *ps << " iUse:" << *iUse << endl;
	//else cout << "obj is delete." << endl;

	cout << "ps:" << *ps << " iUse:" << *iUse << endl;
}


clsStrVec::clsStrVec(const initializer_list<string>& il)
{
	auto pnew=alloc.allocate(il.size());
	//f_free();
	pStrElements = pnew;
	pStrFirst_free= uninitialized_copy(il.begin(), il.end(), pStrElements);
	pStrCap = pStrElements + il.size();
}

void clsStrVec::f_push(const string & s)
{
	chkFree();
	alloc.construct(pStrFirst_free++, s);
}

void clsStrVec::f_realloc()
{
	const size_t	N = 3;
	auto pe = pStrCap;
	auto szCapacity = pStrCap - pStrElements;
	auto szNewCapacity =szCapacity? N * szCapacity:1;

	auto pNewElem = alloc.allocate(szNewCapacity);
	//
	//auto pend=uninitialized_copy_n(pStrElements, szCapacity, pNewElem);
	uninitialized_copy_n(pStrElements, szCapacity, pNewElem);
	while (pe!=pStrElements)
	{
		alloc.destroy(--pe);
	}
	alloc.deallocate(pStrElements, szCapacity);
	//
	pStrElements = pNewElem;
	pStrFirst_free = pStrElements + szCapacity;
	pStrCap = pStrElements+szNewCapacity;

}

void clsStrVec::f_free()
{
	//if (pStrElements==nullptr)
	//{
	//	return;
	//}

	auto pit = pStrCap;
	auto szLen = pStrCap - pStrElements;
	
	while (pit != pStrElements)
	{
		alloc.destroy(--pit);
	}
	
	alloc.deallocate(pStrElements, szLen);
}

void clsStrVec::pt()
{
	if (pStrElements==nullptr)
	{
		cout << "empty clsStrVec." << endl;
		return;
	}
	auto pit = pStrElements;
	size_t	i = 0;
	while (pit!=pStrCap)
	{
		cout << i++ << ": ";
		cout << *pit++ << endl;
	}
}

void clsStrVec::chkFree()
{
	if (pStrCap==pStrFirst_free)
	{
		f_realloc();
	}
}

//加了const clsSizeCount &obj 是神马问题?
//ofstream & operator<<(ofstream & os, const clsSizeCount & obj){	os<<obj.icount << endl;	return os;}
ofstream & operator<<(ofstream & os, clsSizeCount & obj)
{
	os << obj.icount << endl;
	return os; 
}

clsTest9 operator+(const clsTest9 & obj1, const clsTest9 & obj2)
{
	clsTest9	ct9;
	ct9.i = obj1.i + obj2.i;

	return ct9;
}

ostream & operator<<(ostream & os, clsOperatorTest3 & obj)
{
	// TODO: 在此处插入 return 语句
	os << obj.i << endl;
	return os;
}

ostream & operator<<(ostream & os, clsOperatorTest2 & obj)
{
	// TODO: 在此处插入 return 语句
	for (auto c : obj.vecs)
	{
		os << c << " ";
	}
	return os;
}

ostream & operator<<(ostream & os, const clsOperatorTest & obj)
{
	// TODO: 在此处插入 return 语句
	os << "s:" << obj.s << " i:" << obj.i << " d:" << obj.d << " ";
	return os;
}

clsOperatorTest  operator+(const clsOperatorTest & obj1, const clsOperatorTest & obj2)
{
	// TODO: 在此处插入 return 语句
	clsOperatorTest obj;
	obj += obj1;
	obj += obj2;
	return obj;
}

ostream& operator<<(ostream &os, const clsStrVec &obj)
{
	auto pb = obj.pStrElements;
	auto pe = obj.pStrFirst_free;
	while (pb != pe)
	{
		os << *pb << " ";
		++pb;
	}
	cout << endl;
	return os;
}


/*	
//非友元模式下的定义
ostream& operator<<(ostream &os, const clsStrVec &obj)
{
	auto pb = obj.f_Elements();
	auto pe = obj.f_First_free();
	while (pb != pe)
	{
		os << *pb << " ";
		++pb;
	}
	cout << endl;
	return os;
}
*/
