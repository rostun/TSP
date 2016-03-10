#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath> // to use sqrt

class Point
{
	private:
		int city;
		int x;
		int y;
	public:
		Point();
		Point(int cityID, int xCoord, int yCoord);

		void setCityCoord(int cityID);
		void setXCoord(int xCoord);
		void setYCoord(int yCoord);
		
		int getCityID();
		int getXCoord();
		int getYCoord();

		int distanceTo(Point& c);
};

#endif
