#include "Stack.h"



 template <typename T>
 void Stack<T>::stackIncrease()
{
	T* newStack = new T[2 * _supremumOfSize];
	_supremumOfSize *= 2;
	for (int i = 0; i < _sizeOfStack; i++)
	{
		newStack[i] = _stack[i];
	}
	_stack = newStack;
	delete[] newStack;
}
 template <typename T>
Stack<T>::Stack(size_t supremumOfSize) {
	_supremumOfSize = supremumOfSize;
	_stack = new T[_supremumOfSize];
}
template <typename T>
Stack<T>::Stack() {
	_supremumOfSize = 10;
	_stack = new T[_supremumOfSize];
}


template <typename T>
Stack<T>::~Stack() {
	delete[] _stack;
}
template <typename T>
void Stack<T>::operator<<(T& element) {
	if (_sizeOfStack == _supremumOfSize) {
		stackIncrease();
	}
	_stack[_sizeOfStack] = element;
	_sizeOfStack++;
}
template <typename T>
void Stack<T>::operator>>(T& inheritedVariable) {
	inheritedVariable = _stack[_sizeOfStack-1];
	_stack[_sizeOfStack] = {};
	_sizeOfStack--;
}


template <typename T>
void Stack<T>::operator=(Stack& otherStack) {
	_stack = otherStack._stack;
	_supremumOfSize = otherStack._supremumOfSize;
	_sizeOfStack = otherStack._sizeOfStack;
}

template <typename T>
bool Stack<T>::operator==(const Stack& otherStack)
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

template <typename T>
bool Stack<T>::operator<(const Stack& otherStack)
{
	return (_sizeOfStack < otherStack._sizeOfStack);
}

template <typename T>
bool Stack<T>::operator>(const Stack& otherStack)
{
	return (_sizeOfStack > otherStack._sizeOfStack);
}

template <typename T>
int Stack<T>::operator[](size_t index) {
	return _stack[index];
}

template <typename T>
size_t Stack<T>::size()
{
	return _sizeOfStack;
}

