#include <iostream>

using namespace std;


int main()
{
	int n, m, result;
	int ten = 10;
	cout << "Enter two natural numbers m, n: ";
	cin >> m >> n;
	while (n<=0||m<=0)
	{
		cout << "Enter two NATURAL numbers: ";
		cin >> m >> n;
	}
	_asm
	{
		mov ecx, m
		mov eax, n
		mov ebx, 0
		beg:
		cdq
		idiv ten
		add ebx, edx
		loop beg
		mov result, ebx
	}
	cout <<"Sum of "<<m<<" last numbers of "<<n<<" is "<< result;
	return 0;
}