using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Modules
{
    interface Reaction : Module
    {
        void execute(String str);
        void execute();
    }
}
