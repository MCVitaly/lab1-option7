#include <iostream>

using namespace std;


int main()
{
	int a, result;
	cout << "Enter a: ";
	cin >> a;
	_asm {
		mov eax, a
		mov ebx, a
		mov ecx, 7

	begin1:
		imul a
		loop begin1

		add ebx, eax
		mov eax, a

		mov ecx, 11
	begin2:
		imul a
		loop begin2
		
		add ebx, eax
		mov result, ebx
	}

	cout << "a12+a8+a = " << endl;
	cout << "C++: " << pow(a, 12) + pow(a, 8) + a << endl;
	cout << "asm: " << result;
	return 0;
}