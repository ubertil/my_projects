/*
** CmpOutput.cpp for nanotekspice in /home/uberti_p/delivery/nanotekspice/CmpOutput.cpp
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  jeu. févr. 02 16:11:50 2017 Louis-Emile Uberti-Arès
** Last update jeu. févr. 02 16:11:50 2017 Louis-Emile Uberti-Arès
*/

#include "CmpOutput.hpp"

nts::CmpOutput::CmpOutput(const std::string &value) :
    _name(value), _value(nts::Tristate::UNDEFINED)
{

}

nts::Tristate   nts::CmpOutput::Compute(size_t pin_num_this __attribute((unused)))
{
    _value = _comp->Compute(_pin_target);
    return (_value);
}

void            nts::CmpOutput::SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target)
{
    _pin_this = pin_num_this;
    _comp = &component;
    _pin_target = pin_num_target;
}

void            nts::CmpOutput::Dump() const
{
    std::cout << "\tType : Output" << std::endl;
    std::cout << "\tValue : " << _value << std::endl;
}

void            nts::CmpOutput::setValue(nts::Tristate value)
{
    _value = value;
}

void            nts::CmpOutput::Display() const
{
    std::cout << _name << "=" << _value << std::endl;
}