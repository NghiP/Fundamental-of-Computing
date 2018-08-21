// Nghi Phan Prep-Project 2.cpp : Defines the entry point for the console application.
//Dr. Augustine
//CSCI 1410
//Status:complete
//Description: Creating a library to read in books from an inventory file. 


#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Phan.h"
using namespace std;



int main()

{
	const int MAXSIZE = 100;
	BookInfo books[MAXSIZE];
	int size = 0;
	

	//main

	while (true)
	{//menu
		char choice;
		cout << "\t\t Here is the menu for the program that is a library\n"
			<< "1: Read inventory from file\n"
			<< "2: Add an entry \n"
			<< "3: Delete an entry \n"
			<< "4: Update an entry\n"
			<< "5: Sort inventory \n"
			<< "6: Write inventory to file\n"
			<< "e: to exit\n";
		cin >> choice;

		if (choice == '1')
		{
			readInventory(books,size, MAXSIZE);

		}
		else if (choice == '2')
		{
			addInventory(books,size,MAXSIZE);
		}

		else if (choice == '3')
		{
			DeleteInventory(books,size);
		}
		else if (choice == '4')
		{
			updateInventory(books,size);
		}
		else if (choice == '5')
		{
			sortInventory(books,size);
		}
		else if (choice == '6')
		{
			writeInventory(books,size);
		}
		else if (choice == 'e')
			return 0;
		else
			cout << "Please select 1-6 or e in the program" << endl;
	}// menu
	return 0;
}// main

