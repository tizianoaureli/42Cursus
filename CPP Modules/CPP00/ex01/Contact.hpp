#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string.h>

class Contact
{
    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkSecret;
    public:
        
        std::string getfstName();
        std::string getlstName();
        std::string getnick();
        std::string getSecret();
        std::string getNumber();

        void        setfstName(std::string strn);
        void        setlstName(std::string strn);
        void        setnick(std::string strn);
        void        setSecret(std::string strn);
        void        setNumber(std::string strn);
        void        newInfo();
        void        showInfo();
        

        Contact();
        ~Contact();
};

#endif
