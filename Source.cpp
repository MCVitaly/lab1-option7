#include <iostream>

using namespace std;

char* _strchr(const char *str, int c)
{
	int i = 0;
	char* str_p = (char*)str;
	while (str_p[i]!=0)
	{
		if (str_p[i] == char(c))
		{
			return str_p + i;
		}
		i++;
	}
	return NULL;
}
int main()
{
	int size;
	char c;
	cout << "Enter size of string: "<<"\n";
	cin >> size;
	char* str = new char[size];
	cout << "Enter string: " << "\n";
	for (int i = 0; i < size; i++)
	{
		str[i] = getchar();
	}
	cout << "Enter symbol: " << "\n";
	cin >> c;
	if (_strchr(str, int(c)) == NULL) {
		cout << "There is no such symbol in string";
	}
	else
	{
		cout << "Pointer '"<<c<< "' in string : " << _strchr(str, int(c));
	}
	delete[]str;
	return 0;
}