package com.area.modules.action.git;

import com.area.modules.Action;
import com.area.modules.Reaction;
import org.eclipse.egit.github.core.RepositoryBranch;
import org.eclipse.egit.github.core.RepositoryId;
import org.eclipse.egit.github.core.service.RepositoryService;

import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.concurrent.TimeUnit;

public class CheckCommit implements Action {
    Map<String, String> fields = new HashMap<String, String>();
    Reaction r = null;
    RepositoryService service = new RepositoryService();
    RepositoryId repo;
    String lastCommit = "";

    public List<String> getFields() {
        return (new ArrayList<String>() {{
            add("username");
            add("password");
            add("repository owner");
            add("repository name");
            add("branch name");
        }});
    }
    public void setField(Map<String, String> fields) {
        this.fields = fields;
        this.service.getClient().setCredentials(this.fields.get("username"), this.fields.get("password"));
        this.repo = new RepositoryId(this.fields.get("repository owner"), this.fields.get("repository name"));
        this.lastCommit = this.getLastCommit();
    }
    public void addReaction(Reaction r) {
        this.r = r;
    }
    public void update() {
        if (this.r == null) {
            return ;
        }

        String commit = this.getLastCommit();

        if (!this.lastCommit.equals(commit)) {
            this.lastCommit = commit;
            this.r.execute();

        }
    }

    private String getLastCommit() {
        try {
            List<RepositoryBranch> blist = this.service.getBranches(repo);
            RepositoryBranch branch = null;

            for (int i = 0; i < blist.size(); i += 1) {
                if (blist.get(i).getName().equals(this.fields.get("branch name")))
                    branch = blist.get(i);
            }
            if (branch != null)
                return branch.getCommit().getUrl();
        }
        catch (IOException e) {
            System.out.println("Failed to load git branch");
        }
        return this.lastCommit;
    }
}