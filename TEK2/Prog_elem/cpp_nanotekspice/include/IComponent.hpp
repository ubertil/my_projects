/*
** IComponent.hpp for cpp_nanotekspice in /home/uberti_p/delivery/cpp_nanotekspice/IComponent.hpp
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  mer. févr. 01 14:31:08 2017 Louis-Emile Uberti-Arès
** Last update mer. févr. 01 14:31:08 2017 Louis-Emile Uberti-Arès
*/

#pragma once
# include <iostream>
# include <string>
# include <functional>
# include <unordered_map>
# include "Error.hpp"

namespace nts
{
    enum Tristate
    {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };

    class IComponent
    {
    public:
        virtual nts::Tristate Compute(size_t pin_num_this = 1) = 0;
        virtual void SetLink(size_t pin_num_this,
                             nts::IComponent &component,
                             size_t pin_num_target) = 0;
        virtual void Dump(void) const = 0;
        virtual ~IComponent(void) {}
    };
}