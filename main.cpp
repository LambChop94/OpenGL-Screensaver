//3GC3 Assignment 1
//Ryan Lambert
//Student Number: 1218407
//Description: An interactive screensave program to learn the basics of opengl

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <time.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "point.h"

using namespace std;


vector <point *> myPoints ;             //Creating a vector of type point called myPoints
int mode = 1 ;                          //Creating variable for mode and setting it to 1 initially
int w ;                                 //Variable for width
int h ;                                 //Variable for height
int mClick = 1 ;                        //Variable to check what click you're on
point * click = NULL ;                  //Pointer for initializing the points
point * click2 = NULL ;                 //Pointer for initializing second points
float normDirX = 0 ;                    //Used for normalizing x
float normDirY = 0 ;                    //Used for normalizing y
float pointSize = 5 ;                   //Variable for point size
bool isPaused = false ;                 //Boolean to check if the animation is paused
int pause = 1 ;                         //Pause counter


//Display function
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity() ;
	glViewport(0, 0, w, h);             //Making sure the 
	gluOrtho2D(0, w, 0, h);             //window is resizeable


	//The loop containing the display for line mode
	if (mode == 1)
	{
		glPointSize(pointSize);

		for(int i = 0; i < myPoints.size(); i++)
		{
			glBegin(GL_POINTS);
				glColor3f(myPoints[i]->returnc1(), myPoints[i]->returnc2(), myPoints[i]->returnc3()) ;
				glVertex2i(myPoints[i]->returnX(), h-myPoints[i]->returnY()) ;
			glEnd();
		}
	}
	//The loop containing the display for line mode
	else if (mode == 2)
	{
		glLineWidth(pointSize) ;

		for(int i = 1; i < myPoints.size(); i+=2)
		{
			glBegin(GL_LINES);
				glColor3f(myPoints[i-1]->returnc1(), myPoints[i-1]->returnc2(), myPoints[i-1]->returnc3()) ;
				glVertex2i(myPoints[i-1]->returnX(), h-myPoints[i-1]->returnY()) ;
				glColor3f(myPoints[i]->returnc1(), myPoints[i]->returnc2(), myPoints[i]->returnc3()) ;
				glVertex2i(myPoints[i]->returnX(), h-myPoints[i]->returnY()) ;
			glEnd();
		}
	}

	glutSwapBuffers();
}



//Initialize function
void init(void)
{
	glutFullScreen() ;
}



//Mouse function
void mouse(int btn, int state, int x, int y)
{
	//Mouse listener for dot mode
	if (mode == 1)       //Dot mode
	{
		if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			if (mClick == 1)
			{
				mClick = 2 ;

				click = new point(x, y, ((double) rand() / (RAND_MAX)), ((double) rand() / (RAND_MAX)), ((double) rand() / (RAND_MAX))) ;             //Creating a new point on mouse click
			}
			else if (mClick == 2)    //Making and assigning direction of the point
			{
				normDirX = (x - click->returnX()) / sqrt(pow(x - click->returnX(), 2) + pow(y - click->returnY(), 2)) ;
				normDirY = (y - click->returnY()) / sqrt(pow(x - click->returnX(), 2) + pow(y - click->returnY(), 2)) ;
				click->setDirX(normDirX) ;
				click->setDirY(normDirY) ;
				myPoints.push_back(click) ; 
			
				mClick = 1 ;
			}
		}
	}
	//Mouse listener for line mode
	else if (mode == 2)    //Line mode
	{
		if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			if (mClick == 1)
			{
				mClick = 2 ;

				click = new point(x, y, ((double) rand() / (RAND_MAX)), ((double) rand() / (RAND_MAX)), ((double) rand() / (RAND_MAX))) ;             //Creating a new point on mouse click
			}
			else if (mClick == 2)   //Making and assigning direction of the point
			{
				normDirX = (x - click->returnX()) / sqrt(pow(x - click->returnX(), 2) + pow(y - click->returnY(), 2)) ;
				normDirY = (y - click->returnY()) / sqrt(pow(x - click->returnX(), 2) + pow(y - click->returnY(), 2)) ;
				click->setDirX(normDirX) ;
				click->setDirY(normDirY) ;
				myPoints.push_back(click) ;
			
				mClick = 3 ;
			}
			else if (mClick == 3)
			{
				mClick = 4 ;

				click2 = new point(x, y, ((double) rand() / (RAND_MAX)), ((double) rand() / (RAND_MAX)), ((double) rand() / (RAND_MAX))) ;             //Creating a new point on mouse click
			}
			else if (mClick == 4)    //Making and assigning direction of the point
			{
				normDirX = (x - click2->returnX()) / sqrt(pow(x - click2->returnX(), 2) + pow(y - click2->returnY(), 2)) ;
				normDirY = (y - click2->returnY()) / sqrt(pow(x - click2->returnX(), 2) + pow(y - click2->returnY(), 2)) ;
				click2->setDirX(normDirX) ;
				click2->setDirY(normDirY) ;
				myPoints.push_back(click2) ; 

				mClick = 1 ;
			}
		}
	}
}



//Keyboard function
void kbd(unsigned char key, int x, int y)
{
	switch(key)
	{
		case '1':
			mode = 1 ;
			myPoints.clear() ;
			mClick = 1 ;
			break;

		case '2':
			mode = 2 ;
			myPoints.clear() ;
			mClick = 1 ;
			break;

		case '3':
			mode = 3 ;
			myPoints.clear() ;
			mClick = 1 ;
			break;

		case 'r':
			myPoints.clear() ;
			break;

		case '.':
			pointSize += 1 ;
			break;

		case ',':
			if (pointSize > 0)
			{
				pointSize -= 1 ;
			}
			break;

		case 'p':
			if (pause == 1)
			{
				isPaused = true ;
				pause = 2 ;
			}
			else if (pause == 2)
			{
				isPaused = false ;
				pause = 1 ;
			}
			break;

		case '\e':
			exit(0);
	}
}



//Resize function
void resize(int width, int height)
{
	w = width ;
	h = height ;
}



void timer(int value)
{
	if (isPaused == false)     //Checking if the animation is paused
	{
		if (mode == 1)
		{
			//Making the points bounce off the walls
			for(int i = 0; i < myPoints.size(); i++)
			{
				if (myPoints[i]->returnX() <= 0 || myPoints[i]->returnX() >= w)
				{
					myPoints[i]->setDirX(-myPoints[i]->returnDirX()) ;
				}
				else if (myPoints[i]->returnY() <= 0 || myPoints[i]->returnY() >= h)
				{
					myPoints[i]->setDirY(-myPoints[i]->returnDirY()) ;
				}

				myPoints[i]->setX(myPoints[i]->returnX() + myPoints[i]->returnDirX()) ;
				myPoints[i]->setY(myPoints[i]->returnY() + myPoints[i]->returnDirY()) ;
			}
		}
		else if (mode ==2)
		{
			//Making the points bounce off the walls
			for(int i = 0; i < myPoints.size(); i++)
			{
				if (myPoints[i]->returnX() <= 0 || myPoints[i]->returnX() >= w)
				{
					myPoints[i]->setDirX(-myPoints[i]->returnDirX()) ;
				}
				else if (myPoints[i]->returnY() <= 0 || myPoints[i]->returnY() >= h)
				{
					myPoints[i]->setDirY(-myPoints[i]->returnDirY()) ;
				}

				myPoints[i]->setX(myPoints[i]->returnX() + myPoints[i]->returnDirX()) ;
				myPoints[i]->setY(myPoints[i]->returnY() + myPoints[i]->returnDirY()) ;
			}
		}
	}


	glutTimerFunc(8, timer, 0);
	glutPostRedisplay();
}



//Main function
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(600, 600);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutCreateWindow("Assignment 1");


	glutDisplayFunc(display);
	glutReshapeFunc(resize) ;
	glutMouseFunc(mouse);
	glutKeyboardFunc(kbd);
	glutTimerFunc(8, timer, 0);

	init();

	glutMainLoop();

	return(0);
}