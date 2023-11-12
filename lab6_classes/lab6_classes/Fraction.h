#pragma once
#include <iostream>
using namespace std;

int NOD(int a, int b);

class ProperFraction
{
private:
	int _numerator;
	int _denominator;

	void reduceFraction();
public:
	ProperFraction(int numerator, int denominator);

	int GetNumerator();

	int GetDenaminator();
	//arithmetic methods
	void add(const ProperFraction& secondFraction);

	void multiply(const ProperFraction& secondFraction);

	void divide(const ProperFraction& secondFraction);
	//
	//arithmetic operators

	ProperFraction operator+(const ProperFraction& secondFraction);

	ProperFraction operator*(const ProperFraction& secondFraction);

	ProperFraction operator/(const ProperFraction& secondFraction);

	//
	ProperFraction(const ProperFraction& exemplar);

	void print();

};
