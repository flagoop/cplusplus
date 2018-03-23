#pragma once
#include "stdafx.h"

class clsDebugDelete
{
public:
	clsDebugDelete(ostream &s=std::cerr):os(s){}
	template<typename T> void operator()(T *p)
	{
		os << "clsDebugDelete." << endl;
		os << "data " << *p << " should be erase...Address:" <<p<< endl;
		delete p;

	}
protected:
private:
	ostream &os;
};


template<typename T>
void funConTmp2(T &con)
{
	for_each(begin(con), end(con), [](auto obj) {cout << obj << endl; });
}

template<typename T>
void funConTmp(T &con)
{
	typename T::size_type len = con.size();
	typename T::size_type beg = 0;
	for (beg;beg<len;++beg)
	{
		cout << con[beg] << endl;
	}

	//for (auto &c:con){cout << c << endl;}
}


class clsTmp3
{
public:
	clsTmp3(int i = 0) :val(i) {}
	bool operator<(const clsTmp3 &obj)const 
	{
		if (val<obj.val)
		{
			return 1;
		}
		
		return 0;
	}
protected:
private:
	int val;
};

bool	funtmp1(const clsTmp3 &v1, const clsTmp3 &v2);

template<typename T, typename F = less<T>>
bool myTemplateComp(const T&v1, const T&v2, F fun=F())//如果 用的是默认实参less<T> 则F()就是为less<T>建临时对象
{
	if (fun(v1, v2))
	{
		return 1;
	}
	
	return 0;

}


template<typename T> 
class clsListItem
{
public:
	void setdata(T &v) { data = v; }
	void pt() { cout << "data=" << data << endl; }
protected:
private:
	T data;

};

template<typename T>
class clsList
{
public:
	clsList<T>()=default;
	clsList<T>(const clsList<T> &obj){}
	clsList<T>& operator=(const clsList<T> &obj) { *this = obj; return *this; }
	~clsList()	{}

	//void into(clsListItem<T> &obj, T val)
	void into(clsListItem<T> *pcls, T val)
	{

		pcls->setdata(val);
		//obj.setdata(val);

		//obj.data = val;	//error
	}
protected:
private:
	T * pf, *pe;
};


template<typename T> using vt = pair<T, T>;

template<typename T>
class clsTemplateTest2
{
public:
	friend	class clstmp2;

	clsTemplateTest2():val(T()){}
	clsTemplateTest2(T &v):val(v){}
	clsTemplateTest2(T &&v) :val(v) {}

	void pt() { cout << "val=" << val <<" si="<<si<< endl; }
	void setsi(int i) { si = i; }
protected:
private:
	T val;
	static	int si;
};
template<typename T> int clsTemplateTest2<T>::si = 0;


class clstmp2
{
public:
	clstmp2() :ctti(22) {}		//只有利用一下clstmp2的构造函数，会实例化一个模板
	clstmp2(int i):ctti(i){}
	void ptval() { ctti.pt(); }
protected:
private:
	clsTemplateTest2<int> ctti;
	//clsTemplateTest2<int> ctti(22);//error 因为在声明中是不开辟内存空间的，所以22没地方存放

};



//
class clsTemplateFriend1;
template<typename T2> class clsTemplateFriend2;
template<typename T > class clsTemplateFriend3;

template<typename T>
class clsTemplateTest1
{
public:
	friend	class clsTemplateFriend3<T>;
	template<typename T2> friend	class clsTemplateFriend2;

	friend	class clsTemplateFriend1;
	friend	T;//效果同上
	//定义下列友元，只因为定义了friend class clsTemp1，来测试不管T为什么类型，
	//clsTmp1里的成员函数pt(clsTemplateTest1<clsTmp1> &obj)都能访问私有数据T val;
	//逻辑上无意义
	//friend	ostream& operator<<(ostream &os, const clsTemplateTest1<clsTmp1> &obj); 
	//typename<typename X>
	friend	ostream& operator<<(ostream &os, const clsTemplateTest1<T> &obj);


	clsTemplateTest1():val(T()){}
	clsTemplateTest1(T &t):val(t){}
	clsTemplateTest1(T &&t) :val(t) {}

	void pt() { cout << "val=" << val << endl; }
protected:
private:
	T val;
	int j=100;
};

template<typename T>
class clsTemplateFriend3
{
public:
	void pt(clsTemplateTest1<T> &obj)
	{
		obj.pt();
	}
	void ptval(clsTemplateTest1<T> &obj)
	{
		cout << obj.val << endl;
	}

protected:
private:

};

template<typename T2>
class clsTemplateFriend2
{
public:
	clsTemplateFriend2<T2>(){}
	void pt() { ctti.pt(); }
protected:
private:
	clsTemplateTest1<int>	ctti;
	//clsTemplateTest1<int>	ctti2(11);//error 常数?
	clsTemplateTest1<double> cttd;
	//...
};

class clsTemplateFriend1
{
public:
	friend	ostream& operator<<(ostream& os, const clsTemplateFriend1 &obj);
	clsTemplateFriend1() = default;
	clsTemplateFriend1(int i):i(i){}
	clsTemplateFriend1(double d):d(d){}
	void pt() { ctti.pt(); }
	//void pt() { cttd.pt(); }

	//void pt2(clsTemplateTest1<> &obj){ cout << obj.val << endl; } //error
protected:
private:
	int i = 250;
	double	d;
	clsTemplateTest1<int>	ctti;

	//clsTemplateTest1<double> cttd(3.14);

	//clsTemplateTest1<clsTemplateFriend1> cttcls1;
	// ...
	
};

template<typename T,size_t N>
constexpr size_t reArrSize(T (&rarr)[N])
{
	return N;
}

template<typename T,size_t N>
T* mybeg(T(&rarr)[N])
{
	return (rarr);
}
template<typename T,size_t N>
T* myend(T(&rarr)[N])
{
	return (rarr + N);
}


template<typename T,unsigned N>
void template_pt(T(&r)[N])
{
	for (auto c:r)
	{
		cout << c << endl;
	}
}

template<typename T_itB,typename T_itE,typename	Tval>
T_itB myfind(const T_itB &itb,const T_itE &ite,Tval &&i)
{
	auto tmpitb = itb;
	while (tmpitb!=ite)
	{
		if (*tmpitb==i)
		{
			return tmpitb;
		}
		++tmpitb;
	}
	return ite;
}

template<typename T_itB, typename T_itE, typename	Tval>
T_itB myfind(const T_itB &itb, const T_itE &ite, Tval &i)
{
	auto tmpitb = itb;
	while (tmpitb != ite)
	{
		if (*tmpitb == i)
		{
			return tmpitb;
		}
		++tmpitb;
	}
	return ite;
}


template<typename T>
int temp_mycomp(const T &v1, const T &v2)
{
	if (v1 < v2)	return 1;
	if (v2 < v1)	return -1;
	return 0;
}