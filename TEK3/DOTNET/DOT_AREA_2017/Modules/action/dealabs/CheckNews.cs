using System;
using System.Collections.Generic;
using System.Net;

namespace Modules.action.dealabs
{
    class CheckNews : Action
    {
        WebClient client = new WebClient();
        Dictionary<string, string> fields = new Dictionary<string, string>();
        Reaction r = null;
        List<string> send = new List<string>();
        List<string> page = new List<string>();
        List<string> toSend = new List<string>();
        string content = null;

        public List<string> getFields()
        {
            return (new List<string>() { { "keyword" } });
        }

        public void setField(Dictionary<string, string> fields)
        {
            this.fields = fields;
            send = findNews();
        }

        public void addReaction(Reaction r)
        {
            this.r = r;
        }

        private List<string> findNews()
        {
            var link = "";
            this.fields["keyword"] = this.fields["keyword"].ToLower();
            string toFind = "https://www.dealabs.com/bons-plans/";

            try
            {
                content = (client.DownloadString("https://www.dealabs.com/?page=1"));
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex);
            }

            int i = 0;
            while (i <= content.Length)
            {
                if (i + toFind.Length <= content.Length && content.IndexOf(toFind, i, toFind.Length) == i)
                {
                    i += toFind.Length;
                    link = toFind;
                    int j = 0;
                    while (content[i] != '"')
                        link += content[i++];
                    page.Add(link);
                }
                i++;
            }

            foreach (string links in page)
            {
                if (links.Contains(this.fields["keyword"]) && !toSend.Contains(links))
                    toSend.Add(links);
            }

            return (toSend);
        }
        public void update()
        {
            if (this.r == null)
                return;

            string message = "";

            toSend = findNews();

            foreach (string links in toSend)
            {
                if (!send.Contains(links))
                {
                    message += links;
                    message += "\r\n";
                    send.Add(links);
                }
            }

            if (message != "")
                r.execute(message);
        }
    }
}   
