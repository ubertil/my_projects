using System;
using System.Collections.Generic;
using System.Net;

namespace Modules.action.twitch
{
    class CheckOnline : Action
    {
        WebClient client = new WebClient();
        Dictionary<string, string> fields = new Dictionary<string, string>();
        Reaction r = null;
        string content = null;

        public List<string> getFields()
        {
            return (new List<string>() { { "streamer" } });
        }

        public void setField(Dictionary<string, string> fields)
        {
            this.fields = fields;
        }

        public void addReaction(Reaction r)
        {
            this.r = r;
        }
        public void update()
        {
            if (this.r == null)
                return;

            try
            {
                content = (client.DownloadString("https://tmi.twitch.tv/group/user/" + this.fields["streamer"]));
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex);
            }

            string number = "";
            string toFind = "\"chatter_count\":";
            for (int i = 0; i < content.Length; i++)
            {
                if (i + toFind.Length <= content.Length && content.IndexOf(toFind, i, toFind.Length) == i)
                {
                    while (content[i] != ' ')
                        i++;
                    i++;
                    while (content[i] != '\n')
                        number += content[i++];
                }
            }

            int viewers = int.Parse(number);
            string message = "";

            if (viewers != 0)
                message = this.fields["streamer"] + "is now online";
            
            if (message != "")
                r.execute(message);
        }
    }
}
