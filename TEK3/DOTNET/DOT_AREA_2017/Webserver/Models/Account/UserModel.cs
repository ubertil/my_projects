using System;
using System.Runtime.Serialization;

namespace Webserver.Models.Account
{
    /// <summary>
    /// Reprensents a Task.
    /// </summary>
    [Serializable, DataContract]
    public class UserModel
    {
        /// <summary>
        /// Gets or sets the identifier.
        /// </summary>
        /// <value>The identifier.</value>
        [DataMember(Name = "id")]
        public long Id { get; set; }

        /// <summary>
        /// Gets or sets the user name.
        /// </summary>
        /// <value>The user name.</value>
        [DataMember(Name = "userName")]
        public string UserName { get; set; }

        /// <summary>
        /// Gets or sets the password.
        /// </summary>
        /// <value>The password.</value>
        [DataMember(Name = "password")]
        public string Password { get; set; }

        /// <summary>
        /// Gets or sets the status of the user.
        /// </summary>
        /// <value>True if the user is an admin.</value>
        [DataMember(Name = "isAdmin")]
        public bool IsAdmin { get; set; }
    }
}