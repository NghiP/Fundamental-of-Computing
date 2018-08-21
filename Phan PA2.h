// Nghi Phan


#include <iostream>
#include <string>
#include <fstream>
using namespace std;


struct BookInfo
{
	int iSBN;
	string title;
	string Authour;
	string Publisher;
	int Quantity;
	double Price;
};
//function prototype
void readInventory(BookInfo books[], int &size);
void addInventory(BookInfo books[], int &size,int MAXSIZE);
void deleteInventory(BookInfo books[], int &size);
void updateInventory(BookInfo books[], int &size);
void sortInventory(BookInfo books[], int &size);
void writeInventory(BookInfo books[], int &size);


void readInventory(BookInfo books[], int &size, int MAXSIZE)
{
	ifstream inputFile;// input stream variable
	inputFile.open("inventory.txt");
	
	int index = 0;
	while (inputFile && size< MAXSIZE )
		
	{
		inputFile >> books[index].iSBN;
		inputFile.ignore();
		getline(inputFile, books[index].title);
		getline(inputFile, books[index].Authour);
		getline(inputFile, books[index].Publisher);
		inputFile >> books[index].Quantity;
		inputFile >> books[index].Price;
		size++;
	
	}
	cout << "You have successfully read in inventory" << endl;
	inputFile.close();
	
}
//******************************************************************************************		
void addInventory(BookInfo books[], int &size, int MAXSIZE)
{
	if (size < MAXSIZE)
	{

		cout << "Please enter the ISBN number" << endl;
		cin >> books[size].iSBN;

		cout << "Please enter the title" << endl;
		cin.ignore();
		getline(cin, books[size].title);



		cout << "Plese enter the authour" << endl;
		getline(cin, books[size].Authour);


		cout << "Please enter the Publisher" << endl;
			getline(cin, books[size].Publisher);


		cout << "Please enter the quantity" << endl;
		cin >> books[size].Quantity;


		cout << "PLease enter the Price" << endl;
		cin >> books[size].Price;

	}
	else
		cout << "You exceed the limit" << endl;
}


//*******************************************************************************************************************************************
void DeleteInventory(BookInfo books[], int &size)
{
if (size == 0)
	cout << "Please read in an entry first" << endl;
else
{
	int ISBN;
	cout << "Please enter the ISBN you want to delete" << endl;
	cin >> ISBN;

	for (int index = 0; index < size; index++)
	{
		if (books[index].iSBN == ISBN)
		{
			int j = index;
				while (j < size - 1)
				{
					books[j] = books[j + 1];
					j++;
				}
			size--;
		}
		break;
	}
	cout << "You have deleted the entry" << endl;

}

}


//*****************************************************************************************************************************
void updateInventory(BookInfo books[], int &size)
{
	
	int ISBN;
	int quant;
	cout << "Please enter the ISBN of the book you want to update" << endl;
	cin >> ISBN;

	bool notDone = true;
	while (notDone== true)
	{
		char value;
		cout << "Updating the quatity of the books please choose 3 choices\n"
			 << "a.decrement the quantity\n "
			 << "b. increment the quantity\n"
			 << "c. add a new value \n";
		cin >> value;

		if (value == 'a')
		{
			for (int index = 0; index < size; index++)
				if (books[index].iSBN == ISBN)
				{
					books[index].Quantity = (books[index].Quantity - 1);

				}
			notDone = false;
		}
		else if (value == 'b')
		{
			for (int index = 0; index < size; index++)
				if (books[index].iSBN == ISBN)
				{
					books[index].Quantity = (books[index].Quantity + 1);
				}
			notDone = false;

		}
		else if (value == 'c')
		{
			cout << "Please enter the quantity of the book" << endl;
			cin >> quant;
			for (int index = 0; index < size; index++)
				if (books[index].iSBN == ISBN)
				{
					books[index].Quantity = quant;
				}
			notDone = false;
		}
		else
			cout << "Please select a, b, c" << endl;
		
	}
}
//**********************************************************************************************************************************
void sortInventory(BookInfo books[], int &size)
{
		for (int index = 1; index < size; index++)
		{
			BookInfo current = books[index];
			int j = index;
			while (j > 0 && (books[j - 1].title).compare(current.title) > 0)
			{
				books[j] = books[j - 1];
				j--;
			}
			books[j] = current;
		}

		if (size != 0)
			cout << "The array has been sorted successfully." << endl;
		else
			cout << "The array is empty, read the data first." << endl;
}

//**********************************************************************************************************************************
void writeInventory (BookInfo books[], int &size)

{
ofstream OutputFile;
OutputFile.open("inventory.txt");
for (int index = 0; index < size; index++)
		{
	OutputFile << "books" << (index + 1) << endl;
	OutputFile << "ISBN number" << books[index].iSBN << endl;
	OutputFile << "Title of the book" << books[index].title << endl;
	OutputFile << " Authour" << books[index].Authour << endl;
	OutputFile << " Publisher" << books[index].Publisher << endl;
	OutputFile << " Quantity" << books[index].Quantity << endl;
	OutputFile << "Price $" << books[index].Price << endl;
		}
cout << "The array has been successfully read" << endl;
OutputFile.close();

}
