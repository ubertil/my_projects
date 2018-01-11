function validateForm() {
    var isValid = true;
    $(":input").each(function() {
        if ($(this).attr('name') !== undefined && $(this).val() === "") {
            isValid = false;
        }
    });
    return isValid;
}

function getCookie(cname) {
    var name = cname + "=";
    var ca = document.cookie.split(';');
    for(var i = 0; i < ca.length; i++) {
        var c = ca[i];
        while (c.charAt(0) == ' ') {
            c = c.substring(1);
        }
        if (c.indexOf(name) == 0) {
            return c.substring(name.length, c.length);
        }
    }
    return "";
}

// Login page : Redirect to dashboard
function autoConnect() {
    if (getCookie("username") != "" && getCookie("token") != "") {
        $('form').fadeOut(300);
        $('h1').text("Bienvenue " + getCookie("username"));
        $('.wrapper').addClass('form-success');
        setTimeout(function() {document.location.href = "/Area/Dashboard";}, 2000);
    }
}

if ($('#login-secret').length)
    autoConnect();

function register(fromCookies) {
    var user = {};
    user["username"] = $("input[name=username").val();
    user["password"] = $("input[name=password").val();
    user["passwordConfirm"] = $("input[name=passwordConfirm").val();
    $.ajax({
        url : "/api/registerUser",
        type : "POST",
        data : JSON.stringify(user),
        timeout : 100000,
        contentType : "application/json",
        dataType : 'json',
        success : function(data) {
            document.location.href = data.redirection;
        },
        error : function(data) {
            $('#error-msg').html(data.responseJSON.msg);
            $('h1').text("AREA - Création de compte");
            $('.wrapper').removeClass('form-success');
            $('.form').fadeIn(200);
        }
    });
}

function login() {
    var user = {};
    user["username"] = $("input[name=username").val();
    user["password"] = $("input[name=password").val();
    $.ajax({
        url : "/api/logUser",
        type : "POST",
        data : JSON.stringify(user),
        timeout : 100000,
        contentType : "application/json",
        dataType : 'json',
        success : function(data) {
            setTimeout(function() {document.location.href = data.redirection;}, 1000);
        },
        error : function(data) {
            $('#error-msg').html(data.responseJSON.msg);
            $('h1').text("AREA - Connexion à votre espace");
            $('.wrapper').removeClass('form-success');
            $('.form').fadeIn(200);
        }
    });
}

// Login
$("#login-button").click(function(event) {
    event.preventDefault();
    if (validateForm()) {
        $('form').fadeOut(500);
        $('h1').text("Connexion en cours");
        $('.wrapper').addClass('form-success');
        setTimeout(login, 2000);
    }
});

// Register
$("#registration-button").click(function(event){
    if (validateForm()) {
        event.preventDefault();
        $('form').fadeOut(500);
        $('h1').text("Vérification en cours");
        $('.wrapper').addClass('form-success');
        setTimeout(register, 2000);
    }
});