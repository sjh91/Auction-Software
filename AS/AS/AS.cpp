// AS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>

//Globals: 

//std::string personName;
//std::string address;
//std::string auctionNumber;
//std::string phoneNumber;
class person
{
public:
	person() {}
	~person() {}
	
	void setPersonName(std::string x) {  personName= x; }
	void setAddress(std::string x) { Address = x; }
	void setAuctionNumber(long x) { auctionNumber = x; }
	void setPhoneNumber(long x) { phoneNumber = x; }
	
	std::string getPersonName(){return personName;}
	std::string getAddress(){return Address;}
	long getAuctionNumber(){return auctionNumber;}
	long getPhoneNumber(){return phoneNumber;}
	
	
private:
	std::string personName; 
	std::string Address; 
	long auctionNumber; 
	long phoneNumber;

};
person * P;
class product 
{
public:
	product(){}
	~product(){}
// Accessor Functions 
	void setPrice(double x){price = x; }
	void setQuantity(double x){quantity = x; }
	void setCropType(std::string x){cropType=x; }
	void setAuctionNumber(long x){auctionNumber=x; }
	
	
private:
	double price;
	double quantity;
	std::string cropType;
	long auctionNumber;
	
};
void addBuyer()
{
	P = new person();
	std::string temp;
	long tempLong;
	
	
	std::ofstream buyers;
	buyers.open("buyers.txt", std::ios::app);
		
	if (buyers.fail())
	{
		std::cout << "Error opening File" << std::endl;
		return;
	}

	std::cout << "Enter Buyers Name" << std::endl;
	std::cin.ignore();
	getline(std::cin, temp);
	P->setPersonName(temp);
	
	std::cout << "Enter Buyers Address" << std::endl;
	getline(std::cin, temp);
	P->setAddress(temp);
		
	std::cout << "Enter Buyers Auction Number" << std::endl;
	std::cin >>tempLong;
	P->setAuctionNumber(tempLong);
	
	std::cout << "Enter Buyers Phone Number" << std::endl;
	std::cin >> tempLong;
	P->setPhoneNumber(tempLong);
	
		buyers << P->getPersonName() << " " << P->getAddress() << " " << P->getAuctionNumber() << " " << P->getPhoneNumber() << std::endl;
	
		buyers.close();

		return;
}

void addSeller()
{
	P = new person();
	std::string temp;
	long tempLong;


	std::ofstream sellers;
	sellers.open("sellers.txt", std::ios::app);

	if (sellers.fail())
	{
		std::cout << "Error opening File" << std::endl;
		return;
	}

	std::cout << "Enter Sellers Name" << std::endl;
	std::cin.ignore();
	getline(std::cin, temp);
	P->setPersonName(temp);

	std::cout << "Enter Seller Address" << std::endl;
	getline(std::cin, temp);
	P->setAddress(temp);

	std::cout << "Enter Seller Auction Number" << std::endl;
	std::cin >>tempLong;
	P->setAuctionNumber(tempLong);

	std::cout << "Enter Seller Phone Number" << std::endl;
	std::cin >> tempLong;
	P->setPhoneNumber(tempLong);

	//write to file
	//sellers << P->personName << " " << P->address << " " << P->auctionNumber << " " << P->phoneNumber << std::endl;

	sellers.close();
}

int main()
{
	std::string name;
	std::string address;
	long number;
	char choice[10];
	while (choice[0] != 'q')
	{
		std::cout << "|----------Menu---------------|" << std::endl;
		std::cout << "|----------Add (B)uyer----------|" << std::endl;
		std::cout << "|----------Add (S)eller---------|" << std::endl;
		std::cout << "|----------Add (C)rop-----------|" << std::endl;
		std::cout << "|----------Create (I)nvoice-----|" << std::endl;

		std::cin >> choice[0];

		switch (choice[0])
		{
		case 'B': addBuyer(); break;
		case 'S': addBuyer(); break;
		case 'C': addBuyer(); break;
		case 'I': addBuyer(); break;

		}
	}
    return 0;
}

