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
	buyers.open("sellers.txt");
		
	if (buyers.fail())
	{
		std::cout << "Error opening File" << std::endl;
		return;
	}

	buyers << name << address << buyerNumber << std::endl;
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
	std::string number;
	int task = 0;
	while (task != 10)
	{
		std::cout << "1.Press 1 to add new seller" << std::endl;
		std::cout << "2.Press 2 to add new item" << std::endl;
		std::cout << "3.Press 3 to add new buyer" << std::endl;
		std::cout << "4.Press 10 to exit" << std::endl;
		
		std::cin >> task;

		if (task == 1)
		{
			std::cout << "adding to buyer list";
			std::cin >> name;
			std::cin >> address;
			std::cin >> number;
		}
		//else if(task == "2")
			//return
		//else if(task == "3")
			//return
		//else if(task == "4")

		//if(task == "5")

	}
    return 0;
}

