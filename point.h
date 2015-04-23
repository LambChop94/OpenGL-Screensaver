//3GC3 Assignment 1
//Ryan Lambert
//Student Number: 1218407
//Description: An interactive screensave program to learn the basics of opengl

#ifndef __POINT_H__
#define __POINT_H__

class point{
public:
	point(float xCoord, float yCoord, double color1, double color2, double color3) ;
	float returnX() ;
	float returnY() ;
	float setX(float sX) ;
	float setY(float sY) ;
	float setDirX(float i) ;
	float setDirY(float j) ;
	float returnDirX() ;
	float returnDirY() ;
	double returnc1() ;
	double returnc2() ;
	double returnc3() ;
private:
	float x ;
	float y ;
	float dirX ;
	float dirY ;
	double c1 ;
	double c2 ;
	double c3 ;
};

#endif