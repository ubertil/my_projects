using System;
using System.Collections.Generic;
using System.Globalization;
using System.Net;   

namespace Modules.action.bourse
{
    class CheckBourse : Action
    {
        WebClient client = new WebClient();
        Dictionary<string, string> fields = new Dictionary<string, string>();
        Reaction r = null;
        List<string> content = null;
        float price = 0;

        private float getPriceValue()
        {
            int i = 0;

            content = new List<string>();
            while (++i < 8)
            {
                try
                {
                    content.Add(client.DownloadString("http://www.boursorama.com/bourse/actions/cours_az.phtml?page=" + i));
                }
                catch (Exception ex)
                {
                    Console.WriteLine(ex);
                }
            }

            string number = "";
            string cotation = "class=\"cotation\">";
            Boolean check = false;
            foreach (string cont in content)
            {
                for (int j = 0; j < cont.Length; j++)
                {
                    if (j + fields["business"].Length <= cont.Length && cont.IndexOf(fields["business"], j, fields["business"].Length) == j)
                    {
                        while (j++ < cont.Length && !check)
                            if (j + cotation.Length <= cont.Length && cont.IndexOf(cotation, j, cotation.Length) == j)
                            {
                                j += cotation.Length;
                                for (int k = 0; k < 5; k++)
                                    number += cont[k + j];
                                check = true;
                            }
                    }
                }
            }

            float value = float.Parse(number, CultureInfo.InvariantCulture);
            return (value);
        }

        public List<string> getFields()
        {
            return (new List<string>() { { "business" },
                { "rate" } });
        }

        public void setField(Dictionary<string, string> fields)
        {
            this.fields = fields;
            this.price = getPriceValue();
        }

        public void addReaction(Reaction r)
        {
            this.r = r;
        }

        public void update()
        {
            if (this.r == null)
                return;

            float value = getPriceValue();

            string message = "";
            if ((price - value > (float.Parse(this.fields["rate"]) * -1)) ||
                    (value - price) > float.Parse(this.fields["rate"]))
            {
                price = value;
                message = this.fields["business"] + " " + price;
            }

            if (message != "")
                r.execute();
        }
    }
}
