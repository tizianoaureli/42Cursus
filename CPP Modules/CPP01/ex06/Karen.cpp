#include "Karen.hpp"

Karen::Karen()
{
    this->karenPhrase[0] = &Karen::debug;
    this->karenPhrase[1] = &Karen::info;
    this->karenPhrase[2] = &Karen::warning;
    this->karenPhrase[3] = &Karen::error;
    this->level[0] = "DEBUG";
    this->level[1] = "INFO";
    this->level[2] = "WARNING";
    this->level[3] = "ERROR";
}

Karen::~Karen()
{
}

void Karen::debug( void )
{
    std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
    info();
    return;
}

void Karen::info( void )
{
    std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
    warning();
    return;
}

void Karen::warning( void )
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
    error();
    return;
}

void Karen::error( void )
{
    std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
    return;
}

void Karen::complain(std::string level)
{
    int i = 0;
    for(i = 0; i < 4; i++)
    {
        if(!level.compare(this->level[i]))
            break;
    }
    switch(i)
    {
        case 0: (this->*karenPhrase[i])();
        break;
        case 1: (this->*karenPhrase[i])();
        break;
        case 2: (this->*karenPhrase[i])();
        break;
        case 3: (this->*karenPhrase[i])();
        break;
        case 4: std::cout << "[High-pitched demonic screeching]";
        break;
    }
}