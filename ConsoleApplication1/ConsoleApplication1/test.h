#pragma once
#include"stdafx.h"

class clsTest8
{
public:

	void operator()(istream& is = cin)
	{
		cout << "type string list:" << endl;
		while (is >> s)
		{
			if (is)
			{
				cout <<"your type is: "<< s << endl;
				vec_Str.push_back(s);
			}
			else
			{
				cout << "error" << endl;
			}

		}
	}
	void pt()const
	{
		cout << "vector is:" << endl;
		for (auto c:vec_Str)
		{
			cout << c << endl;
		}
	}
protected:
private:
	string	s;
	vector<string>	vec_Str;
};

class clsTest7
{
public:
	clsTest7(ostream &os = cout, char ch = ' ') :os(os), ch(ch) {}
	void operator()(int i1, int i2, int i3)
	{
		if (i1>10)
		{
			os << i2;
		}
		else
		{
			os << i3;
		}
	}
protected:
private:
	ostream & os;
	char	ch;
};

class clsAbs
{
public:
	int operator()(int i) { return i < 0 ? -i : i; }
protected:
private:

};

class clsOperatorTest2
{
public:
	clsOperatorTest2() = default;
	clsOperatorTest2(const initializer_list<string> &il) :vecs(il){}

	friend ostream& operator<<(ostream& os, clsOperatorTest2 &obj);

	string&	operator[](size_t n) { return vecs[n]; }
	const string	operator[](size_t n)const { return vecs[n]; }

	string& operator*() { return	vecs[0]; }
	//string* operator->() { return	&vecs[0]; }
	vector<string>* operator->() { return &vecs; }
protected:
private:
	vector<string> vecs;
};

class clsOperatorTest
{
public:
	clsOperatorTest(string	&&s=string(), int i=0, double d=0.0)
		:s(s), i(i), d(d) {};
	
	friend	ostream& operator<<(ostream& os, const clsOperatorTest &obj);
	clsOperatorTest & operator+=(const clsOperatorTest &obj)
	{
		s += obj.s;
		i += obj.i;
		d += obj.d;
		return *this;
	}
protected: 
private:
	string	s;
	int		i;
	double	d;
};

//这和类成员函数本就返回this对象的引用是不同的
//clsOperatorTest& operator+(const clsOperatorTest &obj1, const clsOperatorTest &obj2);

clsOperatorTest operator+(const clsOperatorTest &obj1, const clsOperatorTest &obj2);

//模拟vector<string>
class clsStrVec
{
public:
	clsStrVec()
		:pStrElements(nullptr), pStrFirst_free(nullptr), pStrCap(nullptr)
	{
		cout << "clsStrVec()" << endl;
	}

	clsStrVec(const initializer_list<string> &il);

	//clsStrVec(const clsStrVec &obj)
	//:pStrElements(obj.pStrElements),pStrFirst_free(obj.pStrFirst_free),pStrCap(obj.pStrCap)
	//{ cout << "clsStrVec &obj" << endl; }	//共享一个内存，析构时会对同一块内存释放2次

	clsStrVec(clsStrVec &&rrobj) noexcept:pStrElements(rrobj.pStrElements),
		pStrFirst_free(rrobj.pStrFirst_free), pStrCap(rrobj.pStrCap)
	{
		cout << "(clsStrVec &&rrobj)" << endl;
		rrobj.pStrElements = rrobj.pStrFirst_free = rrobj.pStrCap = nullptr;
	}

	clsStrVec& operator=(clsStrVec &&rrobj)noexcept
	{
		cout << "operator=(clsStrVec &&rrobj)" << endl;
		if (this!=&rrobj)
		{
			f_free();
			pStrElements = rrobj.pStrElements;
			pStrFirst_free = rrobj.pStrFirst_free;
			pStrCap = rrobj.pStrCap;
			rrobj.pStrElements = rrobj.pStrFirst_free = rrobj.pStrCap = nullptr;
		}
		return *this;
	}
	~clsStrVec() { cout << "~clsStrVec()" << endl; f_free(); }
	string* f_Elements()const  { return pStrElements; }		//const 限定pStrElements为常量指针
	string* f_First_free()const { return pStrFirst_free; }
	string* f_Cap()const { return pStrCap; }
	
	void	f_push(const string &s);
	void	f_realloc();

	void	f_free();
	void	pt();

	friend	ostream& operator<<(ostream &os, const clsStrVec &obj);
	
protected:
private:
	static	allocator<string> alloc;
	void	chkFree();
	string*	pStrElements;
	string*	pStrFirst_free;
	string*	pStrCap;
};

//ostream& operator<<(ostream &os, const clsStrVec &obj);	//不定义类友元情况 下 就用这种普通声明

//class clsTest6;
//extern void swap(clsTest6 &obj1, clsTest6 &obj2);
class clsTest6
{
public:
	friend	void swap(clsTest6 &obj1, clsTest6 &obj2);
	clsTest6(const string s = string()) :sp1(new string(s)) { cout << "const string s=string()" << endl; }
	clsTest6(const clsTest6 &obj) :sp1(obj.sp1) { cout << "const clsTest6 &obj" << endl; }
	
	void pt() { cout << *sp1 << endl; }
protected:
private:
	shared_ptr<string>	sp1;
};

inline
void swap(clsTest6 & obj1, clsTest6 & obj2)
{
	//auto tmp = obj1.sp1;
	//obj1.sp1 = obj2.sp1;
	//obj2.sp1 = tmp;
	//using	std::swap;
	swap(obj1.sp1, obj2.sp1);

}


class clsTest5
{
public:
	
	clsTest5(const string s = string()) :ps(new string (s)), iUse(new size_t(1)) { cout << "const string s=string()" << endl; }
	
	clsTest5(const clsTest5 &obj) :ps(obj.ps),iUse(obj.iUse) { ++*iUse; cout << "const clsTest5 &obj" << endl; }
	clsTest5& operator=(const clsTest5 &obj);
	~clsTest5();

	
	void pt();
protected:
private:
	string * ps;
	//shared_ptr<string> sp_Str;
	size_t	*iUse;
};

class clsTest4
{
public:
	void pt() { cout << *sp_Str << endl; }
protected:
private:
	//shared_ptr<string>	sp_Str(new string());//????????????? why error
	//shared_ptr<string> sp_Str = make_shared<string>("kk");
	//int i = 30;
	string *sp_Str = new string("kk");
};

class clsTest3
{
public:
	//clsTest3() = default;
	clsTest3(int i=0) :pi(new int(i)) { cout << "int i" << endl; }

	clsTest3(const clsTest3 &obj) :pi(obj.pi) { cout << "const clsTest3&" << endl; }
	//clsTest3(const clsTest3 &obj) :pi(new int(*obj.pi)) { cout << "const clsTest3&" << endl; }

	~clsTest3() {cout << "~" << endl; }
	void pt() { cout << *pi << endl; }
	void setdata(int i) { *pi =i; }
protected:
private:
	shared_ptr<int> pi;
	//shared_ptr<int> pi;
};

class clsTest2
{
public:
	clsTest2(const string s = string()) :ps(new string(s)) { cout << "const string s" << endl; }
	clsTest2(const clsTest2 &obj) :ps(new string(*obj.ps)) { cout << "const clsTest2" << endl; }
	clsTest2& operator=(const clsTest2 &obj);
	~clsTest2() { delete ps; cout << "~" << endl; }
protected:
private:
	string * ps;
};

class clsEmployee
{
public:
	clsEmployee() = default;
	clsEmployee(const string &s) :strName(s),szId(++szId2) {}
	void pt() { cout << "Id:" << szId << ":" << strName << endl; }
protected:
private:
	static	size_t	szId2;
	size_t	szId;
	string	strName;
};


class clsDelete
{
public:
	void pt()const { cout << iId << endl; }

protected:
private:
	const int iId;	//合成控制拷贝将是隐式delete
	//int iId;
	//int &rd;
};

static int id=0;
class clsNumbered
{
public:
	clsNumbered() :iMysn(++id) { cout << "()" << endl; }
	clsNumbered(clsNumbered &nb) :iMysn(++id) { cout << "const clsNumbered &nb" << endl; }
	clsNumbered& operator=(clsNumbered &nb) 
	{
		iMysn = ++id;
		cout << "operator=" << endl; 
		return *this;
	}
	friend	void f(const clsNumbered &nb);
protected:
private:
	
	int	iMysn;
};


struct X 
{
	X() { cout << "X()" << endl;}
	X(const X&) { cout << "const X&" << endl; }
	X& operator=(const X&) { cout << "operator=()" << endl; return *this; }
	~X() { cout << "~X()" << endl; }
};

class ShardPtrHasPtr
{
public:
	ShardPtrHasPtr() { cout << "my default" << endl; }
	ShardPtrHasPtr(const string &s) :spStr(new string(s)) { cout << "const string &s p:" << *spStr << endl; }
	void pt() { cout << "pt():" << *spStr << endl; }
	~ShardPtrHasPtr() { cout << "~~" << endl; }
protected:
private:
	shared_ptr<string>	spStr;
};

class HasPtr
{
public:
	HasPtr() { cout << "my default" << endl; }
	HasPtr(const HasPtr& hp) :p(new string(*hp.p)), i(2) { cout << "const HasPtr& p:" << p << "-" << *p << endl; }
	//HasPtr(const string &s=string()) :p(new string(s)), i(0) { cout <<"const string &s p:"<<p<<"-"<<*p << endl; }
	HasPtr(const string &s) :p(new string(s)), i(0) { cout << "const string &s p:" << p << "-" << *p << endl; }

	~HasPtr() { delete p; p = nullptr; cout << "~~" << endl; }
	void pt() { cout << "pt():" << *p << endl; }
protected:
private:
	string *p;
	int i;
};


class clsPoint
{
public:
	clsPoint() { cout << "clsPoint default" << endl; };
	clsPoint(const clsPoint&) { cout << "clsPoint(const clsPoint&)" << endl; }
	~clsPoint() { cout << "~~" << endl; };

private:

};

class clsTT;
class clsTest1
{
public:
	clsTest1() { cout << "default" << endl; }
	clsTest1(const clsTest1&) { cout << "const clsTest1&" << endl; }
	clsTest1(clsTT&) { cout << "const clsTT&" << endl; }
	void pt();
	
protected:
private:
	int iArr[5]{ 1,2,3,4,5 };
};

class clsShardPtrTest
{
public:
	clsShardPtrTest() = default;
	clsShardPtrTest(initializer_list<int> il) :vec_Int(il)
		{ cout << "clsShardPtrTest(il)" << endl; }
	void pt()
	{
		for (auto &c:vec_Int)
		{
			cout << c << " ";
		}
		cout << endl;
	}
protected:
private:
	vector<int>	vec_Int;
};


class DateTest
{
public:
	DateTest() = default;
	//DateTest() :year(0), month(0), day(0) {};
	DateTest(string s);

	void pt() { cout << "year:" << year << " month:" << month << " day:" << day << endl; }
protected:
private:
	unsigned	year;
	unsigned	month;
	unsigned	day;
};

unsigned	date_stoi(string &s);
