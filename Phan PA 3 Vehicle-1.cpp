#include "vehicle.h"
#include <string>
#include <iostream>
using namespace std;
//Declaring variable in Dealer class

void Dealer::setDealerName(string input)
{
	dealerName = input;					//setname
}
void Dealer::setDealerAddress(string input)
{
	dealerAddress = input;			//set address
}
string Dealer::getDealerName()
{
	return dealerName;					//return name
}
string Dealer::getDealerAddress()
{
	return dealerAddress;				//return address
}

Dealer::Dealer()
{
	dealerName = " ";
	dealerAddress = "	";				//get the result
}

Dealer::Dealer(string iName)
{
	dealerName = iName;						// get the name

}
//*****************************************************************************************
// declaring the variable in Vehicle class

//need to declare pointer dealer
//need to declare vehicle with iVIN,iMake,iModel,iYear,iPrice

//Public Variable declaration
Vehicle::Vehicle(string iVIN, string iMake,string iModel, int iYear, double iPrice)
{
	iVIN = VIN;
	iMake = make;
	iModel = model;
	iYear = year;
	iPrice = price;
}
Vehicle::Vehicle()
{
	VIN = "";
	make = "";
	model = "";
	year = 0;
	price = 0.00;
	dealerPtr = new Dealer;
}
string Vehicle::getVIN()
{
	return VIN;
}
string Vehicle::getMake()
{
	return make;
}
string Vehicle::getModel()
{
	return model;

}
int Vehicle::getYear()
{
	return year;

}
double Vehicle::getPrice()
{
	return price;
}
void Vehicle::setVIN(string input)
{
	VIN = input;
}
void Vehicle::setMake(string input)
{
	make = input;
}
void Vehicle::setModel(string input)
{
	model = input;//set model
}
void Vehicle::setYear(int input)
{
	year = input;//set year
}
void Vehicle::setPrice(double input)
{
	price = input;//set price
}



//ostream & operator<<(ostream & out, Vehicle car1)

std::ostream & operator<<(std::ostream & out, Vehicle& car1)
{
	out << "VIN:\t" << car1.getVIN() << "\nMake:\t" << car1.getMake << "\nModel:\t" << car1.getModel() <<
		"\nYear:\t" << car1.getYear() << "\nPrice:\t$" << car1.getPrice << "\nDealer Name:\t" << car1.dealerPtr->getDealerName()
		<< "\nDealer Address:\t" << car1.dealerPtr->getDealerAddress();

}
