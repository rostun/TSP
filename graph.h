#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include "point.h"

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

		int greedyTSP(vector <Point> &points);
		void greedy2OPTPair(vector <Point>&points, int &tourDistance);
		void greedy2OPTTSP(vector <Point>&points, int &tourDistance);
		int calculateTourDistance(vector <Point> &points);
};
#endif
