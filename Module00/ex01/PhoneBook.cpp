#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    for (int i = 0; i < 8; i++)
        this->_Contact[i].State = 0;
    this->Oldest = 0;
}

void    PhoneBook::Start()
{
    int i = true;
    std::string comm;

    while (i)
    {
        std::cout << "Please type ADD, SEARCH or EXIT: " << std::endl;
        std::cin >> comm;
        if (comm == "EXIT")
            i = false;
        else if (comm == "ADD")
            AddContact();
        else if (comm == "SEARCH")
            SearchContact();
    }
}

void    PhoneBook::SearchContact()
{
    std::stringstream   sstr;
    std::string         str;

    for (int i = 0; i < 8; i++)
    {
        if (!this->_Contact[i].State)
            break;
        std::cout << i << "|";
        
        if (this->_Contact[i].FirstName.length() <= 10)
            std::cout << std::setw(10) << this->_Contact[i].FirstName << "|";
        for(int j = 0; j < 9 && this->_Contact[i].FirstName.length() > 10; j++)
            std::cout << (char)this->_Contact[i].Nickname[j];
        if (this->_Contact[i].FirstName.length() > 10)
            std::cout << ".|";
        
        if (this->_Contact[i].LastName.length() <= 10)
            std::cout << std::setw(10) << this->_Contact[i].LastName << "|";
        for(int j = 0; j < 9 && this->_Contact[i].LastName.length() > 10; j++)
            std::cout << (char)this->_Contact[i].Nickname[j];
        if (this->_Contact[i].LastName.length() > 10)
            std::cout << ".|";
        
        if (this->_Contact[i].Nickname.length() <= 10)
            std::cout << std::setw(10) << this->_Contact[i].Nickname << std::endl;
        for(int j = 0; j < 9 && this->_Contact[i].Nickname.length() > 10; j++)
            std::cout << (char)this->_Contact[i].Nickname[j];
        if (this->_Contact[i].Nickname.length() > 10)
            std::cout << ".";
        std::cout << std::endl;
    }
    std::cout << "what contact do you want to display: ";
    std::cin >> str;
    try
    {
        int x = stoi(str);
        if (x > 8 || x < 0 || !this->_Contact[x].State)
            std::cout << "no such contact exists\n";
        else if (x < 8 && x >= 0 && this->_Contact[x].State)
            std::cout << this->_Contact[x].FirstName << std::endl \
            << this->_Contact[x].LastName << std::endl \
            << this->_Contact[x].Nickname << std::endl \
            << this->_Contact[x].Phonenumber<< std::endl \
            << this->_Contact[x].DarkestSecret<< std::endl;
    
    }
    catch(const std::exception& e)
    {
        std::cout << "invalid argument\n";
    }
}

void    PhoneBook::AddContact()
{
    int i;
    for (i = 0; i < 8; i++)
    {
        if (!this->_Contact[i].State)
            break;
    }
    if (i == 8)
    {
        i = this->Oldest;
        this->Oldest++;
        if (this->Oldest == 8)
            this->Oldest = 0;
    }
    std::cout << "first name: ";
    std::cin >> this->_Contact[i].FirstName;
    std::cout << "last name: ";
    std::cin >> this->_Contact[i].LastName;
    std::cout << "nickname: ";
    std::cin >> this->_Contact[i].Nickname;
    std::cout << "phonenumber: ";
    std::cin >> this->_Contact[i].Phonenumber;
    std::cout << "darkest secret: ";
    std::cin >> this->_Contact[i].DarkestSecret;
    this->_Contact[i].State = 1;
}
