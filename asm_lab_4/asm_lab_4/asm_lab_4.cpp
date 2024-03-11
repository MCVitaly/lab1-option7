#include <iostream>

extern "C" int myProcedure(int);

using namespace std;


int main()
{
	int x;
	cout << "Enter x: ";
	cin >> x;
	if (x == 0) {
		cerr << "Error: didvision by zero";
		return 1;
	}

	

	cout << "(4 * x – 1) * (4 * x + 1) / 4=" << endl;
	cout << "C++: " << int((4 * x - 1) * (4 * x + 1) / 4) << endl;
	cout << "asm: " << myProcedure(x) << endl;
	return 0;
}