package com.area.modules.action.gmail;

import com.area.modules.Action;
import com.area.modules.Reaction;

import javax.mail.*;
import java.util.*;

public class CheckEmail implements Action {
    Map<String, String> fields = new HashMap<String, String>();
    Reaction r = null;
    private int nbMails = 0;

    public List<String> getFields() {
        return (new ArrayList<String>() {{
            add("from");
            add("password");
        }});
    }
    public void setField(Map<String, String> fields) {
        this.fields = fields;
        this.nbMails = getNbMails();
    }
    public void addReaction(Reaction r) {
        this.r = r;
    }

    private class SMTPAuthenticator extends javax.mail.Authenticator {
        public PasswordAuthentication getPasswordAuthentication() {
            return new PasswordAuthentication(fields.get("from"), fields.get("password"));
        }
    }
    private int getNbMails()
    {
        Properties props = new Properties();
        props.put("mail.smtp.user", fields.get("from"));
        props.put("mail.smtp.host", "smtp.gmail.com");
        props.put("mail.smtp.port", "995");
        props.put("mail.smtp.starttls.enable", "true");
        props.put("mail.smtp.auth", "true");
        props.put("mail.smtp.debug", "true");
        props.put("mail.smtp.socketFactory.port", "995");
        props.put("mail.smtp.socketFactory.class", "javax.net.ssl.SSLSocketFactory");
        props.put("mail.smtp.socketFactory.fallback", "false");

        try {
            Authenticator auth = new CheckEmail.SMTPAuthenticator();
            Session session = Session.getInstance(props, auth);
            Store store = session.getStore("imaps");
            store.connect("imap.gmail.com", fields.get("from"), fields.get("password"));
            Folder folder = store.getFolder("INBOX");
            folder.open(Folder.READ_ONLY);
            Message[] messages = folder.getMessages();
            folder.close(false);
            store.close();
            return (messages.length);
        } catch (Exception mex) {
            System.out.println("Error with Gmail");
        }
        return (0);
    }

    public void update()
    {

        int newNbMails = getNbMails();

        if (newNbMails != this.nbMails) {

            if (newNbMails > this.nbMails && this.r != null)
                this.r.execute();
            this.nbMails = newNbMails;
        }
    }
}
