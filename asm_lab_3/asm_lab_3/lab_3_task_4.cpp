#include <iostream>

using namespace std;

int main()
{
	int _sign = 1;
	int numerator, denominator;
	cout << "Enter numerator and denominator of fraction: ";
	cin >> numerator>>denominator;
	if (denominator<=0)
	{
		cout << "Error: incorrect denominator";
		return 1;
	}
	if (numerator<0)
	{
		_sign = -1;
		numerator *= -1;
	}
	if (numerator==0)
	{
		cout << "0/" << denominator;
		return 0;
	}
	_asm
	{
		mov eax, numerator
		mov ebx, denominator

		_begin:
			cmp eax, ebx
			je _end
			jg IfGreater

			sub ebx, eax
			jmp _begin

		IfGreater:
			sub eax, ebx
			jmp _begin

		_end:
			mov ecx, eax

			mov eax, numerator
			cdq
			idiv ecx
			mov numerator, eax

			mov eax, denominator
			cdq
			idiv ecx
			mov denominator, eax
	}
	numerator *= _sign;
	cout << numerator << "/" << denominator;
	return 0;
}