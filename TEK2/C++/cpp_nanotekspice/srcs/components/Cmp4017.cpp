/*
** Cmp4017.cpp for nanotekspice in /home/uberti_p/delivery/nanotekspice/Cmp4017.cpp
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  jeu. févr. 02 15:50:38 2017 Louis-Emile Uberti-Arès
** Last update jeu. févr. 02 15:50:38 2017 Louis-Emile Uberti-Arès
*/

#include "Cmp4017.hpp"

nts::Cmp4017::Cmp4017(const std::string &value) :
    _name(value)
{

}

nts::Tristate   nts::Cmp4017::Compute(size_t pin_num_this)
{
    (void)pin_num_this;
    return (nts::Tristate::UNDEFINED); // TO CHANGE
}

void            nts::Cmp4017::SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target)
{
    (void)pin_num_target;
    (void)component;
    (void)pin_num_this;
}

void            nts::Cmp4017::Dump() const
{
    std::cout << "\tType : 4017" << std::endl;
}