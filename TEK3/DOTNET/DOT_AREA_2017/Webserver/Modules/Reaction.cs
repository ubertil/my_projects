/**
 * \file        Reaction.cs
 * \author      WTF Corp
 * \version     1.0
 * \date        26 Novembre 2017
 * \brief       Interface d'action
 *
 * \details     Cette interface gère les réactions
 * 
 */
 
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Modules
{
    interface Reaction : Module
    {
        /**
        * \brief    Execute la réaction
        * \details  Execute la réaction avec une chaine de caractere établie
        * \param    str      chaine de caractère envoyée à la reaction
        * \return   \e void
        */
        void execute(String str);

        /**
        * \brief    Execute la reaction
        * \details  Execute la reaction
        * \return   \e void
        */
        void execute();
    }
}
