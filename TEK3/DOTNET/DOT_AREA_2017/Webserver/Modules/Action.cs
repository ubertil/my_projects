/**
 * \file        Action.cs
 * \author      WTF Corp
 * \version     1.0
 * \date        26 Novembre 2017
 * \brief       Interface d'action
 *
 * \details     Cette interface gère les actions
 * 
 */
 
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Modules
{
    interface Action : Module
    {
        /**
        * \brief    Ajouter une reaction
        * \details  Ajouter une reaction configurée
        * \param    r      réaction à ajouter
        * \return   \e void
        */
        void addReaction(Reaction r);

        /**
        * \brief    Verifier qu'une tâche est à jour
        * \details  Verifier qu'une tâche est à jour, execute la reaction si la condition est validée
        * \return   \e void
        */
        void update();
    }
}
