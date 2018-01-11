package com.area.modules.reaction.gmail;

import com.area.modules.Reaction;
import org.eclipse.egit.github.core.RepositoryId;

import javax.mail.*;
import javax.mail.internet.InternetAddress;
import javax.mail.internet.MimeMessage;
import java.util.*;

public class SendEmail implements Reaction {

    Map<String, String> fields = new HashMap<String, String>();

    private class SMTPAuthenticator extends javax.mail.Authenticator {
        public PasswordAuthentication getPasswordAuthentication() {
            return new PasswordAuthentication(fields.get("from"), fields.get("password"));
        }
    }

    public List<String> getFields() {
        return (new ArrayList<String>() {{
            add("from");
            add("password");
            add("to");
            add("subject");
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
        System.out.println("Execution de la réaction");
        Properties props = new Properties();
        props.put("mail.smtp.user", fields.get("from"));
        props.put("mail.smtp.host", "smtp.gmail.com");
        props.put("mail.smtp.port", "465");
        props.put("mail.smtp.starttls.enable", "true");
        props.put("mail.smtp.auth", "true");
        props.put("mail.smtp.debug", "true");
        props.put("mail.smtp.socketFactory.port", "465");
        props.put("mail.smtp.socketFactory.class", "javax.net.ssl.SSLSocketFactory");
        props.put("mail.smtp.socketFactory.fallback", "false");

        try {
            Authenticator auth = new SendEmail.SMTPAuthenticator();
            Session session = Session.getInstance(props, auth);
            session.setDebug(true);
            MimeMessage msg = new MimeMessage(session);
            if (str != null)
                msg.setText(str);
            else
                msg.setText(fields.get("message"));
            msg.setSubject(fields.get("subject"));
            msg.setFrom(new InternetAddress(fields.get("from")));
            msg.addRecipient(Message.RecipientType.TO, new InternetAddress(fields.get("to")));
            Transport transport = session.getTransport("smtps");
            transport.send(msg);
        } catch (Exception mex) {
            System.out.println("Error with Gmail");
        }
    }
}
