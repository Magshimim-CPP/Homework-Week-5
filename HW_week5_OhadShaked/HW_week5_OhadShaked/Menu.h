#pragma once
#ifndef MENU_H
#define MENU_H

//Using iostream, vector, and all of our header files.
#include "Canvas.h"
#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Arrow.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "CImg.h"
#include <vector>
#include <iostream>

//Using specific functions from the std namespace, and Rectangle from myShapes.
using myShapes::Rectangle;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

//Texts for user interface (menu instructions).
#define MENU_OPTIONS "\nMAIN MENU OPTIONS:\n1 - Add a new shape\n2 - Get/Change the info of an existing shape\n3 - Delete all shapes in the program\n4 - Exit\nYour choice:  "
#define NEW_SHAPE_OPTIONS "\nPlease select the shape you want to create\nPress 1 for - Arrow\nPress 2 for - Circle\nPress 3 for - Triangle\nPress 4 for - Rectangle\nYour choice:  "
#define RANGE_ERROR "\nERROR: Number of choice was out of the options range.\nPlease try again\n"
#define EXIT_MESSAGE "\nThank you for using my shape maker program\nGoodbye!\n"
#define SHAPES_OPTIONS_MENU "\nSHAPE OPTIONS MENU:\n1 - move the shape\n2 - get the shape's details.\n3 - delete the shape\nYour choice:  "

//Defining constant values for ZERO (0), ONE (1), and ERROR_NUMBER (-1).
#define ZERO 0
#define ONE 1
#define ERROR_NUMBER -1

//Min and max option numbers to check that the input was in range.
#define MIN_OPTION 1
#define MAX_OPTION 4

//Options for the main menu.
#define NEW_SHAPE 1
#define CHANGE_OR_GET_SHAPE 2
#define DELETE_SHAPES 3
#define EXIT 4

//Option numbers for the shape creation menu.
#define ARROW 1
#define CIRCLE 2
#define TRIANGLE 3
#define RECTANGLE 4

//Colors for program look's
#define CYAN "\033[1;1;36m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m" 
#define RESET_COLOR "\033[0m"

//Change or get shape options.
#define MOVE_SHAPE 1
#define SHAPE_INFO 2
#define DELETE_SHAPE 3

class Menu
{
//private class fields
private:
	Canvas _canvas;
	vector<Shape*> _shapeVector;

//public class methods
public:

	Menu(); //Constructor function for a menu object, also features the main menu.
	~Menu(); //Destructor function for a menu object.
	static Arrow* CreateArrow(Canvas& canvas); //Function creates a new arrow, draws it, and returns it to be added to the shapes vector.
	static myShapes::Rectangle* CreateRectangle(Canvas& canvas); //Function creates a new rectangle, draws it, and returns it to be added to the shapes vector.
	static Triangle* CreateTriangle(Canvas& canvas); //Function creates a new triangle, draws it, and returns it to be added to the shapes vector.
	static Circle* CreateCircle(Canvas& canvas); //Function creates a new circle, draws it, and returns it to be added to the shapes vector.
	static void newShape(Canvas& canvas, vector<Shape*>* shapeVector); //Function for the new shape creation menu. (send's to the creator functions and adds result to the shapes vector).
	static void ChangeOrGet(Canvas& canvas, vector<Shape*>& shapeVector); //Function for changing a shape from the shapes vector (moving or deleting), or get it's details.
	static void deleteAllShapes(Canvas& canvas, vector<Shape*>& shapeVector); //Function to delete all shapes from the shapes vector, and clean the board.
	static void checkInput(int& num); //Static function to check input errors (cin fail), in case user enterd a char to int etc..

};

#endif

