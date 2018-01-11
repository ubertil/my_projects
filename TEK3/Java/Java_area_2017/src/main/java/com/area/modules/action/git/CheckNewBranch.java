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

public class CheckNewBranch implements Action {
    Map<String, String> fields = new HashMap<String, String>();
    Reaction r = null;
    RepositoryService service = new RepositoryService();
    RepositoryId repo;
    List<String> branchs = new ArrayList<String>();

    public List<String> getFields() {
        return (new ArrayList<String>() {{
            add("username");
            add("password");
            add("repository owner");
            add("repository name");
        }});
    }
    public void setField(Map<String, String> fields) {
        this.fields = fields;
        this.service.getClient().setCredentials(this.fields.get("username"), this.fields.get("password"));
        this.repo = new RepositoryId(this.fields.get("repository owner"), this.fields.get("repository name"));
        this.branchs = this.getBranchList();
    }

    public void addReaction(Reaction r) {
        this.r = r;
    }

    public void update() {
        if (this.r == null) {
            return ;
        }

        List<String> branchList = this.getBranchList();

        if (!this.branchs.equals(branchList)) {
            this.branchs = branchList;
            this.r.execute();
        }
    }

    private List<String> getBranchList() {
        try {
            List<RepositoryBranch> blist = this.service.getBranches(repo);

            return new ArrayList<String>() {{
                for (int i = 0; i < blist.size(); i += 1)
                    add(blist.get(i).getName());
            }};
        }
        catch (IOException e) {
            System.out.println("Failed to load git branch");
        }
        return this.branchs;
    }
}
