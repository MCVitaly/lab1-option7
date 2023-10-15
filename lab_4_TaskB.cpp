#include <iostream>

using namespace std;

int SearchDate(char str[], int size)
{
	int counter = 0;
	int i = 1;
	int year;
	while (i < size - 9)
	{
		if (int(str[i]) > 47 && int(str[i]) < 52 &&		//initial checking of numbers
			int(str[i + 1]) > 47 && int(str[i + 1]) < 58 &&
			int(str[i + 2]) == 47 && int(str[i + 5]) == 47 &&
			int(str[i + 3]) > 47 && int(str[i + 3]) < 50 &&
			int(str[i + 4]) > 48 && int(str[i + 4]) < 58 &&
			int(str[i + 6]) > 47 && int(str[i + 6]) < 58 &&
			int(str[i + 7]) > 47 && int(str[i + 7]) < 58 &&
			int(str[i + 8]) > 47 && int(str[i + 8]) < 58 &&
			int(str[i + 9]) > 47 && int(str[i + 9]) < 58)
		{
			if (size == 11 || (i < 2 && size>11 && (str[i + 10] == ' ' || str[i + 10] == '\0')) ||
				(size > 12 && i >= 2 && str[i - 1] == ' ' && (str[i + 10] == ' ' || str[i + 10] == '\0')))		//checking for spaces before and after date
			{
				year = 1000 * (int(str[i + 6]) - 48) + 100 * (int(str[i + 7]) - 48) + 10 * (int(str[i + 8]) - 48) + (int(str[i + 9]) - 48);
				if (((str[i + 4] == '4' || str[i + 4] == '6' ||		//checking for days and months
					str[i + 4] == '9' || (str[i + 3] == '1' && str[i + 4] == '1'))
					&& str[i] == '3' && str[i + 1] == '1') ||
					(str[i + 3] == '1' && int(str[i + 4]) > 50) ||
					(str[i] == '3' && int(str[i + 1]) > 49) ||
					(str[i + 3] == '0' && str[i + 4] == '2' &&		//checking for Febuary
						((int(str[i + 1]) > 57 && str[i] == '2') || str[i] == '3')) ||
					(str[i] == '0' && str[i + 1] == '0') || (str[i + 3] == '0' && str[i + 4] == '0') ||		//checking for '0'
					(year % 400 != 0 && (year % 4 != 0 || year % 100 == 0) &&		//checking for leap year
						str[i] == '2' && str[i + 1] == '9' && str[i + 3] == '0' && str[i + 4] == '2'))

				{
					i += 10;
					continue;
				}
				else
				{
					counter++;
					i += 10;
				}
			}
		}
		i++;
	}
	return counter;
}

int main()
{
	int size;
	cout << "Enter size of string(0<size<301): " << "\n";
	cin >> size;
	while (size>300||size<1)
	{
		cout << "Enter correct size: " << "\n";
		cin >> size;
	}
	char* str = new char[size];
	cout << "Enter string: " << "\n";
	for (int i = 0; i < size; i++)
	{
		str[i] = getchar();
	}
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		cout << str[i];
	}
	cout << "\n";
	cout << "Amount of dates in string is " << SearchDate(str, size);
	delete[]str;
	return 0;
}