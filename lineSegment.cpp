#include "stdafx.h"

#include "lineSegment.h"
#include "point.h"

LineSegment::LineSegment(const class Point& p1, const class Point& p2)
{
	setEnd1(p1);
	setEnd2(p2);
}
void LineSegment::setEnd1(const class Point& p1)
{  
	End1 = p1;
}
void LineSegment::setEnd2(const class Point& p2)
{ 
	End2 = p2;
}
class Point LineSegment::getEnd1() 
{
	return End1;
}
class Point LineSegment::getEnd2()
{
	return End2;
}
double LineSegment::length()
{
	double distance;
	distance = End1.distanceTo(End2);
	return distance;
}