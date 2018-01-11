using System;
using System.Collections.Generic;
using System.Net;
using System.Net.Mail;

namespace Modules.reaction.gmail
{
    class SendEmail : Reaction
    {
        private Dictionary<String, String> fields = new Dictionary<String, String>();

        public List<String> getFields()
        {
            return (new List<String>() { { "from" },
                { "password" },
                { "to" },
                { "subject" },
                { "message" } });
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
            MailMessage mail = new MailMessage();
            mail.From = new MailAddress(fields["from"]);
            SmtpClient smtp = new SmtpClient();
            smtp.Port = 587;
            smtp.EnableSsl = true;
            smtp.DeliveryMethod = SmtpDeliveryMethod.Network;
            smtp.UseDefaultCredentials = false;
            smtp.Credentials = new NetworkCredential(fields["from"], fields["password"]);
            smtp.Host = "smtp.gmail.com";
            mail.To.Add(new MailAddress(fields["to"]));
            mail.Subject = fields["subject"];
            mail.IsBodyHtml = true;
            if (str != null)
                mail.Body = str;
            else
                mail.Body = fields["message"];
            try
            {
                smtp.Send(mail);
            }
            catch (Exception mex)
            {
                Console.WriteLine("Error with Gmail\n" + mex);
            }
                
        }
    }
}
