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