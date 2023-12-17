#include "Calculator.h"
#include <iostream>

using namespace std;

double Sin(double x) { 
    return (round(sin(x) * 10000000) / 10000000);
}

double Cos(double x) { 
    return (round(cos(x) * 10000000) / 10000000);
}

double Ctg(double x) { 
    return (Cos(x) / Sin(x));
}

bool calculator(Stack<double>& stackWithNumbers, Stack<char>& stackWithOperations)
{
    double a, b, c;
    char tempOperation;
    stackWithOperations >> tempOperation;
    stackWithNumbers>>a; 
    switch (tempOperation) {  
    case '+': 
        stackWithNumbers >> b;
        c = a + b;
        stackWithNumbers << c; 
        break;
    case '-': 
        stackWithNumbers >> b;
        c = a - b;
        stackWithNumbers << c; 
        break;
    case '*': 
        stackWithNumbers >> b;
        c = a * b;
        stackWithNumbers << c; 
        break;
    case '/': 
        try
        {
            stackWithNumbers >> b;
            if (b == 0) throw exception("Error: division by zero");
            c = a + b;
            stackWithNumbers << c;
            break;
        }
        catch (const exception& e)
        {
            cerr << e.what() << endl;
        }
        break;
    case '^': 
        stackWithNumbers >> b;
        c = pow(a, b);
        stackWithNumbers << c; 
        break;
    case 's':
        c = Sin(a);
        stackWithNumbers << c;
        break;
    case 'c':
        c = Cos(a);
        stackWithNumbers << c;
        break;
    case 't':
        if (Cos(a) == 0) {
            cerr << "\nError\n";
            return false;
        }
        else {
            c = tan(a);
            stackWithNumbers << c;
            break;
        }
    case 'g':
        if (Sin(a) == 0) {
            cerr << "\nError\n";
            return false;
        }
        else {
            c = Ctg(a);
            stackWithNumbers << c;
            break;
        }
    case 'e':
        c = exp(a);
        stackWithNumbers << c;
        break;
    default:
        cerr << "\nError\n";
        return false;
        break;
    }
    return true;

}

int priorityOfOperations(char temp) { 
    if (temp == 's' || temp == 'c' || temp == 't' || temp == 'g' || temp == 'e') return 4;
    if (temp == '^') return 3;
    if (temp == '+' || temp == '-') return 1;
    if (temp == '*' || temp == '/') return 2;
    else return 0;
}

void read(Stack<double>& stackWithNumbers, Stack<char>& stackWithOperations)
{
    bool indicator = true;
    char temp;
    double value;
    while (true) {
        temp = cin.peek();
        if (temp == '\n') break;
        if (temp == ' ') {
            cin.ignore();
            continue;
        }
        if (temp >= '0' && temp <= '9') {
            cin >> temp;
            value = double(temp);
            stackWithNumbers << value;
        }
        if (temp == 's' || temp == 'c' || temp == 't' || temp == 'e') {
            char arr[3];
            for (int i = 0; i < 3; i++) {
                temp = cin.peek();
                arr[i] = temp;
                cin.ignore();
            }
            if (arr[0] == 's' && arr[1] == 'i' && arr[2] == 'n') {
                temp = 's';
                stackWithOperations << temp;
                continue;
            }
            if (arr[0] == 'c' && arr[1] == 'o' && arr[2] == 's') {
                temp = 'c';
                stackWithOperations << temp;
                continue;
            }if (arr[0] == 't' && arr[1] == 'a' && arr[2] == 'n') {
                temp = 't';
                stackWithOperations << temp;
                continue;
            }if (arr[0] == 'c' && arr[1] == 't' && arr[2] == 'g') {
                temp = 'g';
                stackWithOperations << temp;
                continue;
            }
            if (arr[0] == 'e' && arr[1] == 'x' && arr[2] == 'p') {
                temp = 'e';
                stackWithOperations << temp;
                continue;
            }
        }
        if (temp == '+' || temp == '-' && indicator == 0 || temp == '*' || temp == '/' || temp == '^') {
            if (stackWithNumbers.size() == 0) {
                stackWithOperations << temp;
                cin.ignore();
                continue;
            }
            if (stackWithOperations.size() != 0 && priorityOfOperations(temp) >
                priorityOfOperations(stackWithOperations[stackWithOperations.size()])) {
                stackWithOperations << temp;
                cin.ignore();
                continue;
            }
            if (stackWithOperations.size() != 0 && priorityOfOperations(temp) <=
                priorityOfOperations(stackWithOperations[stackWithOperations.size()])) {
                if (calculator(stackWithNumbers, stackWithOperations) == false) {
                    system("pause");
                    return;
                }
                continue;
            }
        }
        if (temp == '(') {
            stackWithOperations << temp;
            cin.ignore();
            continue;
        }
        if (temp == ')') {
            while (stackWithOperations[stackWithOperations.size()] != '(') {
                if (calculator(stackWithNumbers, stackWithOperations) == false) {
                    system("pause");
                    return;
                }
                else continue;
                stackWithOperations >> temp;
                cin.ignore();
                continue;
            }
        }
        else {
            system("pause");
            return;
        }
    }
}
