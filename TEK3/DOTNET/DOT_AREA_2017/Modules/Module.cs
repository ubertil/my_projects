using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Modules
{
    interface Module
    {
        List<String> getFields();
        void setField(Dictionary<String, String> fields);
    }
}
