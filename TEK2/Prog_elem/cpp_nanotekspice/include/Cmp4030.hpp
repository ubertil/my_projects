/*
** Cmp4030.hpp for nanotekspice in /home/uberti_p/delivery/nanotekspice/Cmp4030.hpp
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  jeu. févr. 02 14:59:53 2017 Louis-Emile Uberti-Arès
** Last update jeu. févr. 02 14:59:53 2017 Louis-Emile Uberti-Arès
*/

#pragma once
# include <map>
# include "IComponent.hpp"

namespace nts
{
    class   Cmp4030 : public IComponent
    {
    public:
        Cmp4030(const std::string &);
        virtual ~Cmp4030() {}
        nts::Tristate Compute(size_t pin_num_this = 1) final;
        void SetLink(size_t pin_num_this,
                     nts::IComponent &component,
                     size_t pin_num_target) final;
        void Dump(void) const final;
    private:
        std::string const                                               _name;
        nts::Tristate                                                   _value;
        std::unordered_map<size_t, std::pair<size_t, IComponent *>>     _pins;
        std::unordered_map<size_t, std::pair<size_t, size_t>>           _output;
        std::unordered_map<size_t, int>                                 _passed;
    };
}

