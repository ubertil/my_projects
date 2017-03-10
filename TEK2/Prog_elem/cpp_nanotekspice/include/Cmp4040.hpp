/*
** Cmp4040.hpp for nanotekspice in /home/uberti_p/delivery/nanotekspice/Cmp4040.hpp
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  jeu. févr. 02 15:00:33 2017 Louis-Emile Uberti-Arès
** Last update jeu. févr. 02 15:00:33 2017 Louis-Emile Uberti-Arès
*/

#pragma once
# include "IComponent.hpp"

namespace nts
{
    class   Cmp4040 : public IComponent
    {
    public:
        Cmp4040(const std::string &);
        virtual ~Cmp4040() {}
        nts::Tristate Compute(size_t pin_num_this = 1) final;
        void SetLink(size_t pin_num_this,
                             nts::IComponent &component,
                             size_t pin_num_target) final;
        void Dump(void) const final;
    private:
        std::string const _name;
    };
}
