/*
** Cmp4069.cpp for nanotekspice in /home/uberti_p/delivery/nanotekspice/Cmp4069.cpp
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  jeu. févr. 02 15:56:04 2017 Louis-Emile Uberti-Arès
** Last update jeu. févr. 02 15:56:04 2017 Louis-Emile Uberti-Arès
*/

#include "Cmp4069.hpp"

nts::Cmp4069::Cmp4069(const std::string &value) :
    _name(value), _value(nts::Tristate::UNDEFINED)
{
    _output[2] = 1;
    _output[4] = 3;
    _output[6] = 5;
    _output[8] = 9;
    _output[10] = 11;
    _output[12] = 13;
    _passed[2] = -1;
    _passed[4] = -1;
    _passed[6] = -1;
    _passed[8] = -1;
    _passed[10] = -1;
    _passed[12] = -1;
}

nts::Tristate       nts::Cmp4069::Compute(size_t pin_num_this)
{
    nts::Tristate   cmp;

    if (static_cast<int>(pin_num_this) <= 0)
        throw nts::ComponentError("Pin number should be positive");
    else if (pin_num_this > 16)
        throw nts::ComponentError("Pin number should not exceed 16");
    if (_passed.at(pin_num_this) == nts::timer)
        return (_value);
    cmp = _pins[_output[pin_num_this]].second->Compute(_pins[_output[pin_num_this]].first);
    _passed[pin_num_this] = nts::timer;
    if (cmp == nts::Tristate::UNDEFINED)
        _value = nts::Tristate::UNDEFINED;
    else if (cmp == nts::Tristate::TRUE)
        _value = nts::Tristate::FALSE;
    else
        _value = nts::Tristate::TRUE;
    return (_value);
}

void            nts::Cmp4069::SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target)
{
    if (static_cast<int>(pin_num_this) <= 0 || static_cast<int>(pin_num_target) <= 0)
        throw nts::ComponentError("Pin number should be positive");
    else if (pin_num_this > 16 || pin_num_target > 16)
        throw nts::ComponentError("Pin number should not exceed 16");
    _pins[pin_num_this].first = pin_num_target;
    _pins[pin_num_this].second = &component;
}

void            nts::Cmp4069::Dump() const
{
    std::cout << "\tType : 4069" << std::endl;
}