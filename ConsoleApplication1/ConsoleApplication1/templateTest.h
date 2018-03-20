#pragma once
#include "stdafx.h"

template<typename T> using vt = pair<T, T>;


template<typename T>
class clsTemplateTest2
{
public:
	friend	class clstmp2;

	clsTemplateTest2():val(T()){}
	clsTemplateTest2(T &v):val(v){}
	clsTemplateTest2(T &&v) :val(v) {}

	void pt() { cout << "val=" << val << endl; }
protected:
private:
	T val;
};

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