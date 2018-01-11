package com.area.modules.action.twitter;

import com.area.modules.Action;
import com.area.modules.Reaction;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.URL;
import java.net.URLConnection;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class CheckTweet implements Action {
    Map<String, String> fields = new HashMap<String, String>();
    Reaction r = null;

    URLConnection connection = null;

    int nbTweet = 0;

    public List<String> getFields() {
        return (new ArrayList<String>() {{
            add("username");
        }});
    }
    public void setField(Map<String, String> fields) {
        this.fields = fields;
        this.nbTweet = getNbTweet();
    }
    public void addReaction(Reaction r) {
        this.r = r;
    }

    private int getNbTweet()
    {
        try {
            connection =  new URL("https://twitter.com/" + this.fields.get("username")).openConnection();


            BufferedReader in = new BufferedReader(new InputStreamReader(
                    connection.getInputStream(), "UTF-8"));
            String inputLine;
            StringBuilder a = new StringBuilder();
            while ((inputLine = in.readLine()) != null)
                //web.append(inputLine);
                if (inputLine.contains("class=\"ProfileNav-value\""))
                {
                    Matcher matcher = Pattern.compile("\\d+").matcher(inputLine);
                    matcher.find();
                    int i = Integer.valueOf(matcher.group());
                    in.close();
                    return (i);
                }
            in.close();
        }catch ( Exception ex ) {
            ex.printStackTrace();
        }
        return (0);
    }

    public void update() {
        if (this.r == null)
            return ;

        int newNbTweet = getNbTweet();

        if (newNbTweet != this.nbTweet) {

            if (newNbTweet > this.nbTweet)
                this.r.execute();
            this.nbTweet = newNbTweet;
        }
    }
}
