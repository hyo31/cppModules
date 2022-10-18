#include "harl.hpp"

harl::harl(void)
{
    std::cout <<    "Constructed harl" << std::endl;
}

harl::~harl(void)
{
    std::cout <<    "Deconstructed harl" << std::endl;
}

void    harl::debug(void)
{
    std::cout <<    "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup"
                    " burger. I really do!" << std::endl;
}

void    harl::info(void)
{
    std::cout <<    "I cannot believe adding extra bacon costs more money. You did not put enough bacon"
                    " in my burger! If you did, I would not be asking for more!" << std::endl;
}

void    harl::warning(void)
{
    std::cout <<    "I think I deserve to have some extra bacon for free. I have been coming for years"
                    " whereas you started working here since last month." << std::endl;
}

void    harl::error(void)
{
    std::cout <<    "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void    harl::complain(std::string level)
{
    std::string actions[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void        (harl::*actions_ptr[4])(void) = {&harl::debug, &harl::info, &harl::warning, &harl::error};
    for (int i = 0; i < 4; i++)
    {
        if (actions[i] == level)
        {
            (this->*actions_ptr[i])();
            break ;
        }
    }
}