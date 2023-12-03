#include <iostream>
#include "Students.h"
#include <vector>

using namespace std;


int main()
{
	char name1[] = { 'I', 'v', 'a', 'n', '\0' };
	char name2[] = { 'A', 'l', 'e', 'x', '\0' };
	char name3[] = { 'P', 'e', 't', 'e', 'r', '\0' };
	vector <Student*> students(3);
	students[0] = new Student(name1, 1, 2, 1000001);
	students[1] = new StudentAfterFirstSession(name2, 2, 4, 1000002);
	students[2] = new StudentAfterSecondSession(name3, 1, 2, 1000003);



	return 0;
}