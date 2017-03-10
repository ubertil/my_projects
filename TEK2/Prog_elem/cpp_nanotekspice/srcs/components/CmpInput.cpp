/*
** CmpInput.cpp for nanotekspice in /home/uberti_p/delivery/nanotekspice/CmpInput.cpp
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  jeu. févr. 02 16:07:22 2017 Louis-Emile Uberti-Arès
** Last update jeu. févr. 02 16:07:22 2017 Louis-Emile Uberti-Arès
*/

#include "CmpInput.hpp"

nts::CmpInput::CmpInput(const std::string &value) :
        _name(value), _value(nts::Tristate::UNDEFINED)
{

}

nts::Tristate   nts::CmpInput::Compute(size_t pin_num_this __attribute((unused)))
{
    return (_value);
}

void            nts::CmpInput::SetLink(size_t pin_num_this __attribute((unused)),
                                       nts::IComponent &component __attribute((unused)),
                                       size_t pin_num_target __attribute((unused)))
{
}

void            nts::CmpInput::Dump() const
{
    std::cout << "\tType : Input" << std::endl;
    std::cout << "\tValue : " << _value << std::endl;
}

void            nts::CmpInput::setValue(nts::Tristate value)
{
    _value = value;
}