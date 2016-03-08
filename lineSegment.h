#ifndef LINESEGMENT_H
#define LINESEGMENT_H

#include "point.h"
 
class LineSegment
{
	private:
		Point End1;
		Point End2;
	public:
		LineSegment();
		LineSegment(const class Point& p1, const class Point& p2);
		void setEnd1(const class Point& p1);
		void setEnd2(const class Point& p2);
		class Point getEnd1();
		class Point getEnd2();
		double length();
};
#endif