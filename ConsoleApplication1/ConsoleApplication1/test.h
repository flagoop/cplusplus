#pragma once
#include"stdafx.h"



void funTemplateCls2();

class clsTest18
{
public:
	clsTest18(int i = 0) :iPrice(i) {}
	friend	bool operator<(const clsTest18 &obj1, const clsTest18 &obj2);
protected:
private:
	int iPrice;
};

class clsTest16
{
public:
	clsTest16() = default;
	clsTest16(int i,const string &s):i(i),strName(s){}
	virtual	void pt() { cout << "i=" << i << " name:" << strName << endl; }
	virtual	~clsTest16(){}
protected:
private:
	int i;
	string strName;
};
class clsSubTest16:public	clsTest16
{
public:
	clsSubTest16() = default;
	clsSubTest16(int i,const string &s,int j):clsTest16(i,s),subi(j){}
	void pt()override {
		cout << "clsSubTest16: " << "subi:"<<subi<< endl;
	}
protected:
private:
	int subi;
};

class clsTest15
{
public:
	clsTest15() { cout << "clsTest15()" << endl; }
	clsTest15(int i) :i(i) { cout << "clsTest15(int)" << endl; }
	clsTest15(const clsTest15 &obj) { cout << "clsTest15(const clsTest15&)" << endl; }
	clsTest15(clsTest15 &&obj) { cout << "clsTest15(const clsTest15&&)" << endl; }
	virtual	~clsTest15() { cout << "~clsTest15()" << endl; }
protected:
private:
	int i;
};
class clsSubTest15:public	clsTest15
{
public:
	//派生类在没有自定义构造的时候，会合成默认，拷贝和移动3类构造函数。
	using	clsTest15 :: clsTest15;//注：这叫继承基类 的除 默认，拷贝和移动这3类的构造函数以外的所有构造函数
	//这里就是继承了基类的 clsTest(int)这个构造

	//clsSubTest15() { cout << "clsSubTest15()" << endl; }
	//派生类如果使用合成的拷贝构造，编译器会为基类选择相应的形参对应版本的构造函数
	//但如果派生类自定义了拷贝构造，则我们也必须显示指定基类的相应形参版本的构造函数，如下条代码
	//否则基类会自作聪明的选择基类的默认构造函数
	//clsSubTest15(const clsSubTest15 &obj):clsTest15(obj) { cout << "clsSubTest15(const clsSubTest15&)" << endl; }

protected:
private:
};



class clsTest14
{
public:
	clsTest14(int k = 0) :i(k) { cout << "clsTest14(int) default" << endl; }
	virtual	~clsTest14() { cout << "~clsTest14" << endl; } //可以实现先析构派生类，再析构基类
	//~clsTest14() { cout << "~clsTest14" << endl; } 基类指针*pb指向派生类时，delete pb,派生类的析构不会调用 
		//而直接调用基类的析构

protected:
private:
	int i;
};
class clsSubTest14:public clsTest14
{
public:
	clsSubTest14() { cout << "clsSubTest14 default" << endl; }
	clsSubTest14(int k) :clsTest14(k), j(k) { cout << "clsSubTest14(int)" << endl; }
	clsSubTest14(const clsSubTest14 &obj) :clsTest14(obj) { cout << "clsSubTest14:copy" << endl; }
	~clsSubTest14() { cout << "~clsSubTest14" << endl; } //若基类析构为virtual 则由上 delete pb时，会动态绑定
		//调用此析构
protected:
private:
	int j;
};

class clsTest13
{
public:
	void f1() { cout << "clsTest13::f1()" << endl; }
	void f1(int i) { cout << "clsTest13::f1(int)" << endl; }
	void f1(string s) { cout << "clsTest13::f1(string)" << endl; }
protected:
private:
};
class clsSubTest13 :public clsTest13
{
public:
	using	clsTest13::f1;
	void f1() { cout << "clsSubTest13::f1()" << endl; }	//编译器查找函数名 原则是名字优先于形参列表，所以clsSubTest13
		//的对象调用f1(int)时将会报错，无可用函数f1(int) 继承类一个f1函数名将覆盖基类的所有f1的3个不同形参的函数
		//using 作用 是将基类中的所有f1的3个不同形参的函数全部显示填写在了clsSubTest13的作用域中，并可以对某一个进行定制
		//重写。
		//这里有一个重要规则 ：作用域的规则 ，clsSubTest13中查不到将向上查找 ，直到找到顶层类
		//using可以把上层的函数直接填写(或者说拷贝)到本类中，避免跨作用域查找函数名
protected:
private:
};



class clsTest12
{
public:
	clsTest12() = default;
	clsTest12(int i,const string &s):pro_i(i), pri_strName(s){}
	void pt1() { cout << "clsTest12::pt1()" << endl; }
protected:
	int pro_i;
private:
	string pri_strName;
};

class clsSubProTest12:protected clsTest12
{
public:
	void pt2() { cout << "pro_i:" << pro_i << endl; }
	//void ppt2(clsTest12 &obj) { cout << obj.pro_i << endl; }
	void ppt2(clsSubProTest12 &obj) { cout << obj.pro_i << endl; }
protected:
private:
	int pri_j;
};

class clsSubPriTest12 :private clsTest12	//private访问限制只针对类clsSubPriTest12的对象作出了相应的访问限制
											//如private刚限制了clsSubPriTest12的对象不能访问基类的所有成员及成员函数
{
public:
	void pt3() { cout << "pro_i:" << pro_i << endl; }
protected:
private:
	int pri_j2;
};

class clsSubTest12:public clsTest12
{
public:
	//void pt() { cout << "pro_i=" << pro_i <<"strname:"<<strName<< endl; }
	void pt() { cout << "pro_i=" << pro_i << endl; }

protected:
private:
};

class clsBase
{
public:
	string	name() { return strBaseName; }
	virtual	void pt(ostream &os) { os <<"strBaseName="<< strBaseName << endl; }
protected:
private:
	string strBaseName;
};
class clsDerived:public clsBase
{
public:
	void pt(ostream &os)
	{
		//clsBase::pt(os);
		os << "i=" << i << endl; 
	}
protected:
private:
	int i;
};

class clsTest11
{
public:
	clsTest11() { cout << "clsTest11" << endl; }
	virtual	void debug() { cout << "i=" << i << endl; }
protected:
private:
	int i;
};
class clsSubTest11:public clsTest11
{
public:
	clsSubTest11() { cout << "clsSubTest11" << endl; }
	void debug() override { cout << "str=" << str << endl; }
protected:
private:
	string str;
};

class clsTest10
{
public:
	virtual	void pt() { cout << "clsTest10" << endl; }
protected:
private:
};
class clsSubTest10 :public clsTest10
{
public:
	void tt() { cout << "clsSubTest10::tt()" << endl; }
	void pt()override { cout << "clsSubTest10" << endl; }
	//void pt(int i)override { cout << "clsSubTest10" << endl; } //override可以帮我们发现编译时无法提示的错误
	//override强制检查pt必须 是覆盖了的虚函数，形参必须与virtual声明时是一样的
};

class clsQuote
{
public:
	clsQuote() = default;
	clsQuote(const string& s,double d):bookno(s),dPrice(d){}
	string	isbn()const { return bookno; }
	virtual double	net_price(size_t n) { return	n*dPrice; }
protected:
	double	dPrice = 0.0;

private:
	string	bookno;
};

class clsBulk_Quote:public clsQuote
{
public:
	clsBulk_Quote(const string &s,double d, size_t szcnt = 10, double dd = 0.7) 
		:clsQuote(s,d), szCnt(szcnt), dDiscount(dd) {}
	double	net_price(size_t n) 
	{
		if (n>=szCnt)
		{
			return n * dPrice*dDiscount;
		}
		else
		{
			return	n * dPrice;
		}
		
	}
protected:
private:
	size_t	szCnt;
	double	dDiscount;
};

class clsTest9
{
public:
	clsTest9(int i = 0) :ival(i) {}
	clsTest9& operator=(clsTest9 &obj) && {ival = obj.ival; return *this; }
	void pt()const { cout << ival << endl; }
protected:
private:
	int ival;
};

class clsAdd
{
public:
	int operator()(int i, int j) { return i + j; }
protected:
private:
};

class clsSizeComp
{
public:
	clsSizeComp(size_t z):sz(z){}
	bool operator()(const string &s) { return	s.size() > sz; }
protected:
private:
	size_t	sz;
};

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
