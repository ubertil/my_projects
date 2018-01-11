/*
** Cmp4008.hpp for nanotekspice in /home/uberti_p/delivery/nanotekspice/Cmp4008.hpp
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  jeu. févr. 02 14:56:37 2017 Louis-Emile Uberti-Arès
** Last update jeu. févr. 02 14:56:37 2017 Louis-Emile Uberti-Arès
*/

#pragma once
# include <unordered_map>
# include <memory>
# include "IComponent.hpp"
# include "Cmp4030.hpp"
# include "Cmp4081.hpp"
# include "Cmp4071.hpp"


namespace nts
{
    class   Cmp4008 : public IComponent
    {
    public:
        Cmp4008(const std::string &);
        virtual ~Cmp4008() {}
        nts::Tristate Compute(size_t pin_num_this = 1) final;
        void SetLink(size_t pin_num_this,
                     nts::IComponent &component,
                     size_t pin_num_target) final;
        void Dump(void) const final;
    private:
        std::string const                                               _name;
        std::unordered_map<size_t, std::pair<size_t, IComponent *>>     _pins;
        std::unique_ptr<nts::Cmp4030>                                   _xor1;
        std::unique_ptr<nts::Cmp4030>                                   _xor2;
        std::unique_ptr<nts::Cmp4081>                                   _and1;
        std::unique_ptr<nts::Cmp4081>                                   _and2;
        std::unique_ptr<nts::Cmp4071>                                   _or1;
    };
}
