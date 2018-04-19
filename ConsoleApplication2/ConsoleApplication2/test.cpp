#include "stdafx.h"
#include "test.h"


void binaryfile_to_binaryfile(ifstream &ifs,ofstream &ofs)
{
	//ifstream	ifs("tt.jpg", ios::binary | ios::ate);
	//ofstream	ofs("tt_bak.jpg", ios::binary);
	char *memblock = nullptr;
	if (ifs)
	{
		auto filesize = ifs.tellg();
		memblock = new char[filesize];
		ifs.seekg(0, ios::beg);
		ifs.read(memblock, filesize);
		ofs.write(memblock, filesize);

		//cout << memblock << endl; //binary 不可以输出。。。
		cout << "file size:" << filesize << " bytes  >file copy succesed.\n";
		delete[]	memblock;
		ifs.close();
		ofs.close();
	}
	else
	{
		cerr << "open origin file is invaild.\n";
	}
}

void	End_of_loop(istream &is,const char c,const string &s)
{
	char ch;
	is >> ch;
	if (ch != c)
	{
		throw Input_type_error(s);
	}
	
}

int		month_to_int(const string &mm)
{
	if (mm == "jan") return 1;
	if (mm == "feb") return 2;
	if (mm == "mar") return 3;
	if (mm == "apr") return 4;
	if (mm == "may") return 5;
	if (mm == "jun") return 6;
	if (mm == "jul") return 7;
	if (mm == "aug") return 8;
	if (mm == "sep") return 9;
	if (mm == "oct") return 10;
	if (mm == "nov") return 11;
	if (mm == "dec") return 12;
	return 0;
}

void Input_error(const string &s)
{
	throw Input_type_error(s);

}

void FileReadingTest::read_file()
{
	int line = 1;
	Reading	rd;
	while (true)
	{
		ist >> rd.uHour >> rd.dTemperature;
		if (ist.eof())
		{
			cout << "Reading file sucessed. End of file.\n";
			break;
		}
		if (chkfile())
			vecReading.push_back(rd);
		else
		{
			cout << "line " << line << " data is invalid.\n";
			break;
		}
		++line;

	}
}

void FileReadingTest::pt_file()
{
	read_file();
	cout << "File context:\n";
	for (auto c : vecReading)
	{
		cout << "hour:" << c.uHour << "  Temperature:" << c.dTemperature << endl;

	}
}

bool FileReadingTest::chkfile()
{
	if (ist.fail() || ist.bad())
	{
		cout << "bad reading in file.\n";
		//funerr("bad reading in file.");
		return	false;
	}
	return true;
}

istream & operator>>(istream & is, Reading2 & r)
{
	// TODO: 在此处插入 return 语句
	char ch1;
	if (is>>ch1 && ch1!='(')
	{
		is.unget();
		is.clear(ios_base::failbit);
		return is;
	}

	char ch2;
	int d;
	int h;
	double	t;
	is >> d >> h >> t >> ch2;
	//if (!is || ch2 != ')') funerr("bad reading.");
	if (!is || ch2 != ')') cerr << "bad reading.\n";

	r.day = d;
	r.hour = h;
	r.tmps = t;
	return is;
	

	/*
	for (char ch;is>>ch;)
	{
		if (ch=='(')
		{
			is >> r.day >> r.hour >> r.tmps;
			if (!is || ch)
			{
			}
			return is;
		}
	}
	
	return is;
	*/
}

istream & operator>>(istream & is, Month & m)
{
	char ch;
	is >> ch;
	if (ch!='{')
	{
		is.unget();
		is.clear(ios_base::failbit);
		return is;
	}

	string	month_marker;
	string	str_month;
	is >> month_marker>>str_month;
	if (!is || month_marker!="month")
	{
		Input_type_error("bad month marker.");
	}
	m.month = month_to_int(str_month);
	for (Reading2 r;is>>r;)
	{
		m.vec_day[r.day].vec_hour[r.hour] = r.tmps;
	}
	End_of_loop(is, '}', "bad end of month");
	return is;
}

istream & operator>>(istream & is, Year & y)
{
	// TODO: 在此处插入 return 语句
	char ch;
	is >> ch;
	if (ch!='{')
	{
		is.unget();
		is.clear(ios_base::failbit);
		//Input_error("file struct is invaild.");
	}


	string	str_year;
	int	yy;
	is >> str_year >> yy;
	if (!is || str_year!="year")
	{
		throw	Input_type_error("data struct is invaild.");
	}
	y.year = yy;
	
	while (true)
	{
		Month	m;
		if (!(is >> m))break;
		//todo
		y.vec_month[m.month] = m;
	}
	
	End_of_loop(is, '}', "bad end of year.");

	return is;
}

GetWord & GetWord::operator>>(vector<string>& v)
{
	// TODO: 在此处插入 return 语句
	


	return *this;
}
