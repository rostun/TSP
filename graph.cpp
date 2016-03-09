#include "stdafx.h"

#include "graph.h"

Graph::Graph()
{

}

Graph::Graph(const vector <Point> &points, const vector<int> &thread)
{
	setCities(points);
	setTours(thread);
}

void Graph::setCities(const vector <Point> &points)
{
	cities = points;
}

void Graph::setTours(const vector<int> &thread)
{
	tour = thread;
}

vector<Point> Graph::getPoints()
{
	return cities;
}

vector<int> Graph::getThread()
{
	return tour;
}

void Graph::greedyTSP(vector <Point> &points, vector<int> &thread)
{
	int ID;
	int smallestDistance = 32767; //largest int
	int tourDistance = 0;
	
	int testDistance; //sort the points by distance
	int i = 0;
	int cityHolder;

	//take the first one from the vector
	while(!points.empty())
	{
		cout << "city: " << i << endl; //start at 0
		for(unsigned int j = i+1; j < points.size(); j++) //compare i rest of cities
		{
			testDistance = points[i].distanceTo(points[j]);
			if(testDistance < smallestDistance)
			{
				cityHolder = j; //save place of nearist city
				ID = points[j].getCityID();
				smallestDistance = testDistance;
			}
			cout << "testDistance: " << testDistance << endl;
			cout << "cityID: " << ID << endl;
			cout << "	smallestDistance: " << smallestDistance << endl;
		}

		tourDistance += smallestDistance;
		smallestDistance = 32767;	

		//deal with swap
		iter_swap(points.begin() + i + 1, points.begin() + cityHolder); // swap (i+1) and j
		i++; //i becomes j
		//
	}
}

//thread.push_back(points[i].getCityID()); //push first city into our tour
//points.erase(find(points.begin(),points.end(),points[i])); //erase city from points