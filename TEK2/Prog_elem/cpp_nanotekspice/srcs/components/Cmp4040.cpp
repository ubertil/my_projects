/*
** Cmp4040.cpp for nanotekspice in /home/uberti_p/delivery/nanotekspice/Cmp4040.cpp
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  jeu. févr. 02 15:54:25 2017 Louis-Emile Uberti-Arès
** Last update jeu. févr. 02 15:54:25 2017 Louis-Emile Uberti-Arès
*/

#include "Cmp4040.hpp"

nts::Cmp4040::Cmp4040(const std::string &value) :
    _name(value)
{

}

nts::Tristate   nts::Cmp4040::Compute(size_t pin_num_this)
{
    (void)pin_num_this;
    return (nts::Tristate::UNDEFINED); // TO CHANGE
}

void            nts::Cmp4040::SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target)
{
    (void)pin_num_target;
    (void)component;
    (void)pin_num_this;
}

void            nts::Cmp4040::Dump() const
{
    std::cout << "\tType : 4040";
}