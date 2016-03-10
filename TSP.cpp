// TSP.cpp : Defines the entry point for the console application.
//

#include <chrono>
#include <ctime>
using namespace std::chrono;

#include "fileFilter.h" 
#include "point.h"
#include "graph.h"

int main()
{
	ifstream readFile;
	ofstream writeFile;
	string fileName;

	vector <string> myCities;
	vector <int> cities;

	//make a 2d vector of x and y coordinates

	cout << "Enter txt filename, don't put extension" << endl;
	cin >> fileName; 
	
	//extract parent arrays from file
	extractLines(readFile, fileName, myCities);

	for(unsigned int place = 0; place < myCities.size(); place++) //if 3 lines, goes through 9 times
	{	
		extractInts(myCities, place, cities);
	}
	
	vector<Point> theMap;
	vector<int> theTour;
	for(unsigned int i = 0; i < cities.size(); i=i+3)
	{
		Point cityHolder(cities[i], cities[i+1], cities[i+2]); //city input
		theMap.push_back(cityHolder);
	}
	Graph greedySolution(theMap, theTour); //put in our vectors

	/*for(unsigned int i = 0; i<theMap.size(); i++)
	{
		cout << greedySolution.getPoints()[i].getCityID() << endl; //returns our cities we just made
	}*/

	int tourDistance;
    
        high_resolution_clock::time_point t1 = high_resolution_clock::now();
	
    tourDistance = greedySolution.greedyTSP(theMap);
       
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        duration<double> time_span1 = duration_cast<duration<double>>(t2 - t1);
		cout << "Time: " << time_span1.count() << endl;
    writeFile.open(fileName + ".txt.tour");
	outputFile(theMap, tourDistance, writeFile);
	writeFile.close();

	return 0;
}

