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

	cout << "2018��ѡ��C�����ҳɼ�С��60�ֵ�ѧ��Ϊ��" << endl;
	outfile << "2018��ѡ��C�����ҳɼ�С��60�ֵ�ѧ��Ϊ��" << endl;
	s1 = (SetofStudent.find_school_year(2018)) && SetofStudent.range_find_coursescore("C Programming Language", 0, 60);
	printAll(s1);
	writeInAll(outfile, s1);
	outfile << endl;


	cout << "�γ�ƽ���ִ���80��ѧ��Ϊ��" << endl;
	outfile << "�γ�ƽ���ִ���80��ѧ��Ϊ��" << endl;
	s2 = SetofStudent.range_find_averagescore(80, 101);
	printInfo(s2);
	writeInInfo(outfile, s2);
	cout << endl; outfile << endl;

	cout << "����12ѧ�ֵ�ѧ��Ϊ��" << endl;
	outfile << "����12ѧ�ֵ�ѧ��Ϊ��" << endl;
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
	{cout << "�ļ���ʧ��" << endl; return 0;}
	StudentSet SetofStudent(s_info, s_cour);
	Text(SetofStudent);
	return 0;
}