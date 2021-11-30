#ifndef KAREN_HPP
# define KAREN_HPP
#include <iostream>
#include <string>

class Karen;
typedef void (Karen::*Jump)(void);

class Karen
{
private:
    Jump karenPhrase[4];
    std::string level[4];
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );
public:
    Karen();
    ~Karen();
    void complain( std::string level );
};

#endif