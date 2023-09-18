//Individual task 1, point 7

#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
	int k;
	long double x;
	cout << "Enter k" << endl;
	cin >> k;
	cout << "Enter x   -1<=x>=1" << endl;
	cin >> x;
	while ((x <= -1) || (x >= 1)) {
	cout << "Enter correct x       -1<=x>=1 :";
	cin >> x;
}
	long double num = 1 / pow((x + 1), 3);
	long double sum = 0;
	int i = 1;
	while ((abs(sum - num) >= pow(10, -k)))
	{
		sum+= (pow(-1, (i+1))*i * (i + 1) * pow(x, (i-1))) / 2;
		i++;
	}
	cout << setprecision(k)<< num << " " << sum;
	return 0;
}
