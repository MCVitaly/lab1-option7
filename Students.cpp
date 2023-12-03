#include <iostream>
#include <time.h>
#include "Students.h"
#include <ostream>
using namespace std;

int count_ID = 0;

const vector<char> createID()
{
	vector<char> ID = { 'I', 'D' };
	for (int i = 1000; i > 0; i /= 10)
	{
		ID.push_back(48 + (count_ID - count_ID % i) % (i * 10));
	}
	count_ID++;
	return ID;
}

int averageScoreAfterFirstSession(vector<StudentAfterFirstSession*> student)
{
	int temp = 0;
	for (StudentAfterFirstSession* obj : student) {
		temp += obj->averageScore();
	}
	return temp / student.size();
}

int averageScoreAfterTwoSession(vector<StudentAfterSecondSession*> student)
{
	int temp = 0;
	for (StudentAfterFirstSession* obj : student) {
		temp += obj->averageScore();
	}
	for (StudentAfterSecondSession* obj : student) {
		temp += obj->averageScore();
	}
	return temp / (2 * student.size());
}

int averageScoreOfGroupAfterFirstSession(vector<StudentAfterFirstSession*> student, int numOfGroup)
{
	int temp = 0;
	int count = 0;
	for (StudentAfterFirstSession* obj : student) {
		if (obj->get_group() == numOfGroup)
		{
			temp += obj->averageScore();
			count++;
		}
	}
	return temp / count;
}

int averageScoreOfGroupAfterSecondSession(vector<StudentAfterSecondSession*> student, int numOfGroup)
{
	int temp = 0;
	int count = 0;
	for (StudentAfterFirstSession* obj : student) {
		if (obj->get_group() == numOfGroup)
		{
			temp += obj->averageScore();
			count++;
		}
	}
	for (StudentAfterSecondSession* obj : student) {
		if (obj->get_group() == numOfGroup)
		{
			temp += obj->averageScore();
			count++;
		}
	}
	return temp / count;
}

Student::Student(char* name, int course, int group, int numOfRecordBook)
{
	_name = name;
	_course = course;
	_group = group;
	_numOfRecordBook = numOfRecordBook;
}

Student::Student(const Student& other)
{
	_name = other._name;
	_course = other._course;
	_group = other._group;
	_numOfRecordBook = other._numOfRecordBook;
}


ostream& Student::operator<<(ostream& output)
{
	output << "_______________________________________________________________________________________"
		<< endl << "Student" << endl;
	for (int i = 0; i < _ID.size(); i++)
	{
		output << _ID[i];
	}
	output << endl <<
		"Name: ";
	for (int i = 0; _name[i] != '\0'; i++)
	{
		output << _name[i];
	}
	output << endl <<
		"Course: " << _course << endl <<
		"Group: " << _group << endl <<
		"Number of record book: " << _numOfRecordBook << endl
		<< "_______________________________________________________________________________________" << endl;
	return output;

}

ostream& StudentAfterFirstSession::operator<<(ostream& output)
{
	output << "_______________________________________________________________________________________"
		<< endl << "Student after first session" << endl;
	for (int i = 0; i < _ID.size(); i++)
	{
		output << _ID[i];
	}
	output << endl <<
		"Name: ";
	for (int i = 0; i < _name[i] != '\0'; i++)
	{
		output << _name[i];
	}
	output << endl <<
		"Course: " << _course << endl <<
		"Group: " << _group << endl <<
		"Number of record book: " << _numOfRecordBook << endl <<
		"Marks for first session: ";
	for (int i = 0; i < 4; i++)
	{
		output << _marksAfterFirstSession[i] << " ";
	}
	output << endl
		<< "_______________________________________________________________________________________" << endl;
	return output;

}

int StudentAfterFirstSession::averageScore()
{
	int temp = 0;
	for (int i = 0; i < 4; i++)
	{
		temp += _marksAfterFirstSession[i];
	}
	return temp / 4;
}

ostream& StudentAfterSecondSession::operator<<(ostream& output)
{
	output << "_______________________________________________________________________________________"
		<< endl << "Student after second session" << endl;
	for (int i = 0; i < _ID.size(); i++)
	{
		output << _ID[i];
	}
	output << endl <<
		"Name: ";
	for (int i = 0; i < _name[i] != '\0'; i++)
	{
		output << _name[i];
	}
	output << endl <<
		"Course: " << _course << endl <<
		"Group: " << _group << endl <<
		"Number of record book: " << _numOfRecordBook << endl <<
		"Marks for first session: ";
	for (int i = 0; i < 4; i++)
	{
		output << _marksAfterFirstSession[i] << " ";
	}
	output << endl
		<< "_______________________________________________________________________________________" << endl;;
	return output;

}

int StudentAfterSecondSession::averageScore() {
	int temp = 0;
	for (int i = 0; i < 5; i++)
	{
		temp += _marksAfterSecondSession[i];
	}
	return temp / 5;
}
