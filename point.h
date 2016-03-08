#ifndef POINT_H
#define POINT_H

#include <cmath> // to use sqrt

class Point
{
	private:
		int x, y;
	public:
		Point();
		Point(int xCoord, int yCoord);
		void setXCoord(int xCoord);
		void setYCoord(int yCoord);
		int getXCoord() const;//const so they are not altered
		int getYCoord() const;
		double distanceTo(const Point& c);//Point& to save memory and time
};

#endif