/*
	Rosa Tung + Sam Nelson + Kara Franco
	Date Modified: 3.11.16
*/

//timers
#include <chrono>
#include <ctime>
using namespace std::chrono;

#include "fileFilter.h" //deal with file inputs and outputs
#include "point.h" //city class that stores cityID, X and Y coordinates
#include "graph.h" //graph class that stores tour vector and algorithms

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
	{	//fileFilter
		extractInts(myCities, place, cities); //put strings into myCities, convert them into integers and put those into cities vector
	}
	
	vector<Point> theMap; //tour vector
	vector<int> theTour; //ended up not using 
	for(unsigned int i = 0; i < cities.size(); i=i+3)
	{
		Point cityHolder(cities[i], cities[i+1], cities[i+2]); //city input
		theMap.push_back(cityHolder); //push city objects into tour vector
	}
	Graph greedySolution(theMap, theTour); //make graph object; includes vector tour and algorithms

	/*for(unsigned int i = 0; i<theMap.size(); i++)
	{
		cout << greedySolution.getPoints()[i].getCityID() << endl; //returns our cities we just made
	}*/

	int tourDistance;
		//start timer
        high_resolution_clock::time_point t1 = high_resolution_clock::now();
	
    tourDistance = greedySolution.greedyTSP(theMap); //put tour through algorithms
       
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        duration<double> time_span1 = duration_cast<duration<double>>(t2 - t1);
		cout << "Time: " << time_span1.count() << endl;
    writeFile.open(fileName + ".txt.tour"); //write to file
	outputFile(theMap, tourDistance, writeFile);
	writeFile.close();

	return 0;
}

