#ifndef RUBRIC_HPP
# define RUBRIC_HPP

#include <iostream>
#include <string.h>
#include "Contact.hpp"

class Rubric
{
public:
    Contact contact[8];
    int     numCont;

    Rubric();
    ~Rubric();
    void    printList();
    void    searchList();
    void    addnCont();
    void    initializeNum();
    int     retCont();
};


#endif