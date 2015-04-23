//3GC3 Assignment 1
//Ryan Lambert
//Student Number: 1218407
//Description: An interactive screensave program to learn the basics of opengl

#include <stdlib.h>
#include <stdio.h>

#include "point.h"

point::point(float xCoord, float yCoord, double color1, double color2, double color3){
	x = xCoord ;
	y = yCoord ;
	c1 = color1 ;
	c2 = color2 ;
	c3 = color3 ;
}

float point::returnX(){
	return(x) ;
}

float point::returnY(){
	return(y) ;
}

float point::setX(float sX){
	x = sX ;
}

float point::setY(float sY){
	y = sY ;
}

float point::setDirX(float i){
	dirX = i ;
}

float point::setDirY(float j){
	dirY = j ;
}

float point::returnDirX(){
	return(dirX) ;
}

float point::returnDirY(){
	return(dirY) ;
}

double point::returnc1(){
	return(c1) ;
}

double point::returnc2(){
	return(c2) ;
}

double point::returnc3(){
	return(c3) ;
}