/*
** Cmp2716.cpp for nanotekspice in /home/uberti_p/delivery/nanotekspice/Cmp2716.cpp
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  mer. févr. 08 14:03:22 2017 Louis-Emile Uberti-Arès
** Last update mer. févr. 08 14:03:22 2017 Louis-Emile Uberti-Arès
*/

#include "Cmp2716.hpp"

nts::Cmp2716::Cmp2716(const std::string &value) :
        _name(value)
{

}

nts::Tristate   nts::Cmp2716::Compute(size_t pin_num_this)
{
    (void)pin_num_this;
    return (nts::Tristate::UNDEFINED); // TO CHANGE
}

void            nts::Cmp2716::SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target)
{
    (void)pin_num_target;
    (void)component;
    (void)pin_num_this;
}

void            nts::Cmp2716::Dump() const
{
    std::cout << "\tType : 2716" << std::endl;
}