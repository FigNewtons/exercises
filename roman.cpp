/*
	Roman Numeral Converter
	Written by: FigNewtons
	Date: October 20, 2013

	Converts user-entered roman numeral into its equivalent decimal value.
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

void toUpper(string &);
bool errorCheck(string, map <char, int>);
int calcValue(string, map <char, int>);

int main()
{
	string numeral;

	// Define Map for Roman Numeral Values
	map <char, int> romanValues;
	
	romanValues['I'] = 1;
    romanValues['V'] = 5;
    romanValues['X'] = 10;
    romanValues['L'] = 50;
    romanValues['C'] = 100;
    romanValues['D'] = 500;
    romanValues['M'] = 1000;

	// Get user input
	cout << "Enter a roman numeral: ";
	cin >> numeral;

	toUpper(numeral);

	if(errorCheck(numeral, romanValues))
		cout << "The value is: " << calcValue(numeral, romanValues) << endl;
	else
		cout << "Invalid input" << endl;

	return 0;
}


// Convert string to uppercase letters 
void toUpper(string &numeral)
{
	for (int i = 0; i < numeral.length(); i++)
		numeral[i] = toupper(numeral[i]);
}


// Check if user has entered a valid roman numeral letters
bool errorCheck(string numeral, map <char, int> romanValues)
{
	for (int i=0; i < numeral.length(); i++)
		if(romanValues.count(numeral[i]) <= 0)
			return false;

	return true;
}


// Calculate value of roman numeral
int calcValue(string numeral, map <char, int> romanValues)
{
	int len = numeral.length();

	if (len == 1)
		return romanValues[numeral[0]];

	else
	{
		int sum = 0;

		for (int i=0; i < len; i++)
		{
			int m = romanValues[numeral[i]];
   			int n = romanValues[numeral[i+1]];

			if (m < n)
        	      {
        	       sum = sum + (n-m);
        	       i++;
        	      }
        	   else
        	       sum += m;
		}
		return sum;	
	}
	
}
