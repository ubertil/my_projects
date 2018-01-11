namespace Webserver.Models.Account
{
    using System;
    using System.Runtime.Serialization;

    /// <summary>
    /// Reprensents a Task.
    /// </summary>
    [Serializable, DataContract]
    public class TaskModel
    {
        /// <summary>
        /// Gets or sets the identifier.
        /// </summary>
        /// <value>The identifier.</value>
        [DataMember(Name = "id")]
        public long Id { get; set; }

        /// <summary>
        /// Gets or sets the user.
        /// </summary>
        /// <value>The user.</value>
        [DataMember(Name = "user")]
        public string User { get; set; }

        /// <summary>
        /// Gets or sets the description.
        /// </summary>
        /// <value>The description.</value>
        [DataMember(Name = "description")]
        public string Description { get; set; }

        /// <summary>
        /// Gets or sets the name of the action.
        /// </summary>
        /// <value>The name of the action.</value>
        [DataMember(Name = "actionName")]
        public string ActionName { get; set; }

        /// <summary>
        /// Gets or sets the action fields.
        /// </summary>
        /// <value>The action fields.</value>
        [DataMember(Name = "actionFields")]
        public string ActionFields { get; set; }

        /// <summary>
        /// Gets or sets the name of the reaction.
        /// </summary>
        /// <value>The name of the reaction.</value>
        [DataMember(Name = "reactionName")]
        public String ReactionName { get; set; }
        
        /// <summary>
        /// Gets or sets the reaction fields.
        /// </summary>
        /// <value>The reaction fields.</value>
        [DataMember(Name = "reactionFields")]
        public string ReactionFields { get; set; }

        /// <summary>
        /// Gets or sets a value indicating whether this <see cref="T:Webserver.Models.TaskModel"/> is activated.
        /// </summary>
        /// <value><c>true</c> if activated; otherwise, <c>false</c>.</value>
        [DataMember(Name = "activated")]
        public bool Activated { get; set; }
    }
}