using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.IO;
using System.Text.RegularExpressions;

namespace Modules.action.twitter
{
    class CheckTweet : Action
    {
        WebClient client = new WebClient();
        Dictionary<string, string> fields = new Dictionary<string, string>();
        Reaction r = null;
        string content = null;
        string lastTweetValue = null;
        int n = 0;


        public List<String> getFields()
        {
            return (new List<String>() { { "username" } });
        }

        private int getNbTweets()
        {
            int n = 0;
            try
            {
                content = client.DownloadString("https://twitter.com/" + fields["username"]);
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex);
            }
            using (StringReader reader = new StringReader(content))
            {
                string line;
                while ((line = reader.ReadLine()) != null)
                {
                    if (line.Contains("p class=\"TweetTextSize"))
                    {
                        var s = line.Substring(line.IndexOf(">") + 1);
                        lastTweetValue = "Nouveau tweet : " + s.Substring(0, s.Length - 4);
                        break;
                    }
                }
            }
            using (StringReader reader = new StringReader(content))
            {
                string line;
                while ((line = reader.ReadLine()) != null)
                {
                    if (line.Contains("class=\"ProfileNav-value\""))
                    {
                        n = Int32.Parse(Regex.Match(line, @"\d+").Value);
                        break;
                    }
                }
            }
            return n;
        }

        public void setField(Dictionary<string, string> fields)
        {
            this.fields = fields;
            this.n = getNbTweets();
        }

        public void addReaction(Reaction r)
        {
            this.r = r;
        }

        public void update()
        {
            int newNbTweet = getNbTweets();

            if (newNbTweet != this.n)
            {

                if (newNbTweet > this.n)
                    this.r.execute(lastTweetValue);
                this.n = newNbTweet;
            }
        }
    }
}
