namespace Webserver.Models.Forms
{
    using System;
    using System.Runtime.Serialization;

    /// <summary>
    /// Defines a Connection on our website
    /// </summary>
    [Serializable, DataContract]
    public class Connection
    {
        /// <summary>
        /// Gets or sets the username.
        /// </summary>
        /// <value>The username.</value>
        [DataMember(Name="username")]
        public string Username { get; set; }

        /// <summary>
        /// Gets or sets the password.
        /// </summary>
        /// <value>The password.</value>
        [DataMember(Name="password")]
        public string Password { get; set; }

        /// <summary>
        /// Gets or sets the password confirmation.
        /// </summary>
        /// <value>The password confirm.</value>
        [DataMember(Name="passwordConfirm")]
        public string PasswordConfirm { get; set; }
    }
}