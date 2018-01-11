/*
** CmpFalse.hpp for nanotekspice in /home/uberti_p/delivery/nanotekspice/CmpFalse.hpp
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  jeu. févr. 02 15:22:17 2017 Louis-Emile Uberti-Arès
** Last update jeu. févr. 02 15:22:17 2017 Louis-Emile Uberti-Arès
*/

#pragma once
# include "IComponent.hpp"

namespace nts
{
    class   CmpFalse : public IComponent
    {
    public:
        CmpFalse(const std::string &);
        virtual ~CmpFalse() {}
        nts::Tristate Compute(size_t pin_num_this = 1);
        void SetLink(size_t pin_num_this,
                     nts::IComponent &component,
                     size_t pin_num_target) final;
        void Dump(void) const final;
    private:
        std::string const   _name;
        nts::Tristate const _value;
    };
}
