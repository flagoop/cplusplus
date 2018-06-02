#pragma once
#include "stdafx.h"

struct Def_struc
{
	//Def_struc() { cout << "Def_struc()" << endl; };
	Def_struc(int i) { cout << "Def_struc(int)" << endl; };
	void pt() { cout << "pt()" << endl; }
};

struct TmpStruct
{
	void pt() { cout << "pt()" << endl; }
	int v1;
	double	d1;
	int v2;
	


};

template<typename T,int N>
struct Arr
//class Arr
{
	//T elem[N];
	T v1;
};

class Shape
{
public:
	Shape() { cout << "Shape()" << endl; }
	Shape& operator=(Shape &v) { cout << "operator=(Shape &)" << endl; return *this; }
	void pt() { cout <<v1<< " Shape.pt()" << endl; }
protected:
private:
	double v1=1.1;
};

class Circle :public Shape
{
public:
	Circle() { cout << "Circle()" << endl; }
	void pt() { cout << c << " Circle.pt()" << endl; }
protected:
private:
	char c = 'A';
};


class Tmpcls
{
public:
	Tmpcls(int i) {}
	void pt()
	{
		for (auto c:v)
		{
			cout << c <<'\n';
		}
	}
protected:
private:
	vector<int> v;
};

class MyVector
{
public:
	MyVector() = default;

	MyVector(int sz):len(sz),elem(new double[sz])
	{
		for (int i=0;i<len;++i)
		{
			elem[i] = 0.0;
		}
	}
	MyVector(initializer_list<double> lst) :len(lst.size()), elem(new double[len])
	{
		int i = 0;
		for (auto c:lst)
		{
			elem[i] = c;
			++i;
		}
	}


	MyVector(MyVector &v):len(v.len),elem(new double[len])
	{
		for (int i=0;i<v.len;++i)
		{
			elem[i] = v.elem[i];
		}
	}

	
	MyVector(MyVector &&v) :len(v.len), elem(v.elem)
	{
		v.len = 0;
		v.elem = nullptr;
	}
	
	MyVector& operator=(MyVector &&v)
	{
		len = v.len;
		elem = v.elem;
		v.elem = nullptr;
		return *this;
	}

	void set(int pos, double val)
	{
		if (pos>=len)
		{
			cout << "out of range pos:" << pos << '\n';
			return;
		}
		elem[pos] = val;
	}

	void pt()const 
	{
		for (int i=0;i<len;++i)
		{
			cout << elem[i] << " ";
		}
		cout << endl;
	}

	~MyVector()
	{
		delete[] elem;
	}
private:
	size_t len=0;
	double	*elem=nullptr;

};

class GetWord
{
public:
	GetWord(ifstream &ifs, string &wch) :ifs(ifs), white_ch(wch) {};
	void add_white_char(const string &s) { white_ch += s; }
	GetWord& operator>>(vector<string> &v);
protected:
private:
	ifstream &ifs;
	string	white_ch;
	istringstream buffer;
};

void	binaryfile_to_binaryfile(ifstream &ifs, ofstream &ofs);

void	Input_error(const string &s);
void	End_of_loop(istream &is, const char c, const string &s);
int		month_to_int(const string &mm);

class Input_type_error
{
public:
	Input_type_error(string s) :msg(s) {}
	string msg;
};

const int not_a_reading = -900;
const int not_a_month = -1;

struct Day
{
	vector<double> vec_hour{ vector<double>(24,not_a_reading) };
};

struct Month
{
	int month{ not_a_month };
	vector<Day> vec_day{ 31 };
};

struct Year
{
	int year;
	vector<Month> vec_month{ 12 };
};

struct Reading2
{
	size_t	day;
	size_t	hour;
	double	tmps;
};

class Date
{
public:
protected:
private:
	size_t	year;
	size_t	month;
	size_t	day;
};

enum class Month_enum
{
	jan=1,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec
};

istream& operator>>(istream &is, Reading2 &r);
istream& operator>>(istream &is, Month &m);
istream& operator>>(istream &is, Year &y);


class FileReadingTest
{
public:
	FileReadingTest(const string &fname) :ist(fname) {}
	void	read_file();
	void	pt_file();
protected:
private:
	struct Reading
	{
		unsigned	uHour;
		double		dTemperature;
	};
	vector<Reading>	vecReading;
	ifstream	ist;

	bool	chkfile();
};