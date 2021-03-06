// ConsoleApplication1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "test.h"
#include "templateTest.h"

//using	std::placeholders::_1;
using	namespace std::placeholders;
#define	BUFFER_SIZE	100


/*
VOID wcs2mbs(LPCOLESTR wcstr, char* chResult)
{
	size_t wLen = wcslen(wcstr) + 1;  // 宽字符字符长度，+1表示包含字符串结束符  
	auto aLen = WideCharToMultiByte(CP_ACP, 0, wcstr, wLen, NULL, 0, NULL, NULL);

	LPSTR lpa = new char[aLen];
	WideCharToMultiByte(CP_ACP, 0, wcstr, wLen, lpa, aLen, NULL, NULL);
	strcpy_s(chResult, 200, lpa);
	delete[] lpa;
	lpa = NULL;
}

bool UnicodeToAnsi(wchar_t* lpString, char* szAnsi)//(in,out)  
{
	size_t nLen = wcslen(lpString) * 2, nReturnLen;//wcslen <string.h>   
	char* lpszBuf = (char*)malloc(nLen);//malloc <stdlib.h> and <malloc.h>   
	size_t	convers = 0;
	_wsetlocale(LC_ALL, L"zh-CN");
	nReturnLen = wcstombs_s(&convers,szAnsi,nLen, lpString, _TRUNCATE);//wcstombs <stdlib.h>   
	if (nReturnLen < 0)
	{
		free(lpszBuf);
		return false;
	}
	strcpy_s(szAnsi,nLen, lpszBuf);
	cout << lpszBuf << endl;
	return true;
}
*/

void	shortening(string &s, const string &oldVal, const string &newVal)
{
	auto it = s.find(oldVal);
	s.replace(it, size(oldVal), newVal);

}

string	&prefixName(string &s)
{
	s.insert(0, "Mr.");
	s.append("III");
	return s;
}

bool	funTest3(const string &s1)
{
	return s1.size() >= 5;
}

bool	isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

bool	funTest4(const string	&s)
{
	if (s.find('2', 0)!=s.size())
	{
		return true;
	}
	
	return false;
}

bool	funTest5(int i, int j)
{
	if ((j - i) == 2)
	{
		return true;
	}
	else
		return false;
}

bool	check_size(const string &s,size_t sz)
{
	return s.size() >= sz;
}

struct STR_test
{
	int	val;
	string	name;
	void pt()const { cout << val << "  " << name << endl; }

};


class CLS_test
{
	int	val;
	string	name;
public:
	void pt()const { cout << val << "  " << name << endl; }
};

struct myComp2
{
	bool	operator()(const STR_test &st1, const STR_test &st2)
	{
		//return	st1.name < st2.name;
		return st1.val < st2.val;
	}
};

bool	myComp(const STR_test& st1,const STR_test &st2)
{
	return	st1.name < st2.name;
}

bool	myCompTest(const STR_test& st1, const STR_test &st2)
{
	return	st1.name < st2.name;
}
using	funTest6 =bool (const STR_test &,const STR_test &);
//bool(*funTest7)(const STR_test &, const STR_test &) = myCompTest;
//typedef	bool(funTest6)(const STR_test &, const STR_test &);

//using	funTest8 = bool (*)(const STR_test &, const STR_test &);

namespace myspace
{
	int i = 20;
	int j = 30;
}

int i = 100;

namespace myspaceFun
{
	int mymax(int v1, int v2) { cout << "mysapceFun::mymax(int,int)\n"; return 1; }
	double mymaxd(double d1, double d2) { cout << "myspaceFun::mymax(double,double)"; return 1.1; }
}
int mymax(int v1, int v2) { cout << "::mymax(int,int)\n"; return 1; }
int mymax(double d1, double d2) { cout << "::mymax(double,double)"; return 1; }

string::const_iterator	getNumIt(const string &str)
{
	set<char> set_C{ '1','2','3','4','5','6','7','8','9','0' };

	auto it = find_if(str.begin(), str.end(), [set_C](auto &c)
	{
		for (auto &e : set_C)
		{
			if (c == e)
			{
				return true;
			}
		}
		return false;
	});
	if (it==str.end())
	{
		return str.end();
	}
	
	//string	strSub(it, str.end());
	//cout << strSub << endl;
	//size_t	sz;
	//int i = stoi(strSub, &sz);
	//cout << sz << endl;
	//return i;
	return it;
}

pair<string, size_t>	getPair(const string &s)
{
	istringstream iss(s);
	//string strName, strBrithday;
	set<char>	set_C{ '1','2','3','4','5','6','7','8','9','0' };
	auto itNum = find_if(s.begin(), s.end(), [set_C](auto &c) 
		{
			for (auto &e:set_C)
			{
				if (c==e)
				{
					return true;
				}
			}
			return false;
		});
	string strName(s.cbegin(), itNum);
	string strBrithday(itNum, s.cend());
	//copy(s.cbegin(), itNum, back_inserter(strName));
	//copy(itNum, s.end(), back_inserter(strBrithday));
	size_t brithday =(size_t) stoi(strBrithday);
	auto pp = make_pair(strName, brithday);
	//pair<string, size_t>	p{strName,brithday};
	return pp;

}

int seq1[] = { 1, 2, 3,4, 5 ,6}, seq2[] = { 9, 8, 7, 7, 6, 5 };


string translateFun(const string &word)
{
	//getline string in file passwd.txt
	fstream	fIn("passwd.txt", ios::in);
	string strLine;
	map<string, string>	map_StrStr;
	while (getline(fIn, strLine))
	{
		string key, destStr;
		istringstream	iss(strLine);
		iss >> key;
		iss >> destStr;
		map_StrStr.insert({ key,destStr });
	}


	string newWord;
	auto it = map_StrStr.find(word);
	if (it!= map_StrStr.end())
	{
		newWord = it->second;
		return newWord;
	}
	else
	{
		return word;
	}
	
}

void processTest1(shared_ptr<int> sp)
{
	cout << "processTest1()" << endl;

	cout << sp.use_count() << endl;

}

map<size_t, string>	seachWord(unordered_multimap<string, size_t> ummap_StrSz, const string &word)
{
	map<size_t,string>	map_StrSz;
	for (auto &c : ummap_StrSz)
	{
		//cout << c.second << "-" << c.first << endl;
		//cout << c.first << "-" << c.second << endl;
		istringstream	iss(c.first);
		string strWord,strUpper;
		transform(word.begin(), word.end(), back_inserter(strUpper), [](auto c) { return toupper(c); });
		while (iss >> strWord)
		{
			if (strWord == word || strWord ==strUpper )
			//if (strWord == word)
			{
				//cout << c.second << "-" << c.first << endl;
				map_StrSz.insert({c.second,c.first});
				break;
			}
		}
	}
	return map_StrSz;
}

//clsPoint	global;
/*
clsPoint	foo_bar(clsPoint arg)
{
	clsPoint	local = arg;
	clsPoint	*heap = new clsPoint(global);
	clsPoint	pa[4] = { local,*heap };
	return	*heap;
}*/

void ftest(const initializer_list<string> &il)
{
	auto	itb = il.begin();
	while (itb!=il.end())
	{
		cout << *itb++ << endl;
	}
}

allocator<string> alloc2;
string* ftest2()
{
	auto pstr = alloc2.allocate(3);
	return	pstr;
}

string* ftest3()
{
	//auto pstr = new string("JULK");
	//string	s = "jk;jl";
	//auto pstr = &s;
	//return pstr;
	return	nullptr;
}
string	ftest4()
{
	string s = "jj";
	return s;
}

int	ftest5()
{
	int i = 50;
	return i;
	//return 55;
}

int ftest6(int i)
{
	return i;
}

vector<int> ftest7(int i)
{
	vector<int>	v{ i * 1,i * 2,i * 3,i * 4 };
	return v;
}
void ftest8(int i, vector<int> *pv)
{
	pv->push_back(i * 1);
	pv->push_back(i * 2);
	pv->push_back(i * 3);
	pv->push_back(i * 4);
}

int ftest9(int &&rri)
{
	return rri;
}

//void testpt(clsTest10 obj)	//动态必须是引用或者指针 才能实现 
void testpt(clsTest10 &obj)
{
	obj.pt();
}

int tmpfun1(int i)
{
	if (i == 3)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void tmppt(int(&r)[3])
{
	for (auto c : r)
	{
		cout << c << endl;
	}
}

extern	template class clstmp4<string>; //如果没写这个，则会在此cpp中生成clstmp4<string>的单独模板实例

template<typename T>
class clstmp7
{
public:
	clstmp7(T i){}
	clstmp7(T i,const string s){}
	void pt() { cout << "class clstmp7" << endl; }
protected:
private:
	int i;
};

class clstmp8
{
public:
	void pt() { cout << "clstmp8" << endl; }
protected:
private:
	clstmp7<int>	*p2;
};

template<typename T>
void fref(const T &r1, const T &r2)
{
}
template<typename T>
void fun2(T,T)
{}

template<typename T>
void fun3(const T &r1, const T &r2)
{}

template<typename T>
void fun4(const T*, const T*)
{
	T k = 20;
	cout << k << endl;
}

template<typename T>
void fun5(T &r1, T &r2)
{}

template<typename T>
void fun6(T*, T*)
{}

template<typename T1,typename T2,typename T3>
//T3 fun7(T1, T2)	//函数形参没有T3，所以无法推断出T3的模板参数类型，只 能显示指定<>，但是<>显示指定时顺序是
	//一一对应的，<T1,T2,T3> 所以要想显示指定 T3，就必须把T1,T2都写出来，多此一举
T1	fun7(T2,T3)	//调用时只需要 fun7<int>(double,float); T1是int T2是double T3是float
{
	return T1();
	//return T3();
}

template<typename T>
auto fun8(T itb, T ite)->decltype(*beg + 0)
{

}

template<typename T>
void funTemplate1(T &&val)
//void funTemplate1(T &val)
//void funTemplate1(T val)
//void funTemplate1(const T& val)
{

}

int funtmp3()
{
	int a = 20;
	return a;
}

void funtmp4(int &&v1, int &v2)
{
	int k = v1 + v2;
	cout << "k=" << k << endl;
}
template<typename F,typename T1,typename T2>
//void flip(F f, T1 t1, T2 t2)
void flip(F f,T1 &&t1,T2 &&t2)
{
	f(std::forward<T1>(t1), std::forward<T2>(t2));
	//f(std::move(t1), std::forward<T2>(t2));
}



int main(int argc, char *argv[])
{
	string s = "kkk";
	tuple<int, double, string, const char*> t1(1, 2.3, s, "zzz");

	//tuple<int, double, string,const char*> t1(1, 2.3, string("kkk"),"zzz");
	tuple<int, double, string,const char*> t2{ 1,2.2,string("bbb"),"joke" };
	get<0>(t1) = 77;
	cout << ":" << get<0>(t1) << endl;

	get<2>(t1) = string("fuck");
	cout << ":" << get<2>(t1) << endl;
	//auto k4 = get<2>(t1);
	//k4 = string("fuck");
	//cout << "k4=" << get<2>(t1) << endl;

	auto k1 = get<0>(t1);
	k1 = 20;
	cout << "k1=" << get<0>(t1) << endl;
	//auto k = get<3>(t1);
	auto k2 = get<3>(t1);
	//cout << k2 << endl;
	k2 = "jj";
	auto k3 = get<3>(t1);
	cout << "k3=" << k3 << endl;
	tuple_element<3, tuple<int, double, string, const char*>>::type k = "kk";
	
	if (t1 < t2)
	{
		cout << "<" << endl;
	}
	else
		cout << ">" << endl;

	/*
	vector<int>	vecInt{ 1,2,3,4,5,6,7,8,9,10,11,12,4,3,10,10 };
	vector<double>	vecDbl{ 1.11,2.22,3.33,4.44,5.55,7.77,2.22,4.44,8.88 };
	vector<string>	vecStr{ "aa","bb","cc","dd","aa","cc","dd","dd" };
	vector<const char*> vecChr{ "h1","h2","h3","h2","h3","h1","h1" };

	auto cnt2 = funTemplate5(vecDbl, 4.44);
	cout << cnt2 << endl;

	auto cnt4 = funTemplate5(vecChr, "h1");
	cout << cnt4 << endl;
	
	auto cnt = funTemplate5(vecInt, 10);
	cout << cnt << endl;
	//string	s = "dd";
	//auto cnt3 = funTemplate5(vecStr, s);
	//auto cnt3 = funTemplate5(vecStr, "dd");//error
	auto cnt3 = funTemplate5(vecStr, string("dd"));
	cout << cnt3 << endl;

	

	/*
	funTemplate4("apple", "pig");

	/*
	funTemplate3( cout,1, 2, 3, 4, 5);

	/*
	int i = 77;
	double d = 3.14;
	string	s = "pig";
	//funTemplate2(20, i, d);
	funTemplate2(i,d,s,"14",9,8);


	/*
	int i = 10, j = 20;
	//funtmp4(i, j);
	//flip(funtmp4, i, j);
	flip(funtmp4, 20, j);
	//funtmp4(20, i);
	/*
	int i = 70;
	int *pi = &i;
	int &&rri = 20;
	int &&rri2 = funtmp3();
	int &&rri3 = static_cast<int&&>(i);
	//int &&rri4 = *pi;//error
	int &&rri4 = std::move(*pi);
	cout << "rri2:" << rri2 << endl;
	cout << "rri3:" << rri3 << endl;
	int j = rri;
	int j2 = std::move(88);
	//int &rj2 = std::move(90);//error
	int &rj = rri;
	//int &rj = std::move(70);//error
	cout << j << endl;
	cout << rj << endl;

	/*
	int i = 20;
	int &&rri = static_cast<int&&>(i);
	cout << rri << endl;
	cout << i*2 << endl;

	/*
	int i = 20;
	const	int ci = 40;
	//funTemplate1(std::move(77));
	funTemplate1(77);
	funTemplate1(i);
	funTemplate1(ci);
	funTemplate1(i*ci);
	funTemplate1(i = ci);


	/*
	vector<int> vecInt{ 1,2,3 };
	using ty_k = typename remove_reference<decltype(*vecInt.begin())>::type;

	/*
	vector<int> vecInt{ 1,2,3 };
	auto k = vecInt.begin();
	cout << *k << endl;
	*k = 77;
	for (auto c:vecInt)
	{
		cout << c << endl;
	}

	/*
	//auto k = max(20, 30);
	auto k = max(20.7, 20);
	//auto k = max<double>(20.7, 20);
	cout << k << endl;
	/*

	fref("aa", "bb");
	char c='z';
	fun2(c, 'd');
	int i = 22, j = 44;
	const int ci = 99;
	int *p = &i;
	const int *cp1 = &i, *cp2 = &j;
	fun2(cp1, cp2);

	const	int *cp3 = &i;
	int const*cp4 = &j;//同上
	int *const cp5 = &j;
	*cp5 = 99;
	//*cp3 = 33;//e
	//*cp4 = 80;//e
	fref(i, ci);
	//fref(p, cp1);//error
	fun2(i, ci);
	fun3(i,ci);
	fun4(p, cp1);
	//fun5(i, ci);//error
	fun5<const int>(i, ci);
	//fun5(p, cp1);
	//fun6(p, cp1);
	fun6<const int>(p, cp1);

	fun6(p, cp5);

	//fun2(2, 'd');//error
	/*
	int a1[3]{ 1,2,3 }, a2[3]{ 3,4,6 };
	fref(a1, a2);	//数组相同维数就可以顺利转换成T引用，除非只能使用指针 int *p; 

	/*
	clstmp8	*p = &clstmp8();
	p->pt();

	/*
	clsTmp6	ct;
	//clsMyshared_ptr<clsTmp6>	cmsp(new clsTmp6(ct));
	//cmsp.pt();
	cout << "kkk" << endl;

	/*
	clstmp7<int> ct(2);
	clstmp7<int> ct2(2,"kkk");
	ct.pt();
	ct2.pt();



	/*
	clsMyunique_ptr<int>	up(new int(22));//error
	up.myreset();
	cout << "kkk" << endl;
	/*
	clsTmp6	ct,ct2;
	clsMyunique_ptr<clsTmp6, clsDeleteTest1>	myup(new clsTmp6(ct), clsDeleteTest1());
	myup.myreset(ct2);
	//myup.myreset();
	cout << "kkkk" << endl;

	/*
	clsTmp6	ct;
	clsDeleteTest1 *p = &clsDeleteTest1();
	(*p)(new clsTmp6(ct));

	//shared_ptr<clsTmp6>	spcls(new clsTmp6(ct), clsDeleteTest1());

	//clsMyshared_ptr<clsTmp6>	cmsp(new clsTmp6(ct),&clsDeleteTest1());
	//clsTmp6 *p = new clsTmp6(ct);

	//clstmp7		ct;
	//clstmp7	*pf = &clstmp7();
	//pf->pt();

	

	/*
	clsTmp6	ct,*p;
	p = new clsTmp6(ct);
	delete p;
	cout << "kkk" << endl;

	/*
	clsMyshared_ptr<int>	cmsp(new int(22)),cmsp2(new int(33));
	clsMyshared_ptr<int>	cmsp3(cmsp);
	{
		clsMyshared_ptr<double> cmsp4(new double(3.14)); 
		cmsp4.pt();
	}
	cmsp3.pt();
	cmsp = cmsp2;
	cmsp.pt();
	cmsp2.pt();
	cmsp3.pt();


	//cout <<cmsp << endl;
	//cout <<"Address &cmsp "<<&cmsp << endl;

	/*
	clsTmp5	ct;
	cout << ct << endl;

	/*
	clsTmp5	&r = ct;
	cout << &ct << endl;
	cout << &r << endl;


	//clsTmp5	ct;
	//ct.pt();
	//cout << ct << endl;

	/*

	clsTmp5	ct,ct2;
	//clsTmp5	*pcls = new clsTmp5(ct);
	//delete	pcls;
	shared_ptr<clsTmp5>	spInt(new clsTmp5(ct));
	spInt.reset(new clsTmp5(ct2), clsDeleteTest1());

	//shared_ptr<clsTmp5>	spInt = make_shared<clsTmp5>(ct);

	/*
	shared_ptr<int>	spInt(new int(33),clsDeleteTest1());
	cout << spInt << endl;
	

	/*
	funTemplateCls2();
	clstmp4<double>	ct;
	ct.pt();
	clstmp4<string>	ctStr;
	clstmp4<string>	ctStr2;
	clstmp4<string>	ctStr3;
	clstmp4<string>	ctStr4;
	clstmp4<string>	ctStr5;
	clstmp4<string>	ctStr6;
	clstmp4<string>	ctStr7;
	clstmp4<string>	ctStr8;
	
	ctStr.pt();

	/*
	shared_ptr<int>	spInt(new int, clsDebugDelete());
	unique_ptr<int, clsDebugDelete>	upInt(new int, clsDebugDelete());

	/*
	int *pnew = new int(22);
	cout << *pnew << endl;
	clsDebugDelete	cdd;
	cdd(pnew);


	/*
	vector<string>	vecStr{ "aa","bb","cc" };
	auto itb = begin(vecStr);
	auto ite = end(vecStr);
	auto it = itb;
	for (it;it!=ite;++it)
	{
		cout << *it << endl;
	}

	//for_each(begin(vecStr), end(vecStr), [](auto c) {cout << c << endl; });
	//for_each(vecStr.begin(),vecStr.end(), [](auto c) {cout << c << endl; });
	for (auto c:vecStr)
	{
		cout << c << endl;
	}

	/*
	vector<string>	vecStr{ "aa","bb","cc" };
	vector<int>		vecI{ 1,2,3,4,5,6 };
	//list<double>	lstD{ 1.11,2.22,3.33 };
	//funConTmp(vecStr);
	//funConTmp(vecI);
	//funConTmp(lstD);

	funConTmp2(vecStr);
	funConTmp2(vecI);


	/*
	vector<int>	veci{ 1,2,3,4,5,6 };
	vector<string>::size_type k=veci.size();

	//auto k = veci.size();
	cout << k << endl;


	/*

	clsTmp3	ct(20), ct2(30);
	auto k = funtmp1;
	auto k2 = k(ct, ct2);	//指向函数的指针调用用 k和*k是一样的，下面的k和*k地址是一样的
	cout << "k=" << k << " *k=" << *k << endl;
	cout<<" k2="<< k2 << endl;

	/*

	clsTmp3	ct(20), ct2(30);
	//auto k=myTemplateComp<clsTmp3> (ct, ct2);//用的就是默认实参 less<T> 

	auto k=myTemplateComp<clsTmp3> (ct, ct2,funtmp1);
	cout << k << endl;
	/*

	clsList<int>	cl, cl2, cl3;
	clsListItem<int>	clii;
	clsListItem<double>	clid;
	cl.into(&clii, 20);
	clii.pt();
	clid.pt();
	/*

	clsList<int>	cl, cl2, cl3;
	clsListItem<int>	clii;
	clsListItem<double>	clid;
	cl.into(clii, 20);
	clii.pt();
	cl2.into(clii, 21);
	clii.pt();
	cl3.into(clii, 23);
	clii.pt();
	cout << "==========" << endl;
	
	clid.pt();
	/*

	clsTemplateTest2<int>	ctti(70);
	ctti.setsi(100);
	clsTemplateTest2<int>	ctti2(71);
	clsTemplateTest2<int>	ctti3(72);

	clsTemplateTest2<double> cttd(3.14);
	cttd.setsi(999);

	clsTemplateTest2<string> cttstr("kkk");
	clsTemplateTest2<string> cttstr2("JJJ");

	ctti.pt();
	ctti2.pt();
	ctti3.pt();

	cttd.pt();

	cttstr.pt();
	cttstr2.pt();

	/*
	clstmp2	ct(77);
	ct.ptval();

	/*

	pair<int, int> p1(2, 3);
	cout << p1.first << " " << p1.second << endl;

	vt<int> v1(2, 3);
	cout << v1.first << " " << v1.second << endl;

	/*
	clsTemplateTest1<int>	ctt(222);
	clsTemplateFriend2<int>	ctfi;
	ctfi.pt();

	/*

	clsTemplateTest1<int>	ctt(222);
	clsTemplateTest1<char>	ctt2('K');
	clsTemplateFriend2<int>	ctfi;
	clsTemplateFriend2<double> ctfd;
	clsTemplateFriend3<char> ctfc;
	//ctfc.ptval(ctt2);
	//ctfd.ptval(ctt);
	ctfi.pt();
	ctfd.pt();
	//ctfi.pt(ctt);

	/*
	//clsTemplateTest1<clsTmp1>	ctt(ct1);
	clsTemplateTest1<int>	ctt2(77);
	//clsTemplateTest1<double>	ctt3(3.14);

	clsTemplateFriend1	ctf(22);
	ctf.pt();

	//ct1.pt(ctt3);	//暂时没法实现clsTemplateTest1<T>任意类型下，作为其的友元class clsTmp1的成员函数
	//都可以访问clsTemplateTest1<T>下的私有数据 

	//ctt3.pt();
	//ctt.pt();
	//ctt2.pt();
	//cout << ctt << endl;
	//ctt.pt();

	/*
	clsTemplateTest1<int>	ctt(200);
	//ctt.pt();
	clsTmp1	ct;
	clsTemplateTest1<clsTmp1>	ctt2(ct);
	ctt2.pt();

	/*
	vector<string>	vecStr{ "aa","bb","cc" };
	shared_ptr<vector<string>>	spVec;
	spVec = make_shared<vector<string>>(vecStr);
	auto k = spVec->back();
	cout << k << endl;

	/*

	int arri[10]{ 1,2,3,4 };
	auto arrlen = reArrSize(arri);
	cout << arrlen << endl;

	/*
	int arri[4]{ 1,2,3,4 };
	auto *parr = &arri;
	//auto arrlen = end(arri) - begin(arri);
	auto arrlen = end(*parr) - begin(*parr);
	cout << "arrlen=" << arrlen << endl;

	vector<int>	veci;
	veci.insert(veci.begin(), { 1,2,3 });
	//transform(begin(arri), end(arri),back_inserter(veci), [](auto c) {return c; });
	//copy(begin(arri), end(arri), back_inserter(veci));
	//copy(begin(arri), end(arri),veci.begin());	//error
	cout << veci.size() << endl;
	for (auto c:veci)
	{
		cout << c << endl;
	}
	

	/*
	int arri[3]{ 1,2,3 };
	int(&rarr)[3] = arri;
	auto k1 = rarr;
	auto k2 = &rarr;
	//cout << rarr << endl;
	//cout << &rarr << endl;

	/*
	int i = 3;
	int &ri = i;
	cout << &ri << endl;

	/*
	
	int arri[3]{ 1,2,3 };
	string	arrstr[5]{ "aa","bb","cc","dd","ee" };
	//auto itb = mybeg(arri);
	//auto ite = myend(arri);
	auto itb = mybeg(arrstr);
	auto ite = myend(arrstr);
	auto it = itb;
	while (it!=ite)
	{
		cout << *it << endl;
		++it;

	}
	//template_pt(arrstr);
	//begin(arri);
	//tmppt(arri);

	/*

	vector<int>	vec_i{ 1,2,3,4,5 };
	list<int>	lst_i{ 1,2,3,4,5 };
	int	arri[5]{ 1,2,3,4,5 };
	//auto k = find(lst_i.begin(),lst_i.end(), 3);
	int i = 3;
	//auto k = myfind(vec_i.begin(), vec_i.end(), 5);
	//auto k = myfind(lst_i.begin(),lst_i.end(), 5);
	//auto k = myfind(begin(arri), end(arri), 5);
	//cout << k << endl;




	/*

	vector<int>	vec_i{ 1,2,3,4,5 };

	auto k = for_each(vec_i.begin(), vec_i.end(), tmpfun1);
	auto p1 = k(3);
	cout << p1 << endl;

	/*
	vector<int>	vec_i{ 1,2,3,4,5 };
	auto k = find(vec_i.begin(), vec_i.end(), 3);
	cout << k - vec_i.begin() << endl;


	/*

	clsTest18	ct1(10), ct2(30);
	auto k = temp_mycomp(ct1, ct2);
	if (k == 1)
	{
	cout << "<" << endl;
	}
	else if (k == -1)
	{
	cout << ">" << endl;
	}
	else
	{
	cout << "=" << endl;
	}

	/*
	clsTest16		ct(20, "aaa");
	clsSubTest16	csubt(30, "jjj", 70);
	vector<shared_ptr<clsTest16>>	vecClsT16;
	vecClsT16.push_back(make_shared<clsTest16>(ct));
	vecClsT16.push_back(make_shared<clsSubTest16>(csubt));
	//vecClsT16.back()->pt();
	vecClsT16.front()->pt();


	/*

	//clsSubTest15	csubt;
	//clsSubTest15	csubt2(std::move(csubt));
	//clsSubTest15	csubt2(csubt);
	clsSubTest15	csubt3(20);

	/*
	clsTest14		ct;
	clsSubTest14	csubt;
	clsSubTest14	csubt2(csubt);
	//ct = csubt;

	/*

	//clsSubTest14	*p = new clsSubTest14;
	//delete p;
	clsTest14	*p1= new clsSubTest14;
	cout << "deleting..." << endl;
	delete	p1;

	cout << "after delete p1" << endl;
	/*

	//clsTest13		ct;
	clsSubTest13	csubt;
	csubt.f1(2);

	/*

	clsTest12		ct(20, "kk");
	clsSubProTest12	csubprot;
	clsSubPriTest12	csubprit;
	clsSubTest12	csubt;
	

	//csubprit.pt1();	//error
	//clsTest12	*pct1 = &csubprit;	//error
	//clsTest12	&rpct1 = csubprit;	//error

	//clsTest12	*pct2 = &csubprot;	//error
	//clsTest12	&rpct2 = csubprot;	//error

	//csubprot.pt1();	//protected 访问限制符继承的类用记csubprot不能访问基类的所有成员及成员函数

	//csubprit.pt3();
	csubt.pt1();
	/*
	clsSubTest12	csubt;
	clsTest12	*pct3 = &csubt;

	/*
	clsSubTest12	csubt;
	csubt.pt();

	/*

	clsBase		bobj;
	clsDerived	dobj;
	clsBase	*pb = &bobj;
	clsBase	*pd = &dobj;
	clsBase	&rpb = bobj;
	clsBase &rpd = dobj;

	//bobj.pt(cout);
	//dobj.pt(cout);
	pd->name();
	/*
	clsBase	cb;
	cb.pt(cout);
	clsDerived	cd;
	cd.pt(cout);


	/*

	//clsTest11		ct;
	clsSubTest11	csubt;
	//ct.debug();
	csubt.debug();

	/*
	clsTest10		ct;
	clsSubTest10	cst;
	clsTest10		&rct = cst;
	//rct.tt();
	//testpt(cst);
	ct = cst;
	//ct.tt();
	ct.pt();
	rct.pt();

	/*

	clsQuote		cq("hz-001", 20);
	clsBulk_Quote	cbq("hz-001",10);
	//auto	netPrice = cbq.net_price(2);
	clsQuote	&rcq = cq;
	cout << rcq.net_price(10) << endl;

	cq = cbq;
	cout << cq.net_price(10) << endl;
	
	rcq = cbq;
	
	//auto *p = &cbq;
	//auto	*p = &cq;
	//auto netPrice = p->net_price(3);
	//auto netPrice = cbq.net_price(9);
	//auto netPrice = cbq.net_price(3);
	//cout << netPrice << endl;


	//auto price = cq.net_price();
	//cout << price << endl;

	/*

	clsTest9	ct9(20),ct92;
	std::move(ct92) = ct9;
	ct92.pt();

	/*
	//计算器

	clsAdd	iadd;
	//auto k1 = iadd(10, 20);
	//cout << k1 << endl;
	auto isub = [](int i, int j) {return i - j; };
	//auto k2 = isub(20, 5);
	//cout << k2 << endl;
	multiplies<int>	imul;
	//auto k3 = imul(7, 7);
	//cout << k3 << endl;

	map < string, function<int(int, int)>> map_StrFunction=
	{ {"+",iadd},{"-",isub},{"*",imul} };
	//cout << map_StrFunction["*"](2, 3) << endl;

	string	line;
	while (cin >> line)
	{
		//find_first_of(line.begin(),line.end(),)
		auto mark=line.find_first_of("+*-/");
		//cout << mark << endl;

		string	smark =string()+ line[mark];
		string	sLval = line.substr(0, mark);
		string	sRval = line.substr(line.find_first_of("0123456789",mark+1), line.size());
		int		iLval = stoi(sLval);
		int		iRval = stoi(sRval);

		int		kval = map_StrFunction[smark](iLval,iRval);
		cout << "=" << kval << endl;

		//cout << iLval+1 << " " << iRval << endl;

		//cout << Lval << endl;
		//cout << Rval << endl;
		//map_StrFunction[smark]
	}

	/*
	char	c = 'k';
	string	s = string() + c;
	cout << s << endl;
	/*

	vector<string>	vec_Str{ "aa","bb","cccccccc","ddd" };
	
	auto k = find_if(vec_Str.begin(), vec_Str.end(), clsSizeComp(5));
	cout << *k << endl;

	/*
	clsTest8	ct8;
	ct8();
	ct8.pt();
	/*
	clsTest7	ct7;
	ct7(5, 3, 7);

	/*
	clsAbs	a1;
	cout << a1(-20) << endl;
	cout << a1(30) << endl;


	/*
	clsOperatorTest2	ot{ "aa","bb","cc","dd" ,"ee" };
	cout << ot->size() << endl;

	/*
	clsOperatorTest2	ot{ "aa","bb","cc" };
	cout << ot->size() << endl;
	cout << *ot << endl;

	vector<string>	vecs{ "aa","bb","cc","dd" ,"ee"};
	cout << vecs.size() << endl;

	/*
	const clsOperatorTest2	ot({ "aa","bb","cc" });
	//ot[2] = "kk";
	cout << ot[2] << endl;

	/*
	clsOperatorTest2	ot({ "aa","bb","cc" });
	//cout << ot << endl;
	//cout << ot[2] << endl;
	ot[1] = "JK";
	cout << ot << endl;


	/*
	initializer_list<string> il{ "aa","bb","cc" };
	//cout << *il.begin() << endl;
	//vector<string>	vec_Str(il);
	vector<string>	vec_Str;
	copy(il.begin(), il.end(), back_inserter(vec_Str));
	for (auto c:vec_Str)
	{
		cout << c << " ";
	}
	cout << endl;

	/*
	clsOperatorTest	ot("dd", 1, 3.3);
	clsOperatorTest ot2("ff", 2, 4.4);
	//ot += ot2;
	//cout << ot << endl;

	clsOperatorTest	ot3;
	ot3 = ot + ot2;
	cout << ot3 << endl;

	/*
	int i = 30, k = 40;
	int v = (++i, ++k);
	cout << v << endl;
	cout << i << endl;

	/*

	int	i;
	cin >> i;
	
	if (cin.bad())
	{
		cout << "cin.bad" << endl;
	}
	if (cin.fail())
	{
		cout << "cin.fail" << endl;
	}
	cout << cin.rdstate() << endl;

	cin.clear();
	//fflush(stdin);	//no
	//cin.ignore(INT_MAX, '\n');
	//cin.sync();	//no
	//_flushall();	//no
	//while (cin.get()!='\n')	continue;
	int j;
	cin >> j;
	cout <<"j:"<< j << endl;

	/*
	clsStrVec	sv1{ "aa","bb","cc" };
	cout << sv1;
	int i = 3;
	cout << i << endl;

	/*
	string	s = "word";
	auto k=operator+("hi", s);
	cout << k << endl;

	/*
	
	clsStrVec	sv1;
	clsStrVec	sv2(std::move(sv1));

	clsStrVec	sv3{ "aa","bb","cc" };
	//clsStrVec	sv4(sv3);	//no definies copy constructions
	

	/*
	{
		clsStrVec	sv1;
		clsStrVec	sv2(std::move(sv1));
		cout << "sv3:" << endl;
		sv2.pt();
		clsStrVec	sv3{ "aa","bb","cc" };
		clsStrVec	sv4{ "jj","kk","tt" };
		sv3 = std::move(sv4);
		cout << "sv3:" << endl;
		sv3.pt();
		cout << "sv4:" << endl;
		sv4.pt();
	}

	/*
	clsStrVec	sv1;
	sv1 = std::move(sv1);
	sv1.pt();
	

	/*
	vector<string>	vec_Str;
	vec_Str.push_back("kkk");
	vec_Str.push_back("kkk2");
	vec_Str.push_back("kkk3");
	vec_Str.push_back("kkk4");


	/*

	int arr[3]{ 1,2,3 };
	int &&rri = arr[1] * ftest6(3);
	cout << rri << endl;

	/*
	int &&rri = 30;;
	rri = 2;
	//int &ri2 = rri;
	//ri2 = 2;

	cout << rri << endl;


	/*
	int arr[3]{ 1,2,3 };
	int &ri = arr[1];
	//int &&ri = arr[1];	//error
	cout << ri << endl;
	//int &ri = ftest6(99); //error


	/*

	//bool &&rri = 20 > 1;
	//int &&rri = 20 +3;
	int i = 2;
	int &&rri = i++;
	//int &&rri = ++i;
	cout << rri << endl;

	/*
	//auto k = ftest9(99);
	//int	&&k = ftest9(99);
	//int *p = &(ftest9(99));	//error
	cout << k << endl;

	/*
	auto k = ftest7(2);
	for (auto c : k)
	{
		cout << c << endl;
	}

	/*
	vector<int>	k;
	ftest8(2, &k);
	for (auto c:k)
	{
		cout << c << endl;
	}

	/*

	/*
	int &&rri = 30;
	int ki = rri;
	ki = 40;
	cout << rri << endl;

	cout << ftest6(rri) << endl;

	/*
	//int k = ftest6(20);
	int k=ftest6(std::move(20));
	cout << k << endl;

	/*
	int &&rri = 30;
	int *p = &rri;
	cout << *p << endl;
	
	/*
	
	int i = 30;
	auto p = &i;
	int &ri = i;
	*p = 40;
	cout << ri << endl;

	/*
	//int	&ri = ftest5();

	const int &ri1 = ftest5();
	auto ri = ftest5();
	int	&&rri = ftest5();
	cout << rri << endl;

	/*
	int i = 33;
	int i2 = 44;
	auto ps = &i;
	cout << ps << endl;
	auto ps2 = &i2;
	cout << ps2 << endl;


	/*
	int	i = 33;
	auto ps = &i;
	cout << ps << endl;

	auto i2 = std::move(i); //无法移动内置变量，因为没有移动构造函数
	auto ps2 = &i2;
	cout << ps2 << endl;

	cout << i2 << endl;
	cout << i << endl;
	/*
	string	s = "jowieurpoqiurlkvn";
	auto ps = &s;
	cout << ps << endl;
	auto s2 = std::move(s);	//指向了同一块内存块，改变了指向，而非拷贝  调用了string的移动构造函数
	auto ps2 = &s;
	cout << ps2 << endl;

	cout << s2 << endl;
	cout << s << endl;
	/*
	auto s = ftest4();
	cout << s << endl;
	/*
	auto pstr = ftest3();
	cout << *pstr << endl;
	//delete pstr;
	//pstr = nullptr;
	/*
	auto pstr = ftest2();
	alloc2.construct(pstr, "OK");
	cout << *pstr << endl;

	/*13.5
	clsStrVec	sv({ "aa","bb","cc","dd" });
	sv.f_push("JJ");
	sv.pt();
	/*
	clsStrVec	sv2;
	for (size_t i=0;i<10000;i++)
	{
		sv2.f_push("kk");
	}
	sv2.pt();

	/*
	allocator<int>	alloc;
	auto pb=alloc.allocate(5);
	auto pbtmp = pb;
	vector<int>	vecI{ 1,2,3 };
	auto p2=uninitialized_copy_n(vecI.begin(), vecI.size(), pb);
	alloc.construct(p2, 7);	//返回实际构造的最后一个元素之后的位置
	for (size_t i=0;i<5;i++)
	{
		cout <<*( pbtmp + i) << endl;
	}

	//ftest({ "aa","bb","cc" });

	/*
	size_t	szN = 3;
	allocator<string>	alloc;
	auto pBeg=alloc.allocate(szN);
	auto p = pBeg;	
	alloc.construct(p, "abcdef");
	p++;
	alloc.construct(p, "a2");
	p++;
	alloc.construct(p, "a3");
	p++;
	alloc.construct(p, "a4");
	
	for (size_t i=0;i<szN;++i)
	{
		cout << *(pBeg + i) << endl;
	}

	while (p!=pBeg)
	{
		alloc.destroy(p--);
	}
	alloc.deallocate(pBeg, szN);
	/*
	clsTest6	ct1("kkk");
	clsTest6	ct2("jjj");
	swap(ct1, ct2);
	ct1.pt();
	ct2.pt();

	/*
	clsTest5	ct("kk");
	clsTest5	ct2(ct);
		
	cout << string(20, '-') << endl;
	ct.pt();
	ct2.pt();

	cout << string(20, '-') << endl;
	clsTest5	ct3("luck");
	ct3.pt();
	ct3 = ct;
	ct3.pt();
	ct.pt();

	cout << string(20, '-') << endl;
	clsTest5	ct4("joke");
	ct4.pt();
	ct = ct4;
	ct.pt();
	ct4.pt();

	cout << string(20, '-') << endl;
	ct.pt();
	ct2.pt();
	ct3.pt();
	ct4.pt();

	

	/*
	clsTest4	ct;
	ct.pt();

	/*
	shared_ptr<string>	sp_Str(new string("kkk"));
	cout << *sp_Str << endl;
	
	/*
	clsTest3	ct1;
	clsTest3	ct2(ct1);
	
	ct1.pt();
	ct2.pt();
	cout << "================" << endl;
	ct2.setdata(7);
	ct1.pt();

	/*
	clsTest2	ct1;
	clsTest2	ct2(ct1);
	clsTest2	ct3;
	ct3 = ct1;

	/*
	clsEmployee	ep1("joke");
	
	clsEmployee	ep2("lucy");
	clsEmployee	ep3("mary");
	ep1.pt();
	ep2.pt();
	ep3.pt();


	/*
	clsDelete	de1;
	clsDelete	de2;
	clsDelete	de3 = de1;
	de3.pt();

	/*
	clsNumbered	nb1;
	clsNumbered	nb2;
	cout << "---------------------------" << endl;

	f(nb1);
	f(nb2);

	cout << "---------------------------" << endl;
	clsNumbered	nb3 = nb1, nb4 = nb3;
	clsNumbered nb5(nb3);
	cout << "---------------------------" << endl;

	f(nb3);
	f(nb4);
	f(nb5);
	cout << "---------------------------" << endl;
	clsNumbered	nb6;
	nb6 = nb1;
	f(nb6);

	/*
	ShardPtrHasPtr	sphp("kk");
	{
		ShardPtrHasPtr	sphp1(sphp);
		cout << "in" << endl;
	}
	sphp.pt();

	/*
	HasPtr	hp("kk");
	{
		HasPtr	hp1(hp);
		cout << "in" << endl;
	}
	hp.pt();

	/*

	HasPtr		hp("kk");	
	//HasPtr	hp1("bb");
	//HasPtr	hp2("cc");
	{
		//HasPtr *p1 = &hp1;
		//auto &rp = hp;
		//auto &rp = hp1;
		HasPtr	hp1(hp);	//error ，string p is invalid, hp1 delete *p;
		cout << "in" << endl;
	}
	cout << "++++++++++" << endl;
	int test=1;
	hp.pt();

	/*
	X	x1;
	X	x2;
	X	x3(x1);
	auto *p = new X(x1);
	x2 = x1;

	/*
	HasPtr	hp1("aa");
	HasPtr	hp2(hp1);
	hp2.pt();

	cout << "******************" << endl;
	/*
	clsPoint	arg;
	foo_bar(arg);

	/*
	
	clsTest1	ct1;
	clsTest1	ct2(ct1);
	ct2.pt();

	/*

	//string	str1 = "kkk";
	string	str2("kkk");
	

	/*
	
	fstream	fin("t2.txt", ios::in);
	//map<size_t, string>	map_SzStr;
	unordered_multimap<string,size_t>	unordMulMap_SzStr;
	//istream_iterator<string>	is_it(fin), is_End;
	//cout << *is_it << endl;
	//is_it++;
	//cout << *is_it << endl;
	
	string	strLine;
	size_t	sz = 1;
	while (getline(fin, strLine))
	{
		//unordMulMap_SzStr.insert(make_pair(strLine, sz));
		unordMulMap_SzStr.insert({strLine,sz});
		sz++;
	}
	auto map_SzStr = seachWord(unordMulMap_SzStr, "void");
	for (auto &c:map_SzStr)
	{
		cout << c.first << "-" << c.second << endl;
	}

	/*
	string	str( "abc");
	string	s;
	//transform(str.begin(), str.end(), s.begin(), [](auto c) {return toupper(c); });
	std::transform(str.begin(), str.end(), back_inserter(s),
	[](auto c) { return toupper(c); });
	cout << s << endl;

	
	/*
	unordered_multimap<string, int>	unordMulMap_StrInt;
	//unordered_multimap<string, int>	unordMulMap_StrInt{ {"aa",1},{"bb",2},{"cc",3} };


	vector<string>	vecStr{ "aa","bb","cc" };
	int i = 0;
	for (auto c : vecStr)
	{
		unordMulMap_StrInt.insert({ c,i++ });
		//unordMulMap_StrInt[c]=i++; //multi一对多的特性，所以不能用[]来赋值
	}
	/*
	for (auto c:unordMulMap_StrInt)
	{
	cout << c.first << "-" << c.second << endl;
	}

	/*

	vector<int>	vec_Int{ 1,2,3,4,5,6,7,8 };
	allocator<int>	aloc;
	auto	alocSize = vec_Int.size();
	auto	pAloc = aloc.allocate(alocSize);
	uninitialized_copy(vec_Int.begin(), vec_Int.end(), pAloc);
	//auto alocSize = aloc.max_size();
	//cout << alocSize << endl;
	//cout << *pAloc << endl;
	//pAloc++;
	//cout << *pAloc << endl;

	for (auto i=0;i<alocSize;++i)
	{
		cout << *(pAloc+i) << endl;
	}

	auto pTmp = pAloc + alocSize;
	while (pTmp !=pAloc)
	{
		aloc.destroy(--pTmp);
	}
	aloc.deallocate(pAloc, alocSize);
	
	/*
	
	size_t	n = 5;
	allocator<string>	alc;
	auto	p1 = alc.allocate(n);
	auto	p = p1;
	alc.construct(p1++, "abc");
	alc.construct(p1++, " !!#");
		
	size_t	sz_conts = p1 - p;
	for (size_t i=0;i<sz_conts;++i)
	{
		cout << *(p + i) << endl;
	}


	//for (size_t i=0;i<n;++i)	{		cout << *(p+i) << endl;	}
	alc.destroy(--p1);
	//while (p1!=p)	{		alc.destroy(--p1);	}

	cout << "--------------------------" << endl;
	alc.construct(p1++, "hello");
	alc.construct(p1++, "world");
	alc.construct(p1++, "friend");
	
	//
	alc.construct(p1++, "friend2");
	//alc.construct(p1++, "friend3");
	sz_conts = p1 - p;
	
	for (size_t i=0;i<sz_conts;++i)
	{
		cout << *(p+i) << endl;
	}

	//for (size_t i = 0; i < n; ++i)	{		cout << *(p + i) << endl;	}
	
	while (p1 != p)
	{
		alc.destroy(--p1);
	}
	alc.deallocate(p, sz_conts);

	cout << "************************" << endl;
	if (n > sz_conts)
	{
		p = p + (sz_conts - 1);
		alc.construct(p, "fuck");
		cout << *p << endl;
	}
	else
		cout << "full construct" << endl;
	//cout << *p << endl;	//竟然不报任何错误。

	//cout << "----------" << endl;
	//cout << *p << endl;

	/*
	unique_ptr<string>	up_Str;
	string	str;
	while (cin >> str)
	{
		up_Str.reset(new string(str));
		cout << *up_Str << endl;
		up_Str.release();
	}
	

	/*
	string	str1 = "aaaa";
	string	str2 = "bbb";
	string	str = str1 + str2;
	unique_ptr<string>	up_Str(new string(str));
	//unique_ptr<string>	up_Str;
	//up_Str.reset(new string(str));
	cout << *up_Str << endl;

	/*
	const char	*pArr1 = "aaaa";
	const char	*pArr2 = "bbb";
	auto strLen1 = strlen(pArr1);
	auto strLen2 = strlen(pArr2);
	string	str =string()+ *pArr1 + *pArr2;
	size_t strLen = strLen1 + strLen2;
	cout << strLen << endl;

	//unique_ptr<char[]>	up_CharArr(new char[strLen]);
	unique_ptr<char[]>	up_CharArr;
	up_CharArr.reset(new char[strLen]);
	for (auto i=0;i<strLen1;++i)
	{
		up_CharArr[i] = pArr1[i];
	}
	for (size_t i = 0,j=strLen1; i < strLen2; ++i,++j)
	{
		up_CharArr[j] = pArr2[i];
	}
	for (auto i=0;i<strLen;++i)
	{
		cout << up_CharArr[i] << " ";
	}
	cout << endl;
	up_CharArr.release();
	
	/*

	auto p1 = new int[10]();
	for (size_t i=0;i<10;++i)
	{
		cout << * (p1+i) << endl;
	}
	delete []p1;

	/*

	int ix = 1024, *pi = &ix, *pi2 = new int(1024);
	//typedef	unique_ptr<int>	uptr_Int;
	using	uptr_Int= unique_ptr<int>;
	//uptr_Int p0(pi);
	//uptr_Int p1(&ix);
	uptr_Int p2(pi2);
	uptr_Int p3(p2.get());

	//cout << *p0 << endl;

	/*

	unique_ptr<int>	up_Int(new int(33));
	//unique_ptr<int>	up2 = up_Int;
	unique_ptr<int>	up2(up_Int);

	/*
		
	unique_ptr<int>	up_Int(new int(33));
	//auto p1 = up_Int.release();
	//up_Int.reset(new int(44));
	//up_Int = nullptr;
	up_Int.reset(nullptr);
	cout << *up_Int << endl;

	/*
	shared_ptr<int>	sp_Int(new int(33));
	auto p1 = sp_Int;
	sp_Int.reset(new int(44));
	cout << p1.use_count() << endl;


	/*

	auto p1 = make_shared<int>(77);
	//auto p2 = p1.get();
	auto p2 = p1;
	p2.reset(new int(88));
	auto p3 = p2;
	auto p4 = p3.get();
	cout << p2.use_count() << endl;
	delete	p4;

	/*

	shared_ptr<int>	sp_Int(new int(44));
	//processTest1(shared_ptr<int>(sp_Int.get()));
	//processTest1(shared_ptr<int>(sp_Int));
	//processTest1(new int());	//error
	auto pv = new int(88);
	shared_ptr<int> p3(pv);
	cout << p3.use_count() << endl;
	//shared_ptr<int> p3(sp_Int);
	cout << *p3 << endl;
	/*

	auto p1 = sp_Int;
	//auto p2 = sp_Int;
	auto p2 = p1;
	cout << sp_Int.use_count() << endl;
	p2.reset(new int(77));
	cout << sp_Int.use_count() << endl;
	cout << p2.use_count() << endl;


	/*
	cout << sp_Int.use_count() << endl;

	//processTest1(sp_Int);
	processTest1(shared_ptr<int>(sp_Int));
	cout << sp_Int.use_count() << endl;


	cout << *sp_Int << endl;

	/*
	//auto p1 = sp_Int;
	auto p2 = sp_Int;
	cout << sp_Int << endl;
	cout << p2 << endl;

	
	if (!sp_Int.unique())
	{
		cout << "no unique" << endl;
		//sp_Int.reset(new int(*sp_Int));
		p2.reset(new int(*p2));
	}
	else
		cout << "unique" << endl;

	cout << sp_Int << endl;
	cout << p2 << endl;


	/*
	cout << "after reset:" << endl;
	if (!sp_Int.unique())
	{
		cout << "no unique" << endl;
	}
	else
		cout << "unique" << endl;

	*sp_Int = 77;
	cout << *sp_Int << endl;
	
	//cout << *p1 << endl;
	cout << *p2 << endl;

	/*
	cout << *sp_Int << endl;
	cout << sp_Int << endl;
	sp_Int.reset();
	cout << sp_Int << endl;

	/*

	auto p1 = new int(20);
	auto p2 = p1;
	delete p1;
	p1 = nullptr;
	cout << p2 << " " << p1 << endl;

	/*
	int i = 77;
	void *ppi;
	//int	 *pi;
	ppi =&i;
	auto pk2 = ppi;
	decltype(ppi) pk3;
	//pi = &i;
	//cout << *pi << endl;
	cout << *((int*)ppi) << endl;
	//auto pk=static_cast<int*>(ppi);
	//cout << *(static_cast<int*>(ppi)) << endl;
	//cout << *pk << endl;

	/*

	int pi = 20;
	void	*ppi=nullptr;
	auto pd = new string("kk");
	//ppi = pd;
	//delete ppi;
	delete pd;
	pd = nullptr;
	cout << ppi << " " << pd << endl;
	//delete pi;	//error
	int i = 44;
	//pd = &i;
	ppi = &i;
	//cout << "*ppi:" << *ppi << endl;	//error
	/*
	string s1 = "ab";
	pd = &s1;
	cout << "*pd:" << *pd << endl;


	auto p = new int(20);
	auto p2 = new vector<string>{ "aa","bb","cc" };
	for (auto c:*p2)
	{
		cout << c << endl;
	}
	
	auto p3 = new const int(40);
	auto p4 = new (nothrow) int(77);

	/*

	//vector<string> *pvecStr;
	shared_ptr<vector<string>> sp_vecStr;
	{
		vector<string>	vecStr2{ "aa","bb","cc" };
		cout << "address of vecStr2:" << &vecStr2 << endl;
		//pvecStr = &vecStr2;
		//cout << "address of pvecStr:" << pvecStr << endl;

		sp_vecStr = make_shared<vector<string>>(vecStr2);
		//sp_vecStr = { "aa","kk" };
		cout << "address of sp_vecStr:" << sp_vecStr << endl;
		vecStr2.push_back("joke");
	}
	//cout << (*pvecStr)[0] << endl;
	//cout << (*sp_vecStr)[0] << endl;
	for (auto c:*sp_vecStr)
	//for (auto c : *pvecStr)
	{
		cout << c << endl;
	}


	/*
	
	vector<string>	vec_Str1;
	{
		vector<string>	vecStr2{ "aa","bb","cc" };
		vec_Str1 = vecStr2;
	}
	for (auto c:vec_Str1)
	{
		cout << c << endl;
	}

	/*

	clsShardPtrTest	cspt1;
	{
		clsShardPtrTest	cspt2({1,2,3,4,5});
		cspt1 = cspt2;
		cout << "in fun:";
		cspt1.pt();
	}
	cout << "out fun:";
	cspt1.pt();

	/*
	//000000729f2ff6c4
	
	string	s="000000729f2ff6c4";
	size_t	sz;
	unsigned long long val=stoi(s, &sz, 16);
	cout << sz << endl;
	cout <<"val="<< val << endl;
	//printf("%x\n", val);
	//cout << stoi(s, 0, 16) << endl;

	/*
	int	i = 20;
	//int *p=nullptr;

	int	*p = &i;
	if (p)
	{
		cout << "point something" << endl;
		cout << p << endl;
	}
	else
		cout << "nothing poing" << endl;

	string	strAddr;
	cin >> strAddr;
	cout << "strAddr:" << strAddr << endl;
	LONG64 val = stoi(strAddr, 0, 16);
	cout << val << endl;
	//string strAddr = to_string(&i);
	//cout<<"stoi:"<<stoi()

	

	
	/*
	unordered_map<string, size_t>	unordMap_StrSzt;
	string	strWord;
	while (cin>>strWord)
	{
		if (strWord=="end")	break;
		unordMap_StrSzt.insert( {strWord,++unordMap_StrSzt[strWord] });
		//unordMap_StrSzt[strWord]++;

	}
	for (auto c:unordMap_StrSzt)
	{
		cout << c.first << "-" << c.second << endl;
	}

	/*

	unordered_map<string, int>
		unordMap_StrInt{ { "b1",20 },{ "a2",50 },{ "a3",820 },{ "a1",24 },{ "a2",20 } };
	for (auto c:unordMap_StrInt)
	{
		cout << c.first << "-" << c.second << endl;
	}

	cout <<"max_bucket_count:"<< unordMap_StrInt.max_bucket_count()<<endl;
	auto ff = unordMap_StrInt.load_factor();
	cout << "load_factor:" << ff << endl;

	auto ff_max = unordMap_StrInt.max_load_factor();
	cout << "max_load_factor:" << ff_max << endl;

	for (size_t i=0;i<20;++i)
	{
		cout <<i<<"bucket:"<< unordMap_StrInt.bucket_size(i) << endl;
	}

	auto k1 = unordMap_StrInt.bucket("a1");
	cout <<"elem <a1> in bucket:"<< k1 << endl;
	auto k2 = unordMap_StrInt.bucket("a2");
	cout << "elem <a2> in bucket:" << k2 << endl;
	auto k3 = unordMap_StrInt.bucket("a3");
	cout << "elem <a3> in bucket:" << k3 << endl;
	auto k4 = unordMap_StrInt.bucket("b1");
	cout << "elem <b1> in bucket:" << k4 << endl;

	/*
	map<string, int>	map_StrInt{ {"a1",20},{ "a2",50 },{ "a3",820 } };
	string	strKey = "a1";
	//map_StrInt[strKey] = 40;
	map_StrInt.insert({ "a1",70 });

	for (auto c:map_StrInt)
	{
		cout << c.first << "-" << c.second << endl;
	}



	/*
	string	str = "abc";
	auto str2 = str.substr(1);
	cout << str2 << endl;
	

	/*
	//11.3.6 练习11.33
	//input string
		//get string form cin

	string inputLine;
	cout << ">";
	getline(cin, inputLine);
	istringstream	iss(inputLine);

	//translate
	//ostringstream	oss(outfile);
	
	ostringstream	oss;
	while (!iss.eof())
	{
		string strWord;
		iss >> strWord;
		auto newStr=translateFun(strWord);
		oss << newStr<<" ";
	}

	//output file
	fstream	fout("crackfile.txt", ios::out);
	fout << oss.str();
	fout.close();
	




	/*

	multimap<string, int>	mmap_StrInt{ {"a1",20},{"b1",20},{"a1",70},{"a1",40} };
	//multimap<string, int>::iterator	it = mmap_StrInt.find("a1");
	//mmap_StrInt::iterator	it = mmap_StrInt.find("a1");	//类名/结构后面才能有 :: (对象后面跟::不合法)
	auto	it = mmap_StrInt.find("a1");
	cout << it->first << "-" << it->second << endl;

	/*
	multimap<string, int>	mmap_StrInt{ {"a1",20},{"b1",20},{"a1",70},{"a1",40} };
	for (auto c:mmap_StrInt)
	{
		cout << c.first<<"-"<<c.second << endl;
	}
	cout << ".........." << endl;

	auto pairV = mmap_StrInt.equal_range("a1");
	for (auto i=pairV.first;i!=pairV.second;++i)
	{
		cout << i->first<<"-"<<i->second << endl;
	}

	/*
	std::vector<int> v{ 3, 1, 4,7,11,99,234 };

	auto vi = v.begin();

	std::advance(vi, 4);

	std::cout << *vi << '\n';

	/*
	cout << upper_bound(begin(seq1), end(seq1), 3) - begin(seq1) << endl;
	cout << lower_bound(begin(seq1), end(seq1), 3) - begin(seq1) << endl;
	
	/*
	//vector<string, int>	vec_StrInt;
	vector<string>	vec_StrInt;
	vec_StrInt.push_back( "abc");
	for (auto c:vec_StrInt)
	{
		cout << c << endl;
	}

	/*
	map<string, int>	map_StrInt;
	//auto k = map_StrInt["kk"];
	//map_StrInt::mapped_type	k2 = map_StrInt["kk"];
	map<string, int>::mapped_type k3 = map_StrInt["kk"];
	/*
	vector<string>	vec_Str;
	//vec_Str[0] = "kk";	//编译通过，运行时出错 
	for (auto c:vec_Str)
	{
		cout << c << endl;
	}


	/*
	//map<int, string>	const map_IntStr;
	map<int, string>	map_IntStr;
	map_IntStr[1] = "kkk";

	for (auto c : map_IntStr)
	{
		cout << c.first << "-" << c.second << endl;
	}

	auto v = map_IntStr.at(1);
	cout << v << endl;
	/*
	map<int, string>	map_IntStr;
	//auto map_it = map_IntStr.begin();
	//*map_it = make_pair(20, "klj");	//no map_it::key_value is const

	//auto p=pair<int, string>({ 20,"kkk" });
	//*map_it = p;

	//auto iter = inserter(map_IntStr, map_it);

	//auto pair1=map_IntStr.insert(make_pair( 20,"jjj" ));
	//auto pair1 = map_IntStr.insert({20,"jjj"});

	auto pair3 = map_IntStr.insert({ 30,"fff" });
	if (!pair3.second)
	{
		cout << "insert is error" << endl;
	}
	else
		cout << "insert success" << endl;
	//auto pair2 = map_IntStr.emplace(make_pair(30, "hello"));
	//auto pair2 = map_IntStr.emplace({30,"hello"});	//fail

	auto pair2 = map_IntStr.emplace(pair<int,string>{ 20,"hello" });

	//pair2.first->second = "j8";
	auto map_it = map_IntStr.begin();
	//map_it->first = 3;	// no map::key_value is const
	//map_it->second = "fuck";

	//++map_it;
	map_IntStr.insert(map_it, { 2,"luck" });
	if (pair2.second)
	{
		pair2.first->second = "log";
	}

	for (auto c:map_IntStr)
	{
		cout << c.first << "-" << c.second << endl;
	}

	/*
	multiset<string>	mset_str;
	multiset<string>	mset_str2{ "jj","kk","mm" };
	set<string>			set_str3{ "f1","f2","f3" };
	vector<string>		vec_str{ "aa","bb","cc" };
	vector<string>		vec_str2;
	map<string, int>	map_StrInt{ {"jk1",20},{"fl3",10},{"u77",30} };

	//vec_str2.insert(vec_str2.begin(),mset_str2.begin(), mset_str2.end());
	//vec_str2.insert(set_str3.begin(), set_str3.end());
	//vec_str2.insert(vec_str2.begin(),vec_str.begin(), vec_str.end());
	//mset_str2.insert(vec_str.begin(), vec_str.end());
	map_StrInt.insert(vec_str.begin(), vec_str.end());

	for (auto &c:map_StrInt)
	{
		cout << c.first<<"-"<<c.second<< endl;
	}

	/*

	multiset<string>	mset_str;
	multiset<string>	mset_str2{ "jj","kk","mm" };
	vector<string>		vec_str{"aa","bb","cc"};
	vector<string>		vec_str2;
	vec_str2.resize(mset_str2.size());
	int i = 0;
	for (auto c:vec_str2)
	{
		cout << ++i << ": ";
		cout << c << endl;
	}
	cout << "..............." << endl;
	//copy(vec_str.begin(), vec_str.end(), inserter(mset_str, mset_str.end()));
	//copy(vec_str.begin(), vec_str.end(), back_inserter(mset_str));
	copy(mset_str2.begin(),mset_str2.end(),inserter(vec_str2,vec_str2.end()));
	//copy(mset_str2.begin(), mset_str2.end(), back_inserter(vec_str2));
	//copy(mset_str2.begin(), mset_str2.end(), vec_str2.begin());
	for (auto &c:vec_str2)
	{
		cout << c << endl;
	}

	/*

	map<string, int>	map_StrInt{ {"aa",10},{"bb",20} };
	auto	itBmap = map_StrInt.begin();
	itBmap->second = 77;
	for (auto &c:map_StrInt)
	{
		cout << c.first << " " << c.second << endl;
	}


	/* 11.2.3 11.14
	map<string, vector<pair<string, size_t>>> map_StrVec_str;
	string	familyName, strLine, strLineSub, strBrithday;
	while (getline(cin, strLine))
	{

		if (strLine == "end")
		{
			cout << ".........." << endl;
			break;
		}
		auto itBlank = strLine.find(" ");
		if (itBlank >= strLine.size())
		{
			cout << "input format as [FamilyName Name...]" << endl;
			continue;
		}
		familyName = strLine.substr(0, itBlank);
		strLineSub = strLine.substr(itBlank + 1, strLine.size());

		map_StrVec_str[familyName].push_back(getPair(strLineSub));

		//pair<string, int>	pNameBrithday;
		//pNameBrithday.first = strName;
		//pNameBrithday.second = getNum(strLine);
		int test = 1;
	}

	for (auto &c : map_StrVec_str)
	{
		cout << c.first << "-";
		for (auto &e : c.second)
		{
			cout << "[" << e.first << " " << e.second << "],";
		}
		cout << endl;
	}


	/*
	vector<string>	vec_str{ "aa","bb","cc" };
	//vector<string>	vec_str2{ "a1","11","c2" };
	vector<string>	vec_str2;
	vec_str2.resize(vec_str.size());

	//vec_str2.reserve(vec_str.size() * 2);
	//cout << vec_str2.size() << endl;
	//copy(vec_str.begin(), vec_str.end(), back_inserter(vec_str2));

	copy(vec_str.begin(), vec_str.end(), vec_str2.begin());
	for (auto c : vec_str2)
	{
		cout << c << endl;
	}

	/*
	int a1[] = { 1,2,3 };
	int a2[3];
	copy(begin(a1), end(a1), begin(a2));
	for (auto c:a2)
	{
		cout << c << endl;
	}
	/*
	string s{ "aslkdfj" };
	string s2;
	//s2.reserve(s.size());
	//s2.resize(s.size());
	//s2.assign(s.cbegin(), s.cend());
	copy(s.begin(),s.end(), back_inserter(s2));
	//copy(s.begin(), s.end(), s2.begin());

	cout << s2 << endl;

	
	
	
	/*
	vector<pair<string, int>> vecPair;
	string	str;
	int i;
	while (cin>>str)
	{
		cin >> i;
		vecPair.push_back({ str,i });
		//vecPair.push_back(make_pair(str,i));
		//vecPair.push_back(pair<string,int>(str,i));
	}

	for (auto &c:vecPair)
	{
		cout << c.first << "-" << c.second << endl;
	}


	/*
	pair<string, int> p1{ "bb",20 };
	pair<string, int> p2{ "bb",20 };
	if (p1==p2)
	{
		cout << "==" << endl;
	}
	if (p1<p2)
	{
		cout << "p1<p2" << endl;
	}
	if (p1>p2)
	{
		cout << "p1>p2" << endl;
	}
	/*

	using	myspaceFun::mymax;
	//using namespace myspaceFun;
	mymax(2,3);


	/*
	//using	myspace::i;
	using namespace myspace;
	cout << i << endl;


	/*练习 11.2.2 11.11

	STR_test	st1{ 20,"bbb" }, st2{ 30,"aaa" }, st3{ 1,"kkk" };

	//decltype(myComp)* pfun = myCompTest;
	//funTest6* pfun2 = myCompTest;
	//pfun2(st1, st2);
	
	//set<STR_test,decltype(myComp)*>	setS(myComp);
	//set<STR_test, myComp2>setS;
	//set<STR_test, (*)(const STR_test&,const STR_test&)>	setS(myComp);
	set<STR_test, funTest6*>	setS(myCompTest);
	//set<STR_test, funTest8>	setS(myCompTest);
	setS = { st1,st2,st3 };
	for (auto c : setS)
	{
	c.pt();
	}



	/*
	
	//11.2.2 练习11.9
	multimap<string, size_t>	mmap_StrSzt{ {"milk",7},{"hello",1},{"good",4},{"hello",20} };
	list<size_t>	lst_szt;
	map<string, list<size_t>>	map_StrLst_szt;
	//map<string, vector<size_t>>	map_StrLst_szt;
	for (auto &c:mmap_StrSzt)
	{
		//map_StrLst_szt[c.first].insert(list<size_t>::end(), c.second);
		map_StrLst_szt[c.first].push_back(c.second);	//不能用insert 因为没有it可以定位 
		//map_StrLst_szt[c.first].push_back(c.second);
	}

	for (auto &e:map_StrLst_szt)
	{
		cout << e.first << " ";
		for (auto &e2:e.second)
		{
			cout << e2 << ",";
		}
		cout << endl;
	}
	/*

	list<int>	lst_i;
	lst_i.insert(lst_i.begin(), 20);
	lst_i.push_back(70);
	auto itend = back_inserter(lst_i);
	auto itbeg = front_inserter(lst_i);
	*itend = 99;
	*itbeg = 51;
	for (auto &c:lst_i)
	{
	cout << c << endl;
	}

	

	/*
	STR_test	st1;
	cout << st1.val << "  " << st1.name << endl;
	CLS_test	ct1;
	ct1.pt();
	/*
	set<string>	setS;
	string words;
	while (cin>>words)
	{
		setS.insert(words);
	}

	for (auto c:setS)
	{
		cout << c << endl;
	}


	/*
	map<string, vector<string>> mp_sVecStr;
	string	strLine;
	//string	words,strName;
	//while (cin>>words)
	//auto it = strLine.find(" ");

	cout << "input Famile Name:" << endl;
	cout << ">";

	while(getline(cin,strLine))
	{

		/* 在map中添加一个家庭 以及家庭中的多个孩子 p378 练习11.7
		//istringstream	iss(strLine);
		//iss >> words;
		if (strLine=="end")
		{
			cout << "oh..exit..." << endl;
			cout << endl;
			break;
		}
		if (strLine.find(" ") > strLine.size())
		{
			cout << "---------erro input name." << endl;
			cout << "input Famile Name:" << endl;
			cout << ">";

			continue;
		}
		cout << "input Famile Name:" << endl;
		cout << ">";

		
		auto it = strLine.find(" ");
		auto strFamily = strLine.substr(0, it);
		auto strName = strLine.substr(it, strLine.size());
		
		mp_sVecStr[strFamily].push_back(strName);
		
	}

	for (auto &c:mp_sVecStr)
	{
		cout << c.first << " have "<<c.second.size()<<" childrens: ";
		for (auto &e:c.second)
		{
			cout << e << ",";
		}
		cout << endl;
	}
	/*
	getline(cin, strLine);

	if (strLine.find(" ") > strLine.size())
	{
	cout << "no find" << endl;
	}
	else
	cout << "find" << endl;
	/*
	map<string, size_t>	mp_sSt;
	set<string>	st_s{ "and","or","not","hi" };
	string	words;
	while (cin>>words)
	{
		if (st_s.find(words)==st_s.end())
		{
			++mp_sSt[words];
		}
	}
	for (auto &c : mp_sSt)
	{
		cout << c.first << " occurs " << c.second
			<< ((c.second > 1) ? " times" : " time") << endl;
	}

	/*

	map<string, size_t>mp_tel;
	string	strName;
	while (cin>>strName)
	{
		++mp_tel[strName];
	}
	for (auto &c:mp_tel)
	{
		cout << c.first << " occurs " << c.second 
			<< ((c.second > 1) ? " times" : " time") << endl;
	}


	/*

	list<string>	lstStr{ "z6","b2","d3","z4","a5","d3","dd" };
	list<string>	lstStr2{ "tt","kk","jj","bb","ee" };
	forward_list<string> flst{ "70","10","50","20" };
	forward_list<string> flst2{ "600","100","200","000" };

	auto it = find(lstStr.begin(), lstStr.end(), "z4");
	//lstStr.splice(--lstStr.end(), lstStr2);
	//lstStr.splice(it, lstStr2);
	//lstStr.sort();
	//lstStr2.sort();
	//lstStr.merge(lstStr2);
	auto it2 = find(flst.begin(), flst.end(), "10");
	flst.splice_after(it2, flst2);

	for (auto c : flst)
	{
		cout << c << " ";
	}
	cout << endl;

	for (auto c : flst2)
	{
		cout << c << " ";
	}
	cout << endl;


	/*
	for (auto c : lstStr)
	{
		cout << c << " ";
	}
	cout << endl;

	for (auto c : lstStr2)
	{
		cout << c << " ";
	}
	cout << endl;

	/*
	//lstStr.remove("z4");
	//lstStr.remove_if([](auto c)
	//		{return	c.find('d') < c.size(); }
	//{return c == "d3"; }
	//	);
	//lstStr.reverse();
	lstStr.sort();
	cout << "after sort():" << endl;
	for (auto c : lstStr)
	{
		cout << "[" << c << "]";
		//if (auto it=c.find('d')>=c.size())
		//{	cout << "yes" << endl;	}
		//else{cout << "no" << endl;	}
	}
	cout << endl;
	cout << "after unique:" << endl;
	lstStr.unique([](auto c1, auto c2)
	{//cout << c1 << " " << c2 << endl;
		//return c1 == c2; });
		//return c1 <c2; });
		return c1 >c2; });
	for (auto c : lstStr)
	{
		cout <<"["<< c << "]";
		//if (auto it=c.find('d')>=c.size())
		//{	cout << "yes" << endl;	}
		//else{cout << "no" << endl;	}
	}
	cout << endl;
	/*
	lstStr.sort();
	lstStr2.sort();
	lstStr.merge(lstStr2);
	//cout << lstStr2.size() << endl;
	cout << &lstStr2 << endl;
	
	for (auto &c:lstStr2)
	{
		cout << c << endl;
	}

	/*
	vector<int>	vecI;
	vecI.reserve(5);
	//cout << vecI[0] << endl;
	cout << vecI.capacity() << endl;
	cout << vecI.size() << endl;
	/*
	vector<int>	vecI{ 1,2,3,4,5 };
	vector<int> vecI2;
	//vecI2.reserve(5);
	vecI2.resize(5);
	
	//replace(vecI.begin(), vecI.end(), 3, 70);
	//replace_copy(vecI.begin(), vecI.end(),back_inserter(vecI2), 3, 70);
	//cout << vecI2.size() << endl;
	replace_copy(vecI.begin(), vecI.end(), vecI2.begin(), 3, 70);
	for (auto e:vecI2)
	{
		cout << e << " ";
	}
	cout << endl;

	/*

	fstream fsin("data.txt", ios::in);
	fstream fsout1("data1.txt", ios::out);
	fstream fsout2("data2.txt", ios::out);

	if (!fsin&&!fsout1&&!fsout2)
	{
		cout << "open or write file is error." << endl;
		return -1;
	}
	istream_iterator<int>	istm_it(fsin), istm_eof;
	ostream_iterator<int>	ostm_it1(fsout1," "),ostm_it2(fsout2,"\n");

	//cout << *istm_it << endl;
	
	for_each(istm_it, istm_eof, 
		[&ostm_it1, &ostm_it2](auto e) { e % 2 == 0 ? (ostm_it2 = e) : (ostm_it1 = e); });

	fsin.close();
	fsout1.close();
	fsout2.close();

	/*

	istream_iterator<int>	istm_it(cin), istm_eof;
	ostream_iterator<int>	ostm_it(cout," ");

	while (istm_it!=istm_eof)
	{
		ostm_it = *istm_it++;
	}



	/*
	cout << "list:" << endl;
	for_each(istm_it, istm_eof, [](auto c) {cout << c << endl; });

	/*
	while (istm_it == istm_eof || *istm_it==?)
	{
		cout << "0d0a" << endl;
	}
	/*
	string	s;
	cout << *istm_it << endl;
	istm_it++;
	if (istm_it==istm_eof)
	{
		cout << "eof" << endl;
	}
	cout << *istm_it << endl;
	istm_it++;
	if (istm_it == istm_eof)
	{
		cout << "eof" << endl;
	}

	cout << *istm_it << endl;
	istm_it++;
	if (istm_it == istm_eof)
	{
		cout << "eof" << endl;
	}

	/*
	while (istm_it!=istm_eof)
	{
		//cout << *istm_it << endl;
		s = *istm_it;
		++istm_it;
	}
	//for_each(istm_it, istm_eof, [](auto c) {cout << c << endl; });
	//copy(istm_it, istm_eof, ostm_it);

	/*
	int i;
	while (cin >> i)
	{
		//cout << i << " ";

	}
	cout << endl;

	/*
	vector<string>	vecs;
	fstream	fop("t1.txt", ios::in);
	if (!fop)
	{
		cout << "open error" << endl;
		return -1;
	}
	istream_iterator<string>	istm_it(fop),istm_eof;
	//copy(istm_it, istm_eof, back_inserter(vecs));
	
	for (auto e:vecs)
	{
		cout << e << endl;
	}
	

	/*
	if (argc<=1 ||argc>2){ cout << "e.g  dellineno.exe t1.txt" << endl;	return 0;}

	//fstream	fop("t1.txt", ios::binary || ios::out || ios::ate);
	fstream	fop(argv[1], ios::binary || ios::out || ios::ate);
	if (!fop)
	{
		cout << "open " << argv[1] << " error." << endl;
		return 0;
	}
	string sLine;
	ostringstream	oss;
	while (getline(fop,sLine))
	{
		istringstream	iss(sLine);
		string words;
		iss >> words;
		auto words_len = words.size();
		auto Line_len = sLine.size();
		//空行
		if (words_len == Line_len)
		{
			oss << "" << endl;
			continue;
		}
		auto stmp = sLine.substr(words_len + 1, Line_len - words_len - 1);
		cout << stmp << endl;
		oss << stmp<<endl;

	}
	
	fop.close();
	
	//fop.open("t1.txt",ios::out);
	fop.open(argv[1], ios::out);
	fop << oss.str();
	fop.close();

	/*

	//ostream_iterator<string>	out_oit(cout,"\n");
	//out_oit = "klsdjf;";
	
	//ifstream	inf("asi1.txt");
	ofstream	outf("asi1.txt", ios::binary||ios::ate);
	outf.seekp(0,ios::beg);
	outf << "L\n";
	/*

	//fstream		inf("asi1.txt",ios::out||ios::app);
	//fstream		inf("asi3.txt", ios::out);
	
	//istream_iterator<string>	in_itf(inf), in_eof;
	//ostream_iterator<string>	out_itf(inf);
	ostream_iterator<string>	out_itf(outf);
	//vector<string>	vecs(in_itf,in_eof);
	
	
	//++in_itf;
	//cout << *in_itf << endl;
	
	string	s1 = "p2";
	//out_itf = inf.seekg(ios::beg);
	
	out_itf = s1;
	
	/*
	//auto it=find(in_itf, in_eof, "qqwweoo");
	auto it = find(vecs.begin(),vecs.end(), "qqwweoo3");
	if (it != vecs.end())
	{
		cout << "find." << endl;
	}
	else
		cout << "dont find." << endl;


	/*
	ifstream	inf("test.cpp");
	string	strLine;
	vector<string>	vecS;
	while (getline(inf,strLine))
	{
		vecS.push_back(strLine);
	}
	for (auto c : vecS)
	{
		cout << c<<endl;
	}


	/*
	//istream_iterator<int>	in_itor(cin), in_eof;
	//vector<int>	vecI(in_itor, in_eof);
	//istream_iterator<string>	in_itor(cin), in_eof;
	ifstream	inf("test.cpp");
	istream_iterator<string>	in_itor(inf), in_eof;
	vector<string>	vecS(in_itor, in_eof);
	
	for (auto c : vecS)
	{
		cout << c ;
	}
	cout << endl;

	/*
	istream_iterator<int>	in_itor(cin);
	istream_iterator<int>	in_eof;
	vector<int>	veci;
	while (in_itor!=in_eof)
	{
		veci.push_back(*in_itor++);
	}
	for (auto c:veci)
	{
		cout << c << " ";
	}
	cout << endl;
	/*
	string s{ "abc" };
	auto it = s.begin();
	cout << *it++ << endl;	//++ > * 

	/*
	vector<int>	veci{ 1,2,3 };
	auto it = back_inserter(veci);
	back_insert_iterator<vector<int>> it2=it;
	
	*it2 = 40;
	for_each(veci.begin(), veci.end(), [](auto c) {cout << c << endl; });


	vector<int>	vec1;
	vec1.reserve(veci.size());
	//for_each(veci.begin(), veci.end(), [it](auto c) {*it = c; });

	/*
	vector<int> veci{ 1,2,3 };
	//auto it = back_inserter(veci);
	//back_insert_iterator<vector<int>> it2 = it;
	//*it2 = 40;

	auto it = inserter(veci, veci.begin());
	insert_iterator<vector<int>> it2=it;
	//it2 = it;
	*it2 = 50;
	
	for_each(veci.begin(), veci.end(), [](auto c) {cout << c << endl; });
	/*
	vector<int>	vec;
	//vec.reserve(3);
	vec.resize(3);
	cout << vec.size() << endl;
	/*
	vector<int>	vecI{ 1,2,3,4,5,6,7,8,9 };
	//vector<int>	vec1(9);
	//vector<int>	vec2(9);
	//list<int>	vec3(9);
	vector<int>	vec1;
	vector<int>	vec2;
	list<int>	vec3;
	//vec1.reserve(9);
	//vec2.reserve(9);
	//vec3.reserve(9);

	auto itor1 = inserter(vec1, vec1.begin());
	auto itor2 = back_inserter(vec2);
	auto itor3 = front_inserter(vec3);

	for_each(vecI.begin(), vecI.end(), [&itor1](auto c) {*itor1 = c; });
	
	for_each(vecI.begin(), vecI.end(), [&itor2](auto c) {*itor2 = c; });
	
	for_each(vecI.begin(), vecI.end(), [&itor3](auto c) {*itor3 = c; });
	
	cout << "vec1:" << endl;
	for_each(vec1.begin(), vec1.end(), [](auto c) {cout << c << " "; });
	cout << endl;

	cout << "vec2:" << endl;
	for_each(vec2.begin(), vec2.end(), [](auto c) {cout << c << " "; });
	cout << endl;

	cout << "vec3:" << endl;
	for_each(vec3.begin(), vec3.end(), [](auto c) {cout << c << " "; });
	cout << endl;

	/*

	vector<int>	vecI{ 1,2,3,4,5,2,4 };
	sort(vecI.begin(), vecI.end());
	
	vector<int>	vecI2;
	vecI2.resize(vecI.size());

	auto it2=unique_copy(vecI.begin(), vecI.end(), vecI2.begin());
	vecI2.erase(it2, vecI2.end());
	for_each(vecI2.begin(), vecI2.end(), [](auto e) {cout << e << endl; });
	cout << "capacity:" << vecI2.capacity() << endl;

	list<int>	lstI;
	lstI.resize(vecI.size());
	auto it3 = unique_copy(vecI.begin(), vecI.end(), lstI.begin());
	lstI.erase(it3, lstI.end());
	for_each(lstI.begin(),lstI.end(), [](auto e) {cout << e << endl; });
	

	/*
	auto it = unique(vecI.begin(), vecI.end());
	for_each(vecI.begin(), vecI.end(), [](auto e) {cout << e << endl; });
	vecI.erase(it, vecI.end());
	cout << "after erase:" << endl;
	for_each(vecI.begin(), vecI.end(), [](auto e) {cout << e << endl; });


	/*

	copy(vecI.begin(), vecI.end(), vecI2.begin());
	for_each(vecI2.begin(), vecI2.end(), [](auto e) {cout << e << endl; });

	/*
	vector<int>	vecI{ 12,1,99,80 };
	auto itb = vecI.begin();
	
	auto it = inserter(vecI, itb);
	*it = 70;
	*it = 20;
	auto it3=vecI.insert(vecI.begin(), 30);
	//*it = 40;

	int test = 10;

	/*
	auto it=vecI.insert(itb, 70);

	/*
	vector<string>	vecI{ "a1","a2","b1","b2" };
	auto itb = vecI.begin();
	*itb = ";ajf";
	for_each(vecI.begin(), vecI.end(), [](auto c) {cout << c << endl; });
	//cout << *(++vecI.begin()) << endl;
	/*
	auto itb=vecI.begin();
	++itb;
	cout << *itb << endl;

	/*

	vector<string>	vecStr{ "ab","adasfjlkasjf","oiwerooi","afioiw","jjo","[8798785" };
	sort(vecStr.begin(), vecStr.end(),
			[](auto c1, auto c2) {return c1.size() < c2.size(); });
	int n = 5;
	auto newC = bind(check_size,_1,n);
	auto it = find_if(vecStr.begin(), vecStr.end(), newC);
	vecStr.erase(it, vecStr.end());
	for_each(vecStr.begin(), vecStr.end(), [](auto c) {cout << c << " "; });
	cout << endl;

	/*
	//形参只能一个
	auto it=find_if(vecStr.begin(), vecStr.end(), 
		[](const string &s1, const string &s2) {return s1.size()==s2.size(); });
	if (it != vecStr.end())
	{
		cout << "find it" << endl;
	}
	else
		cout << "dont find" << endl;

	/*

	int i = 3;
	//isis只是声明一个函数而以，并不立即执行
	auto isis = [&i]()->bool {if (i == 0) return false; else { --i; return true; }};
	while (isis())
	{
		cout << "+" << endl;
	}
	
	/*
	vector<string>	vecStr{ "ab","adasfjlkasjf","oiwerooi","afioiw","jjo","[8798785" };
	auto cnt = count_if(vecStr.begin(), vecStr.end(),
		[](auto s) {return s.size() >= 6; });

	cout << cnt << endl;
	/*
	vector<int>	veci{ 1,2,3,4,6,7,8,9,7,2,9,0,0,0 };
	auto cnt = count_if(veci.begin(), veci.end(), 
		[](int e) {return e==7; });
	//auto cnt = count_if(veci.begin(), veci.end(),funTest5);
	cout << cnt << endl;
	

	/*

	int arri[3] = { 1,2,3 };
	array<int, sizeof(arri) / sizeof(int)> arryi;
	string	s;
	copy(begin(arri), end(arri), s.begin());
	//s.push_back('\0');
	//for_each(s.begin(), s.end(), [](auto c) {cout << c << " "; });

	//transform(begin(arri), end(arri), arryi.begin(), nullptr);
	copy(begin(arri), end(arri), arryi.begin());
	for_each(arryi.begin(), arryi.end(), [](auto c) {cout << c << " "; });
	cout << endl;
	/*

	int i = 20;
	//auto f = [&i]() {++i; };
	//auto f = [&]() {return ++i; };
	auto f = [i]()mutable {return ++i; };
	i = 30;
	cout <<"f():"<< f() << endl;
	cout <<"i:"<< i << endl;

	/*
	int i1, i2;
	string	s1, s2;
	//cin >> i1 >> i2;
	//auto t1add = [i1, i2](int j) {return i1 + i2+j; };
	auto t1add = [s1,s2](string	s) {return s1+s+s2; };
	cout << t1add("ok") << endl;

	/*
	//vector<string>	vecStr{ "low","jj","lkjaflk","owiuerovc","jj","321948903217491874","fuck" };
	vector<string>	vecStr{ "low","jj","j2j","lkflk","owiuerc","jj","321990321744","fuck","P" };
	int sz=5;
	auto it = find_if(vecStr.begin(), vecStr.end(), [sz1](const string &s)
	{return s.size() >= sz1; });

	/*
	auto it = vecStr.begin();
	//auto it2 = vecStr.erase(it);
	auto it2 = vecStr.insert(it, "KKK");
	int test = 20;
	
	/*
	auto it = find_if(vecStr.begin(), vecStr.end(), [](const string& s)
	{return s.find('2', 0) < s.size(); });
	//auto it2 = vecStr.erase(it);
	auto it2 = vecStr.insert(it, "kkk");

	int i = 20;	//F9 assert

	/*
	//auto it=find(vecStr.begin(), vecStr.end(), "fuck");
	//auto	it = find_if(vecStr.begin(), vecStr.end(), funTest4);
	//vecStr.erase(it);

	auto	itb = vecStr.begin();
	while (itb!=vecStr.end())
	{
		auto it = find_if(itb, vecStr.end(), [](const string& s)
		{return s.find('2', 0) < s.size(); });
		if (it!=vecStr.end())
		{
			itb = vecStr.erase(it);
		}
		else
		{
			itb = it;
		}
		

	}
	for (auto &e : vecStr)
	{
		cout << "[" << e << "]" << " ";
	}
	cout << endl;



	/*
	for (auto &e : vecStr)
	{
		if (e.find('2', 0)<e.size())
		{
			cout << "finded" << endl;

		}
		else
		{
			cout << "dont find" << endl;
		}
		
		//cout << "[" << e << "]" << " ";
	}
	cout << endl;


	/*
	sort(vecStr.begin(), vecStr.end(), [](const string &s1,const string	&s2)
	{return s1.size() < s2.size(); });

	for (auto &e : vecStr)
	{
		cout << "[" << e << "]" << " ";
	}
	cout << endl;



	auto it = find_if(vecStr.begin(), vecStr.end(), [](const string &s1)
	{return s1.size() >= 5; });
	

	//vecStr.erase(it, vecStr.end());
	for (auto &e : vecStr)
	{
		cout << "[" << e << "]" << " ";
	}
	cout << endl;
	auto counts = vecStr.end() - it;
	cout << counts << endl;

	/*
	auto ite = unique(vecStr.begin(), vecStr.end());
	for (auto &e : vecStr)
	{
		cout << "[" << e << "]" << " ";
	}
	cout << endl;

	/*
	sort(vecStr.begin(), vecStr.end(),isShorter);
	//sort(vecStr.begin(), vecStr.end());

	for (auto &e:vecStr)
	{
		cout << "[" << e << "]" << " ";
	}
	cout << endl;
	

	//auto ite=unique(vecStr.begin(), vecStr.end(),isShorter);
	auto ite = unique(vecStr.begin(), vecStr.end());
	for (auto &e : vecStr)
	{
		cout <<"["<< e <<"]"<< " ";
	}
	cout << endl;

	vecStr.erase(ite, vecStr.end());
	for (auto &e : vecStr)
	{
		cout << "[" << e << "]" << " ";
	}
	cout << endl;


	//auto it=find_if(vecStr.begin(), vecStr.end(), funTest3);
	

	/*
	vector<string>	vecS{ "kb1","kb2","kb1","bb1","bc1","bd1","bb1","cj1","cj2","bb1" };


	cout << "unique():" << endl;
	auto itE = unique(vecS.begin(), vecS.end());
	for (auto &e : vecS)
	{
		cout << e << endl;
	}

	cout << "sort():" << endl;
	sort(vecS.begin(), vecS.end());
	for (auto &e:vecS)
	{
		cout << e << endl;
	}
	cout << "unique2():" << endl;
	auto itE2 = unique(vecS.begin(), vecS.end());
	for (auto &e : vecS)
	{
		cout << e << endl;
	}
	vecS.erase(itE2, vecS.end());
	cout << "erase():" << endl;

	for (auto &e : vecS)
	{
		cout << e << endl;
	}
	/*

	vector<int>	vecI;
	//vecI.reserve(10);
	vecI.resize(10);
	//vecI[0] = 1;
	for (auto &e : vecI)
	{
		cout << e << endl;
	}
	/*
	fill_n(vecI.begin(), 10, 0);
	for (auto &e:vecI)
	{
		cout << e << endl;
	}


	/*
	vector<int>	vecI{ 1,2,3 };
	cout << "before reserve:" << vecI.capacity() << endl;
	vecI.reserve(5);
	cout << "after reserve(5):" << vecI.capacity() << endl;
	vecI.reserve(2);
	cout << "after reserve(2):" << vecI.capacity() << endl;
	for (auto &e:vecI)
	{
		cout << e << endl;
	}

	vecI.resize(2);
	cout << "after resize(2) vecI.capacity():" << vecI.capacity() << endl;
	cout << "after resize(2) vecI.size():" << vecI.size() << endl;
	for (auto &e : vecI)
	{
		cout << e << endl;
	}


	/*
	vector<int>	vecI;
	list<int>	lst{ 1,2,3,4,5 };
	lst.push_back(30);
	cout << "container lst content:" << endl;
	for (auto &e : lst)
	{
		cout << e << endl;
	}
	
	deque<int>	deqI;
	//copy(lst.begin(), lst.end(), vecI.begin());
	copy(lst.begin(), lst.end(), back_inserter(vecI));
	//copy(lst.begin(), lst.end(),vecI);
	cout << "container vector content:" << endl;
	for (auto &e : vecI)
	{
		cout << e << endl;
	}

	/*

	int arI[] = { 1,2,3,4,5,3,66,3 };
	vector<int>	vecI(begin(arI), end(arI));
	for (auto &e : vecI)
	{
		cout << e << endl;
	}


	/*
	int arI[] = { 1,2,3,4,5,3,66,3 };
	
	//fill_n(begin(arI), end(arI),0);
	vector<int>	vecI{ 1,2,3,4,5,3,66,3 };
	fill_n(begin(arI), sizeof(arI) / sizeof(int), 0);
	//fill_n(vecI.begin(),vecI.size(),0);
	//fill(vecI.begin(), vecI.end(), 0);

	for (auto &e : arI)
	{
		cout << e << endl;
	}

	/*
	char	arC[] = "abc";
	const char	*pc = "jkm";
	string	s = arC;
	string	s2 = pc;
	cout << s << endl;
	cout << s2 << endl;
	s2[0] = 'F';
	cout << s2 << endl;


	/*
	int arI[] = { 1,2,3,4,5,3,66,3 };
	array<int, sizeof(arI) / sizeof(int)>	arrayI;
		
	//arrayI = arI;
	auto	parI = arI;
	//vector<int>	vecI = parI;
	copy(begin(arI), end(arI), arrayI.begin());
	for (auto &e:arrayI)
	{
		cout << e << endl;
	}

	/*
	int arI[] = { 1,2,3,4,5,3,66,3 };

	vector<int>	vecI;
	auto it=copy(begin(arI), end(arI), back_inserter(vecI));
	for (auto &e:vecI)
	{
		cout << e << endl;
	}
	cout <<"the size of vecI is:"<<  vecI.size() << endl;

	//vector<int>::iterator	ite = (vector<int>::iterator) it;
	//vecI.insert((vector<int>::iterator)it, 70);
	vecI.insert(vecI.end(), 70);
	cout << "after insert vecI.end():" << endl;
	for (auto &e : vecI)
	{
		cout << e << endl;
	}

	cout << "after insert vecI.end() 2:" << endl;
	vecI.insert(vecI.end(), 80);
	for (auto &e : vecI)
	{
		cout << e << endl;
	}
	cout <<"vecI.size():"<< vecI.size() << endl;

	replace(vecI.begin(), vecI.end(), 3, 33);
	cout << "after replace():" << endl;
	for (auto &e : vecI)
	{
		cout << e << endl;
	}

	/*
	vector<int>	veci(2);
	/*
	veci.insert(veci.end(), 77);
	veci.insert(veci.end(), 88);
	veci.insert(veci.end(), 99);
	
	//fill_n(veci.end(), 3, 77);
	fill_n(back_inserter(veci), 3, 77);
	for (auto &c : veci)
	{
		cout << c << endl;
	}

	/*
	//cout << size(veci) << endl;
	//cout << veci.size() << endl;
	//fill_n(veci, size(veci), 0);
	//fill(veci.cbegin(), veci.cend(), 10);
	//fill(veci.begin(), veci.end(), 10);

	auto it=fill_n(veci.begin(), size(veci), 10);
	veci.insert(it, 77);
	for (auto &c : veci)
	{
		cout << c << endl;
	}
	/*
	char	c1{ 'a' },c2='j',c3='P';
	char	*p1, *p2, *p3;
	p1 = &c1, p2 = &c2, p3 = &c3;
	vector<const char*>	vecPc1{ "a1","a2","b1","b2" };
	vector<const char*>	vecPc2{ "a1","a2","b1","b2","b3" };
	vector<char*>	vecP{ p1,p2,p3 };
	for (auto c:vecP)
	{
		cout << "char*: " <<*c<< endl;
		//printf("char*:%c\n", *c);
	}
	
	if (equal(vecPc1.cbegin(), vecPc1.cend(), vecPc2.cbegin(), vecPc2.cend()))
	//if (equal(vecPc1.cbegin(), vecPc1.cend(), vecPc2.cbegin()))
	{
		cout << "==" << endl;
	}
	else
	{
		cout << "!=" << endl;
	}


	/*
	//vector<char*>	vecPc;
	char*	pc;
	pc =(char*) "jj";
	cout << pc << endl;

	/*
	vector<double>	vecD{ 1.1,2.2,3.4,4.99 };
	double	val = accumulate(vecD.cbegin(), vecD.cend(), 0.0);
	cout << val << endl;

	/*
	string	s{ "abc" };
	//string	s2{ "abcdsfawerqr" };
	string	s2{ "ab" };
	if (equal(s.cbegin(), s.cend(), s2.cbegin()))
	{
		cout << "==" << endl;
	}
	else
	{
		cout << "!=" << endl;
	}
	

	/*
	//vector<char>	s{ 'a','b','c'};
	//vector<string>	s{ "a1","b2","c3" };
	auto val = accumulate(s.begin(), s.end(), string(""));
	cout << val << endl;

	/*
	string	s{ "a124fddofuckyyy[[]i" };
	string	s2;

	auto	cnt = count(s.begin(), s.end(), 'f');
	cout << "cnt:" << cnt << endl;

	/*
	auto	it = s.find("fuck");
	cout << "it:" << it << endl;
	//s2.assign(s.substr(it));
	s2 = s.substr(it);
	cout << "s2:" << s2 << endl;
	/*
	auto	it = find(s.begin(), s.end(), 'k');
	if (it==s.end())
	{
		cout << "dont find." << endl;
	}
	else
	{
		//cout<<"*it:" << *it << endl;
		s2.assign(it, s.end());
		cout << "s2:" << s2 << endl;
	}
	

	/*
	vector<string>	vecS{ "a1","a2","b1","b2" };
	string	s2;
	string	sval = "a2";
	//const char	*pc = "abc";
	char	pa[] = "june";
	//auto	ss = pc;
	//auto	ss = pa;
	//string	ss = pc;
	string	ss = pa;
	cout << ss << endl;
	//auto it = s.find("fuck3");
	//auto it = find(s.begin(), s.end(),sval);
	auto	it = find(vecS.begin(), vecS.end(), sval);
	
	if (it == vecS.end())
	{
		cout << "dont find." << endl;
	}
	else
	{
		s2.assign(*it);
		cout << s2 << endl;
	}

	/*

	DateTest	dt1("june 22,1990");
	dt1.pt();


	/*
	string	s{ "january 22,1990" };
	auto it = s.find("january");
	cout << it << endl;
	auto s2 = s.substr(it,3);
	cout << s2 << endl;
	/*
	vector<string>	vecS{ "123", "55", "7897", "41" };
	//int		sum = 0;
	double		sum = 0;
	for (auto &e:vecS)
	{
		//auto	val = stoi(e);
		auto	val = stod(e);
		sum += val;

	}
	cout << "sum:" << sum << endl;

	/*
	string	s{ "pi= 7xfmul 2.33 =7.3162" };
	auto s2=s.substr(s.find_first_of("+-.0123456789"));
	cout << "s2:" << s2 << endl;
	//double	d = stod(s.substr(s.find_first_of("+-.0123456789")));
	//cout << d << endl;

	size_t	pos;
	auto	val = stoi(s2,&pos,10);
	cout <<"val="<< val << " pos:" << pos << endl;

	//cout << s2 << endl;
	/*
	if (auto d2 = stod(s))
	{
		cout << d2 << endl;
	}
	else
	{
		cout << "dont find" << endl;
	}
	*/
	/*
	string	s{ "363236aadwervcx3690942wepoir[xczv2#$!$@#$(*)_*365415987896" };
	//cout << s.compare("36") << endl;
	cout << s.compare(0, 2, "36") << endl;

	/*
	string	number{ "0123456789" };
	string	name{ "r2d2" };


	if (number.find(name)==string::npos)
	{
		cout << "dont find." << endl;
	}
	cout << number.find(name) << endl;
	size_t	i = -1;
	cout << i << endl;

	/*
	string	s{ "ab2c3d7R4E6" };
	string	number{ "0123456789" };
	size_t	pos=0;
	cout << "s:\n" <<s<< endl;
	cout << "number pos:" << endl;
	while ((pos=s.find_first_of(number,pos))!=string::npos)
	{
		cout << pos++ << endl;
	}
	pos = 0;
	cout << "char pos:" << endl;
	while ((pos=s.find_first_not_of(number,pos))!=string::npos	)
	{
		cout << pos++ << endl;
	}

	/*
	string	s{ "FXX piloat .FXX is soilder!" };
	string	sch{ "FXX" };
	vector<size_t> it;
	size_t	pos = 0,len=size(sch);
	
	
	while ((pos=s.find(sch,pos))!=string::npos)
	{
		it.push_back(pos);
		pos += len;
	}
	
	/*
	while (pos<=len)
	{
		size_t post=s.find(sch,pos);
		it.push_back(post);
		pos = post +size(sch) ;
	}
	
	for (auto &c:it)
	{
		cout << c << endl;
	}



	/*

	string	strName;
	cin >> strName;
	cout << prefixName(strName) << endl;


	/*
	string	s{ "abc though jk tfdo." };
	
	
	//shortening(s, "though", "tho");
	//cout << s << endl;
	
	istringstream	iss(s);
	string	word;
	auto	it = s.begin();
	while (iss>>word)
	{
		
		auto	len = size(word);
		if (word=="though")
		{
			//s.replace(it, it + len, "tho");
			s.erase(it, it + len);
			s.insert(it, {'t','h','o'});
		}
		else
		{
			it += len+1;
		}
	}
	cout << s << endl;
	
	
	/*
	int k = 30;
	int &rk = k;
	auto j = rk;


	/*
	const char	*pc = "abcdef";
	string	s2 = "jklmn";
	//s2.replace(s2.begin(), s2.end(), "fuck");
	//auto st=s2.replace(s2.begin() + 1,s2.end(), "fuck");
	auto &st = s2.replace(s2.begin() + 1, s2.end(), "fuck");
	st.assign("good");
	cout << s2 << endl;

	/*
	string	s;
	//s.insert(s.size(), pc + 2);	//&(pc+2) 到最后'\0';	vc2017中与c++primer p362不符
	//s.insert(s.size(), pc, 2);	//从 &(pc+0)开始的2个char;
	//s.insert(s.size(), s2, 2);		//从s2的下标 s2[2]开始到最后;
	s.insert(0, s2);
	cout << s << endl;
	s = "fuck";
	cout << s << endl;

	/*
	vector<char>	vecC(100000, 'a');
	vecC.push_back('\0');

	auto pc = &vecC[0];
	//auto it = vecC.begin();
	//cout << pc << endl;
	//cout << *it << endl;
	string s = pc;
	cout << s << endl;
	/*
	string	s;
	for (auto c:vecC)
	{
		s.push_back(c);
	}

	cout << s << endl;


	/*

	const	char	*pc = "abcde";
	vector<int>		vecI{ 1,2,3,4,5,6,7,8,9 };
	vector<string>	vecS{ "aa","bb","cc","dd","ee" };
	string	strT = "goodlove";
	char	noNull[] = { 'T','K' };
	
	//string	s(pc+2);
	//string	s(pc, 2);
	//s = pc;
	//string	s(strT,1,2);
	//string		s(&strT[0] + 1);
	string		s(strT, 0,3);
	cout<< s << endl;

	
	/*
	vector<int>		vecI{ 1,2,3,4,5,6,7,8,9 };
	cout << "before reserve:" << endl;
	cout <<"capacity:"<< vecI.capacity() << endl;
	cout <<"size:"<< vecI.size() << endl;
	vecI.reserve(15);
	cout << "after reserve:" << endl;
	cout <<"capacity:"<<vecI.capacity() << endl;
	cout <<"size:"<< vecI.size() << endl;

	cout << "after resize:" << endl;
	vecI.resize(vecI.size() / 2);
	cout << "capacity:" << vecI.capacity() << endl;
	cout << "size:" << vecI.size() << endl;

	cout << "List of vecI:" << endl;
	for (auto &c:vecI)
	{
		cout << c << endl;
	}


	/*
	vector<int>	vecI;
	
	for (int i=0;i<24;++i)
	{
		vecI.push_back(i);
	}
	cout << vecI.size() << endl;
	cout << vecI.capacity() << endl;



	/*
	vector<int>		vecI{ 10,20,30};
	cout << vecI.capacity() << endl;
	//vecI.reserve(20);
	//cout << vecI.capacity() << endl;
	vecI.push_back(40);
	cout << vecI.capacity() << endl;
	cout << vecI.size() << endl;
	vecI.resize(2);
	cout << "list:" << endl;
	for (auto &c:vecI)
	{
		cout << c << endl;
	}
	cout << vecI.capacity() << endl;
	/*
	vector<int>		vecI{ 10,20,30,40,50,60,7,8,9,10,11,12,13,14,15,16,17 };
	auto	itb = vecI.begin();
	
	auto	it = vecI.insert(itb, *itb++);	//参数入栈从右往左，所以先处理*itb++这项参数了
						//itb++先返回 *itb 然后itb+1 ，因此 pos位置变成 了itb+1的新位置了，
	//而非原先指定的itb 可以运行，但与原意图违背
	it += 2;
	cout <<"*it:"<< *it << endl;
	for (auto &c : vecI)
	{
	cout << c << endl;
	}



	/*
	int k = 30;
	int *p = &k;
	cout << *++p << endl;



	/*
	forward_list<int>		vecI{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17 };
	//auto	itb = vecI.begin();
	//auto	it = vecI.insert_after(itb, 70);
	//cout << *it << endl;
	
	auto	it = vecI.begin(), pre = vecI.begin();
	while (it != vecI.end())
	{

		if (*it % 2)
		{
			it = vecI.insert_after(pre, *it);
			pre = it;
			it++;
		}
		else
		{
			it = vecI.erase_after(pre);
			pre = it;
		}

	}
	for (auto &c : vecI)
	{
		cout << c << endl;
	}

	/*
	list<int>		vecI{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17 };

	auto	it = vecI.begin();
	while (it != vecI.end())
	{
		if (*it % 2)
		{
			it = vecI.insert(it, *it);
			it++;
			it++;
		}
		else
		{
			it = vecI.erase(it);
		}

	}
	for (auto &c : vecI)
	{
		cout << c << endl;
	}

	/*
	vector<int>		vecI{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17 };

	auto	it = vecI.begin();
	while (it!=vecI.end())
	{
		if (*it%2)
		{
			it = vecI.insert(it, *it);
			it += 2;
		}
		else
		{
			it = vecI.erase(it);
		}

	}
	for (auto &c : vecI)
	{
		cout << c << endl;
	}


	/*
	vector<int>		vecI{ 1,2,3,4,5,6 };
	cout << "ori:" << endl;
	for (auto &c : vecI)
	{
		cout << c << endl;
	}

	auto	itb = vecI.begin();
	++itb;
	auto	it = vecI.erase(itb);
	cout << "after OP:" << endl;
	for (auto &c : vecI)
	{
		cout << c << endl;
	}
	cout <<"the new *pos after erase :"<< *it << endl;
	

	/*
	vector<int>		vecI{ 1,2,3,4,5,6 };
	auto	itb = vecI.begin();
	++itb;
	auto	it = vecI.insert(itb, 10);
	it += 2;
	cout << *it << endl;

	for (auto &c : vecI)
	{
		cout << c << endl;
	}
	/*
	vector<double>	vecI;
	vecI.resize(100);
	for (auto &c:vecI)
	{
		cout << c << endl;
	}

	/*
	//list<int>	lstI{ 1,2,3,4,5,6 };
	forward_list<int>	lstI{ 1,2,3,4,5,6 };
	auto	it = lstI.begin();
	auto	pre = it;

	while (it!=lstI.end())
	{
		if (*it == 3)
		{
			break;
		}
		else
		{
			pre=it;
			++it;
			
		}
			
	}
	//lstI.insert(it, 70);
	lstI.insert_after(pre, 70);
	for (auto &c:lstI)
	{
		cout << c << endl;
	}
	
	//vector<int>	vecI{ 1,2,3,4,5,6 };
	//cout << vecI[1] << endl;
	/*
	auto	it = lstI.begin();
	++it;
	lstI.insert(it, 90);
	for (auto &c:lstI)
	{
		cout << c << endl;
	}

	
	forward_list<int>	fwlst{ 1,2,3,4,5,6 };

	fwlst.push_front(90);
	
	/*
	//auto	it=fwlst.before_begin();
	//fwlst.insert_after(it,7);
	fwlst.insert_after(fwlst.before_begin(), 8);
	auto	itend = fwlst.end();
	
	//fwlst.insert_after(itend--,	20);
	/*
	auto isEven = [](int i) -> bool
	{
		return (i % 2 == 0);
	};
	
	

	for (auto &c:fwlst)
	{		
		cout << c << endl;
	}

	/*
	int		ia[]{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17 };
	vector<int>	vecI{ begin(ia),end(ia) };
	list<int>	lstI{ begin(ia),end(ia) };
	auto	itVecB = vecI.begin();
	auto	itLstB = lstI.begin();

	while (itVecB!=vecI.end())
	{
		if (*itVecB%2!=0)
		{
			itVecB = vecI.erase(itVecB);
		}
		else
		{
			++itVecB;
		}
	}

	while (itLstB!=lstI.end())
	{
		if (*itLstB%2==0)
		{
			itLstB = lstI.erase(itLstB);
		}
		else
		{
			++itLstB;
		}
	}
	cout << "vecI:" << endl;
	for (auto c:vecI)
	{
		cout << c << endl;
	}

	cout << "lstI:" << endl;
	for (auto c : lstI)
	{
		cout << c << endl;
	}

	/*
	list<int>	lstInt{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17 };
	
	auto	it = lstInt.begin();
	it=lstInt.erase(it);
	//++it;
	cout << *it << endl;
	
	/*
	auto	it = lstInt.begin();

	while (it!=lstInt.end())
	{
		if (*it%2!=0)
		{
			it = lstInt.erase(it);
		}
		else
		{
			++it;
		}
	}
	
	for (auto	it=lstInt.begin();it!=lstInt.end();)
	{
		if (*it%2!=0)
		{
			it=lstInt.erase(it);
		}
		else
		{
			++it;
		}
	}
	*/
	/*
	for (auto it = lstInt.begin(); it != lstInt.end();++it)
	{
		if (*it % 2 != 0)
		{
			lstInt.erase(it);
		}
	}
	
	for (auto c:lstInt)
	{
		cout << c << endl;
	}
	*/

	/*
	vector<string>	vecStr{ "a1","a2","b1","b2","b3","b4" };
	//auto	it = vecStr.erase(++vecStr.begin(), vecStr.end());
	//auto	it = vecStr.erase(vecStr.begin() + vecStr.size() / 2, vecStr.end());
	//auto	it = vecStr.begin();
	
	auto	pit = &vecStr[3];
	cout <<"before erase  *pit:"<<*pit<< endl;
	//auto	it = vecStr.begin();
	vector<string>::iterator	it = vecStr.begin()+2;
	//auto	pit = vecStr.begin();

	auto	it2 = vecStr.erase(it);
	cout << "after earse *pit:" << *pit << endl;
	//cout << &vecStr[1] << endl;
	//vecStr.clear();
	for (auto c:vecStr)
	{
		cout << c << endl;
	}
	/*
	if (it==vecStr.end())
	{
		cout << "end" << endl;
	}
	else
	{
		cout << "no end" << endl;
	}

	/*
	vector<string>	vecStr;
	if (!vecStr.empty())
	{
		//cout << vecStr.at(0) << endl;

		//vector<string>	vecStr{ "a1","a2","b1","b2" };
		//cout << vecStr.at(1) << endl;
		cout << vecStr.front() << endl;
		//cout << vecStr.back() << endl;
		//cout << vecStr[1] << endl;

	}
	else
	{
		cout << "vecStr is empty." << endl;
	}

	/*
	string	s1 = "abc";
	//auto	p = &s1[1];
	//auto	p = s1.begin();
	//cout << *p << endl;
	//s1 = "tlm";
	//s1.insert(s1.begin(),13, 'K');
	
	//cout << *p << endl;	//!!!realloction memory when insert to many data;

	auto	&rf = s1.front();
	rf = 'j';
	s1.front()++;
	for (auto c:s1)
	{
		cout << c << endl;
	}

	/*
	vector<int>	veci{ 1,2,3 };
	auto	&rv = veci[1];
	auto	*pv = &veci[1];
	auto	it = veci.begin();
	cout << *it << endl;
	//cout << rv << endl;
	//cout << *pv << endl;
	//veci.insert(veci.begin(), { 7,9,0 });
	//veci.insert(veci.end(), { 20,30,40 });
	veci.push_back(77);
	//cout << *pv << endl;
	//cout << rv << endl;
	cout << *it << endl;

	/*
	list<int>	listi{ 1,2,3 };
	vector<int>	veci{ 1,2,3 };
	if (listi<veci)	//nonono
	{
	}

	/*
	string	vecs1="abcd";
	string	vecs2="fkfkfk";
	vector<int>	vecti;
	vector<string>	vects;
	array<int,3>		arri;
	array<string, 3>	arris;
	list<int>		listi;
	list<string>	lists;

	cout << vecs1.max_size() << endl;
	cout << vecti.max_size() << endl;
	cout << vects.max_size() << endl;
	cout << arri.max_size() << endl;
	cout << arris.max_size() << endl;
	cout << listi.max_size() << endl;
	cout << lists.max_size() << endl;


	//vector<string>	vecs1 = { "a1","a2","a3" };
	//vector<string>	vecs2 = { "b1","b2","b3" };
	//array<string,3>	vecs1 = { "a1","a2","a3" };
	//array<string,3>	vecs2 = { "b1","b2","b3" };
	//vector<string>	vecs1 = { "a1","a2","a3" };
	//vector<string>	vecs2 = { "b1","b2" };
	auto it1 = vecs1.begin();
	auto it2 = vecs2.begin();
	//auto &it1 = vecs1.at(1);
	//auto &it2 = vecs2.at(1);
	//auto	it3 = vecs1[1];
	//auto	it4 = vecs2[1];
	
	//vecs1.swap(vecs2);

	cout << *it1 << " " << *it2 << endl;

	swap(vecs1, vecs2);
	cout << "after swap..." << endl;
	cout << "vecs1:" << endl;
	for (auto c:vecs1)
	{
		cout << c << endl;
	}
	cout << "vecs2:" << endl;
	for (auto c : vecs2)
	{
		cout << c << endl;
	}


	//cout << it1 << " " << it2 << endl;
	//cout << *it1 << " " << *it2 << endl;
	//cout << it3 << " " << it4 << endl;

	/*
	vector<int>	veci;
	vector<int>	veci2=veci;
	vector<int>	veci3(10);
	vector<int>	veci4(10, 1);
	vector<int>	veci5(veci3.begin(),veci3.end());
	vector<int>	veci6(veci4);
	veci6 = { 1,2,3,4,5 };
	/*
	for (auto c:veci6)
	{
		cout << c << endl;
	}
	
	array<int, 3>	arri = { 1,2,3 };
	arri = { 7 };
	cout << "arri:" << endl;
	for (auto c:arri)
	{
		cout << c << endl;
	}

	array<int, 3>	arri2{ 9 };
	array<int, 3>	arri3(arri);
	array<int, 3>	arri4 = arri2;
	//	arri2.assign(arri.begin(),arri.end());	//no 2 param
	//arri2.assign(7);	//no
	cout << "arri4:" << endl;
	for (auto c:arri4)
	{
		cout << c << endl;
	}
	vector<int>	veci7;
	//veci7.assign({ 7,9,990 });
	veci7.assign(10, 2);
	cout << "veci7:" << endl;
	for (auto c:veci7)
	{
		cout << c << endl;
	}
	/*
	vector<int>	vecI{11, 22, 33};
	array<int, 3>	ai2{ 1,2,3 };
	//array<int, 3> ai(ai2.begin(),ai2.end()-1);
	//vector<int>	vecI2(vecI.begin(), vecI.end());
	vector<int>	vecI3(ai2.begin(), ai2.end());

	int	arri[3] = { 10,20,30 };
	vector<int>	vecI4(begin(arri), end(arri));
	//array<int, 3>	ai3 (vecI4.begin(),vecI4.end());	//no

	for (auto c:vecI4)
	{
		cout << c << endl;
	}

	/*
	int a[3]{};
	for (auto c:a)
	{
		cout << c << endl;
	}


	/*

	const vector<int> veci;
	vector<int>	veci2;
	auto t1 = veci.begin();
	auto t2 = veci2.begin();
	auto t3 = veci2.cbegin();


	/*
	vector<TestStruct>	vecTS(2);
	TestStruct	t1;

	vecTS.insert(vecTS.begin(),t1);
	vecTS.emplace_back(t1);
	vecTS.emplace_back(TestStruct{ 10,2.3 });
	vecTS.insert(vecTS.end(), TestStruct{ 2,7.9 });

	vector<TestStruct>::value_type	k1;
	vector<TestStruct>::reference	r1 = t1;
	using	ty1 = vector<TestStruct>;
	ty1	t2;
	ty1::value_type	k2;
	auto	dd1 = vecTS.end() - vecTS.begin();
	cout << "dd1:" << dd1 << endl;

	auto d3 = vecTS.rbegin();
	auto d4 = vecTS.rend();

	//vecTS.erase(vecTS.begin() + 1, vecTS.end());

	for (auto c : vecTS)
	{
		cout << c.i << " " << c.d << endl;
	}

	auto	vecBeg = vecTS.begin();
	auto	vecEnd = vecTS.end();
	auto	vecCounts = vecEnd - vecBeg;

	cout << "have " << vecCounts << "s data in this vector!" << endl;
	cout <<"MaxCounts:"<< vecTS.max_size() << endl;

	/*
	ifstream	wRFile("unicodet4.txt");
	wRFile.seekg(0, wRFile.end);
	auto	fSize = wRFile.tellg();
	wRFile.seekg(2, wRFile.beg);
	wcout << wRFile.rdbuf() << endl;

	string	wc;
	while (!wRFile.eof())
	{
		wRFile >> wc;
		cout << wc << endl;
	}

	/*
	auto	dest_pc = new char[fSize*2]();
	

	ostringstream	oss;
	oss << wRFile.rdbuf();
	string	strTmp;
	strTmp = oss.str();
	cout << strTmp << endl;
	auto pc = strTmp.c_str();

	
	//strcpy_s(dest_pc,12,pc);
	//cout << dest_pc << endl;

	//WideCharToMultiByte(CP_ACP,0,wRFile.rdbuf(),)
	


	/*
	TCHAR testChar[BUFFER_SIZE];
	memset(testChar, 0, sizeof(TCHAR)*BUFFER_SIZE);
	wsprintf(testChar, L"汉字");

	size_t wsize = wcslen(testChar);
	cout << wsize << endl;


	cout << "cout output :" << testChar << endl;  //只能输出地址  
	//wcout<<"wcout output :"<<testChar<<endl;  //输出空(连后面的endl都没有，程序异常结束)  

	size_t	convers = 0;
	auto	pc = new char[BUFFER_SIZE * 2]();

	//locale loc("chs");
	//wcout.imbue(loc);
	_wsetlocale(LC_ALL, L"zh-CN");
	auto nReturnLen = wcstombs_s(&convers, pc, BUFFER_SIZE*2, testChar,_TRUNCATE);
	cout <<pc << endl;
	cout << nReturnLen << endl;

	/*
	auto nLen=WideCharToMultiByte(CP_ACP, 0, testChar, BUFFER_SIZE, 0, 0, NULL, NULL);
	WideCharToMultiByte(CP_ACP, 0, testChar, nLen, pc, BUFFER_SIZE * 2, NULL, NULL);
	cout << pc << endl;
	//UnicodeToAnsi(testChar, pc);
	
	/*
	wcstombs_s(&convers,pc,BUFFER_SIZE*2, testChar, _TRUNCATE);
	auto	buf = new char[BUFFER_SIZE * 2]();
	strcpy_s(buf, BUFFER_SIZE * 2, pc);
	cout <<buf << endl;


	/*
	// 方法二：转化为ANSI字符集
	char szcConv[BUFFER_SIZE];
	memset(szcConv, 0, BUFFER_SIZE * sizeof(char));
	wcs2mbs(testChar, szcConv);
	cout << "After conversion : " << szcConv << endl;

	/*
	// 方法一：本地化 
	locale loc("chs");
	wcout.imbue(loc);
	wcout << endl << "After locale ,wcout out:" << testChar << endl;
	
	
	


	/*
	//const wchar_t	*wc = L"ab";
	const char	*pc = "ab";

	ofstream	ofile("t4.txt");
	ostringstream	oss;
	//ofile << "abc";
	//oss << "abc";
	//oss << pc;
	//ofile << oss.str();
	//cout << oss.str()<< endl;

	/*
	auto	pc = oss.rdbuf();
	pc->sputn("abc", 3);
	//cout << pc->str() << endl;
	//cout << oss.str() << endl;
	//ofile << oss.str();
	cout << oss.rdbuf() << endl;

	/*
	ifstream	RFile("unicodet4.txt");
	RFile.seekg(0, RFile.end);
	auto	fSize = RFile.tellg();
	//RFile.seekg(2, RFile.beg);
	//cout << RFile.rdbuf() << endl;
	
	char DestBuf[256];
	wostringstream	woss;
	woss << RFile.rdbuf();
	wstring		wstr = woss.str();
	//cout << str << endl;
	const wchar_t	*pwc = wstr.c_str();
	size_t		convers = 0;
	wcstombs_s(&convers, DestBuf, fSize, pwc, _TRUNCATE);
	DestBuf[255] = '\0';
	cout << convers << endl;
	cout << DestBuf << endl;

	/*
	size_t	i;
	char   *pMBBuffer = (char *)malloc(BUFFER_SIZE);
	const wchar_t*pWCBuffer = L"Hello, world.";                             //(1)
																		//wchar_t*  pWCBuffer = L"世界, 你好.";  //换成_T("世界, 你好.")也不行 //(2)

	printf("Convert wide-character string:\n");

	// Conversion
	wcstombs_s(&i, pMBBuffer, (size_t)BUFFER_SIZE,
		pWCBuffer, (size_t)BUFFER_SIZE);

	// Output
	printf("   Characters converted: %u\n", i);
	printf("    Multibyte character: %s\n\n",
		pMBBuffer);

	// Free multibyte character buffer
	if (pMBBuffer)
	{
		free(pMBBuffer);
	}

	/*
	

	/*
	string	strTmp;
	auto	buf = new char[4]();
	ostringstream	oss;
	string	str = "abc";
	oss << str;
	strTmp = oss.str();
	auto buf2 = strTmp.c_str();
	cout <<buf2	 << endl;
	/*
	strcpy_s(buf,4, "abc");
	cout << buf << endl;

	/*
	

	/*
	
	/*
	const wchar_t	*fname =L"unicodet4.txt";
	FILE	*pfile = NULL;
	
	_wfopen_s(&pfile, fname, L"r ccs=UNICODE");
	wchar_t		buf[10];
	if (!fgetws(buf, 9, pfile))
	{
		cout << "fgets is error" << endl;
		return -1;
	}
	buf[9] = L'\0';
	//printf("%ls", buf);

	/*
	if (_wfopen_s(&pfile,L"unicodet4.txt", L"r,ccs=UNICODE")!=0)
	{
		cout << pfile << endl;
	}

	/*
	char	c[2] = { 49,'\x6c' };
	ofstream	ofile("tt3.txt");
	ofile << c;
	
	cout << ofile.rdbuf() << endl;

	/*
	ifstream	ifile("unicodet4.txt");
	if (!ifile)
	{
		cout << "file open error!" << endl;
	}
	else
	{
		ifile.seekg(2, ifile.beg);
		//cout << ifile.rdbuf() << endl;
		char	c[2];
		ifile.read(&c[0], 1);
		ifile.read(&c[1], 1);
		//cout << c[0] << c[1] << endl;
		printf("%x %x\n", c[0], c[1]);
	}


	/*
	//ifstream	ifile("unicodet2.txt");
	ofstream	ofile("unicodet4.txt");
	//ofile << ifile.rdbuf();
	ofile.write("\xff\xfe", 2);
	ofile.write((char*)L"汉字a", 6);
	ofile.close();

	/*
	string		str;
	


	/*
	size_t	convers = 0;
	wcstombs_s(&convers, DestBuf, fSize, pwc, _TRUNCATE);
	cout << convers << endl;
	cout << DestBuf << endl;

	/*
	const wchar_t str[] = L"wcs";
	auto  buffer = new char[32]();
	size_t ret=0;

	printf("wchar_t string: %ls \n", str);
	
	wcstombs_s(&ret,buffer,32, str, _TRUNCATE);
	if (ret == 32) buffer[31] = '\0';
	//if (ret) printf("multibyte string: %zd %s \n",ret, buffer);
	if (ret)
	{
		cout <<"multibyte string:" <<ret<<" "<< buffer << endl;
	}

	/*
	
	/*
	const char	*pc = "abc";
	string		str;
	str = pc;
	cout << str << endl;


	/*
	auto		fileSize = wRFile.tellg();
	cout << "fileSize:" << fileSize << endl;
	auto		buf = new wchar_t[fileSize]();
	
	wRFile.read(buf,fileSize);
	wcout << buf << endl;
	delete(buf);


	/*
	ifstream	RFile("unicodet2.txt");
	char	c;
	RFile.read(&c, 1);
	cout << c << endl;

	/*
	wifstream	wRFile("unicodet2.txt");
	wofstream	wWFile("uncodet2_bak.txt");
	wostringstream	woss;
	woss << wRFile.rdbuf();
	wWFile << woss.str();
	wRFile.close();
	wWFile.close();

	/*
	ifstream	RFile("unicodet2.txt");
	ofstream	WFile("uncodet2_bak.txt");
	ostringstream	oss;
	oss << RFile.rdbuf();
	WFile << oss.str();
	RFile.close();
	WFile.close();

	/*
	ifstream	RFile("unicodet2.txt");
	cout << RFile.rdbuf() << endl;
	
	//ostringstream	oss;
	//oss << RFile.rdbuf();
	//cout << oss.str() << endl;
	RFile.close();


	wifstream	wRFile("unicodet2.txt");
	wcout << wRFile.rdbuf() << endl;
	//wostringstream	woss;
	//woss << wRFile.rdbuf();
	//wcout << woss.str() << endl;
	

	wRFile.close();

	
	

	
	/*
	wchar_t		*pwc;
	size_t		convertedChars = 0;
	ifstream	RFile("unicode.txt");
	if (!RFile.is_open())
	{
		cout << "open file error" << endl;
		return -1;
	}
	RFile.seekg(0, ios::end);
	auto		fileSize = RFile.tellg();
	pwc = new wchar_t[fileSize]();
	RFile.seekg(0, RFile.beg);
	ostringstream	oss;
	oss << RFile.rdbuf();
	strLine = oss.str();

	auto pc = strLine.c_str();
	//cout << strLine << endl;
	cout << pc << endl;

	//mbstowcs(pwc, pc, fileSize);
	mbstowcs_s(&convertedChars, pwc,fileSize, pc, _TRUNCATE);
	wstring	strTmp = pwc;
	cout << convertedChars<< endl;

	
	/*
	ifstream	RFile("unicode.txt");
	//RFile.seekg(2, ios::beg);
	while (!RFile.eof())
	{
		wchar_t		wc;
		RFile.read((char*)&wc, 2);
		cout << wc << endl;
	}


	
	

	/*
	wifstream	wRFile("unicode.txt", ios::binary);
	while (!wRFile.eof())
	{
		wchar_t		wc;
		wRFile.read(&wc, 2);
		cout << wc<<endl;
	}

	/*
		/*
	wifstream	wRFile("unicode.txt");
	wRFile.seekg(1);
	wostringstream	wOss;
	wOss << wRFile.rdbuf();
	wcout << wOss.str() << endl;


	/*
	ifstream	RFile("tt.txt");
	cout << RFile.rdbuf() << endl;



	//auto pFContext = cout.rdbuf(outFile.rdbuf());
	//auto	pFcontext = cin.rdbuf(infile.rdbuf());
	
	/*
	outFile << infile.rdbuf();
	outFile.close();
	infile.close();

	ifstream	ifile("tt.txt");
	cout << ifile.rdbuf() << endl;
	ifile.close();
	
	cout << strLine << endl;
	
	
	

	/*	
	while (getline(infile, strLine)	)
	{
		//cout << strLine << endl;
		PersonInfo	pi;
		string	strTmp;
		istringstream	iss(strLine);

		iss >> pi.strName;
		while (iss>>strTmp)
		{
			pi.vecStrTel.push_back(strTmp);
		}
		vecPersonInfo.push_back(pi);
	}
	
	for (auto c:vecPersonInfo)
	{
		cout << c.strName << "-";
		for (auto e:c.vecStrTel)
		{
			cout << e << " ";
		}
		cout << endl;
	}
	/*
	while (infile >> strLine)
	{
		cout << strLine << endl;
	}
	*/
	

	return 0;
}


