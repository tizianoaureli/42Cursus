#include "Karen.hpp"

int main(int argc, char **argv)
{
    if(argc == 2)
    {
        Karen karen;
        karen.complain(argv[1]);
    }
    else
        std::cout << "Wrong number of arguments" << std::endl;
    return 0;
}