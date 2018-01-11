using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Modules.reaction.system
{
    class PrintLine : Reaction
    {
        private Dictionary<String, String> fields = new Dictionary<String, String>();

        public List<String> getFields()
        {
            return (new List<String>() { { "message" } });
        }

        public void setField(Dictionary<String, String> fields)
        {
            this.fields = fields;
        }

        public void execute()
        {
            this.execute(null);
        }

        public void execute(String str)
        {
            if (str != null)
                Console.WriteLine(str);
            else
                Console.WriteLine(fields["message"]);
        }

    }
}
