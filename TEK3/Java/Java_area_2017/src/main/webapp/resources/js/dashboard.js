// Display only the clicked tab, hide the others
function activeCurrentTab(clicked) {
    var old_tab = $('.view');
    old_tab.fadeOut(400);
    old_tab.removeClass('active-tab');
    old_tab.promise().done(function(){
        clicked.fadeIn(400);
    });
    clicked.addClass('active-tab');
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

$(document).ready(function() {
    // Load User tasks
    AreaAPI.getTasks();

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

    // Save web new task
    $('#save-task').click(function() {
        var task = {};
        var tmpActionFields = {};
        var tmpReactionFields = {};
        $('.view.active-tab#add-new-task-tab .content input').each(function () {
            task[$(this).attr('name')] = $(this).val();
            if ($(this).attr('name').match("^action")) {
                tmpActionFields[$(this).attr('name')] = $(this).val();
            }
            else if ($(this).attr('name').match("^reaction")) {
                tmpReactionFields[$(this).attr('name')] = $(this).val();
            }
        });
        task["action"] = $("select[name=v_action]").val();
        task["reaction"] = $("select[name=v_reaction]").val();
        task["actionFields"] = JSON.stringify(tmpActionFields);
        task["reactionFields"] = JSON.stringify(tmpReactionFields);
        $.ajax({
            url : "/api/addTask",
            type : "POST",
            headers : AreaAPI.csrf_headers,
            contentType : "application/json",
            data : JSON.stringify(task),
            dataType : 'json',
            timeout : 100000,
            success : function(data) {
               alert(data.msg);
            },
            error : function(data) {
                alert(data.msg);
                console.log(data);
            },
        });
    });

    // Change status when clicking on web task
    $(document).on('click', '.status-button', function () {
        var isActivated = ($(this).attr('class') === "status-button green");
        if (isActivated) {
            $(this).removeClass('green');
            $(this).text('Desactivé');
        }
        else {
            $(this).addClass('green');
            $(this).text('Activé');
        }
    });
});