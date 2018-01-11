using System.Collections.Generic;
using System;
using OpenPop.Pop3;

namespace Modules.action.gmail
{
    class CheckMail : Action
    {
        Reaction r = null;
        int nbMails;
        private Dictionary<String, String> fields = new Dictionary<string, string>();

        public List<String> getFields()
        {
            return (new List<String>() { { "email" }, { "password" }});
        }

        public void setField(Dictionary<String, String> fields)
        {
            this.fields = fields;
            this.nbMails = getNbMails();
        }

        private int getNbMails()
        {
            Pop3Client client = new Pop3Client();
            client.Connect("pop.gmail.com", 995, true);
            client.Authenticate(fields["email"], fields["password"]);
            return (client.GetMessageCount());
        }

        public void addReaction(Reaction r)
        {
            this.r = r;
        }

        public void update()
        {
            if (this.r == null)
                return;

            int newNbMails = getNbMails();
            if (newNbMails != this.nbMails)
            {
                if (newNbMails > this.nbMails)
                    this.r.execute();
                this.nbMails = newNbMails;
            }
        }
    }
}
