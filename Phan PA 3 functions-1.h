/*
Peter Nguyen
Last Date Modified: 6 December 2016
Assignment: Programming Assignment #3
Description: A program that manages a car dealership
Status: Complete
Met All Requirements: Yes
*/

#ifndef functions_h
#define functions_h

// Pre-processor directives
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "vehicle.h"
#include <fstream>

using namespace std;

/*
THIS WILL CONTAIN GLOBAL FUNCTIONS
*/

// Function prototypes
void displayV(vector<Vehicle>);
vector<Vehicle> addV(vector<Vehicle>);
vector<Vehicle> editV(vector<Vehicle>);
vector<Vehicle> deleteV(vector<Vehicle>);
vector<Vehicle> sortV(vector<Vehicle>);
void searchV(vector<Vehicle>);
vector<Vehicle> readV(vector<Vehicle>);
void writeV(vector<Vehicle>);

// **************************************************************
// FUNCTION DEFINITIONS

// Displays the inventory
void displayV(vector<Vehicle> vectInv)
{
	// If the inventory is empty
	if (vectInv.empty())
	{
		cout << "\nSorry the inventory currently has no vehicles within it." << endl;
	}
	// If the inventory is not empty
	else
	{

		cout << "**************************************************************" << endl;
		for (int index = 0; index < vectInv.size(); index++)
		{
			cout << setprecision(2) << fixed;
			cout << "\n----------------------" << endl;
			cout << "\nVehicle:\t#" << index + 1 << endl;
			cout << "\nVIN:\t\t" << vectInv[index].getVIN() << endl;
			cout << "\nMake:\t\t" << vectInv[index].getMake() << endl;
			cout << "\nModel:\t\t" << vectInv[index].getModel() << endl;
			cout << "\nYear:\t\t" << vectInv[index].getYear() << endl;
			cout << "\nPrice:\t\t$" << vectInv[index].getPrice() << endl;
			cout << "\nDealer Name:\t" << vectInv[index].dealerPtr->getDealerName() << endl;
			cout << "\nDealer Address:\t" << vectInv[index].dealerPtr->getDealerAdd() << endl;
			
		}
		cout << "\n**************************************************************" << endl;
	}
}

// Adds a vehicle
vector<Vehicle> addV(vector<Vehicle> vectInv)
{
	// Variables
	int xYear;
	double xPrice;
	string xVIN, xMake, xModel, xDealerName, xDealerAddress;
	
	cout << "\nPlease enter the vehicle's VIN:" << endl;
	cin >> xVIN;
	
	cout << "Please enter the vehicle's make:" << endl;
	cin >> xMake;

	cout << "Please enter the vehicle's model:" << endl;
	cin >> xModel;

	cout << "Please enter the vehicle's year:" << endl;
	cin >> xYear;

	cout << "Please enter the vehicle's price/value:" << endl;
	cin >> xPrice;

	Vehicle v(xVIN, xMake, xModel, xYear, xPrice); 

	cin.ignore();
	cout << "Please enter the name of the vehicle's dealer:" << endl;
	getline (cin, xDealerName); 
	cout << "Please enter the address of the vehicle's dealer:" << endl;
	getline (cin, xDealerAddress);

	v.dealerPtr->setDealerName(xDealerName); 
	v.dealerPtr->setDealerAdd(xDealerAddress);

//	Store values in the vector
	vectInv.push_back(v);

	return vectInv;
}

vector<Vehicle> editV(vector<Vehicle> vectInv)
{
	// If the inventory is empty
	if (vectInv.empty())
	{
		cout << "\nSorry the inventory currently has no vehicles within it." << endl;
		return vectInv;
	}
	else
	{
		// Variables
		int choice1, choice2;

		cout << endl;

		// Display the inventory again
		displayV(vectInv);

		cout << "\nPlease enter the vehicle's number(#) that is desired to be edited:\n" << endl;
		cin >> choice1;

		// Error checking
		if (choice1 < vectInv.size() + 1 && choice1 > 0)
		{
			do
			{
				cout << endl << "Please enter the number corresponding to the aspect of vehicle #" << choice1 << " that is desired to be edited." << endl;
				cout << "1. VIN" << endl;
				cout << "2. Make" << endl;
				cout << "3. Model" << endl;
				cout << "4. Year" << endl;
				cout << "5. Price" << endl;
				cout << "6. Return to the main menu" << endl << endl; 
				cin >> choice2;

				// Variables
				string xxVIN, xxMake, xxModel, xxdealerName, xxdealerAddress;
				int xxYear;
				double xxPrice;

					switch (choice2)
					{
						case 1:
							cout << "\nPlease enter the new VIN of the vehicle:" << endl;
							cin >> xxVIN;
							vectInv[choice1 - 1].setVIN(xxVIN);
							cout << "VIN changed." << endl;
							break;
						case 2:
							cout << "\nPlease enter the new make of the vehicle:" << endl;
							cin >> xxMake;
							vectInv[choice1 - 1].setMake(xxMake);
							cout << "Make changed." << endl;
							break;
						case 3:
							cout << "\nPlease enter the new model of the vehicle:" << endl;
							cin >> xxModel;
							vectInv[choice1 - 1].setModel(xxModel);
							cout << "Model changed." << endl;
							break;
						case 4:
							cout << "\nPlease enter the new year of the vehicle:" << endl;
							cin >> xxYear;
							vectInv[choice1 - 1].setYear(xxYear);
							cout << "Year changed." << endl;
							break;
						case 5:
							cout << "\nPlease enter the new price of the vehicle:" << endl;
							cin >> xxPrice;
							vectInv[choice1 - 1].setPrice(xxPrice);
							cout << "Price changed." << endl;
							break;
						case 6:
							int main();
							break;
						default:
							cout << "You did not enter any number from 1 to 6. Please try again." << endl;
					}
			} while (choice2 != 6);
		}
		else
		{
			cout << "That vehicle number(#) is invalid." << endl;
		}
	}
	 return vectInv;
}

vector<Vehicle> deleteV(vector<Vehicle> vectInv)
{
	if (vectInv.empty())
	{
		cout << "\nSorry the inventory currently has no vehicles within it." << endl;
		return vectInv;
	}
	else
	{
		// Variables
		int choice1, choice2, index;

		cout << endl;

		displayV(vectInv);

		cout << "Please enter the vehicle's number(#) that is desired to be deleted:\n" << endl;
		cin >> choice1;

		// Error check
		if (choice1 < vectInv.size() + 1 && choice1 > 0)
		{
			for (index = choice1 - 1; index < vectInv.size() - 1; index++)
			{
				vectInv[index] = vectInv[index + 1];
			}
			vectInv.pop_back();
			cout << "\nVehicle #" << choice1 << " has been deleted." << endl;
		}
		else
		{
			cout << "That vehicle number(#) is invalid." << endl;
		}
		return vectInv;
	}
}

vector<Vehicle> sortV(vector<Vehicle> vectInv)
{
	if (vectInv.empty())
	{
		cout << "\nSorry the inventory currently has no vehicles within it." << endl;
		return vectInv;
	}
	else
	{
		int capacity = vectInv.size() - 1;
		while (capacity != 0)
		{
			for (int index = 0; index < vectInv.size() - 1; index++)
			{
				if (vectInv[index].getVIN() > vectInv[index + 1].getVIN())
				{
					// SWAP
					Vehicle dummy1 = vectInv[index];
					Vehicle dummy2 = vectInv[index + 1];
					vectInv[index] = dummy2;
					vectInv[index + 1] = dummy1;
				}
			}
			capacity--;
		}
		cout << "The inventory has been sorted by the VIN number of all vehicles." << endl;
		return vectInv;
	}
}

void searchV(vector<Vehicle> vectInv)
{
	if (vectInv.empty())
	{
		cout << "\nSorry the inventory currently has no vehicles within it." << endl;
	}
	else
	{
		// Variables
		int index = 0;
		int location = -1;
		string searchVal;
		bool discovered = false;

		cout << "Please enter the make of the vehicle desired to be searched:" << endl;
		cin >> searchVal;

		// See if the "searchVal" even exists
		while (index < vectInv.size() && !discovered)
		{
			if (vectInv[index].getMake() == searchVal)
			{
				discovered = true;
				location = index;
			}
			index++;
		}
		if (location == -1)
		{
			cout << "The inventory has no such make." << endl;
		}
		else
		{
			cout << "A(n) " << searchVal << " was found, its vehicle/index number is #" << location + 1 << " within the inventory." << endl;
		}
	}
}

vector<Vehicle> readV(vector<Vehicle> vectInv)
{
	// Variables
	int xYear;
	int index = 0;
	double xPrice;
	string xVIN, xMake, xModel, xDealerName, xDealerAddress;

	ifstream inputFile;

	inputFile.open("inventory.txt");

	while (!inputFile.eof())
	{
		{
			string dummy;
			
			// Have to use getline for STRING
			getline(inputFile, xVIN);
			getline(inputFile, xMake);
			getline(inputFile, xModel);
			inputFile >> xYear;
			inputFile >> xPrice;
			inputFile.ignore();
			getline(inputFile, xDealerName);
			getline(inputFile, xDealerAddress);

			Vehicle v(xVIN, xMake, xModel, xYear, xPrice);

			v.dealerPtr->setDealerName(xDealerName);
			v.dealerPtr->setDealerAdd(xDealerAddress);

			//	Store values in the vector
			vectInv.push_back(v);
		}
	}
	cout << "\nSuccess" << endl;
	inputFile.close();
	return vectInv;
}

void writeV(vector<Vehicle> vectInv)
{
	ofstream outFile;
	outFile.open("inventory.txt");

	if (outFile)
	{
		// Last iteration
		for (int index = 0; index < vectInv.size(); index++)
		{
			// Last iteration
			if (index == vectInv.size() - 1)
			{
				outFile << setprecision(2) << fixed;
				outFile << vectInv[index].getVIN() << "\n";
				outFile << vectInv[index].getMake() << "\n";
				outFile << vectInv[index].getModel() << "\n";
				outFile << vectInv[index].getYear() << "\n";
				outFile << vectInv[index].getPrice() << "\n";
				outFile << vectInv[index].dealerPtr->getDealerName() << "\n";
				outFile << vectInv[index].dealerPtr->getDealerAdd();
			}
			else
			{
				outFile << setprecision(2) << fixed;
				outFile << vectInv[index].getVIN() << "\n";
				outFile << vectInv[index].getMake() << "\n";
				outFile << vectInv[index].getModel() << "\n";
				outFile << vectInv[index].getYear() << "\n";
				outFile << vectInv[index].getPrice() << "\n";
				outFile << vectInv[index].dealerPtr->getDealerName() << "\n";
				outFile << vectInv[index].dealerPtr->getDealerAdd() << endl;
			}
		}
		// Close
		outFile.close();
	}
	cout << "File written successfully." << endl;
}
#endif