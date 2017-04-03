// AS.cpp : Defines the entry point for the console application.
//Sam Hardy
//sjh91@zips.uakron.edu;

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>



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
	void setSellerNumber(std::string x) { sellerNumber= x; }
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
// adds seller to file with their info
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

void makeBuyerInvoice()
{
	double price = 0;
	double totalAmount = 0;

	std::string buyerNumber;
	std::cout << "What is the buyers number" << std::endl;
	std::cin >> buyerNumber;

	std::ifstream marketData;
	marketData.open("marketdata.csv");

	std::ofstream invoice;
	invoice.open("invoice.csv");

	if (marketData.fail())
	{
		std::cout << "File could not be opened, it may not exist yet or may be open";
		return;
	}
	if (invoice.fail())
	{
		std::cout << "File could not be opened, it may not exist yet or may be open";
		return;
	}

	CSVRow row;

	while (!marketData.eof())
	{
		while (marketData >> row)
		{
			//sort for buyer number
			if (row[3] == buyerNumber)

			{
				price = stod(row[1])*stod(row[2]);
				totalAmount += price;
				invoice << row[0] << "," << row[4] << "," << row[1] << "," << row[2] << "," << "$:"<< price << "," << std::endl;
			}
		}
		invoice << "," << "," << "," << "," << "Total:"<<totalAmount << std::endl;
	}
	invoice.close();
	marketData.close();
}

void makeSellerInvoice()
{
	double price = 0;
	double totalAmount = 0;

	std::string sellerNumber;
	std::cout << "What is the seller number" << std::endl;
	std::cin >> sellerNumber;

	std::ifstream marketData;
	marketData.open("marketdata.csv");

	std::ofstream sellerInvoice;
	sellerInvoice.open("invoice.csv");

	if (marketData.fail())
	{
		std::cout << "File could not be opened, it may not exist yet or may be open";
		return;
	}
	if (sellerInvoice.fail())
	{
		std::cout << "File could not be opened, it may not exist yet or may be open";
		return;
	}

	CSVRow row;

	while (!marketData.eof())
	{
		while (marketData >> row)
		{
			//sort for seller number
			if (row[4] == sellerNumber)

			{
				price = stod(row[1])*stod(row[2]);
				totalAmount += price;
				sellerInvoice << row[0] << "," << row[1] << "," << row[2] << "," << "$:" << price << "," << std::endl;
			}
		}
		sellerInvoice << "," << "," << "," << "Total:" << totalAmount << std::endl;
	}
	sellerInvoice.close();
	marketData.close();

}

double processQuantity(CSVRow row,  double quantity)
{
	// row[1]=quantity;
	quantity =+ stod(row[1]); // converts to double
	
		return quantity;
}

double processHighPrice(CSVRow row, double highPrice)
{
	if (stod(row[2]) > highPrice)
		return stod(row[2]);
	else
		return highPrice;
}
double processLowPrice(CSVRow row, double lowPrice)
{
	if (stod(row[2]) < lowPrice)
		return stod(row[2]);
	else
		return lowPrice;
}

double processAverage(CSVRow row, double average)
{
	return 1;
}

double processTotal(CSVRow row, double totalPrice)
{
	totalPrice += stod(row[1]) * stod(row[2]);
	return totalPrice;
}

void generateMarketReport()
{
	std::string crop;
	double price; // price of 1 lot.
	double totalPrice; // used to find average total price / quantity = average
	double averagePrice = 0;
	double quantity = 0; 
	double highPrice = 0;
	double lowPrice = 100; // arbitrary number

	std::ifstream marketData;
	marketData.open("marketdata.csv");

	std::ofstream marketReport;
	marketReport.open("marketReport.csv");
	if (marketReport.fail())
	{
		std::cout << "File could not be opened, it may not exist yet or may be open";
		return;
	}

	CSVRow row;

	while (!marketData.eof())
	{
		while (marketData >> row)
		{
			if (row[0] == "tom")

			{
			 quantity = processQuantity(row, quantity);
			 highPrice = processHighPrice(row, highPrice);
			 lowPrice = processLowPrice(row, lowPrice);
			 totalPrice = processTotal(row, totalPrice);

			}

			marketData.clear();
			marketData.seekg(0, std::ios::beg);
			
			
			else if (row[0] == "zuc")
			{


			}


			else if (row[0] == "cant")
			{


			}

			else if (row[0] == "watermelon")
			{



			}

			else if (row[0] == "cuc")
			{

			}
			else if (row[0] == "grape tom")
			{

			}
			else if (row[0] == "yellow squash")
			{

			}
			else if (row[0] == "cabbage")
			{

			}
			else if (row[0] == "pumpkins")

			{


			}
		}
	}
	marketReport.close();
	marketData.close();
}

int main()
{

	char choice[10];


	while (choice[0] != 'q')
	{
		std::cout << "|----------Menu-----------------|" << std::endl;
		std::cout << "|----------Add (B)uyer----------|" << std::endl;
		std::cout << "|----------Add (S)eller---------|" << std::endl;
		std::cout << "|----------Add (C)rop-----------|" << std::endl;
		std::cout << "|--------Create Buyer(I)nvoice--|" << std::endl;
		std::cout << "|------Create Seller(R)invoice--|" << std::endl;
		std::cout << "|-----Create (M)arket Report----|" << std::endl;

		std::cin >> choice[0];

		switch (choice[0])
		{
		case 'B': addBuyer(); break;
		case 'S': addSeller(); break;
		case 'C': addCrop(); break;
		case 'I': makeBuyerInvoice(); break;
		case 'R': makeSellerInvoice(); break;
		//case 'M': markertReport(); break;
			//TODO Generate market Report

		}
	}
	return 0;
}

