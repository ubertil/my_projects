/**
 * \file        Modules.cs
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
    interface Module
    {
        /**
        * \brief    Retourne la liste des champs
        * \details  Retourne la liste des champs nécessaires
        * \return   \e List<String></String>
        */
        List<String> getFields();

        /**
        * \brief   Configurer les champs
        * \details Configurer les champs nécessaires
        * \param    fields      le dictionnaire des champs
        * \return   \e void
        */
        void setField(Dictionary<String, String> fields);
    }
}
