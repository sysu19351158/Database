
#include "Student.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

ostream& operator << (ostream& os, Date t)
{
	string date = to_string(t.year) + "/" + to_string(t.month) + "/" + to_string(t.day);
	os << date; return os;
}



void Student::showAll()const
{
	cout << setw(6) << setiosflags(ios::left) << "id" << setw(10) << setiosflags(ios::left) << "name"
		<< setw(7) << setiosflags(ios::left) << "sex" << setw(10) << setiosflags(ios::left) << "birthday"
		<< setw(12) << setiosflags(ios::left) << "school_year" << setw(11) << setiosflags(ios::left) << "birthplace" << endl;

	cout << setw(6) << setiosflags(ios::left) << id << setw(10) << setiosflags(ios::left) << name
		<< setw(7) << setiosflags(ios::left) << sex << setw(10) << setiosflags(ios::left) << birthday
		<< setw(12) << setiosflags(ios::left) << school_year << setw(11) << setiosflags(ios::left) << birthplace << endl;

	cout << setw(25) << setiosflags(ios::left) << "course" << setw(7) << setiosflags(ios::left) << "credit"
		<< setw(6) << setiosflags(ios::left) << "score" << endl;

	for (auto iter = str_Stu_map.begin(); iter != str_Stu_map.end(); iter++)
		cout << setw(25) << setiosflags(ios::left) << iter->second.course << setw(7) << setiosflags(ios::left) << iter->second.credit
		<< setw(6) << setiosflags(ios::left) << iter->second.score << endl;
}

void Student::showAll()
{
	cout << setw(6) << setiosflags(ios::left) << "id" << setw(10) << setiosflags(ios::left) << "name"
		<< setw(7) << setiosflags(ios::left) << "sex" << setw(10) << setiosflags(ios::left) << "birthday"
		<< setw(12) << setiosflags(ios::left) << "school_year" << setw(11) << setiosflags(ios::left) << "birthplace" << endl;

	cout << setw(6) << setiosflags(ios::left) << id << setw(10) << setiosflags(ios::left) << name
		<< setw(7) << setiosflags(ios::left) << sex << setw(10) << setiosflags(ios::left) << birthday
		<< setw(12) << setiosflags(ios::left) << school_year << setw(11) << setiosflags(ios::left) << birthplace << endl;

	cout << setw(25) << setiosflags(ios::left) << "course" << setw(7) << setiosflags(ios::left) << "credit"
		<< setw(6) << setiosflags(ios::left) << "score" << endl;

	for (auto iter = str_Stu_map.begin(); iter != str_Stu_map.end(); iter++)
		cout << setw(25) << setiosflags(ios::left) << iter->second.course << setw(7) << setiosflags(ios::left) << iter->second.credit
		<< setw(6) << setiosflags(ios::left) << iter->second.score << endl;
}
void Student::showInfo()const
{
	cout << setw(6) << setiosflags(ios::left) << id << setw(10) << setiosflags(ios::left) << name
		<< setw(7) << setiosflags(ios::left) << sex << setw(10) << setiosflags(ios::left) << birthday
		<< setw(12) << setiosflags(ios::left) << school_year << setw(11) << setiosflags(ios::left) << birthplace << endl;
}
void Student::showInfo()
{
	cout << setw(6) << setiosflags(ios::left) << id << setw(10) << setiosflags(ios::left) << name
		<< setw(7) << setiosflags(ios::left) << sex << setw(10) << setiosflags(ios::left) << birthday
		<< setw(12) << setiosflags(ios::left) << school_year << setw(11) << setiosflags(ios::left) << birthplace << endl;
}



void Student::writeInAll(ofstream& s)const
{
	s << "id" << "\t" << "name"
		<< "\t" << "sex" << "\t" << "birthday"
		<< "\t" << "school_year" << "\t" << "birthplace" << endl;
	s << id << "\t" << name
		<< "\t" << sex << "\t" << birthday
		<< "\t" << school_year << "\t\t" << birthplace << endl;
	s << "course" << "\t\t\t" << "credit" << "\t" << "score" << endl;
	auto count_str_space = [](string& s)
	{
		int count = 0;
		for (unsigned int i = 0; i < s.size(); i++)
			if (s[i] == ' ')
				count += 1;
		return count;
	};
	for (auto iter = str_Stu_map.begin(); iter != str_Stu_map.end(); iter++)
	{
		string str = iter->second.course;
		int count = count_str_space(str);
		if (count == 0)
			s << iter->second.course << "\t\t\t" << iter->second.credit << "\t" << iter->second.score << endl;
		else if (count == 1)
			s << iter->second.course << "\t\t" << iter->second.credit << "\t" << iter->second.score << endl;
		else
			s << iter->second.course << "\t" << iter->second.credit << "\t" << iter->second.score << endl;
	}
}


void Student::writeInAll(ofstream& s)
{
	s << "id" << "\t" << "name"
		<< "\t" << "sex" << "\t" << "birthday"
		<< "\t" << "school_year" << "\t" << "birthplace" << endl;
	s << id << "\t" << name
		<< "\t" << sex << "\t" << birthday
		<< "\t" << school_year << "\t\t" << birthplace << endl;
	s << "course" << "\t\t\t" << "credit" << "\t" << "score" << endl;

	auto count_str_space = [](string& s)
	{
		int count = 0;
		for (unsigned int i = 0; i < s.size(); i++)
			if (s[i] == ' ')
				count += 1;
		return count;
	};
	for (auto iter = str_Stu_map.begin(); iter != str_Stu_map.end(); iter++)
	{
		string str = iter->second.course;
		int count = count_str_space(str);
		if (count == 0)
			s << iter->second.course << "\t\t\t" << iter->second.credit << "\t" << iter->second.score << endl;
		else if (count == 1)
			s << iter->second.course << "\t\t" << iter->second.credit << "\t" << iter->second.score << endl;
		else
			s << iter->second.course << "\t" << iter->second.credit << "\t" << iter->second.score << endl;
	}
}
void Student::writeInInfo(ofstream& s)const
{
	s << id << "\t" << name
		<< "\t" << sex << "\t" << birthday
		<< "\t" << school_year << "\t\t" << birthplace << endl;
}

void Student::writeInInfo(ofstream& s)
{
	s << id << "\t" << name
		<< "\t" << sex << "\t" << birthday
		<< "\t" << school_year << "\t\t" << birthplace << endl;
}


void printAll(set<Student> ss)
{
	for (auto iter = ss.begin(); iter != ss.end(); iter++)
	{
		iter->showAll(); cout << endl;
	}
}


void printInfo(set<Student> ss)
{
	cout << setw(6) << setiosflags(ios::left) << "id" << setw(10) << setiosflags(ios::left) << "name"
		<< setw(7) << setiosflags(ios::left) << "sex" << setw(10) << setiosflags(ios::left) << "birthday"
		<< setw(12) << setiosflags(ios::left) << "school_year" << setw(11) << setiosflags(ios::left) << "birthplace" << endl;
	for (auto iter = ss.begin(); iter != ss.end(); iter++)
	{
		iter->showInfo();
	}
}

void writeInAll(ofstream& s, set<Student> ss)
{
	for (auto iter = ss.begin(); iter != ss.end(); iter++)
	{
		iter->writeInAll(s);
	}
}
void writeInInfo(ofstream& s, set<Student> ss)
{
	for (auto iter = ss.begin(); iter != ss.end(); iter++)
	{
		iter->writeInInfo(s);
	}

}

set<Student> operator &&(const set<Student>& s1, const set<Student>& s2)
{
	set<Student> ss;
	set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(ss, ss.end()));
	return ss;
}
set<Student> operator ||(const set<Student>& s1, const set<Student>& s2)
{
	set<Student> ss;
	set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(ss, ss.end()));
	return ss;
}