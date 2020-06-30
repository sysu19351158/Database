#ifndef _STUDENTSET_H_
#define _STUDENTSET_H_

#include"Student.h"
#include <iostream>
#include <set>
#include <map>
using namespace std;

class StudentSet
{

public:
	StudentSet(ifstream& s_info, ifstream& s_cour);

	//各种查询函数
	Student find_id(int i);
	Student find_name(string n);
	set<Student> find_sex(string s);
	set<Student> find_birthday(Date bir);
	set<Student> range_find_birthday(Date bir1, Date bir2);
	set<Student> find_school_year(int y);
	set<Student> range_find_school_year(int y1, int y2);
	set<Student> find_birthplace(string s);
	set<Student> find_course(string s);
	set<Student> find_totalcredit(double t);
	set<Student> range_find_totalcredit(double t1, double t2);
	set<Student> find_score(int i);
	set<Student> range_find_score(int i1, int i2);
	set<Student> range_find_totalscore(int i1, int i2);
	set<Student> range_find_averagescore(double d1, double d2);
	set<Student> range_find_coursescore(string s, int i1, int i2);

	//删除函数以查询结果为参数，在各个map中删除相应元素
	void deleteStudent(set<Student> ss);

private:
	multimap<int, Studentcourse> id_Stu_course_map;
	map<int, Student> Stu_map;

	map<string, Student> name_Stu_map;
	multimap<string, Student> sex_Stu_map;
	multimap<Date, Student, ComDate> birthday_Stu_map;
	multimap<int, Student> sch_year_Stu_map;
	multimap<string, Student> birthplace_Stu_map;
	multimap<int, Student> totalscore_Stu_map;
	multimap<double, Student> averagescore_Stu_map;
	multimap<double, Student> totalcredit_Stu_map;
	multimap<string, Student> course_Stu_map;
	multimap<int, Student> score_Stu_map;
};


//用于map对value，也就是Student对象的查找
template<class T>
class map_student_finder
{
public:
	map_student_finder(const Student s) :stu(s) {}
	bool operator ()(const typename map<T, Student>::value_type& pair)
	{
		return pair.second == stu;
	}
private:
	const Student stu;
};

#endif