#pragma once
#include <iostream>

using namespace std;
template<typename T>
class Stack
{
private:
	size_t _supremumOfSize;
	size_t _sizeOfStack=0;
	T* _stack;
	void stackIncrease();
public:
	Stack(size_t supremumOfsize);
	Stack();
	~Stack();

	void operator<<(T& element);

	void operator>>(T& inheritedVariable);

	void operator=(Stack& otherStack);

	bool operator==(const Stack& otherStack);

	bool operator<(const Stack& otherStack);

	bool operator>(const Stack& otherStack);

	int operator[](size_t index);

	size_t size();
};
