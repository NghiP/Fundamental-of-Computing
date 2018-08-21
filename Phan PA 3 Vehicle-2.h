#ifndef Vehicle_h
#define Vehicle_h
#include <string>
using namespace std;
class Dealer				//naming the class dealer
{
private:					//private
	string dealerName;
	string dealerAddress;

public:						//Public

	void setDealerName(string input);	//do for all dealer and vehicle class
	void setDealerAddress(string input);
	string getDealerName();
	string getDealerAddress();
	Dealer();
	Dealer(string iName);

};

//********************************************************************

class Vehicle						//declaring the class Vehicle
{
	string VIN;
	string make;
	string model;
	int year;
	double price;
	
public:								//public
	Dealer *dealerPtr;								//declaring a pointer
	Vehicle();
	Vehicle(string iVIN, string iMake, string iModel, int iYear, double iPrice);
	string getVIN();
	string getMake();
	string getModel();
	int getYear();
	double getPrice();
	void setVIN(string input);
	void setMake(string input);
	void setModel(string input);
	void setYear(int input);
	void setPrice(double input);
	
	
	friend std::ostream &operator<<(ostream &os, Vehicle car1);
	
	//friend ostream& operator << (ostream &out, Vehicle car1);
	//need to declare friend operator<<(out:ostream &,Vehicle:car 1):ostream &

};

#endif/* Vehicle_h*/
