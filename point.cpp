#include "stdafx.h"

#include "Point.h"
#include <iostream>

Point::Point() //no initial values to set
{

}

Point::Point(int cityID, int xCoord,int yCoord)//sets values for x, y  
{
	setCityCoord(cityID);
	setXCoord(xCoord);
	setYCoord(yCoord); 
}
void Point::setCityCoord(int cityID)
{
	city = cityID;
}

void Point::setXCoord(int xCoord) //sets value for xCoord
{
    x = xCoord;
}

void Point::setYCoord(int yCoord)//sets value for yCoord
{
    y = yCoord;
}

int Point::getCityID()
{
	return city;
}

int Point::getXCoord()//sets value for XCoord
{
	return x;
}

int Point::getYCoord()//returns value for YCoord
{
	return y;
}

int Point::distanceTo(Point& c)//Returns the distance between 2 points
{
	return (sqrt(pow((c.getXCoord() - getXCoord()),2) + (pow ((c.getYCoord() - getYCoord()), 2))));
}
