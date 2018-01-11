function validateForm() {
    var isValid = true;
    $(":input").each(function() {
        if ($(this).attr('name') !== undefined && $(this).val() === "") {
            isValid = false;
        }
    });
    return isValid;
}

$("#login-button").click(function(event){
    event.preventDefault();
    if (validateForm()) {
        $('form').fadeOut(500);
        $('h1').text("Connexion en cours");
        $('.wrapper').addClass('form-success');
        setTimeout(function () {
            $('form').submit();
        }, 2000);
    }
});

$("#registration-button").click(function(event){
    if (validateForm()) {
        event.preventDefault();
        $('form').fadeOut(500);
        $('h1').text("Vérification en cours");
        $('.wrapper').addClass('form-success');
        setTimeout(function () {
            $('form').submit();
        }, 1500);
    }
});