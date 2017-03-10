/*
** CmpTrue.cpp for nanotekspice in /home/uberti_p/delivery/nanotekspice/CmpTrue.cpp
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  jeu. févr. 02 16:09:32 2017 Louis-Emile Uberti-Arès
** Last update jeu. févr. 02 16:09:32 2017 Louis-Emile Uberti-Arès
*/

#include "CmpTrue.hpp"

nts::CmpTrue::CmpTrue(const std::string &value) :
        _name(value), _value(nts::Tristate::TRUE)
{

}

nts::Tristate   nts::CmpTrue::Compute(size_t pin_num_this __attribute((unused)))
{
    return (this->_value);
}

void            nts::CmpTrue::SetLink(size_t pin_num_this __attribute((unused)),
                                      nts::IComponent &component __attribute((unused)),
                                      size_t pin_num_target __attribute((unused)))
{
}

void            nts::CmpTrue::Dump() const
{
    std::cout << "\tType : True" << std::endl;
    std::cout << "\tValue : " << _value << std::endl;
}