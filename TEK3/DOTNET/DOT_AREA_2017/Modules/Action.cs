using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Modules
{
    interface Action : Module
    {
        void addReaction(Reaction r);
        void update();
    }
}
