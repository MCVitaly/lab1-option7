#include <iostream>

using namespace std;


int main()
{
	_int16 A1, A2, A3, B1, B2, B3, C1, C2, C3;
	cout << "Enter A3, A2, A1: ";
	cin >> A3 >> A2 >> A1;
	cout<< "Enter B3, B2, B1: ";
	cin >> B3 >> B2 >> B1;
	_asm
	{
		mov ax, A1
		add ax, B1
		mov C1, ax

		mov ax, A2
		add ax, B2
		mov C2, ax

		mov ax, A3
		add ax, B3
		mov C3, ax
	}
	cout <<hex<< C3 << " " << C2 << " " << C1<<endl;
	cout.unsetf(ios::hex);
	_int64 result;
	result = static_cast<_int64>(C3);;
	result << 16;
	result += static_cast<_int64>(C2);
	result << 16;
	result += static_cast<_int64>(C1);;
	cout << result;
	return 0;
}