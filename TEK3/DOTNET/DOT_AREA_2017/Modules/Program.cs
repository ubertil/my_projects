/*using Modules.action.bourse;
using Modules.action.dealabs;
using Modules.action.twitch;
using Modules.reaction.gmail;
using System.Collections.Generic;

namespace Modules
{
    class Program
    {
        static void Main(string[] args)
        {
            List<Action> actions = new List<Action>();

            SendEmail r = new SendEmail();
            Dictionary<string, string> fields = new Dictionary<string, string>();
            fields.Add("from", "zbrahbot@gmail.com");
            fields.Add("password", "zbrahzbrah");
            fields.Add("to", "grellardfelix@gmail.com");
            fields.Add("subject", "zbrahzbrah");
            fields.Add("message", "zbrahzbrah");
            r.setField(fields);

            /*CheckOnline newonline = new CheckOnline();
            newonline.setField(new Dictionary<string, string>() { { "streamer", "lestream" } });
            newonline.addReaction(r);
            newonline.update();

            CheckBourse newbourse = new CheckBourse();
            newbourse.setField(new Dictionary<string, string>() { { "business", "AB SCIENCE" },
                { "rate", "1" }});
            newbourse.addReaction(r);
            newbourse.update();

            CheckNews newitem = new CheckNews();
            newitem.setField(new Dictionary<string, string>() {{ "keyword", "nintendo" }});
            newitem.addReaction(r);
            newitem.update();

            CheckCommit a = new CheckCommit();
            a.setField(new Dictionary<string, string>() {{ "username", "zbrah" },
                { "password", "zbrahzbrah1" },
                { "repository owner", "zbrah" },
                { "repository name", "testouille" },
                { "branch name", "master" }});
            a.addReaction(r);

            actions.Add(a);

            while (true)
            {
                foreach (Action action in actions)
                {
                    action.update();
                }
            }
        }
    }
}
*/