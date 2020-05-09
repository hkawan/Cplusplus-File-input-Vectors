#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


void printVect(int i)
{
	cout << setfill('0') << setw(4) << i << " hours" << endl;
}

void main()
{
	char buf[80];
	string line;
	ifstream inFile;
	vector<int> timeVect;
	
	inFile.open("../TimesFile.txt", ios::binary);
	if (!inFile)
	{
		cout << "Error in opening the file";
		return;
	}

	while (getline(inFile, line, ','))
	{		
		//Parsing in order to remove unwanted chars
		line.erase(remove(line.begin(), line.end(), ' '), line.end());
		line.erase(remove(line.begin(), line.end(), ':'), line.end());
		line.erase(remove(line.begin(), line.end(), ','), line.end());
	
		
		int time = 0;
		stringstream timeStr(line);
		timeStr >> time;
		timeVect.push_back(time);
	}
	inFile.close();

	cout << "Before Sorting" << endl;
	for_each(timeVect.begin(), timeVect.end(), printVect);

	cout << endl;

	//Sorted in ascending order
	sort(timeVect.begin(), timeVect.end());

	cout << "After Sorting" << endl;
	for_each(timeVect.begin(), timeVect.end(), printVect);	

}