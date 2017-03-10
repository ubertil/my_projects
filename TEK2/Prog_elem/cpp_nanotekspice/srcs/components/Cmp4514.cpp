/*
** Cmp4514.cpp for nanotekspice in /home/uberti_p/delivery/nanotekspice/Cmp4514.cpp
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  jeu. févr. 02 16:04:21 2017 Louis-Emile Uberti-Arès
** Last update jeu. févr. 02 16:04:21 2017 Louis-Emile Uberti-Arès
*/

#include "Cmp4514.hpp"

nts::Cmp4514::Cmp4514(const std::string &value) :
    _name(value)
{

}

nts::Tristate   nts::Cmp4514::Compute(size_t pin_num_this)
{
    (void)pin_num_this;
    return (nts::Tristate::UNDEFINED); // TO CHANGE
}

void            nts::Cmp4514::SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target)
{
    (void)pin_num_target;
    (void)component;
    (void)pin_num_this;
}

void            nts::Cmp4514::Dump() const
{
    std::cout << "\tType : 4514" << std::endl;
}