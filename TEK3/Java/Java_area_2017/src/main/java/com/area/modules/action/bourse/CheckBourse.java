package com.area.modules.action.bourse;

import com.area.modules.Action;
import com.area.modules.Reaction;

import java.net.URL;
import java.net.URLConnection;
import java.util.*;

public class CheckBourse implements Action {
    Map<String, String> fields = new HashMap<String, String>();
    Reaction r = null;
    List<String> content = null;
    URLConnection connection = null;
    float price;

    public List<String> getFields() {
        return (new ArrayList<String>() {{
            add("business");
            add("rate");
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

        int i = 0;

        content = new ArrayList<>();
        while (++i < 8) {
            try {
                connection = new URL("http://www.boursorama.com/bourse/actions/cours_az.phtml?page=" + i).openConnection();
                Scanner scanner = new Scanner(connection.getInputStream());
                scanner.useDelimiter("\\Z");
                content.add(scanner.next());
            } catch (Exception ex) {
                ex.printStackTrace();
            }
        }

        String number = "";
        String cotation = "class=\"cotation\">";
        boolean check = false;
        for (String cont : content) {
            for (int j = 0; j < cont.length(); j++) {
                if (cont.regionMatches(j, this.fields.get("business"), 0, this.fields.get("business").length())) {
                    while (j++ < cont.length() && !check)
                        if (cont.regionMatches(j, cotation, 0, cotation.length())) {
                            j += cotation.length();
                            for (int k = 0; k < 5; k++)
                                number += cont.charAt(k + j);
                            check = true;
                        }
                }
            }
        }

        float value = Float.parseFloat(number);
        System.out.println(value);
        if ((price - value > (Integer.parseInt(this.fields.get("rate")) * -1)) ||
                (value - price) > Integer.parseInt(this.fields.get("rate"))) {
            price = value;
            r.execute();
        }
    }
}