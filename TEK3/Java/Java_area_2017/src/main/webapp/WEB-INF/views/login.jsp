<%@ taglib prefix="spring" uri="http://www.springframework.org/tags" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="form" uri="http://www.springframework.org/tags/form" %>
<%@ page contentType="text/html;charset=UTF-8"%>
<c:set var="contextPath" value="${pageContext.request.contextPath}"/>
<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta name="description" content="wtf area donnez nous le max de points svp">
    <meta name="author" content="wtf">
    <title>AREA | Connexion à votre espace membre</title>
    <link rel="icon" href="${contextPath}/resources/img/favicon.ico" />
    <link href="${contextPath}/resources/css/login.css" rel="stylesheet">
</head>
<body>
<div class="wrapper">
    <div class="container">
        <h1>AREA - Connexion à votre espace</h1>
        <form method="POST" action="${contextPath}/login" class="form">
            <span>${message}</span>
            <c:if test="${not empty message}">
                <br><br>
            </c:if>
            <input name="username" type="text" placeholder="Pseudo" id="form-field" required>
            <input name="password" type="password" placeholder="Mot de passe" id="form-field" required>
            <span>${error}</span>
            <c:if test="${not empty error}">
                <br><br>
            </c:if>
            <input type="hidden" name="${_csrf.parameterName}" value="${_csrf.token}"/>
            <button type="submit" id="login-button">Se connecter</button><br><br>
            <span>Pas de compte ? &nbsp; <a href="${contextPath}/registration">Créer un compte</a></span>
        </form>
    </div>
    <ul class="bg-bubbles">
        <li></li>
        <li></li>
        <li></li>
        <li></li>
        <li></li>
        <li></li>
        <li></li>
        <li></li>
        <li></li>
        <li></li>
    </ul>
</div>
<script src="${contextPath}/resources/js/jquery.min.js"></script>
<script src="${contextPath}/resources/js/login.js"></script>
</body>
</html>