// AREA API Object
var AreaAPI = {
    // CSRF TOKEN
    csrf : "<%=${_csrf.token}%>",

    // CSRF HEADERS
    csrf_headers : {
        "X-CSRF-TOKEN" : this.csrf,
        "_csrf" : this.csrf
    },

    isValidTask : function(task) {
        var remainingKeys = [];
        var isEmpty = function(obj, keysArr) {
            for (var key in obj) {
                if (typeof obj[key] === "object" && obj.hasOwnProperty(key)) {
                    isEmpty(obj[key], keysArr);
                } else {
                    if (obj[key] == "" || obj[key] == null) {
                        keysArr.push(key);
                    }
                }
            }
        };
        isEmpty(task["actionFields"], remainingKeys);
        isEmpty(task["reactionFields"], remainingKeys);
        return (task["username"] != "" && task["description"] != "" && 
                task["actionName"] != null && task["reactionName"] != null && remainingKeys.length == 0);
    },

    getTasks : function(username) {
        return $.ajax({
            url : "/api/getTasks",
            type : "GET",
            headers : AreaAPI.csrf_headers,
            data : {
                "username" : username
            },
            timeout : 100000,
            success : function(data) {
                var tasks_html = '<div class="pipeline">';
                for (var i = 0; i < data.tasks.length; i++) {
                    var task = data.tasks[i];
                    tasks_html += '<div class="title">' + task.actionName + " &rarr; " + task.reactionName + '</div>' +
                        '<ul>' +
                        '<li>' +
                        '<input type="text" id="task-id" value="' + task.id + '" hidden>' +
                        '<i class="fa fa-square-o"></i><span>' + task.description + '</span>' +
                        '<div class="info">' +
                        '<div class="status-button ' + ((task.activated) ? ("green") : ("")) + '">' + ((task.activated) ? ("Activée") : ("Désactivée")) + '</div>' +
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

    getActionFields : function() {
        return $.ajax({
            url : "/api/getActionFields",
            type : "GET",
            headers : this.csrf_headers,
            data : {
                "module" : $("select[name=v_action]").val()
            },
            timeout : 100000,
            success : function(data) {
                var fields_html = "<br><br>";
                for (var field in data.fields) {
                    field = data.fields[field];
                    fields_html += "<input type=\"text\" name=\"action_" + field + "\" placeholder=\"" + field + "\"><br>";
                }
                $("#data_actions_add_task").html(fields_html);
            },
            error : function(e) {
                console.log("Error when getting action's fields on enpoint /api/getActionFields");
            }
        });
    },

    getReactionFields : function() {
        return $.ajax({
            url : "/api/getReactionFields",
            type : "GET",
            headers : this.csrf_headers,
            data : {
                "module" : $("select[name=v_reaction]").val(),
            },
            timeout : 100000,
            success : function(data) {
                var fields_html = "<br><br>";
                for (var field in data.fields) {
                    field = data.fields[field];
                    fields_html += "<input type=\"text\" name=\"reaction_" + field + "\" placeholder=\"" + field + "\"><br>";
                }
                $("#data_reactions_add_task").html(fields_html);
            },
            error : function(e) {
                console.log("Error when getting action's reactions on enpoint /api/getReactionFields");
            }
        });
    },

    changeActivated : function(task) {
        return $.ajax({
            url : "/api/activateTask",
            type : "POST",
            headers : this.csrf_headers,
            contentType : "application/json",
            data : JSON.stringify(task),
            dataType : 'json',
            timeout : 100000,
            success : function(data) {
                console.log("Task edited");
            },
            error : function(e) {
                console.log("Couldn't edit task");
            }
        });
    },

    addTask : function(task) {
        return $.ajax({
            url : "/api/addTask",
            type : "POST",
            headers : AreaAPI.csrf_headers,
            data : JSON.stringify(task),
            contentType: "application/json",
            dataType : 'json',
            timeout : 100000,
            success : function(data) {
                console.log(data.msg);
                $('.menu li#tasks').click();
            },
            error : function(data) {
                console.log("Error when adding task on endpoint /api/addTask");
            },
        });
    },

    deleteTask : function(id) {
        var task = {};
        task["id"] = id;
        return $.ajax({
            url : "/api/deleteTask",
            type : "POST",
            headers : this.csrf_headers,
            contentType : "application/json",
            data : JSON.stringify(task),
            dataType : 'json',
            timeout : 100000,
            success : function(data) {
                console.log("Task deleted");
                $('.menu li#tasks').click();
            },
            error : function(e) {
                console.log("Couldn't delete task on endpoint /api/deleteTask");
            }
        });
    },

    getActions : function() {
        return $.ajax({
            url : "/api/getActions",
            type : "GET",
            headers : AreaAPI.csrf_headers,
            contentType : "application/json",
            dataType : 'json',
            timeout : 100000,
            success: function (data) {
                var actions_selector = '<select onchange="AreaAPI.getActionFields()" name="v_action" style="width:49%"><option selected disabled>Choisissez une action</option>';
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
        return $.ajax({
            url : "/api/getReactions",
            type : "GET",
            headers : AreaAPI.csrf_headers,
            contentType : "application/json",
            dataType : 'json',
            timeout : 100000,
            success: function (data) {
                var reactions_selector = '<select onchange="AreaAPI.getReactionFields()" name="v_reaction" style="width:49%"><option selected disabled>Choisissez une reaction</option>';
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