#pragma once

class clstmp1;
template<typename T>
class clsTemplateTest1
{
public:
	friend	clsTmp1;
	clsTemplateTest1(T &t):val(t){}
	clsTemplateTest1(T &&t) :val(t) {}

	void pt() { cout << "val=" << val << endl; }
protected:
private:
	T val;
	int j=100;
};

class clsTmp2
{
public:
	friend	class clsTmp1;
protected:
private:
	int k = 120;
};

class clsTmp1
{
public:

	clsTmp1() { i = k; }
	//clsTmp1(int i = 0) :i(j) {}
	friend	ostream& operator<<(ostream &os, const clsTmp1 &obj);
protected:
private:
	int i;
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