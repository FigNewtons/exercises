/*
	Example Drive-thru Order
	Written by: Fig Newtons 
	Date: October 23, 2013

	Simulates ordering at the drive-thru of a fast food place. 
	Uses structs, templates, and maps

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

// Create map to keep track of user's order
map <string, int> order;


// Template for getting user input
template <typename T, typename U>
T getInput(U str)
{
	T input;
	cout << str << endl;
	cin >> input;

	return input;
}

// Check if key exists in map -- 
// used to validate user input for option number (map menu)
// and add new items to receipt (map order)
template <typename U, typename V>
bool inMap(U map, V key)
{
	if (map.find(key) == map.end())
		return false;
	else
		return true;
}

// Function prototypes
void displayMenu();
void displayReceipt(float, float);
bool isValidChar(char);


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
	Option clubChicken = {"Club Chicken", 4.29, 5.99}; 
	Option classic = {"Classic Chicken", 3.99, 5.69}; 

	// Declare menu 
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
	string prompt1 = "Press a valid option number: ";
	string prompt2 = "Press 'y' for yes or any other character for no: ";
	bool isOrderDone = false; 
	float total = 0;
	const float SALES_TAX = 0.07;
	
	do
	{
		displayMenu();
		int optionNum = getInput <int, string>("What would you like to order? " + prompt1);

		// Checks if user entered in a valid option number 
		if(!inMap(menu, optionNum))
    		cout << "Invalid option entered.\n";
		else
		{
			// Checks if user has order the same item before and keeps running total
			if(!inMap(order, menu[optionNum].name))
				order[menu[optionNum].name] = 1;
			else
				order[menu[optionNum].name] +=1;

			// Asks user if they want the meal version
			char input = getInput <char, string>("Would you like that to be a meal? " + prompt2);

			if(isValidChar(input))
				{
				total += menu[optionNum].mealPrice;

				// If user has not ordered same item before -- the key is updated to show meal
				if(!inMap(order, menu[optionNum].name + "-Meal"))
					{
					order.erase(menu[optionNum].name);
					order[menu[optionNum].name + "-Meal"] = 1;
					}
				}
			else
				total += menu[optionNum].regPrice;

		}

		// Asks if user is done ordering 
   		char done = getInput <char, string>("Will that be all today? " + prompt2);
		if(isValidChar(done))
			isOrderDone = true;
		
	}
	while(!isOrderDone);

	displayReceipt(total, SALES_TAX);

	return 0;
}



// Displays menu 
void displayMenu()
{
	cout << "------------------------------------------------------\n";
	cout << "--------------------McDonald's Menu-------------------\n";
	cout << "------------------------------------------------------\n";
	for (int i=1; i < menu.size()+1; i++)
	{
		cout << i << ". " << menu[i].name << " " << setw(47- menu[i].name.length()) 
			 << "$" << menu[i].regPrice << endl;

		cout << "   " << menu[i].name << " - Meal" << setw(41- menu[i].name.length()) 
			 << "$" << menu[i].mealPrice << endl;		
	}
}

//Displays receipt
void displayReceipt(float total, float tax)
{
	cout << "------------------------------------------------------\n";
	cout << "------------------------Receipt-----------------------\n";
    cout << "------------------------------------------------------\n";

	// Iterates through order map to print out how many of each item the user ordered
	for (map<string,int>::iterator it = order.begin(); it!= order.end(); it++)
		cout << it->first << "(" << it -> second << ")" << endl;

	cout << showpoint << fixed << setprecision(2); 
	cout << "Subtax:" << setw(10) << "$" << total << endl;
	cout << "Tax:" << setw(13) << "$" << total * tax << endl;
	total = total * (1 + tax);
	cout << "Your total is:" << setw(3) << "$" << total << endl;
	cout << "Please come again!" << endl;
}



// Validates user input for yes or no 
bool isValidChar(char input)
{
	input = tolower(input);
	if (input == 'y')
		return true;
	else
		return false; 
}


