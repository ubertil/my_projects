/*
** CmpTrue.hpp for nanotekspice in /home/uberti_p/delivery/nanotekspice/CmpTrue.hpp
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  jeu. févr. 02 15:23:32 2017 Louis-Emile Uberti-Arès
** Last update jeu. févr. 02 15:23:32 2017 Louis-Emile Uberti-Arès
*/

#pragma once
# include "IComponent.hpp"

namespace nts
{
    class   CmpTrue : public IComponent
    {
    public:
        CmpTrue(const std::string &);
        virtual ~CmpTrue() {}
        nts::Tristate Compute(size_t pin_num_this = 1) final;
        void SetLink(size_t pin_num_this,
                     nts::IComponent &component,
                     size_t pin_num_target) final;
        void Dump(void) const final;
    private:
        std::string const   _name;
        nts::Tristate const _value;
    };

}
