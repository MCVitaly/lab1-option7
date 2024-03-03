#include <iostream>

using namespace std;
//50=2х+3у 
int main()
{
	int three = 3;
	int two = 2;
	int solY[9];
	int solX[9];
	int numOfSolutions;
	_asm
	{
		
		xor ebx, ebx
		xor esi, esi

		_begin:
			inc esi
			cmp esi, 17
			je _end
			mov eax, esi
			mul three
			neg eax
			add eax, 50
			idiv two
			cmp edx, 0
			jne _begin
			mov solX[ebx*4], eax
			mov solY[ebx*4], esi
			inc ebx
			jmp _begin
		_end:
			mov numOfSolutions, ebx 
	}
	cout << "Number of solutions of equations 2x+3y=50 is " << numOfSolutions << endl;
	for (size_t i = 0; i < 8; i++)
	{
		cout <<"2*"<< solX[i] << "+3*" << solY[i]<<"=50" << endl;
	}
	return 0;
}