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
    <meta name="description" content="">
    <meta name="author" content="wtf">
    <title>AREA | Créer un compte</title>
    <link rel="icon" href="${contextPath}/resources/img/favicon.ico" />
    <link href="${contextPath}/resources/css/login.css" rel="stylesheet">
</head>
<body>
<div class="wrapper">
    <div class="container">
        <h1>AREA - Création de compte</h1>
        <form:form method="POST" modelAttribute="userForm" class="form">
            <spring:bind path="username">
                <form:input type="text" path="username" class="form-control" placeholder="Pseudo"></form:input>
                <form:errors path="username"></form:errors>
            </spring:bind>
            <spring:bind path="password">
                <form:input type="password" path="password" class="form-control" placeholder="Mot de passe"></form:input>
                <form:errors path="password"></form:errors>
            </spring:bind>
            <spring:bind path="passwordConfirm">
                <form:input type="password" path="passwordConfirm" class="form-control"
                            placeholder="Confirmer votre mot de passe"></form:input>
                <form:errors path="passwordConfirm"></form:errors>
            </spring:bind>
            <button type="submit" id="registration-button">Créer son compte</button><br><br>
            <span>Déjà un compte ? &nbsp; <a href="${contextPath}/login">Se connecter</a></span>
        </form:form>
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