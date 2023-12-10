#pragma once
#include <iostream>

using namespace std;

class Stack
{
private:
	size_t _supremumOfSize;
	size_t _sizeOfStack=0;
	int* _stack = new int[_supremumOfSize];
	void stackIncrease();
public:
	Stack(size_t supremumOfsize);
	Stack();
	~Stack();

	void operator<<(int element);

	void operator>>(int& inheritedVariable);

	void operator=(Stack& otherStack);

	bool operator==(const Stack& otherStack);

	bool operator<(const Stack& otherStack);

	bool operator>(const Stack& otherStack);

	int operator[](size_t index);

	size_t size();
};
