package com.area.modules;


import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class ModulesManager {
    Map<String, String> actions = new HashMap<String, String>();
    Map<String, String> reactions = new HashMap<String, String>();

    public Map<String, String> getActions() {
        return this.actions;
    }

    public Map<String, String> getReactions() {
        return this.reactions;
    }

    ModulesManager() {
        actions.put("CheckBourse", "Verifier les evolutions d'une action en bourse");
        actions.put("CheckNews", "Verifier les nouveaux produits dealabs");
        actions.put("CheckCommit", "Verifier un commit Git");
        actions.put("CheckNewBranch", "Verifier une nouvelle branche Git");
        actions.put("CheckEmail", "Verifier la reception des emails Gmail");
        actions.put("CheckOnline", "Verifier si un Twitch est connecte");
        actions.put("CheckTweet", "Verifier si une personne web tweete");

        reactions.put("SendEmail", "Envoyer un mail");
        reactions.put("PrintLine", "Dev mode verbose");
    }

    public void /*Action*/ createModule(String action, Map<String, String> action_data,
                               String reaction, Map<String, String> reaction_data)
    {
        //new Reaction
        //feed avec reaction_data

        // new action
        // action.reaction = reaction
        // return action
    }
}
