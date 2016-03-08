// TSP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#include "fileFilter.h" 
#include "point.h"
#include "lineSegment.h"
#include "algos.h"
#include "graph.h"

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream readFile;
	string fileName;

	vector <string> myCities;
	
	vector <int> cityID;
	vector <int> myXCoords;
	vector <int> myYCoords;
	//make a 2d vector of x and y coordinates
	vector<vector<int>> Graph;

	cout << "Enter txt filename, don't put extension" << endl;
	cin >> fileName; 
	
	//extract parent arrays from file
	extractLines(readFile, fileName, myCities);

	for(int place = 0; place < myCities.size(); place++) //if 3 lines, goes through 9 times
	{	
		extractInts(myCities, place, cityID, myXCoords, myYCoords);
	}

	return 0;
}

