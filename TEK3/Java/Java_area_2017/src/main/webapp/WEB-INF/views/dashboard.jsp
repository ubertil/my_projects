<%@ taglib prefix="spring" uri="http://www.springframework.org/tags" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8"%>
<c:set var="contextPath" value="${pageContext.request.contextPath}"/>
<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta name="description" content="area donnez nous le max de points svp">
    <meta name="author" content="wtf">
    <title>AREA | Dashboard</title>
    <link rel="stylesheet" href="${contextPath}/resources/css/dashboard.css" />
    <link rel="icon" href="${contextPath}/resources/img/favicon.ico" />
</head>
<body>
<div class="page">
    <div class="pageHeader">
        <div class="title">Espace de gestion</div>
        <div class="userPanel">
            <form id="logoutForm" method="POST" action="${contextPath}/logout">
                <input type="hidden" name="${_csrf.parameterName}" value="${_csrf.token}"/>
                <i class="fa fa-sign-out" id="account-develop" onclick="document.forms['logoutForm'].submit()">Deconnexion</i>
            </form>
            <span id="username" class="username">${pageContext.request.userPrincipal.name}</span>
        </div>
    </div>
    <div class="main">
        <div class="nav">
            <div class="searchbox">
                <div><i class="fa fa-search"></i>
                    <input type="search" placeholder="Rechercher une tâche" name="search" id="search-bar"/>
                </div>
            </div>
            <div class="menu">
                <div class="title">Navigation</div>
                <ul>
                    <li id="dashboard" class="active"><i class="fa fa-home"></i>Dashboard</li>
                    <li id="tasks"> <i class="fa fa-tasks"></i>Gérer mes tâches</li>
                    <li id="account"><i class="fa fa-user"></i>Mon compte</li>
                    <li id="information"><i class="fa fa-info"></i>Informations</li>
                </ul>
            </div>
        </div>
        <!-- Dashboard -->
        <div class="view active-tab" id="dashboard-tab">
            <div class="viewHeader">
                <div class="title">Votre dashboard</div>
            </div>
            <div class="content">
                <div class="list">
                    <div class="title">Rapport</div>
                    <ul>
                        <li><span>Bonjour ${pageContext.request.userPrincipal.name}, comment allez-vous aujourd'hui ?</span></li>
                        <li><span>Vous avez peu de tâches activées, n'hésitez pas à en activer sous l'onglet "Gérer mes tâches" &rarr; "Ajouter une nouvelle tâche"</span></li>
                    </ul>
                </div>
            </div>
        </div>
        <!-- Tasks manager -->
        <div class="view" id="tasks-tab">
            <div class="viewHeader">
                <div class="title">Gérer mes tâches</div>
                <div class="functions">
                    <div id="add-new-task" class="button active">Ajouter une nouvelle tâche</div>
                </div>
            </div>
            <div class="content">
                <div class="list">
                    <div class="pipeline">
                        <ul>
                            <span id="listTasks"></span>
                        </ul>
                    </div>
                </div>
            </div>
        </div>
        <!-- Add task tab -->
        <div class="view" id="add-new-task-tab">
            <div class="viewHeader">
                <div class="title">Ajouter une tâche</div>
                <div class="functions">
                    <div id="save-task" class="button active">Sauvegarder</div>
                </div>
            </div>
            <div class="content">
                <div class="list">
                    <input type="hidden" type="text" name="username" value="${pageContext.request.userPrincipal.name}">
                    <div class="title">Actions</div>
                    <span id="actions_add_task"></span>
                    <div id="data_actions_add_task"></div>
                    <div class="title">Reactions</div>
                    <span id="reactions_add_task"></span>
                    <div id="data_reactions_add_task"></div>
                </div>
            </div>
        </div>
        <!-- Account -->
        <div class="view" id="account-tab">
            <div class="viewHeader">
                <div class="title">Mon compte</div>
            </div>
            <div class="content">
                <div class="list">
                    <div class="title">Pseudo</div>
                    <ul>
                        <li><span>${pageContext.request.userPrincipal.name}</span></li>
                    </ul>
                    <div class="title">Rôle</div>
                    <ul>
                        <li><span>Utilisateur</span></li>
                    </ul>
                    <div class="title">Changer de mot de passe</div>
                    <ul>
                        <li>
                            Mot de passe actuel <input type="password" name="password" placeholder="">
                        </li>
                        <li>
                            <span>Nouveau mot de passe <input type="password" name="new_password" placeholder=""></span>
                        </li>
                        <li>
                            <span>Confirmer votre mot de passe <input type="password" name="new_password_confirm" placeholder=""></span>
                        </li>
                    </ul>
                </div>
            </div>
        </div>
        <!-- Information -->
        <div class="view" id="information-tab">
            <div class="viewHeader">
                <div class="title">Informations | AREA crée par WTF (Web Team Framework)</div>
            </div>
            <div class="content">
                <div class="list">
                    <div class="title">Plateforme Web&nbsp;<i class="fa fa-globe"></i></div>
                    <p>Nous mettons à votre disposition une plateforme permettant <b>l'intégration et l'inter-communication de différentes API</b></p><br><br><br>
                    <div class="title">Équipe&nbsp;<i class="fa fa-star"></i></div>
                    <ul>
                        <li><span>Alexis Papadimitriou</span></li>
                        <li><span>Come Grellard</span></li>
                        <li><span>Felix Grellard</span></li>
                        <li><span>Nicolas Trognot</span></li>
                        <li><span>Nicolas Wadel</span></li>
                        <li><span>Louis-Emile Uberti</span></li>
                    </ul>
                    <div class="title">Contact&nbsp;<i class="fa fa-envelope"></i></div>
                    <ul>
                        <li><span><a href="mailto:louis-emile.uberti-ares@epitech.eu?subject=Contact site AREA">louis-emile.uberti-ares@epitech.eu</a></span></li>
                    </ul>
                </div>
            </div>
        </div>
    </div>
</div>
<script src="${contextPath}/resources/js/jquery.min.js"></script>
<script src="${contextPath}/resources/js/api.js"></script>
<script src="${contextPath}/resources/js/dashboard.js"></script>
</body>
</html>
