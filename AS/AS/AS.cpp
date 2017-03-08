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
//Global
person * P;
class product 
{
public:

	product(){}
	~product(){}

// Accessor Functions 
	void setCropType(std::string x) { cropType = x; }
	void setQuantity(double x) { quantity = x; }
	void setPrice(double x){price = x; }
	void setSellerNumber(long x){sellerNumber=x; }
	void setBuyerNumber(long x) { buyerNumber = x; }
	
	std::string getCropType() { return cropType; }
	double getQuantity() { return quantity; }
	double getPrice() { return price; }
	long getSellerNumber() { return sellerNumber; }
	long getBuyerNumber() { return buyerNumber; }

private:

	double price;
	double quantity;
	std::string cropType;
	long sellerNumber;
	long buyerNumber;
	
};
//Global
product * Prod;
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
	sellers << P->getPersonName() << " " << P->getAddress() << " " << P->getAuctionNumber() << " " << P->getPhoneNumber() << std::endl;

	sellers.close();
}

void addCrop()
{

	Prod = new product();
	std::string temp; // string of item sold
	double tempDouble; // used for price and quantity
	long tempLong; // used for numbers of buyers and sellers

	std::ofstream marketData;
	marketData.open("marketdata.txt", std::ios::app);
	if (marketData.fail())
	{
		std::cout << "Error opening Market Data file." << std::endl;
		return;
	}

	std::cout << "Enter type of produce sold" << std::endl;
	std::cin.ignore();
	getline(std::cin, temp);
	Prod->setCropType(temp);
	
	std::cout << "Enter quantity sold" << std::endl;
	std::cin >> tempDouble;
	Prod->setQuantity(tempDouble);

	std::cout << "Enter price of goods sold" << std::endl;
	std::cin >> tempDouble;
	Prod->setPrice(tempDouble);

	std::cout << "Enter Seller Number" << std::endl;
	std::cin >> tempLong;
	Prod->setSellerNumber(tempLong);

	std::cout << "Enter Buyer Number" << std::endl;
	std::cin >> tempLong;
	Prod->setBuyerNumber(tempLong);

	marketData << Prod->getCropType() << " " << Prod->getQuantity() << " " << Prod->getPrice() << " " << Prod->getBuyerNumber() << " " << Prod->getSellerNumber() << std::endl;

	marketData.close();
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
		case 'S': addSeller(); break;
		case 'C': addCrop(); break;
		//TODO:case 'I': makeInvoice(); break;
		//TODO Generate market Report

		}
	}
    return 0;
}

