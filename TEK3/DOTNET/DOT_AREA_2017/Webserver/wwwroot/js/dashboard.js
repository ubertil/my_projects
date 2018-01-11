// Display only the clicked tab, hide the others
function activeCurrentTab(clicked) {
    var old_tab = $('.view');
    // Refresh tasks tab
    old_tab.fadeOut(400);
    AreaAPI.getTasks($("#username").html());
    old_tab.removeClass('active-tab');
    old_tab.promise().done(function(){
        clicked.fadeIn(400);
    });
    clicked.addClass('active-tab');
}

function logout() {
   $.ajax({
        url : "/api/logout",
        type : "POST",
        timeout : 100000,
        contentType : "application/json",
        dataType : 'json',
        success : function(data) {
            document.location.href = data.redirection;
        }
    });
}

// Returns the current tab activated
function getActiveTab() {
    var ret = "";
    $('.view').each(function () {
        if ($(this).hasClass("active-tab")) {
            ret = $(this).attr('id').valueOf();
        }
    });
    return ret;
}

$(document).ready(function () {
    // Set username from cookie
    $('#username').html(getCookie("username"));
    $('#username-account').html(getCookie("username"));
    $('#greeting').html("Bonjour " + $('#username').html() + ", comment allez-vous aujourd'hui ?");


    // Load User tasks
    AreaAPI.getTasks($("#username").html());

    // Load Actions and Reactions
    AreaAPI.getActions();
    AreaAPI.getReactions();

    // Display only the active tab
    $('.view').fadeOut(0);
    $('.view.active-tab').fadeIn(0);

    // Pointer cursor on logout icon
    $('#account-develop').hover(
        function() {
            $(this).css("cursor", "pointer");
        }, function() {
            $(this).css("cursor", "auto");
        }
    );

    // Check the checkbox when clicking on them
    // Also check the hidden input box
    $(document).on('click', ".view i[class*='square']", function () {
        var isClicked = ($(this).parent().attr('class') === 'checked');
        if (isClicked) {
            $(this).parent().removeClass('checked');
            $(this).parent().find('input').prop('checked', false);
            $(this).attr('class', 'fa fa-square-o');
        } else {
            $(this).parent().addClass('checked');
            $(this).parent().find('input').prop('checked', true);
            $(this).attr('class', 'fa fa-check-square-o');
        }
    });

    // Switch tabs and set the clicked on to active
    $('.menu li').click(function() {
        var isActivated = ($(this).attr('class') === "active");
        var newCurrentTab = $('.view#' + $(this).attr('id') + '-tab');
        if (!isActivated) {
            $('.menu li').removeClass('active');
            $(this).addClass('active');
            activeCurrentTab(newCurrentTab);
        } else if (isActivated && $('#add-new-task-tab').attr('class').search('active')) {
            // Special case just for add task so we can switch back to the manage task one
            activeCurrentTab(newCurrentTab);
        }
    });

    // Switch to add new task tab
    $('#add-new-task').click(function() {
        activeCurrentTab($('.view#add-new-task-tab'));
    });

    // Filter search results
    $('input#search-bar').on('input', function() {
        // Switch to task tab to show results
        if (getActiveTab() !== "tasks-tab") {
            activeCurrentTab($('.view#tasks-tab'));
        }
        var filter = $('input#search-bar').val().toUpperCase();
        // Check all tasks
        $('.view.active-tab#tasks-tab .content .list .pipeline ul').find('li').each(function() {
            if ($(this).find('span').text().toUpperCase().indexOf(filter) > -1) {
                $(this).css("display", "");
            } else {
                $(this).css("display", "none");
            }
        });
        var oneDisplayed = false;
        // Desactivate web pipeline if all the task inside are not displayed
        $('.view.active-tab#tasks-tab .content .list .pipeline').each(function () {
            var display = false;
            $(this).find('ul').find('li').each(function() {
                if ($(this).css("display") === "list-item") {
                    display = true;
                }
            });
            if (!display) {
                $(this).find('.title').css('display', 'none');
            } else {
                oneDisplayed = true;
                $(this).find('.title').css('display', '');
            }
        });
        // If nothing was found, display no result
        if (!oneDisplayed) {
            $('.title.no-result').remove();
            $('.view.active-tab#tasks-tab .content .list').append("<div class='title no-result'>Aucun résultat trouvé pour " + '"' +
                filter + '"' + "</div>");
        } else {
            $('.title.no-result').remove();
        }
    });

    // Save new task
    $('#save-task').click(function() {
        var task = {};
        var tmpActionFields = {};
        var tmpReactionFields = {};
        $('.view.active-tab#add-new-task-tab .content input').each(function () {
            var name = $(this).attr('name').substr($(this).attr('name').indexOf('_') + 1, $(this).attr('name').length);
            if ($(this).attr('name').match("^action")) {
                tmpActionFields[name] = $(this).val();
            } else if ($(this).attr('name').match("^reaction")) {
                tmpReactionFields[name] = $(this).val();
            }
        });
        // Build task
        task["user"] = $('#username').html();
        task["description"] = $("input[name=description]").val();
        task["actionName"] = $("select[name=v_action]").val();
        task["reactionName"] = $("select[name=v_reaction]").val();
        task["actionFields"] = JSON.stringify(tmpActionFields);
        task["reactionFields"] = JSON.stringify(tmpReactionFields);
        task["activated"] = true;
        if (AreaAPI.isValidTask(task)) {
            // Reset fields
            $('.view.active-tab#add-new-task-tab .content input').each(function () {
                $(this).val("");
            });
            AreaAPI.getActions();
            AreaAPI.getReactions();
            $('.view#add-new-task-tab .content .list .closebtn').click();
            // Send task to API
            $.when(AreaAPI.addTask(task)).done($('.menu li#tasks').click());
        } else {
            $('.view#add-new-task-tab .content .list .alert').css("display", "block");
        }
    });

    // Delete tasks selected
    $('#delete-task').click(function() {
        var ids = [];
        $('.view.active-tab .content .list .pipeline').each(function () {
                $(this).find('ul').find('li').each(function() {
                    if ($(this).hasClass("checked")) {
                        ids.push($(this).find('input').val());
                    }
                });
            });
        if (ids.length ==  0) {
            alert("Cocher les tâches que vous souhaitez supprimer avant de cliquer sur 'Supprimer'");
            return;
        }
        var confirmed = confirm("Êtes-vous sûr de vouloir supprimer ces tâches ?");
        // User said OK
        if (confirmed) {
            // Find all checked tasks and get their id
            for (var i =0; i < ids.length - 1; i++) {
                AreaAPI.deleteTask(ids[i]);
            }
        }
        $.when(AreaAPI.deleteTask(ids[i++])).done($('.menu li#tasks').click());
    });

    // Change status when clicking on web task
    $(document).on('click', '.status-button', function () {
        var task = {};
        task["id"] = $(this).parent().parent().find('input').val();
        if ($(this).attr('class').includes("green")) {
            $(this).removeClass('green');
            $(this).text('Desactivée');
            task["activated"] = false;
        } else {
            $(this).addClass('green');
            $(this).text('Activée');
            task["activated"] = true;
        }
        AreaAPI.changeActivated(task);
    });

    // Close error
    $(document).on('click', '.closebtn', function () {
        $(this).parent().fadeOut(500);
    });
});