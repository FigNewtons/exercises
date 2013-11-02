/*
	Dynamically allocating arrays using pointers (example)
	Written By: Fig Newtons
	Date: October 22, 2013

	Using one array to dynamically allocate another 
*/

#include <iostream>

using namespace std;

int *createArray(int *, int);

int main()
{
	// Declare first array
	const int SIZE = 5;
	int array[SIZE] = {8,21,32,14,5};
	
	// Store pointer of new array 
	int *ptr = createArray(array, SIZE);

	cout << ptr << endl;    // Displays address of new array
	cout << ptr[3] << endl; // Displays 3rd element of new array - 32

	return 0;
}


/*
   Creates new array one element larger than the
   first, places zero in element zero, and then copies
   the values of first array into the remaining elements
   of the new array.
*/
int *createArray(int *array, int size)
{
	int *newArray = new int[size + 1];

	newArray[0] = 0;
	for (int i = 0; i < size; i++)
	{
		newArray[i+1] = array[i];
	}

	return newArray;

}
