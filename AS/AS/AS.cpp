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
//Accessor Functions 
	void setPersonName(std::string x) { personName = x; }
	void setAddress(std::string x) { address = x; }
	void setauctionNumber(std::string x) { auctionNumber = x; }
	void setphoneNumber(std::string x) { phoneNumber = x; }
	std::string getPersonName() { return personName; }
	std::string getAddress() { return address; }
	std::string getAuctionNumber() { return auctionNumber; }
	std::string getPhoneNumber() { return phoneNumber; }

private:
	std::string personName; 
	std::string address; 
	std::string auctionNumber; 
	std::string phoneNumber;
};

void addBuyer()
{
	std::ofstream buyers;
	buyers.open("buyers.txt", std::ios::app);
		
	if (buyers.fail())
	{
		std::cout << "Error opening File" << std::endl;
		return;
	}

	std::cout << "Enter Buyers Name" << std::endl;
	std::cin.ignore();
	getline(std::cin, personName);

	std::cout << "Enter Buyers Address" << std::endl;
	getline(std::cin, address);
	
	std::cout << "Enter Buyers Auction Number" << std::endl;
	getline(std::cin, auctionNumber);
	
	std::cout << "Enter Buyers Phone Number" << std::endl;
	getline(std::cin, phoneNumber);
	
		buyers << personName << " " << address << " " << auctionNumber << " " << phoneNumber << std::endl;
	buyers.close();

}

struct seller 
{
	std::string Name;
	std::string Address;
	long auctionNumber;

};

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

