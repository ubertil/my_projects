package com.area.modules.action.twitch;

import com.area.modules.Action;
import com.area.modules.Reaction;

import java.net.URL;
import java.net.URLConnection;
import java.util.*;

public class CheckOnline implements Action {
    Map<String, String> fields = new HashMap<String, String>();
    Reaction r = null;
    URLConnection connection = null;
    String content = null;


    public List<String> getFields() {
        return (new ArrayList<String>() {{
            add("streamer");
        }});
    }

    public void setField(Map<String, String> fields) {
        this.fields = fields;
    }

    public void addReaction(Reaction r) {
        this.r = r;
    }

    public void update() {
        if (this.r == null)
            return;

        try {
            connection =  new URL("https://tmi.twitch.tv/group/user/" + this.fields.get("streamer")).openConnection();
            Scanner scanner = new Scanner(connection.getInputStream());
            scanner.useDelimiter("\\Z");
            content = scanner.next();
        }catch ( Exception ex ) {
            ex.printStackTrace();
        }

        String number = "";
        String toFind = "\"chatter_count\":";
        for (int i = 0; i < content.length(); i++) {
            if (content.regionMatches(i, toFind, 0, toFind.length())) {
                while (content.charAt(i) != ' ')
                    i++;
                i++;
                while (content.charAt(i) != '\n')
                    number += content.charAt(i++);
            }
        }
        int viewers = Integer.parseInt(number);
        if (viewers != 0)
            r.execute();
    }
}
