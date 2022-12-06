#include "Menu.h"
//MAIN CODE
void main()
{
	//creating main menu object (contains the program)
	Menu* program = new Menu();
	//deleting the dynamic memory of the menu object once we are finished with it.
	delete program;
}