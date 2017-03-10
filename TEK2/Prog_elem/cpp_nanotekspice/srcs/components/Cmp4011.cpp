/*
** Cmp4011.cpp for nanotekspice in /home/uberti_p/delivery/nanotekspice/Cmp4011.cpp
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  jeu. févr. 02 15:48:37 2017 Louis-Emile Uberti-Arès
** Last update jeu. févr. 02 15:48:37 2017 Louis-Emile Uberti-Arès
*/

#include "Cmp4011.hpp"

nts::Cmp4011::Cmp4011(const std::string &value) :
    _name(value), _value(nts::Tristate::UNDEFINED)
{
    _output[3].first = 1;
    _output[3].second = 2;
    _output[4].first = 5;
    _output[4].second = 6;
    _output[11].first = 12;
    _output[11].second = 13;
    _output[10].first = 8;
    _output[10].second = 9;
    _passed[3] = -1;
    _passed[4] = -1;
    _passed[10] = -1;
    _passed[11] = -1;
}

nts::Tristate       nts::Cmp4011::Compute(size_t pin_num_this)
{
    nts::Tristate   cmp1;
    nts::Tristate   cmp2;

    if (static_cast<int>(pin_num_this) <= 0)
        throw nts::ComponentError("Pin number should be positive");
    else if (pin_num_this > 16)
        throw nts::ComponentError("Pin number should not exceed 16");
    if (_passed.at(pin_num_this) == nts::timer)
        return (_value);
    _passed[pin_num_this] = nts::timer;
    cmp1 = _pins[_output[pin_num_this].first].second->Compute(_pins[_output[pin_num_this].first].first);
    cmp2 = _pins[_output[pin_num_this].second].second->Compute(_pins[_output[pin_num_this].second].first);
    if (cmp1 == nts::Tristate::FALSE || cmp2 == nts::Tristate::FALSE)
        _value = nts::Tristate::TRUE;
    else if (cmp1 == nts::Tristate::TRUE && cmp2 == nts::Tristate::TRUE)
        _value = nts::Tristate::FALSE;
    else
        _value = nts::Tristate::UNDEFINED;
    return (_value);
}

void            nts::Cmp4011::SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target)
{
    if (static_cast<int>(pin_num_this) <= 0 || static_cast<int>(pin_num_target) <= 0)
        throw nts::ComponentError("Pin number should be positive");
    else if (pin_num_this > 16 || pin_num_target > 16)
        throw nts::ComponentError("Pin number should not exceed 16");
    _pins[pin_num_this].first = pin_num_target;
    _pins[pin_num_this].second = &component;
}

void            nts::Cmp4011::Dump() const
{
    std::cout << "\tType : 4011" << std::endl;
}