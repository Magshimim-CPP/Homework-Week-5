#include "Menu.h"

/*
Constructor function for a menu object, also features the main menu.
Input: none
Output: none
*/
Menu::Menu() 
{
	//setting menu variables at the start of the function.
	bool exitMenu = false;
	int menuChoice;

	//looping until the user chooses to exit (option 4)
	while (!exitMenu)
	{
		cout << MENU_OPTIONS; //Printing the main menu
		cin >> menuChoice; //Taking input for user's choice

		Menu::checkInput(menuChoice); //checking the validity of the input.

		//PICKING ACTION ACCORDING TO THE USER'S CHOICE:
		switch (menuChoice)
		{

		case (NEW_SHAPE): //OPTION 1 - NEW SHAPE
			Menu::newShape(_canvas, &_shapeVector);
			break;

		case (CHANGE_OR_GET_SHAPE): //OPTION 2 - CHANGE OR GET A SHAPE
			Menu::ChangeOrGet(_canvas, _shapeVector);
			break;

		case (DELETE_SHAPES): //OPTION 3 - DELETE ALL SHAPES
			Menu::deleteAllShapes(_canvas, _shapeVector);
			break;

		case (EXIT): //OPTION 4 - EXIT
			cout << GREEN;
			cout << EXIT_MESSAGE;
			cout << RESET_COLOR;
			exitMenu = true;
			break;

		default: //DEFAULT - INPUT WAS OUT OF RANGE
			cout << RED;
			cout << RANGE_ERROR << endl;
			cout << RESET_COLOR;
		}
	}
}

/*
Function for the new shape creation menu. (send's to the creator functions and adds result to the shapes vector).
Input: Canvas& canvas, vector<Shape*>* shapeVector
Output: none
*/
void Menu::newShape(Canvas& canvas, vector<Shape*>* shapeVector)
{
	//stating variables at the start of the function.
	int newShapeMenuChoice;

	cout << NEW_SHAPE_OPTIONS; //Printing the new shape actions menu
	cin >> newShapeMenuChoice; //Taking input for user's choice

	Menu::checkInput(newShapeMenuChoice); //checking the validity of the input.

	//If user's choice input was out of the options range, printing error and taking new input.
	while (newShapeMenuChoice < MIN_OPTION || newShapeMenuChoice > MAX_OPTION)
	{
		cout << RED;
		cout << RANGE_ERROR << endl;
		cout << RESET_COLOR;
		cin >> newShapeMenuChoice;
		Menu::checkInput(newShapeMenuChoice); //checking the validity of the input.
	}

	//Cyan text for user's input at the shape's data collecting fields.
	cout << CYAN;

	//PICKING ACTION ACCORDING TO THE USER'S CHOICE:
	switch (newShapeMenuChoice)
	{
	case (ARROW): //Create a arrow shape
		(shapeVector)->push_back(Menu::CreateArrow(canvas));
		break;
	case (CIRCLE): //Create a circle shape
		(shapeVector)->push_back(Menu::CreateCircle(canvas));
		break;
	case (TRIANGLE): //Create a triangle shape
		(shapeVector)->push_back(Menu::CreateTriangle(canvas));
		break;
	case (RECTANGLE): //Create a rectangle shape
		(shapeVector)->push_back(Menu::CreateRectangle(canvas));
		break;
	}
	cout << RESET_COLOR; //reseting the color (from cyan back to white).
}

/*
Function creates a new arrow, draws it, and returns it to be added to the shapes vector.
Input: Canvas& canvas
Output: pointer to the new created arrow
*/
Arrow* Menu::CreateArrow(Canvas& canvas)
{
	//setting variables at the start of the function
	double X1, Y1, X2, Y2;
	string name;

	//taking input for the shape's name and parameters.
	cout << "\nPlease enter a name for the shape:  ";
	cin >> name;

	cout << "Please enter the X coordinate of the first point:  ";
	cin >> X1;

	cout << "Please enter the Y coordinate of the first point :  ";
	cin >> Y1;

	cout << "Please enter the X coordinate of the second point :  ";
	cin >> X2;

	cout << "Please enter the Y coordinate of the second point :  ";
	cin >> Y2;

	//creating a new shape with the recived input.
	Arrow* arrow = new Arrow(Point(X1, Y1), Point(X2, Y2), "Arrow", name);
	//drawing the shape.
	arrow->draw(canvas);
	//returning the shape's pointer.
	return arrow;
}

/*
Function creates a new rectangle, draws it, and returns it to be added to the shapes vector.
Input: Canvas& canvas
Output: pointer to the new created rectangle
*/
myShapes::Rectangle* Menu::CreateRectangle(Canvas& canvas)
{
	//setting variables at the start of the function
	double X, Y, width, length;
	string name;

	//taking input for the shape's name and parameters.
	cout << "\nPlease enter a name for the shape:  ";
	cin >> name;

	cout << "Please enter the X coordinate of the left corner:  ";
	cin >> X;

	cout << "Please enter the Y coordinate of the  left corner:  ";
	cin >> Y;

	cout << "Please enter the width:  ";
	cin >> width;

	cout << "Please enter the length:  ";
	cin >> length;

	//creating a new shape with the recived input.
	myShapes::Rectangle* rectangle = new myShapes::Rectangle(Point(X, Y), length, width, "Rectangle", name);
	//drawing the shape.
	rectangle->draw(canvas);
	//returning the shape's pointer.
	return rectangle;
}

/*
Function creates a new triangle, draws it, and returns it to be added to the shapes vector.
Input: Canvas& canvas
Output: pointer to the new created triangle
*/
Triangle* Menu::CreateTriangle(Canvas& canvas)
{
	//setting variables at the start of the function
	double X1, Y1, X2, Y2, X3, Y3;
	string name;

	//taking input for the shape's name and parameters.
	cout << "\nPlease enter a name for the shape:  ";
	cin >> name;

	cout << "Please enter the X coordinate for the first point:  ";
	cin >> X1;

	cout << "Please enter the Y coordinate for the first point:  ";
	cin >> Y1;

	cout << "Please enter the X coordinate for the second point:  ";
	cin >> X2;

	cout << "Please enter the Y coordinate for the second point:  ";
	cin >> Y2;

	cout << "Please enter the X coordinate for the third point:  ";
	cin >> X3;

	cout << "Please enter the Y coordinate for the third point:  ";
	cin >> Y3;

	//creating a new shape with the recived input.
	Triangle* triangle = new Triangle(Point(X1, Y1), Point(X2, Y2), Point(X3, Y3), "triangle", name);
	//drawing the shape.
	triangle->draw(canvas);
	//returning the shape's pointer.
	return triangle;
}

/*
Function creates a new circle, draws it, and returns it to be added to the shapes vector.
Input: Canvas& canvas
Output: pointer to the new created circle
*/
Circle* Menu::CreateCircle(Canvas& canvas)
{
	//setting variables at the start of the function
	double X, Y, radius;
	string name;

	//taking input for the shape's name and parameters.
	cout << "\nPlease enter a name for the shape:  ";
	cin >> name;

	cout << "Please enter the X coordinate for the center of the circle:  ";
	cin >> X;

	cout << "Please enter the Y coordinate for the center of the circle:  ";
	cin >> Y;

	cout << "Please enter a radius for the circle:  ";
	cin >> radius;

	//creating a new shape with the recived input.
	Circle* circle = new Circle(Point(X, Y), radius, "circle", name);
	//drawing the shape.
	circle->draw(canvas);
	//returning the shape's pointer.
	return circle;
}

/*
Function for changing a shape from the shapes vector (moving or deleting), or get it's details.
Input: Canvas& canvas, vector<Shape*>& shapeVector
Output: none.
*/
void Menu::ChangeOrGet(Canvas& canvas, vector<Shape*>& shapeVector)
{
	//setting variables at the start of the function
	int choice, action, toMoveX, toMoveY;

	//entering if the vector has at least one shape.
	if (shapeVector.size() != ZERO)
	{
		//printing all shapes from the vector, and the number for selecting each one.
		for (int i = ZERO; i < shapeVector.size(); i++)
		{
			cout << "Enter " << (i + ONE) << " for the " << shapeVector[i]->getType() << " named " << shapeVector[i]->getName() << endl;

		}

		cin >> choice; //decreasing the choice by one (to represent index).
		Menu::checkInput(choice); //checking the validity of the input.
		choice--;
		cout << SHAPES_OPTIONS_MENU; //printing the shape options menu, and taking user's input.
		cin >> action;
		Menu::checkInput(choice); //checking the validity of the input.

		//PICKING ACTION ACCORDING TO THE USER'S CHOICE:
		switch (action)
		{
		case MOVE_SHAPE:
			//getting x and y moving scale input.
			cout << "Please enter the x moving scale:  ";
			cin >> toMoveX;
			Menu::checkInput(choice); //checking the validity of the input.
			cout << "Please enter the y moving scale:  ";
			cin >> toMoveY;
			Menu::checkInput(choice); //checking the validity of the input.

			shapeVector[choice]->clearDraw(canvas); //clearing the shape (before changing).
			shapeVector[choice]->move(Point(toMoveX, toMoveY)); //moving the shape.

			//printing all shapes again after moving one shape.
			for (int i = ZERO; i < shapeVector.size(); i++)
			{
				shapeVector[i]->draw(canvas);
			}
			break;

		case SHAPE_INFO: //printing the selected shape's details to the user (in green text).
			cout << GREEN;
			shapeVector[choice]->printDetails();
			cout << RESET_COLOR;
			break;

		case DELETE_SHAPE: //deleting the selected shape.
			shapeVector[choice]->clearDraw(canvas);
			//moving all the items of the vector one slot back.
			for (int i = choice; i < shapeVector.size() - ONE; i++)
			{
				shapeVector[i] = shapeVector[i+ONE];
			}

			shapeVector.pop_back(); //popping the last slot.

			//drawing all shapes again after deletion of one shape.
			for (int i = ZERO; i < shapeVector.size(); i++)
			{
				shapeVector[i]->draw(canvas);
			}
		}
	}
}

/*
Function to delete all shapes from the shapes vector, and clean the board.
Input: Canvas& canvas, vector<Shape*>& shapeVector
Output: none
*/
void Menu::deleteAllShapes(Canvas& canvas, vector<Shape*>& shapeVector)
{
	//looping through the shapes vector, to clean each shape from the board and pop it from the vector.
	for (int i = shapeVector.size() - ONE; i >= 0; i--)
	{
		shapeVector[i]->clearDraw(canvas); //cleaning from the board.
		shapeVector.pop_back(); //popping from the vector.
	}
}

/*
Destructor function for a menu object.
Input: none
Output: none
*/
Menu::~Menu()
{
}

/*
Static function to check input errors (cin fail), in case user enterd a char to int etc..
Input: int& num (reference variable)
Output: none
*/
void Menu::checkInput(int& num)
{
	if (cin.fail()) //checking if there is a cin fail (input error)
	{
		num = ERROR_NUMBER; //setting num to ERROR_NUMBER (-1) in order to repeat the option choice in the main code.
		cin.clear(); //clearing the input buffer
		cin.ignore(CHAR_MAX, '\n'); //ignoring cin input until '\n' (new line).
	}
}

