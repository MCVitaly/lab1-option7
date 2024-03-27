#include <iostream>

using namespace std;

int main()
{
	double k = 1;
	double sum=0;
	double minusOne = -1;
	double two = 2;
	double one = 1;
	double result;
	double eight = 8;
	double trash;
	_asm
	{
		mov ecx, 1000000

	loop1:
		fld minusOne
		fld two
		fld k
		fmul
		fadd

		fld one
		fdiv st(0), st(1)
		fld sum
		fadd
		fstp sum

		fstp trash

		fld one
		fld k
		fadd
		fstp k

		fstp trash
	loop loop1

		fld sum
		fmul eight
		fsqrt
		fstp result
	}
	cout << result;
	return 0;
}