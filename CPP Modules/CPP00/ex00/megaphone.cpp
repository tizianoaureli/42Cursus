#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    int numsize = 0;
    char c;
    std::string phrase;
    
    if(argc > 1)
    {
        for(int j = 1; j < argc; j++)
        {
            phrase = argv[j];
            numsize = phrase.length();
            for(int i = 0; i <= numsize; i++)
            {
                if (phrase[i] >= 'a' && phrase[i] <= 'z')
                {
                    c = toupper(phrase[i]);
                    std::cout << c;
                }
                else
                    std::cout << phrase[i];
            }
        }
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << std::endl;
    return (0);
}