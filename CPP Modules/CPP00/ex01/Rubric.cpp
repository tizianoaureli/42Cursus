#include <iostream>
#include "Rubric.hpp"

Rubric::Rubric()
{
	//std::cout << "Rubric constructor called" << std::endl;
}

Rubric::~Rubric()
{
	//std::cout << "Rubric destroyer called" << std::endl;
}

void Rubric::addnCont()
{
	this->numCont++;
	return;
}

void Rubric::initializeNum()
{
	this->numCont = 0;
}

int Rubric::retCont()
{
	return(this->numCont);
}

void Rubric::searchList()
{
	std::string	usr;
	while(1)
	{
		std::cout << "Type a number (between 1-8) to print the contact's info: ";
		std::getline(std::cin, usr);
		if (usr[0] - 48 >= 1 && usr[0] - 48 <= 8 && usr[0] - 48 <= retCont())
		{
			this->contact[usr[0] - 48 - 1].showInfo();
			return;
		}
		else if(usr[0] - 48 > 8 || usr[0] - 48 < 0 || usr[0] - 48 > retCont())
		{
			std::cout << "Cannot find contact " << (usr[0] - 48) << std::endl;
			return;
		}
	}
}

void Rubric::printList()
{
	if(this->numCont == 0)
	{
		std::cout << "No contact found!" << std::endl;
		return;
	}
	int i = 0;
	int j = 10;
	std::string tmp;

	std::cout << "|    Indice|      Nome|   Cognome|  Nickname|" << std::endl;
	for (i = 0; i < this->numCont; i++)
	{
		std::cout << "|";
		std::cout.width(10);
		std::cout << i + 1 << "|";
		std::cout.width(10);
		if (this->contact[i].getfstName().length() > 10)
		{
			tmp.append(this->contact[i].getfstName());
			tmp[9] = '.';
			while(tmp[j])
				tmp[j++] = 0;
			std::cout << tmp << "|";
			tmp.clear();
			j = 10;
		}
		else
		{
			tmp.append(this->contact[i].getfstName());
			std::cout << tmp << "|";
			tmp.clear();
		}
		std::cout.width(10);
		if (this->contact[i].getlstName().length() > 10)
		{
			tmp.append(this->contact[i].getlstName());
			tmp[9] = '.';
			while(tmp[j])
				tmp[j++] = 0;
			std::cout << tmp << "|";
			tmp.clear();
			j = 10;
		}
		else
		{
			tmp.append(this->contact[i].getlstName());
			std::cout << tmp << "|";
			tmp.clear();
		}
		std::cout.width(10);
		if (this->contact[i].getnick().length() > 10)
		{
			tmp.append(this->contact[i].getnick());
			tmp[9] = '.';
			while(tmp[j])
				tmp[j++] = 0;
			std::cout << tmp << "|";
			tmp.clear();
			j = 10;
		}
		else
		{
			tmp.append(this->contact[i].getnick());
			std::cout << tmp << "|";
			tmp.clear();
		}
		std::cout << std::endl;
	}
	searchList();
	return;
}