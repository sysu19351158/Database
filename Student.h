#ifndef _STUDENT_H_
#define _STUDENT_H_
#include<iostream>
#include <map>
#include <iomanip>
#include <set>
using namespace std;
class Date
{
	friend class Student;
	friend struct ComDate;
	friend ostream& operator << (ostream& os, Date t);
public:
	Date() {}
	Date(int y, int m, int d) : year{ y }, month{ m }, day{ d }{}
	bool operator == (const Date& d)const { return (year == d.year && month == d.month && day == d.day); }
private:
	int year, month, day;
};

//Date的大小比较，用于以Date为key的map中
struct ComDate {
	bool operator()(const Date& d1, const Date& d2) const
	{
		if (d1.year < d2.year)
			return 1;
		else if (d1.year > d2.year)
			return 0;
		else
		{
			if (d1.month < d2.month)
				return 1;
			else if (d1.month > d2.month)
				return 0;
			else
			{
				if (d1.day < d2.day)
					return 1;
				else
					return 0;
			}
		}
	}
};

class Studentcourse
{
	friend class StudentSet;
	friend class Student;
public:
	Studentcourse(int i, string c, double cd, int s) :id{ i }, course{ c }, credit{ cd }, score{ s }{}
	bool operator == (const Studentcourse& s) const { return id == s.id && score == s.score && credit == s.credit && course == s.course; }
private:
	int id, score;
	double credit;
	string course;
};

class Student
{
	friend class StudentSet;
public:
	Student() {}
	Student(int i, string n, string s, Date bd, int s_y, string b, map<string, Studentcourse> m) :
		id{ i }, name{ n }, sex{ s }, birthday{ bd }, school_year{ s_y }, birthplace{ b }, str_Stu_map{ m }{}
	bool operator <(const Student& s) const
	{
		return id < s.id;
	}
	bool operator == (const Student& s)const
	{
		return (id == s.id && school_year == s.school_year && name == s.name && sex == s.sex & birthplace == s.birthplace && birthday == s.birthday && str_Stu_map == s.str_Stu_map);
	}
	//不同情况可能用到的输出函数
	void showAll()const;
	void showAll();
	void showInfo()const;
	void showInfo();
	void writeInAll(ofstream& s)const;
	void writeInAll(ofstream& s);
	void writeInInfo(ofstream& s)const;
	void writeInInfo(ofstream& s);
private:
	int id, school_year;
	string name, sex, birthplace;
	Date birthday;
	map<string, Studentcourse> str_Stu_map;
};

//统一输出set<Student>的函数
void printAll(set<Student> ss);

void printInfo(set<Student> ss);

void writeInAll(ofstream& s, set<Student> ss);

void writeInInfo(ofstream& s, set<Student> ss);

//set<Student>交并操作
set<Student> operator &&(const set<Student>& s1, const set<Student>& s2);

set<Student> operator ||(const set<Student>& s1, const set<Student>& s2);

#endif