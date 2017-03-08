// AS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>

//using namespace std;
struct buyer
{

	std::string Name; 
	std::string Address; 
	long auctionNumber; 

};

void addBuyer(std::string name, std::string address, long buyerNumber)
{
	std::ofstream buyers;
	buyers.open("buyers.txt", std::ios::app);
		
	if (buyers.fail())
	{
		std::cout << "Error opening File" << std::endl;
		return;
	}

	buyers << name << " " << address << " " << buyerNumber << std::endl;
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
		std::cout << "|----------Add Buyer----------|" << std::endl;
		std::cout << "|----------Add Seller---------|" << std::endl;
		std::cout << "|----------Add Crop-----------|" << std::endl;
		std::cout << "|----------Create Invoice-----|" << std::endl;

		std::cin >> choice[0];
	}
    return 0;
}

