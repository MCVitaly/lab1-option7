#pragma once
#include <vector>
#include <time.h>
using namespace std;

const vector<char> createID();

class Student
{
private:
	Student() = default;
protected:
	const vector<char> _ID=createID();
	vector<char> _name;
	int _course;
	int _group;
	int _numOfRecordBook;
public:
	Student(vector<char> name, int course, int group, int numOfRecordBook);
	Student(const Student& other);

	void set_name(vector<char> name) { _name = name; }
	vector<char> get_name() { return _name; }

	void set_course(int course) { _course = course; }
	int get_course() { return _course; }

	void set_group(int group) { _group=group; }
	int get_group() { return _group; }

	int get_numOfRecordBook() { return _numOfRecordBook; }

	vector<char> get_ID() { return _ID; }

	ostream& operator<<(ostream& output);
};

class StudentAfterFirstSession : public Student
{
protected:
	int _marksAfterFirstSession[4];
public:
	void set_marksAfterFirstSession(int* marksAfterFirstSession)
	{
		for (int i = 0; i < 4; i++)
		{
			_marksAfterFirstSession[i] = marksAfterFirstSession[i];
		}
	}
	int* set_marksAfterFirstSession() { return _marksAfterFirstSession; }

	ostream& operator<<(ostream& output);
};

class StudentAfterSecondSession : public StudentAfterFirstSession
{
private:
	int _marksAfterSecondSession[5];
public:
	void set_marksAfterSecondSession(int* marksAfterSecondSession)
	{
		for (int i = 0; i < 4; i++)
		{
			_marksAfterSecondSession[i] = marksAfterSecondSession[i];
		}
	}
	int* set_marksAfterSecondSession() { return _marksAfterSecondSession; }

	ostream& operator<<(ostream& output);
};