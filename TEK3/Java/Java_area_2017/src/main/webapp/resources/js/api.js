// AREA API Object
var AreaAPI = {
    // CSRF TOKEN
    csrf : "<%=${_csrf.token}%>",

    // CSRF HEADERS
    csrf_headers : {
        "X-CSRF-TOKEN" : this.csrf,
        "_csrf" : this.csrf
    },

    update_action_fields : function() {
        $.ajax({
            url : "/api/getActionFields",
            type : "GET",
            headers : this.csrf_headers,
            contentType : "application/json",
            data : {
                "action" : $("select[name=v_action]").val()
            },
            dataType : 'json',
            timeout : 100000,
            success : function(data) {
                $("#data_actions_add_task").html(data.msg);
            },
            error : function(e) {
                alert("Error with ajax");
            }
        });
    },

    update_reaction_fields : function() {
        $.ajax({
            url : "/api/getReactionFields",
            type : "GET",
            headers : this.csrf_headers,
            contentType : "application/json",
            data : {
                "reaction" : $("select[name=v_reaction]").val(),
            },
            dataType : 'json',
            timeout : 100000,
            success : function(data) {
                $("#data_reactions_add_task").html(data.msg);
            },
            error : function(e) {
                alert("Error with ajax");
            }
        });
    },

    changeActivated : function(id) {
        var task = {};
        task["username"] = $("#username").html();
        task["taskID"] = id;
        $.ajax({
            url : "/api/activateTask",
            type : "POST",
            headers : this.csrf_headers,
            contentType : "application/json",
            data : JSON.stringify(task),
            dataType : 'json',
            timeout : 100000,
            success : function(data) {
                window.location.reload();
            },
            error : function(e) {
                alert("Error with ajax");
            }
        });
    },

    deleteTask : function(id) {
        var task = {};
        task["username"] = $("#username").html();
        task["taskID"] = id;
        $.ajax({
            url : "/api/deleteTask",
            type : "POST",
            headers : this.csrf_headers,
            contentType : "application/json",
            data : JSON.stringify(task),
            dataType : 'json',
            timeout : 100000,
            success : function(data) {
                window.location.reload();
            },
            error : function(e) {
                alert("Error with ajax");
            }
        });
    },

    getTasks : function() {
        $.ajax({
            url : "/api/getTasks",
            type : "GET",
            headers : AreaAPI.csrf_headers,
            contentType : "application/json",
            data : {
                "username" : $("#username").html()
            },
            dataType : 'json',
            timeout : 100000,
            success : function(data) {
                var tasks_html = '<div class="pipeline">';
                for (var i = 0; i < data.tasks.length; i++) {
                    var task = data.tasks[i];
                    tasks_html += '<div class="title">' + task.action_name + " &rarr; " + task.reaction_name + '</div>' +
                        '<ul>' +
                        '<li>' +
                        '<i class="fa fa-square-o"></i><span>' + task.description + '</span>' +
                        '<div class="info">' +
                        '<div class="status-button ' + ((task.activated) ? ("green") : ("")) + '">' + ((task.activated) ? ("Actif") : ("Désactif")) + '</div>' +
                        '</li>' +
                        '</ul>';
                }
                tasks_html += '</div>';
                $('.view#tasks-tab .content .list').html(tasks_html);
            },
            error : function(e) {
                console.log("Error when getting user's tasks on endpoint /api/getTasks");
            }
        });
    },

    getActions : function() {
        $.ajax({
            url : "/api/getActions",
            type : "GET",
            headers : AreaAPI.csrf_headers,
            contentType : "application/json",
            dataType : 'json',
            timeout : 100000,
            success : function(data) {
                var actions_selector = '<select onchange="AreaAPI.update_action_fields()" name="v_action" style="width:49%"><option selected disabled>Choisissez une action</option>';
                for (var action in data.actions) {
                    actions_selector += '<option value="' + action + '">' + action + ' (' + data.actions[action] + ')</option>';
                }
                actions_selector += '</select>';
                $("#actions_add_task").html(actions_selector);
            },
            error : function(e) {
                console.log("Error loading actions on endpoint /api/getActions");
            }
        });
    },

    getReactions : function() {
        $.ajax({
            url : "/api/getReactions",
            type : "GET",
            headers : AreaAPI.csrf_headers,
            contentType : "application/json",
            dataType : 'json',
            timeout : 100000,
            success : function(data) {
                var reactions_selector = '<select onchange="AreaAPI.update_reaction_fields()" name="v_reaction" style="width:49%"><option selected disabled>Choisissez une reaction</option>';
                for (var reaction in data.reactions) {
                    reactions_selector += '<option value="' + reaction + '">' + reaction + ' (' + data.reactions[reaction] + ')</option>';
                }
                reactions_selector += '</select>';
                $("#reactions_add_task").html(reactions_selector);
            },
            error : function(e) {
                console.log("Error loading reactions on endpoint /api/getReactions");
            }
        });
    }
};