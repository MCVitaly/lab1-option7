#include <iostream>
#include "Fraction.h"
using namespace std;

int NOD(int a1, int b)
{
	int a = abs(a1);
	if (a == 1 || b == 1) return 1;
	if (a == b) {
		return a;
	}
	if (a > b) {
		return NOD(a - b, b);
	}
	else {
		return NOD(a, b - a);
	}
}

ProperFraction::ProperFraction(int numerator, int denominator)
{
	try
	{
		if (denominator == 0) {
			throw exception("Error: denominator=0");
		}
		if (abs(numerator) >= abs(denominator)) {
			throw exception("numerator >= denominator, it's an improper fraction.");
		}
		if (denominator < 0) {
			_denominator = -1 * denominator;
			_numerator = -1 * numerator;
		}
		if (denominator > 0) {
			_numerator = numerator;
			_denominator = denominator;
		}
		reduceFraction();
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
}
void ProperFraction::reduceFraction()
{
	int nod = 1;
	if (_numerator != 0) nod = NOD(_numerator, _denominator);
	_numerator /= nod;
	_denominator /= nod;
}


int ProperFraction::GetNumerator()
{
	return _numerator;
}

int ProperFraction::GetDenaminator()
{
	return _denominator;
}
//arithmetic methods
void ProperFraction::add(const ProperFraction& secondFraction)
{
	_numerator = _numerator * secondFraction._denominator + secondFraction._numerator * _denominator;
	_denominator = _denominator * secondFraction._denominator;
	reduceFraction();
}

void ProperFraction::multiply(const ProperFraction& secondFraction)
{
	_denominator *= secondFraction._denominator;
	_numerator *= secondFraction._numerator;
	reduceFraction();
}

void ProperFraction::divide(const ProperFraction& secondFraction)
{
	try
	{
		if (secondFraction._numerator == 0) throw exception("Error: division by zero");
		_numerator *= secondFraction._denominator;
		_denominator *= secondFraction._numerator;
		reduceFraction();
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}

}

//
//arithmetic operators

ProperFraction ProperFraction::operator+(const ProperFraction& secondFraction)
{
	_numerator = _numerator * secondFraction._denominator + secondFraction._numerator * _denominator;
	_denominator = _denominator * secondFraction._denominator;
	reduceFraction();
	return ProperFraction(_numerator, _denominator);
}

ProperFraction ProperFraction::operator*(const ProperFraction& secondFraction)
{
	_denominator *= secondFraction._denominator;
	_numerator *= secondFraction._numerator;
	reduceFraction();
	return ProperFraction(_numerator, _denominator);
}

ProperFraction ProperFraction::operator/(const ProperFraction& secondFraction)
{
	try
	{
		if (secondFraction._numerator == 0) throw exception("Error: division by zero");
		_numerator *= secondFraction._denominator;
		_denominator *= secondFraction._numerator;
		reduceFraction();
		return ProperFraction(_numerator, _denominator);
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
}

//
ProperFraction::ProperFraction(const ProperFraction& exemplar)
{
	_numerator = exemplar._numerator;
	_denominator = exemplar._denominator;
}

void ProperFraction::print()
{
	cout << _numerator << "/" << _denominator << endl;
}
