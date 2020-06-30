#include "Student.h"
#include "StudentSet.h"
#include <iostream>
#include <fstream>



using namespace std;

void Text(StudentSet& SetofStudent)
{
	ofstream outfile;
	set<Student> s1, s2, s3;
	outfile.open("result.txt", ios::out | ios::trunc);

	cout << "2018级选修C语言且成绩小于60分的学生为：" << endl;
	outfile << "2018级选修C语言且成绩小于60分的学生为：" << endl;
	s1 = (SetofStudent.find_school_year(2018)) && SetofStudent.range_find_coursescore("C Programming Language", 0, 60);
	printAll(s1);
	writeInAll(outfile, s1);
	outfile << endl;


	cout << "课程平均分大于80的学生为：" << endl;
	outfile << "课程平均分大于80的学生为：" << endl;
	s2 = SetofStudent.range_find_averagescore(80, 101);
	printInfo(s2);
	writeInInfo(outfile, s2);
	cout << endl; outfile << endl;

	cout << "修满12学分的学生为：" << endl;
	outfile << "修满12学分的学生为：" << endl;
	s3 = SetofStudent.range_find_totalcredit(12, 100);
	printInfo(s3);
	writeInInfo(outfile, s3);
	cout << endl; outfile << endl;

}
int main()
{
	ifstream s_info, s_cour;
	s_info.open("StudentInfo.txt");
	s_cour.open("StudentCourse.txt");
	if (!s_info.is_open() || !s_cour.is_open())
	{cout << "文件打开失败" << endl; return 0;}
	StudentSet SetofStudent(s_info, s_cour);
	Text(SetofStudent);
	return 0;
}