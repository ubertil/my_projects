package com.area.modules.action.dealabs;

import com.area.modules.Action;
import com.area.modules.Reaction;

import java.net.URL;
import java.net.URLConnection;
import java.util.HashMap;
import java.util.Map;
import java.util.List;
import java.util.ArrayList;
import java.util.Scanner;

public class CheckNews implements Action {
    Map<String, String> fields = new HashMap<String, String>();
    Reaction r = null;
    List<String> send = new ArrayList<>();
    List<String> page = new ArrayList<>();
    List<String> toSend = new ArrayList<>();
    String content = null;
    String toFind = "https://www.dealabs.com/bons-plans/";
    URLConnection connection = null;


    public List<String> getFields() {
        return (new ArrayList<String>() {{
            add("keyword");
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
            return ;

        toSend.clear();

        try {
            connection =  new URL("https://www.dealabs.com/?page=1").openConnection();
            Scanner scanner = new Scanner(connection.getInputStream());
            scanner.useDelimiter("\\Z");
            content = scanner.next();
        }catch ( Exception ex ) {
            ex.printStackTrace();
        }

        for (int i = 0; i < content.length(); i++) {
            if (content.regionMatches(i, toFind, 0, toFind.length())) {
                i += toFind.length();
                String link = toFind;
                while (content.charAt(i) != '"')
                    link += content.charAt(i++);
                page.add(link);
            }
        }

        int i = 0;
         for (String link:page) {
             if (send.isEmpty())
                if (++i < 21 && link.contains(this.fields.get("keyword")))
                    toSend.add(link);
                else {
                    for (String isSend : send) {
                        if (!isSend.equals(link) && link.contains(this.fields.get("keyword")))
                            if (++i < 21)
                                toSend.add(link);
                    }
                }
        }

        if (!toSend.isEmpty())
            r.execute();
    }
}
