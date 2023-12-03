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
	const vector<char> _ID = createID();
	char* _name;
	int _course;
	int _group;
	int _numOfRecordBook;
public:
	Student(char* name, int course, int group, const int numOfRecordBook);
	Student(const Student& other);

	//set and get
	void set_name(char* name) { _name = name; }
	char* get_name() { return _name; }

	void set_course(int course) { _course = course; }
	int get_course() { return _course; }

	void set_group(int group) { _group = group; }
	int get_group() { return _group; }

	int get_numOfRecordBook() { return _numOfRecordBook; }

	vector<char> get_ID() { return _ID; }
	//

	ostream& operator<<(ostream& output);
};

class StudentAfterFirstSession : public Student
{
private:
	StudentAfterFirstSession() = default;
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
	int* get_marksAfterFirstSession() { return _marksAfterFirstSession; }

	StudentAfterFirstSession(char* name, int course, int group, const int numOfRecordBook) :Student(name, course, group, numOfRecordBook) {}
	StudentAfterFirstSession(const StudentAfterFirstSession& other) :Student(other) {}


	ostream& operator<<(ostream& output);

	virtual int averageScore();
};

class StudentAfterSecondSession : public StudentAfterFirstSession
{
private:
	StudentAfterSecondSession() = default;
	int _marksAfterSecondSession[5];
public:
	void set_marksAfterSecondSession(int* marksAfterSecondSession)
	{
		for (int i = 0; i < 5; i++)
		{
			_marksAfterSecondSession[i] = marksAfterSecondSession[i];
		}
	}
	int* get_marksAfterSecondSession() { return _marksAfterSecondSession; }

	StudentAfterSecondSession(char* name, int course, int group, const int numOfRecordBook) :StudentAfterFirstSession(name, course, group, numOfRecordBook) {}
	StudentAfterSecondSession(const StudentAfterFirstSession& other) :StudentAfterFirstSession(other) {}

	ostream& operator<<(ostream& output);

	int averageScore() override;

};

int averageScoreAfterFirstSession(vector<StudentAfterFirstSession*> student);
int averageScoreAfterTwoSession(vector<Student*> student);

int averageScoreOfGroup(vector<Student*> student, int numOfgroup);
int averageScoreOfGroupAfterSecondSession(vector<StudentAfterSecondSession*> student, int numOfGroup);
