// Phan_PA1.cpp : Defines the entry point for the console application.
//

// ConsoleApplication1.cpp : Defines the entry point for the console application.
/*Nghi Phan
CSCI 1410
Magic Number Program 1a
status: complete, and compile correctly on Visual Studio
Descrption: Program to run a menu and give the magic number 1089 in the end.
*/

#include <iostream>
#include <string>
#include <cmath>


using namespace std;
int main()
{
	// pre-menu
	string className;
	string name;
	cout << "Hello, please enter your first name:";
	cin >> name;
	cout << "please enter your class: ";
	cin.ignore();
	getline(cin, className);
	cout << name << " welcome to your Magic Number Program. I hope it helps you with your "
		<< className << " class\n";

	while (true)
	{
		char choice;
		//display the menu and get a choice.
		cout << "\t\t Please select an operation\n\n"
			<< "A.Display an example\n"
			<< "B. Try it out yourself!\n"
			<< "C. Exit\n";
		cin >> choice;

		if ((choice == 'A') || (choice == 'a'))
		{

			cout << " Here is an example of the program\n"
				<< " Take a three digit number, whose first digit is greater than its last\n"
				<< " Ex: 901\n"
				<< " reverse the number by multiplying the first number by 1/100, second number by 1/10"
				<< " and third number by 1\n"
				<< " Ex: 109\n"
				<< " Subtract the reversal from the original number\n"
				<< " Ex: 901-109= 792\n"
				<< " reverse the resulting number by multiplying the first number by 1/100, second number by 1/10"
				<< " and third number by 1\n"
				<< " Ex: 297\n"
				<< " Add to its un-reversed form\n"
				<< " Ex: 297+792= 1089\n";

		}

		else if ((choice == 'B') || (choice == 'b'))
		{
			int answer;
			cout << "Please enter a number whose first digit is greater than its last\n";
			cin >> answer;
			int nInv; // reverse the number the first time
			int result;

			nInv = (answer % 10 * 100) + ((((answer - answer % 10) / 10) % 10) * 10) +
				((((answer - answer % 100) / 100) % 10) * 1);
			// reversing the number by first isolating each number and then multiply it.

			cout << "the reverse number is  " << nInv << endl;
			cout << "subtract the reversal number from the original number\n";
			//subtract the reversal number from original
			result = (answer - nInv);
			// reverse the resulting number
			int reverse1; // reverse the number a second time
			int magicNumber;

			reverse1 = (result % 10 * 100) + ((((result - result % 10) / 10) % 10) * 10) +
				((((result - result % 100) / 100) % 10) * 1);

			cout << "the reverse number is " << reverse1 << endl;
			cout << " add it to its un-reversed form\n ";
			magicNumber = (reverse1 + result);
			cout << "your magic number is " << magicNumber << endl;


		}

		else if ((choice == 'C') || (choice == 'c'))
		{
			return 0;
		}

		else
			cout << "please enter a,b or c" << endl;
	}//while
	return 0;
}// main 

