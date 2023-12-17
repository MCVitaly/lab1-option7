#include "Calculator.h"
#include <iostream>

using namespace std;

int main()
{
	char temp;
	double value;
	Stack<double> stackWithNumbers;
	Stack<char> stackWithOperations;
    while (stackWithOperations.size() != 0) { 
        if (calculator(stackWithNumbers, stackWithOperations) == false) { 
            return 0;
        }
        else continue; 
    }
    cout << stackWithNumbers[stackWithNumbers.size()] << endl; 
    system("pause");
    return 0;
}