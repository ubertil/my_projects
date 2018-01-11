/*
** CmpClock.cpp for nanotekspice in /home/uberti_p/delivery/nanotekspice/CmpClock.cpp
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  jeu. févr. 02 16:08:38 2017 Louis-Emile Uberti-Arès
** Last update jeu. févr. 02 16:08:38 2017 Louis-Emile Uberti-Arès
*/

#include "CmpClock.hpp"

nts::CmpClock::CmpClock(const std::string &value) :
        _name(value), _value(nts::Tristate::TRUE)
{

}

nts::Tristate   nts::CmpClock::Compute(size_t pin_num_this __attribute__((unused)))
{
    if (_value == nts::Tristate::TRUE)
        _value = nts::Tristate ::FALSE;
    else if (_value == nts::Tristate::FALSE)
        _value = nts::Tristate::TRUE;
    return (_value);
}

void            nts::CmpClock::SetLink(size_t pin_num_this __attribute__((unused)),
                                       nts::IComponent &component __attribute__((unused)),
                                       size_t pin_num_target __attribute__((unused)))
{
}

void            nts::CmpClock::Dump() const
{
    std::cout << "\tType : Clock" << std::endl;
    std::cout << "\tValue : " << _value << std::endl;
}

void            nts::CmpClock::setValue(nts::Tristate value)
{
    _value = value;
}