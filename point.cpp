#include "stdafx.h"

#include "Point.h"
#include <iostream>
#include <cmath>

Point::Point() //no initial values to set
{

}
Point::Point(int xCoord,int yCoord)//sets values for x, y  
{
     setXCoord(xCoord);
     setYCoord(yCoord); 
}
void Point::setXCoord(int xCoord) //sets value for xCoord
{
    x = xCoord;
}
void Point::setYCoord(int yCoord)//sets value for yCoord
{
    y = yCoord;
}
int Point::getXCoord() const //sets value for XCoord
{
	return x;
}
int Point::getYCoord() const//returns value for YCoord
{
	return y;
}
double Point::distanceTo(const Point& c)//Returns the distance between 2 points
{
	return (sqrt(pow((c.getXCoord() - getXCoord()),2) + (pow ((c.getYCoord() - getYCoord()), 2))));
}
