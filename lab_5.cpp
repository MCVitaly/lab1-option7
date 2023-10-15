#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
	vector<string> numeredLines;		//auxiliary vector
	ifstream fin;
	fin.open("FirstFile.txt");
	if (!fin.is_open())		//checking for file availability
	{
		cout << "File opening error " << "\n";
	}
	else
	{
		ofstream fout;
		fout.open("OutputFile.txt");
		if (!fout.is_open())
		{
			cout << "Error" << "\n";
		}
		else
		{
			//filling the auxiliary vector
			string str;
			while (!fin.eof())
			{
				getline(fin, str);
				numeredLines.push_back(str);
			}
			//search for identical consecutive lines
			int counter = 1;
			int j;
			int i = 0;
			int numOfGroup = 1;
			while(i<(numeredLines.size()-1))
			{
				if (!numeredLines[i].compare(numeredLines[i + 1]))
				{
					j = i;
					while (!numeredLines[j].compare(numeredLines[j + 1]))
					{
						counter++;
						j++;
						if (j == numeredLines.size() - 1)
						{
							break;
						}
					}
					fout << "Group: " << numOfGroup << ": <<" << numeredLines[i] << ">>. Amount of repetition: " << counter << ". Number of first line in group: " << (i+1)<<"\n";
					numOfGroup++;
					i=j;
					counter = 1;
				}
				else
				{
					i++;
				}
			}
			//output of text
			for (int i = 0; i < numeredLines.size(); i++)
			{
				cout << numeredLines[i] << "\n";
			}
			//
			fout.close();
		}
	}
	
	fin.close();
	return 0;
}