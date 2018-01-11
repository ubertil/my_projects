/*
** CmpFalse.cpp for nanotekspice in /home/uberti_p/delivery/nanotekspice/CmpFalse.cpp
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  jeu. févr. 02 16:10:53 2017 Louis-Emile Uberti-Arès
** Last update jeu. févr. 02 16:10:53 2017 Louis-Emile Uberti-Arès
*/

#include "CmpFalse.hpp"

nts::CmpFalse::CmpFalse(const std::string &value) :
        _name(value), _value(nts::Tristate::FALSE)
{

}

nts::Tristate   nts::CmpFalse::Compute(size_t pin_num_this __attribute((unused)))
{
    return (this->_value);
}

void            nts::CmpFalse::SetLink(size_t pin_num_this __attribute((unused)),
                                       nts::IComponent &component __attribute((unused)),
                                       size_t pin_num_target __attribute((unused)))
{
}

void            nts::CmpFalse::Dump() const
{
    std::cout << "\tType : False" << std::endl;
    std::cout << "\tValue : " << _value << std::endl;
}