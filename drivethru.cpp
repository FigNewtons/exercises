/*
	Example Drive-thru Menu
	Written by: Fig Newtons 
	Date: October 23, 2013

	Practice with structs and maps

*/

#include <iostream>
#include <iomanip>
#include <string>
#include <map>

using namespace std;

// Create struct for each food option
struct Option
{
	string name; 		// item name
	float regPrice; 	// price without meal
	float mealPrice;	
};

// Create map to pair menu number with food option
map <int, Option> menu;

// Function prototypes
void displayMenu(map <int, Option>);
int getOrder();
bool isValidOption(int);
bool orderDone();


int main()
{

	// Declare food options
	Option bigMac = {"Big Mac", 3.99, 5.69};
	Option cheeseBurger = {"Cheeseburger", 1.29, 4.69}; 
	Option qtrPounder = {"Quarter Pounder with Cheese", 3.69, 5.39}; 
	Option dlbPounder= {"Double Quarter Pounder with Cheese", 4.69, 6.39};
	Option filet = {"Filet-O-Fish", 3.49, 5.19}; 
	Option dlbCheese = {"Double Cheeseburger", 1.29, 3.69}; 
	Option chkBLT = {"Chicken Ranch BLT", 4.19, 5.89};
	Option clubChicken = {"Club Chicken (Grilled or Cripsy)", 4.29, 5.99}; 
	Option classic = {"Classic Chicken (Grilled or Cripsy)", 3.99, 5.69}; 

	// Delcare menu 
	menu[1] = bigMac;
	menu[2] = cheeseBurger;
	menu[3] = qtrPounder;
	menu[4] = dlbPounder;
	menu[5] = filet;
	menu[6] = dlbCheese;
	menu[7] = chkBLT;
	menu[8] = clubChicken;
	menu[9] = classic;


	// -----Where program starts-----
	bool isOrderDone = false; 
	do
	{
		displayMenu(menu);
		int option = getOrder();
		if(!isValidOption(option))
			cout << "Invalid option entered.\n";
		isOrderDone = orderDone();
	}
	while(!isOrderDone);

	return 0;
}



// Displays menu 
void displayMenu(map <int, Option>)
{
	cout << "------------------------------------------------------\n";
	cout << "--------------------McDonald's Menu-------------------\n";
	cout << "------------------------------------------------------\n";
	for (int i=1; i < menu.size()+1; i++)
	{
		cout << i << ". " << menu[i].name << " " << setw(47- menu[i].name.length()) << "$" << menu[i].regPrice << endl;
		cout << "   " << menu[i].name << " - Meal" << setw(41- menu[i].name.length()) << "$" << menu[i].mealPrice << endl;
		
	}
}

// Gets the user's option number
int getOrder()
{
	int order;
	cout << "What would you like to order? Press a valid option number: ";
	cin >> order;

	return order;
}

// Validates user input for number in correct range
bool isValidOption(int order) 
{
	if(menu.find(order) == menu.end())
		return false;
	else
		return true;
}

bool orderDone()
{
	char done;
	cout << "Will that be all today? Press 'y' for yes or any other character for no: ";
	cin >> done;

	done = tolower(done);
	if (done == 'y')
		return true;
	else
		return false; 
}


