#include <iostream>
#include <vector>
#include <limits>
using namespace std;


int main()
{
	const int maxSize = 10;
	int size;
	cout << "Enter size of vector(num of cols=num of rows, 1<=size<=" << maxSize << " " << endl;
	cin >> size;
	while ((size > maxSize) || (size < 2))
	{
		cout << "Enter correct size " << endl;
		cin >> size;
	}

	//creat and fill vector

	vector<vector<double>> vect(size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			vect[i].push_back(-50 + rand() % 100);	//element values are limited for readability
		}
	}
	//first output of vector

	cout << "//////////////////////////////////////////////////////////////////////////////" << "\n";
	for (int i = 0; i < size; i++)
	{
		for (double x : vect[i])
		{
			cout << x << "\t";
		}
		cout << "\n"<<"\n";
	}

	cout << "///////////////////////////////////////////////////////////////////////////////" << "\n";

	//search of max element and sort by diagonal

	double maxElement;
	double row = 0;
	double col=0;
	double temp;
	for (int v = 0; v < size; v++)
	{
		maxElement = numeric_limits<double>::lowest();
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if ((vect[i][j] > maxElement) && (((v != 0) && (vect[v - 1][v - 1] > vect[i][j])) || (v == 0)))
				{
						maxElement = vect[i][j];
						row = i;
						col = j;
				}
			}
		}
		swap(vect[v][v], vect[row][col]);
	}

	//search of first row, that has no positive elements

	bool value = true;
	int numOfRow=-1;
	for (int i = 0; i < size; i++)
	{
		for (double x : vect[i])
		{
			if (x>0)
			{
				value = false;
			}
		}
		if (value)
		{
			numOfRow = i;
			break;
		}
		value = true;
	}
	if (numOfRow>-1)
	{
		cout << "Num of first row, that has no positive elements is " << numOfRow<<"\n";
	}
	else
	{
		cout << "There are no any row in matrix, that has no positive elements"<<"\n";
	}

	//output

	cout << "///////////////////////////////////////////////////////////////////////////////" << "\n";
	for (int i = 0; i < size; i++)
	{
		for (double x : vect[i])
		{
			cout  << x << "\t";
		}
		cout << "\n" << "\n";
	}
	cout << "///////////////////////////////////////////////////////////////////////////////" << "\n";

	return 0;
}