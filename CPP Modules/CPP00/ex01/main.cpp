#include <iostream>
#include "Rubric.hpp"

int main()
{
	Rubric rubric;
	std::string command;
	int			n = 0;

	std::cout << "Type one of the following commands:" << std::endl << "ADD to add a new contact;" << std::endl << "SEARCH to print your contact list;" << std::endl << "EXIT to quit the program." << std::endl;
	std::cout << "Command: ";
	std::getline(std::cin, command);
	std::cout << "Input: " << command << std::endl;
	rubric.initializeNum();
	while(command.compare("EXIT") != 0)
	{
		if(command.compare("ADD") == 0)
		{
			if(n != 8)
			{
				rubric.contact[n].newInfo();
				if(rubric.retCont() <= 7)
					rubric.addnCont();
				n++;
			}
			else
			{
				n = 0;
				rubric.contact[n].newInfo();
				n++;
			}
		}
		else if (command.compare("SEARCH") == 0)
			rubric.printList();
		else
			std::cout << "Command not recognized." << std::endl;
		std::cout << "Command: ";
		std::getline(std::cin, command);
	}

	return 0;
}