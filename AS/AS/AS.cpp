// AS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>

//Globals: 
 person * P;

//std::string personName;
//std::string address;
//std::string auctionNumber;
//std::string phoneNumber;
class person
{
public:
	person() {}
	~person() {}
	
	std:string getPersonName(){return personName;}
	std:string getAddress(){return address;}
	std:string getAuctionNumber(){return auctionNumber;}
	std:string getPhoneNumber(){return phoneNumber;}
	
	
private:
	std::string personName; 
	std::string Address; 
	long auctionNumber; 

};
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
	
}
void addBuyer()
{
	P = new person();
	std:string temp;
	
	
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
	getline(std::cin, temp);
	P->setAuctionNumber(temp);
	
	std::cout << "Enter Buyers Phone Number" << std::endl;
	getline(std::cin, temp);
	P->setPhoneNumber(temp);
	
		buyers << P->personName << " " << P->address << " " << P->auctionNumber << " " << P->phoneNumber << std::endl;
	buyers.close();

}

void addSeller()
{
	P = new person();
	std:string temp;
	
	
	std::ofstream sellers;
	sellers.open("sellers.txt", std::ios::app);
		
	if (buyers.fail())
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
	getline(std::cin, temp);
	P->setAuctionNumber(temp);
	
	std::cout << "Enter Seller Phone Number" << std::endl;
	getline(std::cin, temp);
	P->setPhoneNumber(temp);
	
	//write to file
	sellers << P->personName << " " << P->address << " " << P->auctionNumber << " " << P->phoneNumber << std::endl;
	
	sellers.close();


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

