#ifndef GRAPH_H
#define GRAPH_H

#include "point.h"
#include <vector>
using namespace std;

class Graph
{
	private:
		vector <Point> cities; 
		vector <int> tour; 
	public:
		Graph();
		Graph(const vector <Point> &points, const vector<int> &thread);
		void setCities(const vector <Point> &points);
		void setTours(const vector<int> &thread);
		vector<Point> getPoints();
		vector<int> getThread();

		//greedy algorithm
			//int cityID;
			//int smallestDistance;
			//int tourDistance;
			//
			//start with cities[0] until cities.size()
			//go through all the "cities" as long as "cities" is not empty
				//calculate the distance from cities[i] to city[i->n]
					//if(distance<smallestDistance)
						//cityID = cities[whatever is smallest]
						//tourDistance = smallestDistance
						//reset variables
};
#endif