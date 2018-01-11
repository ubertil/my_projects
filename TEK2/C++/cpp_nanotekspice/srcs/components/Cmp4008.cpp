/*
** Cmp4008.cpp for nanotekspice in /home/uberti_p/delivery/nanotekspice/Cmp4008.cpp
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  mer. févr. 08 14:05:12 2017 Louis-Emile Uberti-Arès
** Last update mer. févr. 08 14:05:12 2017 Louis-Emile Uberti-Arès
*/

#include "Cmp4008.hpp"

nts::Cmp4008::Cmp4008(const std::string &value) :
        _name(value),
        _xor1 (new Cmp4030("xor1")),
        _xor2 (new Cmp4030("xor2")),
        _and1 (new Cmp4081("and1")),
        _and2 (new Cmp4081("and2")),
        _or1 (new Cmp4071("or1"))
{
    _xor1->SetLink(1, *this, 7);
    _xor1->SetLink(2, *this, 6);
    _xor2->SetLink(1, *_xor1, 3);
    _xor2->SetLink(2, *this, 9);
    this->SetLink(10, *_xor2, 3);
    _and1->SetLink(1, *this, 7);
    _and1->SetLink(2, *this, 6);
    _and2->SetLink(1, *_xor1, 3);
    _and2->SetLink(2, *this, 9);
    _or1->SetLink(2, *_and1, 3);
    _or1->SetLink(1, *_and2, 3);
    _xor1->SetLink(5, *this, 5);
    _xor1->SetLink(6, *this, 4);
    _xor2->SetLink(5, *_xor1, 4);
    _xor2->SetLink(6, *_or1, 3);
    this->SetLink(11, *_xor2, 4);
    _and1->SetLink(5, *this, 5);
    _and1->SetLink(6, *this, 4);
    _and2->SetLink(5, *_xor1, 4);
    _and2->SetLink(6, *_or1, 3);
    _or1->SetLink(5, *_and1, 4);
    _or1->SetLink(6, *_and2, 4);
    _xor1->SetLink(12, *this, 3);
    _xor1->SetLink(13, *this, 2);
    _xor2->SetLink(12, *_xor1, 11);
    _xor2->SetLink(13, *_or1, 4);
    this->SetLink(12, *_xor2, 11);
    _and1->SetLink(12, *this, 3);
    _and1->SetLink(13, *this, 2);
    _and2->SetLink(12, *_xor1, 11);
    _and2->SetLink(13, *_or1, 4);
    _or1->SetLink(12, *_and1, 11);
    _or1->SetLink(13, *_and2, 11);
    _xor1->SetLink(8, *this, 1);
    _xor1->SetLink(9, *this, 15);
    _xor2->SetLink(8, *_xor1, 10);
    _xor2->SetLink(9, *_or1, 11);
    this->SetLink(13, *_xor2, 10);
    _and1->SetLink(8, *this, 1);
    _and1->SetLink(9, *this, 15);
    _and2->SetLink(8, *_xor1, 10);
    _and2->SetLink(9, *_or1, 11);
    _or1->SetLink(8, *_and1, 10);
    _or1->SetLink(9, *_and2, 10);
    this->SetLink(14, *_or1, 10);
}

nts::Tristate   nts::Cmp4008::Compute(size_t pin_num_this)
{
    if (static_cast<int>(pin_num_this) <= 0)
        throw nts::ComponentError("Pin number should be positive");
    else if (pin_num_this > 16)
        throw nts::ComponentError("Pin number should not exceed 16");
    switch (pin_num_this)
    {
        case (14):
            return (_or1->Compute(10));
        case (13):
            return (_xor2->Compute(10));
        case (12):
            return (_xor2->Compute(11));
        case (11):
            return (_xor2->Compute(4));
        case (10):
            return (_xor2->Compute(3));
        default:
            return (_pins[pin_num_this].second->Compute(pin_num_this));
    }
}

void            nts::Cmp4008::SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target)
{
    if (static_cast<int>(pin_num_this) <= 0 || static_cast<int>(pin_num_target) <= 0)
        throw nts::ComponentError("Pin number should be positive");
    else if (pin_num_this > 16 || pin_num_target > 16)
        throw nts::ComponentError("Pin number should not exceed 16");
    _pins[pin_num_this].first = pin_num_target;
    _pins[pin_num_this].second = &component;
}

void            nts::Cmp4008::Dump() const
{
    std::cout << "\tType : 4008" << std::endl;
}