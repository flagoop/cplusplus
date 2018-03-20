#pragma once



class clsTmp1;
template<typename T>
class clsTemplateTest1
{
public:
	friend	class clsTmp1;
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


class clsTmp1
{
public:
	friend	ostream& operator<<(ostream& os, const clsTmp1 &obj);
	clsTmp1() = default;
	clsTmp1(int i):i(i){}
	void pt(clsTemplateTest1<clsTmp1> &obj) { cout << obj.val << endl; }

	//void pt2(clsTemplateTest1<> &obj){ cout << obj.val << endl; } //error
protected:
private:
	int i = 250;
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