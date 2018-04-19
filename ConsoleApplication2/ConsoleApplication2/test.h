#pragma once
#include "stdafx.h"

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