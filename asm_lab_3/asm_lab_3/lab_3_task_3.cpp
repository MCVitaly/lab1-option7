#include <iostream>

using namespace std;

int main()
{
	int numOfFibonacciNumbers=2;
	int arr[47];
	arr[0] = 0;
	arr[1] = 1;
		_asm
		{
			mov esi, 2
		_begin:
			cmp esi, 47
			je _end

			mov eax, arr[4*esi-4]
			add eax, arr[4*esi-8]
			jo _end

			mov arr[4*esi], eax
			inc esi
			jmp _begin
		_end:

			mov numOfFibonacciNumbers, esi
		}
		for (int i = 0; i < numOfFibonacciNumbers; i++)
		{
			cout << arr[i] << " ";
		}
	return 0;
}

