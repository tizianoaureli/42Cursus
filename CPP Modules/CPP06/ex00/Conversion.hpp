#pragma once
#include <iostream>
#include <string>

class Conversion
{
private:
    std::string toConv;
public:
    Conversion();
    Conversion(std::string arg);
    ~Conversion();
    Conversion(Conversion const &copy);
    
    Conversion & operator= (const Conversion &uguale);
};
