namespace Webserver.Controllers
{
    using System.Diagnostics;
    using System.Web;
    using Microsoft.AspNetCore.Mvc;
    using Webserver.Models;
    using Webserver.Models.Account;

    /// <summary>
    /// AREA Controller
    /// Controls the main URL endpoints to serve user generated views
    /// </summary>
    public class AreaController : Controller
    {
        /// <summary>
        /// Generates the Login view
        /// </summary>
        /// <returns>The login.</returns>
        public IActionResult Login()
        {
            ViewData["Message"] = "Connexion";

            return View();
        }

        /// <summary>
        /// Generates the Register view
        /// </summary>
        /// <returns>The register.</returns>
        public IActionResult Register()
        {
            ViewData["Message"] = "Créer un compte";

            return View();
        }

        /// <summary>
        /// Generates the Dashboard View if logged in
        /// </summary>
        /// <returns>The dashboard.</returns>
        public IActionResult Dashboard()
        {
            // Build a user with the username and password var in cookies
            string Username = HttpUtility.HtmlDecode(Request.Cookies["username"]);
            string Hash = HttpUtility.HtmlDecode(Request.Cookies["token"]);
            // Check if we have him in database
            if (Username.Length > 0 && Hash.Length > 0 && AccountContext.Instance().CheckUserPassword(Username, Hash))
            {
                ViewData["Message"] = "Dashboard";
                return View();
            }
            return Json("Erreur : Veuillez vous connecter pour accéder à cette espace");
        }

        /// <summary>
        /// Generates an Error view
        /// </summary>
        /// <returns>The error.</returns>
        public IActionResult Error()
        {
            return View(new ErrorViewModel { RequestId = Activity.Current?.Id ?? HttpContext.TraceIdentifier });
        }
    }
}
