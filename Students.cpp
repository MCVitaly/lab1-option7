#include <iostream>
#include <time.h>
#include "Students.h"
#include <ostream>
using namespace std;

const vector<char> createID()
{
	srand(time(NULL));
	vector<char> ID = { 'B', 'S', 'U'};
	for (int i = 0; i < 7; i++)
	{
		ID.push_back(48 + rand() % 10);
	}
	return ID;
}

Student::Student(vector<char> name, int course, int group, int numOfRecordBook)
{
	_name = name;
	_course = course;
	_group = group;
	_numOfRecordBook = numOfRecordBook;
}


Student::Student(const Student& other)
{
	_name = other._name;
	_course - other._course;
	_group = other._group;
	_numOfRecordBook = other._numOfRecordBook;
}

ostream& Student::operator<<(ostream& output)
{
	output << "Student" << endl <<
		"Name: ";
	for (int i = 0; i < _name.size(); i++)
	{
		output << _name[i];
	}
	output << endl <<
		"Course: " << _course << endl <<
		"Group: " << _group << endl <<
		"Number of record book: " << _numOfRecordBook << endl;

}

ostream& StudentAfterFirstSession::operator<<(ostream& output)
{
	output << "Student" << endl <<
		"Name: ";
	for (int i = 0; i < _name.size(); i++)
	{
		output << _name[i];
	}
	output << endl <<
		"Course: " << _course << endl <<
		"Group: " << _group << endl <<
		"Number of record book: " << _numOfRecordBook << endl<<
		"Marks for first session: ";
	for (int i = 0; i < 4; i++)
	{
		output << _marksAfterFirstSession[i] << " ";
	}
	output << endl;

}

ostream& StudentAfterSecondSession::operator<<(ostream& output)
{
	output << "Student" << endl <<
		"Name: ";
	for (int i = 0; i < _name.size(); i++)
	{
		output << _name[i];
	}
	output << endl <<
		"Course: " << _course << endl <<
		"Group: " << _group << endl <<
		"Number of record book: " << _numOfRecordBook << endl<<
		"Marks for first session: ";
	for (int i = 0; i < 4; i++)
	{
		output << _marksAfterFirstSession[i] << " ";
	}
	output << endl;;

}
