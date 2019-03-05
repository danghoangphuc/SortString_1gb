#include "pch.h"
#include "MergeSort.h"
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;
int main(){
	ifstream ifs;
	ofstream file;
	string *str = new string[200000];
	clock_t begin = clock();
	ifs.open("RandomString_500MB.txt");
	int numOfLines = 0;
	if (ifs.is_open())
	{
		while (file.good())
		{
			string line;
			getline(ifs, line);
			if (line == "") break;
			str[numOfLines] = line;
			numOfLines++;
		}
	}
	clock_t endRead = clock();
	cout << "Read File: " << -(begin - endRead) / CLOCKS_PER_SEC << endl;
	merge_sort(str, numOfLines);
	clock_t endSort = clock();
	cout << "Sort " << -(endRead - endSort) / CLOCKS_PER_SEC << endl;
	file.open("result.txt");
	for (int i = 0; i < numOfLines; i++)
	{
		file << str[i] << endl;
	}
	clock_t end = clock();
	file.close();
	cout << "Write File: " << -(endSort - end) / CLOCKS_PER_SEC << endl;
	return 0;
}