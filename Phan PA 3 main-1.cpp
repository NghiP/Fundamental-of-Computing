/*
Peter Nguyen
Last Date Modified: 6 December 2016
Assignment: Programming Assignment #3
Description: A program that manages a car dealership
Status: Complete
Met All Requirements: Yes
*/

// Pre-processor directives
#include "vehicle.h"
#include "functions.h"
#include <iostream>
#include <vector>

// Namespace
using namespace std;

int main()
{
	vector<Vehicle> entireInv;
	int choice;

	do
	{
		// Present the user with a menu
		cout << endl << "Please select an operation from this menu: " << endl;
		cout << "1: Display Inventory" << endl;
		cout << "2: Add a vehicle" << endl;
		cout << "3: Update a vehicle" << endl;
		cout << "4: Delete a vehicle" << endl;
		cout << "5: Sort inventory by VIN" << endl;
		cout << "6: Search inventory by model" << endl;
		cout << "7: Read inventory from a file" << endl;
		cout << "8: Write inventory to a file and exit" << endl << endl;
		cin >> choice;

		// Switch statement
		switch (choice)
		{
		case 1:
			// Call displayV
			displayV(entireInv);
			break;
		case 2:
			// Call addV
			entireInv = addV(entireInv);
			break;
		case 3:
			// Call editV
			entireInv = editV(entireInv);
			break;
		case 4:
			// Call deleteV
			entireInv = deleteV(entireInv);
			break;
		case 5:
			// Call sortV
			entireInv = sortV(entireInv);
			break;
		case 6:
			// Call searchV
			searchV(entireInv);
			break;
		case 7:
			// Call readV
			entireInv = readV(entireInv);
			break;
		case 8:
			// Call writeV
			writeV(entireInv);
			break;
		default:
			cout << "You did not enter any number from 1 to 8. Please try again." << endl;
		}

	} while (choice != 8);

	return 0;
}