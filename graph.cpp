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

int Graph::greedyTSP(vector <Point> &points)
{
	int ID;
	int smallestDistance = 32767; //largest int
	int tourDistance = 0;
	
	int testDistance; //sort the points by distance
	unsigned int i = 0;
	int cityHolder;

	//take the first one from the vector
	while(i < points.size()-1)
	{ //cout << "cityID we're looking at: " << points[i].getCityID() << endl; //start at 0
		for(unsigned int j = i+1; j < points.size(); j++) //compare i rest of cities
		{
			testDistance = points[i].distanceTo(points[j]);
			if(testDistance < smallestDistance)
			{
				cityHolder = j; //save place of nearist city
				ID = points[j].getCityID();
				smallestDistance = testDistance;
			}//cout << "cityID we're testing: " << points[j].getCityID() << endl; cout << "testDistance: " << testDistance << endl;
			//cout << "best cityID: " << ID << endl; cout << "	smallestDistance: " << smallestDistance << endl;
		}

		tourDistance += smallestDistance; //cout << "		Tour so far: " << tourDistance << endl;
		smallestDistance = 32767;	
		iter_swap(points.begin() + i + 1, points.begin() + cityHolder); // swap (i+1) and j
		//for(int k = 0; k < points.size(); k++){cout << points[k].getCityID() << "|";}
		//cout << endl;
		i++; //i becomes j
	}
	//cout << "last point cityID: " << points[points.size()-1].getCityID() << endl; cout << "first point cityID: " << points[0].getCityID() << endl;
	testDistance = points[points.size()-1].distanceTo(points[0]); //cout << "testDistance: " << testDistance << endl;
	tourDistance = tourDistance + testDistance; cout << "tour distance: " << tourDistance << endl;

	cout << "this should be the same: " << calculateTourDistance(points) << endl;
	cout << "improving tourDistance"<< endl;
	greedy2OPTTSP(points, tourDistance);
	return tourDistance;
}


void Graph::greedy2OPTTSP(vector <Point>&points, int &tourDistance)
{
	int changeDistance;
	int ACBD; //edges to be tested
	int ABCD;

	//0 and 1, 1 and 2, 2 and 3,..., 75 and 0
	for(unsigned int i = 0; i < points.size()-2; i+=2)
	{
		ABCD = points[i].distanceTo(points[i+1]) + points[i+2].distanceTo(points[i+3]); //ABCD
		ACBD = points[i].distanceTo(points[i+2]) + points[i+1].distanceTo(points[i+3]); //ACBD
		
		cout << "ACBD and ABCD: " << ACBD <<" " << ABCD << endl;
		if(ACBD < ABCD) //[1-2-3-4]-5-6
		{
			cout << "is this ever happening" << endl;
			changeDistance = ABCD-ACBD;
			tourDistance = tourDistance-changeDistance;
			iter_swap(points.begin() + i+1, points.begin() + i+2); //swap b and c
		}
	}
	cout << "New Tour Distance: " << tourDistance << endl;
	cout << "checking new tour distance: " << calculateTourDistance(points) << endl;
}

//calculate tour distance
int Graph::calculateTourDistance(vector <Point> &points)
{
	int tourDistance = 0;
	int testDistance;

	for(unsigned int i = 0; i < points.size()-1; i++)
	{
		testDistance = points[i].distanceTo(points[i+1]);
		tourDistance = tourDistance + testDistance;
	}
	testDistance = points[points.size()-1].distanceTo(points[0]);
	tourDistance = tourDistance + testDistance;

	return tourDistance;
}
