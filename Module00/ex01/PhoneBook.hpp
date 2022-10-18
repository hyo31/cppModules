#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
    private:
        Contact _Contact[8];
        int     Oldest;
        void    SearchContact();
        void    AddContact();
    
    public:
        PhoneBook();
        void Start();
};

#endif
