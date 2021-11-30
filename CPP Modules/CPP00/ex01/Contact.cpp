#include "Contact.hpp"
//#include <locale>

Contact::Contact()
{
	//std::cout << "Contact constructor called" << std::endl;
}

Contact::~Contact()
{
	//std::cout << "Contact destroyer called" << std::endl;
}

std::string Contact::getfstName()
{
	return(this->firstName);
}

std::string Contact::getlstName()
{
	return(this->lastName);
}

std::string Contact::getnick()
{
	return(this->nickname);
}

std::string Contact::getNumber()
{
	return(this->phoneNumber);
}

std::string Contact::getSecret()
{
	return(this->darkSecret);
}

void		Contact::setfstName(std::string strn)
{
	this->firstName = strn;
	return;
}

void		Contact::setlstName(std::string strn)
{
	this->lastName = strn;
	return;
}

void		Contact::setnick(std::string strn)
{
	this->nickname = strn;
	return;
}

void		Contact::setNumber(std::string strn)
{
	this->phoneNumber = strn;
	return;
}

void		Contact::setSecret(std::string strn)
{
	this->darkSecret = strn;
	return;
}

void		Contact::showInfo()
{
	std::cout << "First name: " << this->firstName << std::endl;
	std::cout << "Last name: " << this->lastName << std::endl;
	std::cout << "Nickname name: " << this->nickname << std::endl;
	std::cout << "Phone number: " << this->phoneNumber << std::endl;
	std::cout << "Darkest secret: " << this->darkSecret << std::endl;
	return;
}

void		Contact::newInfo()
{
	int j = 0;
	int numLen = 0;
	std::string strn;
	
	std::cout << "Adding new contact..." << std::endl;
	std::cout << "First name: ";
	std::getline(std::cin, strn);
	setfstName(strn);
	strn.clear();
	std::cout << "Last name: ";
	std::getline(std::cin, strn);
	setlstName(strn);
	strn.clear();
	std::cout << "Nickname: ";
	std::getline(std::cin, strn);	
	setnick(strn);
	strn.clear();
	while(1)
	{
		std::cout << "Phonenumber: ";
		std::getline(std::cin, strn);
		numLen = strn.length();
		for(int i = 0; i < numLen; i++)
		{
			if(isdigit(strn[i]) == 0)
				j++;
		}
		if(j == 0 && !strn.empty())
			break;
		std::cout << "Not a number, retry" << std::endl;
		j = 0;
	}
	setNumber(strn);
	strn.clear();
	std::cout << "Darkest secret: ";
	std::getline(std::cin, strn);
	setSecret(strn);
	strn.clear();
	std::cout << "Contact saved!" << std::endl;
	
	return;
}