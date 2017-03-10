/*
** Cmp4013.cpp for nanotekspice in /home/uberti_p/delivery/nanotekspice/Cmp4013.cpp
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  jeu. févr. 02 15:49:42 2017 Louis-Emile Uberti-Arès
** Last update jeu. févr. 02 15:49:42 2017 Louis-Emile Uberti-Arès
*/

#include "Cmp4013.hpp"

nts::Cmp4013::Cmp4013(const std::string &value) :
    _name(value),
    _not1(new Cmp4069("not1")),
    _nand1(new Cmp4011("nand1")),
    _or1(new Cmp4071("or1")),
    _and1(new Cmp4081("and1")),
    _not2(new Cmp4069("not2")),
    _nand2(new Cmp4011("nand2")),
    _or2(new Cmp4071("or2")),
    _and2(new Cmp4081("and2"))
{
    // PART 1
    this->SetLink(1, *_or1, 4);
    _or1->SetLink(5, *this, 6);
    _or1->SetLink(6, *_and1, 3);
    _and1->SetLink(1, *_nand1, 10);
    _and1->SetLink(2, *_not1, 4);
    _nand1->SetLink(8, *_nand1, 3);
    _nand1->SetLink(9, *_nand1, 11);
    _not1->SetLink(3, *_or1, 3);
    _or1->SetLink(1, *_nand1, 11);
    _or1->SetLink(2, *this, 4);
    _nand1->SetLink(12, *_nand1, 10);
    _nand1->SetLink(13, *_nand1, 4);
    _nand1->SetLink(5, *this, 3);
    _nand1->SetLink(6, *_not1, 2);
    _not1->SetLink(1, *this, 5);
    _nand1->SetLink(1, *this, 5);
    _nand1->SetLink(2, *this, 3);
    this->SetLink(2, *_or1, 10);
    _or1->SetLink(8, *this, 4);
    _or1->SetLink(9, *_not1, 6);
    _not1->SetLink(5, *_or1, 4);
    // PART 2
    this->SetLink(13, *_or2, 4);
    _or2->SetLink(5, *this, 8);
    _or2->SetLink(6, *_and2, 3);
    _and2->SetLink(1, *_nand2, 10);
    _and2->SetLink(2, *_not2, 4);
    _nand2->SetLink(8, *_nand2, 3);
    _nand2->SetLink(9, *_nand2, 11);
    _not2->SetLink(3, *_or2, 3);
    _or2->SetLink(1, *_nand2, 11);
    _or2->SetLink(2, *this, 10);
    _nand2->SetLink(12, *_nand2, 10);
    _nand2->SetLink(13, *_nand2, 4);
    _nand2->SetLink(5, *this, 11);
    _nand2->SetLink(6, *_not2, 2);
    _not2->SetLink(1, *this, 9);
    _nand2->SetLink(1, *this, 9);
    _nand2->SetLink(2, *this, 11);
    this->SetLink(12, *_or2, 10);
    _or2->SetLink(8, *this, 10);
    _or2->SetLink(9, *_not2, 6);
    _not2->SetLink(5, *_or2, 4);
}

nts::Tristate   nts::Cmp4013::Compute(size_t pin_num_this)
{
    if (static_cast<int>(pin_num_this) <= 0)
        throw nts::ComponentError("Pin number should be positive");
    else if (pin_num_this > 16)
        throw nts::ComponentError("Pin number should not exceed 16");
    switch (pin_num_this)
    {
        case (1):
            return (_or1->Compute(4));
        case (2):
            return (_or1->Compute(10));
        case (13):
            return (_or2->Compute(4));
        case (12):
            return (_or2->Compute(10));
        default:
            return (_pins[pin_num_this].second->Compute(pin_num_this));
    }
}

void            nts::Cmp4013::SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target)
{
    if (static_cast<int>(pin_num_this) <= 0 || static_cast<int>(pin_num_target) <= 0)
        throw nts::ComponentError("Pin number should be positive");
    else if (pin_num_this > 16 || pin_num_target > 16)
        throw nts::ComponentError("Pin number should not exceed 16");
    _pins[pin_num_this].first = pin_num_target;
    _pins[pin_num_this].second = &component;
}

void            nts::Cmp4013::Dump() const
{
    std::cout << "\tType : 4013" << std::endl;
}