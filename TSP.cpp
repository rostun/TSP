// TSP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#include "fileFilter.h" 
#include "point.h"
#include "lineSegment.h"

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream readFile;
	string fileName;

	vector <string> myCities;
	
	vector <int> cityID;
	vector <int> myXCoords;
	vector <int> myYCoords;

	cout << "Enter txt filename, don't put extension" << endl;
	cin >> fileName; 
	
	//extract parent arrays from file
	extractLines(readFile, fileName, myCities);

	for(int place = 0; place < myCities.size(); place++) //if 3 lines, goes through 9 times
	{	
		extractInts(myCities, place, cityID, myXCoords, myYCoords);
	}

	Point p1(myXCoords[0], myYCoords[0]);
	Point p2(myXCoords[1], myYCoords[1]);
	
	LineSegment line (p1, p2);
	cout << "distance: " << line.length() << endl;
	cout << "Get End1: " << line.getEnd1().getXCoord() << endl;

	return 0;
}

