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
		vector <int> tour; //ended up not using 
	public:
		Graph();
		Graph(const vector <Point> &points, const vector<int> &thread); //graph contains points vector and ints vector, ended up not using ints vector
		void setCities(const vector <Point> &points);
		void setTours(const vector<int> &thread); //ended up not using
		vector<Point> getPoints();
		vector<int> getThread(); //ended up not using

		int greedyTSP(vector <Point> &points); //modified from pure greedy, nearest neighbor greedy
		void greedy2OPTPair(vector <Point>&points, int &tourDistance); //filter; test pairs starting from 1st city
		void greedy2OPTTSP(vector <Point>&points, int &tourDistance); //filter; test pairs starting from 2nd city
		int calculateTourDistance(vector <Point> &points); //hard calculate tour distance of city vectors
};
#endif
