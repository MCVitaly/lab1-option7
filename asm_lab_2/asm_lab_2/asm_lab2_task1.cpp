//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	int x, result;
//	cout << "Enter x: ";
//	cin >> x;
//	if (x == 0) {
//		cerr << "Error: didvision by zero";
//		return 1;
//	}
//
//	//1. (x5 + 2 * (x2 – 4) + x) / x3
//	_asm
//	{
//		mov eax, x
//		imul eax
//		sub eax, 4
//		imul eax, 2
//
//		mov ebx, eax
//		mov eax, x
//		imul eax
//		imul eax
//		imul x
//
//		add eax, ebx
//		add eax, x
//
//		cdq
//		idiv x
//		cdq
//		idiv x
//		cdq
//		idiv x
//
//		mov result, eax
//	}
//	cout << "1. (x5 + 2 * (x2 - 4) + x) / x3=" << endl;
//	cout << "C++: " << int((pow(x, 5) + 2 * (x * x - 4) + x) / pow(x, 3)) << endl;
//	cout << "asm: " << result << endl;
//
//	//2. (2 * x – 1) * (2 * x + 1) * (x + 3) / (2 * x)
//
//	_asm
//	{
//		mov eax, x
//		imul eax, 2
//		sub eax, 1
//
//		mov ebx, x
//		imul ebx, 2
//		add ebx, 1
//
//		imul eax, ebx
//
//		mov ebx, x
//		add ebx, 3
//
//		imul eax, ebx
//
//		mov ebx, x
//		imul ebx, 2
//
//		cdq
//		idiv ebx
//
//		mov result, eax
//	}
//	cout << "2. (2 * x – 1) * (2 * x + 1) * (x + 3) / (2 * x)=" << endl;
//	cout << "C++: " << int((2 * x - 1) * (2 * x + 1) * (x + 3) / (2 * x)) << endl;
//	cout << "asm: " << result << endl;
//
//	//3. (4 * x – 1) * (4 * x + 1) / 4
//
//	_asm
//	{
//		mov eax, x
//		mov ebx, 4
//		imul ebx
//		sub eax, 1
//
//		mov ebx, x
//		imul ebx, 4
//		add ebx, 1
//
//		imul eax, ebx
//
//		mov ebx, 4
//
//		cdq
//		idiv ebx
//
//		mov result, eax
//	}
//	cout << "3. (4 * x – 1) * (4 * x + 1) / 4=" << endl;
//	cout << "C++: " << int((4 * x - 1) * (4 * x + 1) / 4) << endl;
//	cout << "asm: " << result << endl;
//
//	return 0;
//}