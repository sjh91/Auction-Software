// AS.cpp : Defines the entry point for the console application.
//Sam Hardy
//sjh91@zips.uakron.edu;

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <template>

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

	void setPersonName(std::string x) { personName = x; }
	void setAddress(std::string x) { Address = x; }
	void setAuctionNumber(std::string x) { auctionNumber = x; }
	void setPhoneNumber(std::string x) { phoneNumber = x; }

	std::string getPersonName() { return personName; }
	std::string getAddress() { return Address; }
	std::string getAuctionNumber() { return auctionNumber; }
	std::string getPhoneNumber() { return phoneNumber; }


private:

	std::string personName;
	std::string Address;
	std::string auctionNumber;
	std::string phoneNumber;

};
//Global
person * P;

class product
{

public:

	product() {}
	~product() {}

	// Accessor Functions 
	void setCropType(std::string x) { cropType = x; }
	void setQuantity(double x) { quantity = x; }
	void setPrice(double x) { price = x; }
	void setSellerNumber(std::string x) { sellerNumber = x; }
	void setBuyerNumber(std::string x) { buyerNumber = x; }

	std::string getCropType() { return cropType; }
	double getQuantity() { return quantity; }
	double getPrice() { return price; }
	std::string getSellerNumber() { return sellerNumber; }
	std::string getBuyerNumber() { return buyerNumber; }

private:

	double price;
	double quantity;
	std::string cropType;
	std::string sellerNumber;
	std::string buyerNumber;

};
//Global
product * Prod;

class CSVRow
{
public:
	std::string const& operator[](std::size_t index) const
	{
		return m_data[index];
	}
	std::size_t size() const
	{
		return m_data.size();
	}
	void readNextRow(std::istream& str)
	{
		std::string line;
		std::getline(str, line);

		std::stringstream lineStream(line);
		std::string cell;

		m_data.clear();
		while (std::getline(lineStream, cell, ','))
		{
			m_data.push_back(cell);
		}
		// This checks for a trailing comma with no data after it.
		if (!lineStream && cell.empty())
		{
			// If there was a trailing comma then add an empty element.
			m_data.push_back("");
		}
	}
private:
	std::vector<std::string>    m_data;
};

std::istream& operator >> (std::istream& str, CSVRow& data)
{
	data.readNextRow(str);
	return str;
}
// adds buyers to buyer file with their info
void addBuyer()
{
	P = new person();
	std::string temp;



	std::ofstream buyers;
	buyers.open("buyers.csv", std::ios::app);

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

	buyers << P->getPersonName() << "," << P->getAddress() << "," << P->getAuctionNumber() << "," << P->getPhoneNumber() << std::endl;

	buyers.close();

	return;
}
// adds sellers seller file with their info
void addSeller()
{
	char comma = ',';
	P = new person();
	std::string temp;


	std::ofstream sellers;
	sellers.open("sellers.csv", std::ios::app);

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
	getline(std::cin, temp);
	P->setAuctionNumber(temp);

	std::cout << "Enter Seller Phone Number" << std::endl;
	getline(std::cin, temp);
	P->setPhoneNumber(temp);

	//write to file
	sellers << P->getPersonName() << "," << P->getAddress() << "," << P->getAuctionNumber() << "," << P->getPhoneNumber() << std::endl;

	sellers.close();
	return; // 
}
// used to add information to market file
void addCrop()
{

	Prod = new product();
	std::string temp; // string of item sold
	double tempDouble; // used for price and quantity

	std::ofstream marketData;
	marketData.open("marketdata.csv", std::ios::app);
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
	std::cin >> temp;
	Prod->setSellerNumber(temp);

	std::cout << "Enter Buyer Number" << std::endl;
	std::cin >> temp;
	Prod->setBuyerNumber(temp);

	marketData << Prod->getCropType() << "," << Prod->getQuantity() << "," << Prod->getPrice() << "," << Prod->getBuyerNumber() << "," << Prod->getSellerNumber() << "," << std::endl;

	marketData.close();
}

void makeInvoice()
{
	std::string buyerNumber;
	std::cout << "What is the buyers number" << std::endl;
	std::cin >> buyerNumber;
	std::ifstream marketData;
	marketData.open("marketdata.csv");

	//std::string text{ std::istreambuf_iterator<char>(marketData), std::istreambuf_iterator<char>() };
	//std::string::iterator first = text.begin();
	//std::string::iterator last = text.end();

	if (marketData.fail())
	{
		std::cout << "File could not be opened, it may not exist yet or may be open";
		return;
	}
	
	CSVRow row;
	while (!marketData.eof())
	{
		while (marketData >> row)
		{
			
			if (row[3] == buyerNumber) {
			

			}

		}
	}
	//TODO: make the file find all lines where the buyers number is present 
	//copy only that data to a new file
	// calculate Total and Prices

int main()
{

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
		case 'I': makeInvoice(); break;
			// todo make sellerinvoice
			//TODO Generate market Report

		}
	}
	return 0;
}

