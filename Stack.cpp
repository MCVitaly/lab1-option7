#include "Stack.h"


void Stack::stackIncrease()
{
	int* newStack = new int[2 * _supremumOfSize];
	_supremumOfSize *= 2;
	for (int i = 0; i < _sizeOfStack; i++)
	{
		newStack[i] = _stack[i];
	}
	_stack = newStack;
	delete[] newStack;
}

Stack::Stack(size_t supremumOfSize) {
	_supremumOfSize = supremumOfSize;
}

Stack::Stack() {
	_supremumOfSize = 10;
}

Stack::~Stack() {
	delete[] _stack;
}

void Stack::operator<<(int element) {
	if (_sizeOfStack == _supremumOfSize) {
		stackIncrease();
	}
	_stack[_sizeOfStack] = element;
	_sizeOfStack++;
}

void Stack::operator>>(int& inheritedVariable) {
	inheritedVariable = _stack[_sizeOfStack-1];
	_stack[_sizeOfStack] = {};
	_sizeOfStack--;
}

void Stack::operator=(Stack& otherStack) {
	_stack = otherStack._stack;
	_supremumOfSize = otherStack._supremumOfSize;
	_sizeOfStack = otherStack._sizeOfStack;
}

bool Stack::operator==(const Stack& otherStack)
{
	if (_supremumOfSize != otherStack._supremumOfSize ||
		_sizeOfStack != otherStack._sizeOfStack) 
	{
		return false;
	}
	for (size_t i = 0; i < _sizeOfStack; i++)
	{
		if (_stack[i] != otherStack._stack[i]) {
			return false;
		}
	}
	return true;
}

bool Stack::operator<(const Stack& otherStack)
{
	return (_sizeOfStack < otherStack._sizeOfStack);
}

bool Stack::operator>(const Stack& otherStack)
{
	return (_sizeOfStack > otherStack._sizeOfStack);
}

int Stack::operator[](size_t index) {
	return _stack[index];
}

size_t Stack::size()
{
	return _sizeOfStack;
}

