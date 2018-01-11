package com.area.modules;

import com.area.modules.action.bourse.CheckBourse;
import com.area.modules.action.dealabs.CheckNews;
import com.area.modules.action.git.CheckCommit;
import com.area.modules.action.twitch.CheckOnline;
import com.area.modules.reaction.gmail.SendEmail;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Test {
    public static void main(String[] str)
    {
        List<Action> actions = new ArrayList<Action>();

        SendEmail r = new SendEmail();
        Map<String, String> fields = new HashMap<String, String>();
        fields.put("from", "zbrahbot@gmail.com");
        fields.put("password", "zbrahzbrah");
        fields.put("to", "grellardfelix@gmail.com");
        fields.put("subject", "zbrahzbrah");
        fields.put("message", "zbrahzbrah");
        r.setField(fields);

        CheckCommit a = new CheckCommit();
        a.setField(new HashMap<String, String>() {{
            put("username", "zbrah");
            put("password", "zbrahzbrah1");
            put("repository owner", "zbrah");
            put("repository name", "testouille");
            put("branch name", "master");
        }});
        a.addReaction(r);

        actions.add(a);

        while (true)
        {
            for (Action action : actions)
            {
                action.update();
            }
        }
    }
}
