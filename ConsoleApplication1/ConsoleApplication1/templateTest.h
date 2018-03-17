#pragma once

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