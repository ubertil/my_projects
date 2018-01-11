namespace Webserver.Controllers
{
    using System.Web;
    using Webserver.Models.Forms;
    using Webserver.Models.Account;
    using Microsoft.AspNetCore.Mvc;
    using System;

    /// <summary>
    /// API Controller which directs all the available endpoints.
    /// </summary>
    public class APIController : Controller
    {
        /// <summary>
        /// Logs the user.
        /// </summary>
        /// <returns>The user.</returns>
        /// <param name="connection">Connection.</param>
        [HttpPost]
        public IActionResult logUser([FromBody]Connection connection)
        {
            if (connection != null)
            {
                // Convert any HTML markup in the status text.
                connection.Username = HttpUtility.HtmlDecode(connection.Username);
                connection.Password = HttpUtility.HtmlDecode(connection.Password);
            }
            if (ModelState.IsValid && connection != null &&
                AccountContext.Instance().CheckUserPassword(connection.Username, AccountContext.Instance().GetHashPassword(connection.Password)))
            {
                Response.Cookies.Append("username", connection.Username);
                Response.Cookies.Append("token", AccountContext.Instance().GetHashPassword(connection.Password));
                return Json(new {
                    redirection = "/Area/Dashboard"
                });
            }
            else
                return BadRequest(new {
                    msg = "Veuillez vérifier vos identifiants",
                });
        }

        /// <summary>
        /// Logout
        /// </summary>
        /// <returns>The user.</returns>
        [HttpPost]
        public IActionResult logout()
        {
            Response.Cookies.Delete("username");
            Response.Cookies.Delete("token");
            return Json(new {
                redirection = "/"
            });
        }

        /// <summary>
        /// Registers the user.
        /// </summary>
        /// <returns>The user.</returns>
        /// <param name="connection">Connection.</param>
        [HttpPost]
        public IActionResult registerUser([FromBody]Connection connection)
        {
            if (connection != null)
            {
                // Convert any HTML markup in the status text.
                connection.Username = HttpUtility.HtmlDecode(connection.Username);
                connection.Password = HttpUtility.HtmlDecode(connection.Password);
                connection.PasswordConfirm = HttpUtility.HtmlDecode(connection.PasswordConfirm);
            }
            if (ModelState.IsValid && connection != null)
            {
                if (connection.Password.Length < 8)
                    return BadRequest(new {
                        msg = "Votre mot de passe doit faire 8 caractères minimum."
                    });
                if (connection.Password != connection.PasswordConfirm)
                    return BadRequest(new {
                        msg = "Vos mots de passe ne correspondent pas."
                    });
                // Check if someone has the same username
                if (AccountContext.Instance().UserAlreadyExist(connection.Username))
                    return Json(new {
                        msg = "Un utilisateur existe déjà avec ce pseudo"
                    });
                // User is valid : Add the new user in database and redirect to login page (or set the connection cookies and directly send to dashboard)
                UserModel User = new UserModel()
                {
                    UserName = connection.Username,
                    Password = connection.Password,
                    IsAdmin = false
                };
                AccountContext.Instance().AddUser(User);
                return Json(new {
                    redirection = "/"
                });
            }
            else
                return BadRequest(new {
                    msg = "Veuillez remplir tous les champs"
                });
        }

        /// <summary>
        /// Gets the actions.
        /// </summary>
        /// <returns>The actions.</returns>
        [HttpGet]
        public IActionResult getActions()
        {
            // List all actions available from module
            return Json(new {
                actions = Modules.ModuleManager.getActions()
            });
        }

        /// <summary>
        /// Gets the reactions.
        /// </summary>
        /// <returns>The reactions.</returns>
        [HttpGet]
        public IActionResult getReactions()
        {
            // List all reactions available from module
            return Json(new {
                reactions = Modules.ModuleManager.getReactions()
            });
        }

        /// <summary>
        /// Returns all tasks associated to a specific username.
        /// </summary>
        /// <returns>The tasks.</returns>
        /// <param name="Username">Username.</param>
        [HttpGet]
        public IActionResult getTasks(string Username)
        {
            if (Username == null)
                return BadRequest();
            return Json(new {
                tasks = AccountContext.Instance().GetTasksByUser(Username)
            }); 
        }

        /// <summary>
        /// Gets the action fields for a specific module.
        /// </summary>
        /// <returns>The action fields.</returns>
        /// <param name="Module">Module.</param>
        [HttpGet]
        public IActionResult getActionFields(string Module)
        {
            if (Module == null)
                return BadRequest();
            return Json(new {
                fields = Modules.ModuleManager.getFields(Module)
            });
        }

        /// <summary>
        /// Gets the reaction fields for a specific module.
        /// </summary>
        /// <returns>The reaction fields.</returns>
        /// <param name="Module">Module.</param>
        [HttpGet]
        public IActionResult getReactionFields(string Module)
        {
            if (Module == null)
                return BadRequest();
            return Json(new {
                fields = Modules.ModuleManager.getFields(Module)
            });
        }

        /// <summary>
        /// Activates the task.
        /// </summary>
        /// <returns>The task.</returns>
        [HttpPost]
        public IActionResult activateTask([FromBody]TaskModel UserTask)
        {
            if (UserTask == null)
                return BadRequest();
            AccountContext.Instance().UpdateTask(UserTask);
            // Activate or desactivate task
            return Json(new {
                msg = "Tâche éditée avec succès !"
            });
        }

        /// <summary>
        /// Adds the task.
        /// </summary>
        /// <returns>The task.</returns>
        [HttpPost]
        public IActionResult addTask([FromBody]TaskModel UserTask)
        {
            if (UserTask == null)
                return BadRequest();
            AccountContext.Instance().AddTask(UserTask);
            return Json(new {
                msg = "Tâche ajoutée avec succès !",
            });
        }

        /// <summary>
        /// Deletes the task.
        /// </summary>
        /// <returns>The task.</returns>
        [HttpPost]
        public IActionResult deleteTask([FromBody]TaskModel UserTask)
        {
            if (UserTask == null)
                return BadRequest();
            // Delete task
            AccountContext.Instance().RemoveTask(UserTask.Id);
            return Json(new {
                msg = "Tâche supprimée avec succès !"
            });
        }
    }
}
