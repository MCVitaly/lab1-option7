#pragma once
#include "Stack.h"

double Sin(double x);

double Cos(double x);

double Ctg(double x);

bool calculator(Stack<double>& stackWithNumbers, Stack<char>& stackWithOperations);

int priorityOfOperations(char temp);

void read(Stack<double>& stackWithNumbers, Stack<char>& stackWithOperations);