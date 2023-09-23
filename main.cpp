//Arrays

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int size;
	const int maxSize=100;
	int LeftBorder, RightBorder;
	cout << "Enter size of array(1<size<" <<maxSize<<") "<< endl;
	cin >> size;
	while ((size>maxSize) || (size < 2))
	{
		std::cout << "Enter correct size " << endl;
		cin >> size;
	}
	double* arr = new double[size];
	int answer;
	cout<<"If you want to fill elements of array yourself, press 1. "<<endl;
	cout << "If you want the array to be filled automayically, press 2 " << endl;
	cin >> answer;
	while ((answer != 1) && (answer != 2)) {
		cout << "Enter correct answer " << endl;
		cin >> answer;
	}
	if (answer == 1) {
		cout << "Enter elements of array: " << endl;
		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];
		}
	}
	else {
		cout << "Enter left border of array: " << endl;
		cin >> LeftBorder;
		cout << "Enter right border of array: " << endl;
		cin >> RightBorder;

		for (int i = 0; i < size; i++) {
			arr[i] = LeftBorder + rand() % (RightBorder - LeftBorder);
		}
	}

	cout << "//////////////////////////////////////////////////////////////////" << endl;

	for (int i = 0; i < size; i++) {
		cout << arr[i]<< "\t";
	}
	cout << endl;

	cout << "//////////////////////////////////////////////////////////////////" << endl;


	//TASK: maximum modulus element of array


	double MaxNum = abs(arr[0]);
	for (int i = 0; i < size; i++)
	{
		if (abs(arr[i]) > MaxNum) {
			MaxNum = abs(arr[i]);
}
	}
	cout << "Maximum modulus element of array is " << MaxNum << endl;;

	cout << "//////////////////////////////////////////////////////////////////" << endl;


	//TASK: sum of elements between first and second positive elments


	double sum = 0;
	for (int i = 0; i < size - 1; i++)
	{
		if ((arr[i] > 0)) {
			i++;
			while (arr[i] < 0) {
				sum += arr[i];
				i++;
			}
			break;
		}
	}
	cout << "Sum of elements between first and second positive elments is : " << sum <<endl;

	cout << "//////////////////////////////////////////////////////////////////" << endl;


	//TASK: in descending order of frequence


	//creating supporting array
	double** arr2 = new double*[size];
	for (int i = 0; i < size; i++)
	{
		arr2[i] = new double[2];
	}
	int frequence = 0;
	double tmp;
	//search for 0
	for (int i = 0; i < size; i++)	
	{
		if (arr[i]==0)
		{
			frequence++;
		}
	}
	int numOfFrequences = 0;
	if (frequence!=0)
	{
		arr2[0][0] = frequence;
		arr2[0][1] = 0;
		numOfFrequences++;
	}

	//frequence search

	frequence = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] != 0) {
			tmp = arr[i];
			for (int j = 0; j < size; j++)
			{
				if (arr[j] == tmp) {
					frequence++;
					arr[j] = 0;
				}
			}
			arr2[numOfFrequences][0] = frequence;
			arr2[numOfFrequences][1] = tmp;
			numOfFrequences++;
			frequence = 0;
		}
	}

	//sort elements of supporting array

	double maxFrequence;
	int index=0;
	double temp0, temp1;
	for (int i = 0; i < numOfFrequences; i++)
	{
		index = i;
		maxFrequence = arr2[i][0];
		for (int j = i; j < numOfFrequences; j++)
		{
			if (arr2[j][0] > maxFrequence) {
				maxFrequence = arr2[j][0];
				index = j;
			}
		}

		//changing position

		temp0 = arr2[i][0];
		temp1 = arr2[i][1];
		arr2[i][0] = maxFrequence;
		arr2[i][1] = arr2[index][1];
		arr2[index][0] = temp0;
		arr2[index][1] = temp1;
	}
	
	//changing arr

	int v = 0;	//coeficient
	for (int i = 0; i < numOfFrequences; i++)
	{
		for (int j = v; j < v+arr2[i][0]; j++)
		{
			arr[j] = arr2[i][1];
		}
		v += arr2[i][0];
	}

	for (int i = 0; i < size; i++) {
		cout <<arr[i]<< "\t";
	}


	//deleting arrays


	for (int i = 0; i < size; i++)
	{
		delete[]arr2[i];
	}
	delete[]arr2;
	delete[]arr;
	return 0;
}