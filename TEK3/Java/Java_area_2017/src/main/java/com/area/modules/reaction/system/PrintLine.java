package com.area.modules.reaction.system;

import com.area.modules.Reaction;

import javax.mail.*;
import javax.mail.internet.InternetAddress;
import javax.mail.internet.MimeMessage;
import java.util.*;

public class PrintLine implements Reaction {

    Map<String, String> fields = new HashMap<String, String>();

    public List<String> getFields() {
        return (new ArrayList<String>() {{
            add("message");
        }});
    }
    public void setField(Map<String, String> fields) {
        this.fields = fields;
    }
    public void execute() {
        this.execute(null);
    }
    public void execute(String str) {
        if (str != null)
            System.out.println(str);
        else
            System.out.println(fields.get("message"));
    }
}
