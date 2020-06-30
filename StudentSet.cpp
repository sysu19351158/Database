#include"StudentSet.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

StudentSet::StudentSet(ifstream& s_info, ifstream& s_cour)
{
	vector<string> s1, s2;
	string text;
	//用id为key，studentcourse为元素，构造multimap
	while (getline(s_info, text))
		s1.push_back(text);
	while (getline(s_cour, text))
		s2.push_back(text);
	for (unsigned int i = 1; i < s2.size(); i++)
	{
		string str[6];
		istringstream is(s2[i]);
		is >> str[0] >> str[1] >> str[2] >> str[3] >> str[4] >> str[5];
		int id = stoi(str[0]), score;
		double credit;
		string course;
		if (!str[5].empty())
		{
			course = str[1] + " " + str[2] + " " + str[3];
			credit = stod(str[4]); score = stoi(str[5]);
		}
		else if (!str[4].empty())
		{
			course = str[1] + " " + str[2];
			credit = stod(str[3]); score = stoi(str[4]);
		}
		else
		{
			course = str[1]; credit = stod(str[2]); score = stoi(str[3]);
		}
		id_Stu_course_map.insert(pair<int, Studentcourse>(id, Studentcourse(id, course, credit, score)));
	}
	for (unsigned int i = 1; i < s1.size(); i++)
	{
		string ss[6];
		istringstream is(s1[i]);
		is >> ss[0] >> ss[1] >> ss[2] >> ss[3] >> ss[4] >> ss[5];
		int id = stoi(ss[0]), school_year = stoi(ss[4]); string name = ss[1], sex = ss[2], birthplace = ss[5];
		for (unsigned int j = 1; j < ss[3].size(); j++)
		{
			if (ss[3][j] == '/')  ss[3][j] = ' ';
		}
		istringstream is_(ss[3]);
		string sss[3];
		is_ >> sss[0] >> sss[1] >> sss[2];
		Date birthday(stoi(sss[0]), stoi(sss[1]), stoi(sss[2]));
		map<string, Studentcourse> str_Stu_map;
		auto sc = id_Stu_course_map.equal_range(id);
		if (sc.first != end(id_Stu_course_map))
		{
			for (auto iter = sc.first; iter != sc.second; ++iter)
				str_Stu_map.insert(pair<string, Studentcourse>(iter->second.course, iter->second));
		}
		Student stu(id, name, sex, birthday, school_year, birthplace, str_Stu_map);
		Stu_map.insert(pair<int, Student>(id, stu));
	}

	for (auto iter = Stu_map.begin(); iter != Stu_map.end(); iter++)
		name_Stu_map.insert(pair<string, Student>(iter->second.name, iter->second));

	for (auto iter = Stu_map.begin(); iter != Stu_map.end(); iter++)
		sex_Stu_map.insert(pair<string, Student>(iter->second.sex, iter->second));

	for (auto iter = Stu_map.begin(); iter != Stu_map.end(); iter++)
		birthday_Stu_map.insert(pair<Date, Student>(iter->second.birthday, iter->second));

	for (auto iter = Stu_map.begin(); iter != Stu_map.end(); iter++)
		sch_year_Stu_map.insert(pair<int, Student>(iter->second.school_year, iter->second));

	for (auto iter = Stu_map.begin(); iter != Stu_map.end(); iter++)
		birthplace_Stu_map.insert(pair<string, Student>(iter->second.birthplace, iter->second));

	for (auto iter = Stu_map.begin(); iter != Stu_map.end(); iter++)
	{
		int totalscore = 0;
		double averagescore = 0;
		for (auto j = iter->second.str_Stu_map.begin(); j != iter->second.str_Stu_map.end(); j++)
			totalscore += j->second.score;
		averagescore = totalscore / iter->second.str_Stu_map.size();
		totalscore_Stu_map.insert(pair<int, Student>(totalscore, iter->second));
		averagescore_Stu_map.insert(pair<double, Student>(averagescore, iter->second));
	}

	for (auto iter = Stu_map.begin(); iter != Stu_map.end(); iter++)
	{
		double totalcredit = 0;
		for (auto j = iter->second.str_Stu_map.begin(); j != iter->second.str_Stu_map.end(); j++)
		{
			if (j->second.score >= 60)
				totalcredit += j->second.credit;
		}
		totalcredit_Stu_map.insert(pair<double, Student>(totalcredit, iter->second));
	}

	for (auto iter = Stu_map.begin(); iter != Stu_map.end(); iter++)
	{
		for (auto j = iter->second.str_Stu_map.begin(); j != iter->second.str_Stu_map.end(); j++)
			course_Stu_map.insert(pair<string, Student>(j->second.course, iter->second));
	}

	for (auto iter = Stu_map.begin(); iter != Stu_map.end(); iter++)
	{
		for (auto j = iter->second.str_Stu_map.begin(); j != iter->second.str_Stu_map.end(); j++)
			score_Stu_map.insert(pair<int, Student>(j->second.score, iter->second));
	}

}




Student StudentSet::find_id(int i)
{
	if (Stu_map.count(i) > 0)
		return Stu_map[i];
	else
	{
		cout << "未找到符合条件的学生，返回空对象" << endl;
		return Student();
	}
}

Student StudentSet::find_name(string n)
{
	if (name_Stu_map.count(n) > 0)
		return name_Stu_map[n];
	else
	{
		cout << "未找到符合条件的学生，返回空对象" << endl;
		return Student();
	}
}


set<Student> StudentSet::find_sex(string s)
{
	if (sex_Stu_map.count(s) > 0)
	{
		set<Student> ss;
		auto a = sex_Stu_map.equal_range(s);
		if (a.first != end(sex_Stu_map))
		{
			for (auto iter = a.first; iter != a.second; iter++)
				ss.insert(iter->second);
		}
		return ss;
	}
	else
	{
		cout << "未找到符合条件的学生，返回空集" << endl;
		return set<Student>();
	}
}



set<Student> StudentSet::find_birthday(Date bir)
{
	if (birthday_Stu_map.count(bir) > 0)
	{
		set<Student> ss;
		auto a = birthday_Stu_map.equal_range(bir);
		if (a.first != end(birthday_Stu_map))
		{
			for (auto iter = a.first; iter != a.second; iter++)
				ss.insert(iter->second);
		}
		return ss;
	}
	else
	{
		cout << "未找到符合条件的学生，返回空集" << endl;
		return set<Student>();
	}

}


set<Student> StudentSet::range_find_birthday(Date bir1, Date bir2)
{
	auto iter1 = birthday_Stu_map.lower_bound(bir1);
	auto iter2 = birthday_Stu_map.upper_bound(bir2);
	set<Student> ss;
	for (; iter1 != iter2; iter1++)
		ss.insert(iter1->second);
	return ss;

}



set<Student> StudentSet::find_school_year(int y)
{
	if (sch_year_Stu_map.count(y) > 0)
	{
		set<Student> ss;
		auto a = sch_year_Stu_map.equal_range(y);
		if (a.first != end(sch_year_Stu_map))
		{
			for (auto iter = a.first; iter != a.second; iter++)
				ss.insert(iter->second);
		}
		return ss;
	}
	else
	{
		cout << "未找到符合条件的学生，返回空集" << endl;
		return set<Student>();
	}
}


set<Student> StudentSet::range_find_school_year(int y1, int y2)
{
	auto iter1 = sch_year_Stu_map.lower_bound(y1);
	auto iter2 = sch_year_Stu_map.upper_bound(y2 - 1);
	set<Student> ss;
	for (; iter1 != iter2; iter1++)
		ss.insert(iter1->second);
	return ss;

}


set<Student> StudentSet::find_birthplace(string s)
{
	if (birthplace_Stu_map.count(s) > 0)
	{
		set<Student> ss;
		auto a = birthplace_Stu_map.equal_range(s);
		if (a.first != end(birthplace_Stu_map))
		{
			for (auto iter = a.first; iter != a.second; iter++)
				ss.insert(iter->second);
		}
		return ss;
	}
	else
	{
		cout << "未找到符合条件的学生，返回空集" << endl;
		return set<Student>();
	}
}



set<Student> StudentSet::find_course(string s)
{
	if (course_Stu_map.count(s) > 0)
	{
		set<Student> ss;
		auto a = course_Stu_map.equal_range(s);
		if (a.first != end(course_Stu_map))
		{
			for (auto iter = a.first; iter != a.second; iter++)
				ss.insert(iter->second);
		}
		return ss;
	}
	else
	{
		cout << "未找到符合条件的学生，返回空集" << endl;
		return set<Student>();
	}

}


set<Student> StudentSet::find_totalcredit(double t)
{
	if (totalcredit_Stu_map.count(t) > 0)
	{
		set<Student> ss;
		auto a = totalcredit_Stu_map.equal_range(t);
		if (a.first != end(totalcredit_Stu_map))
		{
			for (auto iter = a.first; iter != a.second; iter++)
				ss.insert(iter->second);
		}
		return ss;
	}
	else
	{
		cout << "未找到符合条件的学生，返回空集" << endl;
		return set<Student>();
	}
}


set<Student> StudentSet::range_find_totalcredit(double t1, double t2)
{
	auto iter1 = totalcredit_Stu_map.lower_bound(t1);
	auto iter2 = totalcredit_Stu_map.upper_bound(t2 - 0.1);
	set<Student> ss;
	for (; iter1 != iter2; iter1++)
		ss.insert(iter1->second);
	return ss;
}


set<Student> StudentSet::find_score(int i)
{
	if (score_Stu_map.count(i) > 0)
	{
		set<Student> ss;
		auto a = score_Stu_map.equal_range(i);
		if (a.first != end(score_Stu_map))
		{
			for (auto iter = a.first; iter != a.second; iter++)
				ss.insert(iter->second);
		}
		return ss;
	}
	else
	{
		cout << "未找到符合条件的学生，返回空集" << endl;
		return set<Student>();
	}

}


set<Student> StudentSet::range_find_score(int i1, int i2)
{
	auto iter1 = score_Stu_map.lower_bound(i1);
	auto iter2 = score_Stu_map.upper_bound(i2 - 1);
	set<Student> ss;
	for (; iter1 != iter2; iter1++)
		ss.insert(iter1->second);
	return ss;

}

set<Student> StudentSet::range_find_totalscore(int i1, int i2)
{
	auto iter1 = totalscore_Stu_map.lower_bound(i1);
	auto iter2 = totalscore_Stu_map.upper_bound(i2 - 1);
	set<Student> ss;
	for (; iter1 != iter2; iter1++)
		ss.insert(iter1->second);
	return ss;
}




set<Student> StudentSet::range_find_averagescore(double d1, double d2)
{
	auto iter1 = averagescore_Stu_map.lower_bound(d1);
	auto iter2 = averagescore_Stu_map.upper_bound(d2 - 0.001);
	set<Student> ss;
	for (; iter1 != iter2; iter1++)
		ss.insert(iter1->second);
	return ss;
}


set<Student> StudentSet::range_find_coursescore(string s, int i1, int i2)
{
	set<Student> ss1 = find_course(s);
	multimap<int, Student> coursescore_Stu_map;
	for (auto iter = ss1.begin(); iter != ss1.end(); iter++)
	{
		auto it = iter->str_Stu_map.find(s);
		coursescore_Stu_map.insert(pair<int, Student>(it->second.score, *iter));
	}
	auto iter1 = coursescore_Stu_map.lower_bound(i1);
	auto iter2 = coursescore_Stu_map.upper_bound(i2);
	set<Student> ss2;
	for (; iter1 != iter2; iter1++)
		ss2.insert(iter1->second);
	return ss2;
}


void StudentSet::deleteStudent(set<Student> ss)
{
	for (auto iter = ss.begin(); iter != ss.end(); iter++)
	{
		auto i = id_Stu_course_map.equal_range(iter->id);
		if (i.first != end(id_Stu_course_map))
		{
			for (auto j = i.first; j != i.second; j++)
				id_Stu_course_map.erase(j);
		}

		auto it1 = find_if(Stu_map.begin(), Stu_map.end(), map_student_finder<int>(*iter));
		Stu_map.erase(it1);
		auto it2 = find_if(name_Stu_map.begin(), name_Stu_map.end(), map_student_finder<string>(*iter));
		name_Stu_map.erase(it2);
		auto it3 = find_if(sex_Stu_map.begin(), sex_Stu_map.end(), map_student_finder<string>(*iter));
		sex_Stu_map.erase(it3);
		auto it4 = find_if(birthday_Stu_map.begin(), birthday_Stu_map.end(), map_student_finder<Date>(*iter));
		birthday_Stu_map.erase(it4);
		auto it5 = find_if(sch_year_Stu_map.begin(), sch_year_Stu_map.end(), map_student_finder<int>(*iter));
		sch_year_Stu_map.erase(it5);
		auto it6 = find_if(birthplace_Stu_map.begin(), birthplace_Stu_map.end(), map_student_finder<string>(*iter));
		birthplace_Stu_map.erase(it6);
		auto it7 = find_if(totalscore_Stu_map.begin(), totalscore_Stu_map.end(), map_student_finder<int>(*iter));
		totalscore_Stu_map.erase(it7);
		auto it8 = find_if(averagescore_Stu_map.begin(), averagescore_Stu_map.end(), map_student_finder<double>(*iter));
		averagescore_Stu_map.erase(it8);
		auto it9 = find_if(totalcredit_Stu_map.begin(), totalcredit_Stu_map.end(), map_student_finder<double>(*iter));
		totalcredit_Stu_map.erase(it9);

		for (auto it10 = find_if(course_Stu_map.begin(), course_Stu_map.end(), map_student_finder<string>(*iter)); it10 != course_Stu_map.end(); it10 = find_if(course_Stu_map.begin(), course_Stu_map.end(), map_student_finder<string>(*iter)))
			course_Stu_map.erase(it10);

		for (auto it11 = find_if(score_Stu_map.begin(), score_Stu_map.end(), map_student_finder<int>(*iter)); it11 != score_Stu_map.end(); it11 = find_if(score_Stu_map.begin(), score_Stu_map.end(), map_student_finder<int>(*iter)))
			score_Stu_map.erase(it11);
	}
}



