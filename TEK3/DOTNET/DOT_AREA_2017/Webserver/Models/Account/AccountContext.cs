using MySql.Data.MySqlClient;
using System;
using System.Collections.Generic;

namespace Webserver.Models.Account
{
    public class AccountContext
    {
        private static AccountContext instance;

        public string ConnectionString { get; set; }

        public AccountContext(string connectionString)
        {
            this.ConnectionString = connectionString;
        }

        public static AccountContext Instance(string connectionString = null)
        {
            if (instance == null)
            {
                instance = new AccountContext(connectionString);
            }
            return instance;
        }

        private MySqlConnection GetConnection()
        {
            return new MySqlConnection(ConnectionString);
        }

        public List<TaskModel> GetAllTasks()
        {
            List<TaskModel> list = new List<TaskModel>();

            using (MySqlConnection conn = GetConnection())
            {
                conn.Open();
                MySqlCommand cmd = new MySqlCommand("SELECT * FROM task", conn);

                using (var reader = cmd.ExecuteReader())
                {
                    while (reader.Read())
                    {
                        list.Add(new TaskModel()
                        {
                            Id = Convert.ToInt32(reader["id"]),
                            User = reader["user"].ToString(),
                            Description = reader["description"].ToString(),
                            ActionName = reader["action_name"].ToString(),
                            ActionFields = reader["action_field"].ToString(),
                            ReactionName = reader["reaction_name"].ToString(),
                            ReactionFields = reader["reaction_field"].ToString(),
                            Activated = Convert.ToBoolean(reader["activated"])
                        });
                    }
                }
            }
            return list;
        }

        public List<TaskModel> GetTasksActivated()
        {
            List<TaskModel> list = new List<TaskModel>();

            using (MySqlConnection conn = GetConnection())
            {
                conn.Open();
                MySqlCommand cmd = new MySqlCommand("SELECT * FROM task WHERE activated=1", conn);

                using (var reader = cmd.ExecuteReader())
                {
                    while (reader.Read())
                    {
                        list.Add(new TaskModel()
                        {
                            Id = Convert.ToInt32(reader["id"]),
                            User = reader["user"].ToString(),
                            Description = reader["description"].ToString(),
                            ActionName = reader["action_name"].ToString(),
                            ActionFields = reader["action_field"].ToString(),
                            ReactionName = reader["reaction_name"].ToString(),
                            ReactionFields = reader["reaction_field"].ToString(),
                            Activated = Convert.ToBoolean(reader["activated"])
                        });
                    }
                }
            }
            return list;
        }
        public List<TaskModel> GetTasksByUser(string user)
        {
            List<TaskModel> list = new List<TaskModel>();

            using (MySqlConnection conn = GetConnection())
            {
                conn.Open();
                MySqlCommand cmd = new MySqlCommand("SELECT * FROM task WHERE user='" + user + "'", conn);

                using (var reader = cmd.ExecuteReader())
                {
                    while (reader.Read())
                    {
                        list.Add(new TaskModel()
                        {
                            Id = Convert.ToInt32(reader["id"]),
                            User = reader["user"].ToString(),
                            Description = reader["description"].ToString(),
                            ActionName = reader["action_name"].ToString(),
                            ActionFields = reader["action_field"].ToString(),
                            ReactionName = reader["reaction_name"].ToString(),
                            ReactionFields = reader["reaction_field"].ToString(),
                            Activated = Convert.ToBoolean(reader["activated"])
                        });
                    }
                }
            }
            return list;
        }

        public TaskModel FindTask(long id)
        {
            TaskModel task;

            using (MySqlConnection conn = GetConnection())
            {
                string request = "SELECT * FROM task WHERE id = '" + id + "'";
                Console.WriteLine(request);
                conn.Open();
                MySqlCommand cmd = new MySqlCommand(request, conn);

                using (var reader = cmd.ExecuteReader())
                {
                    reader.Read();
                    task = new TaskModel()
                    {
                        Id = Convert.ToInt32(reader["id"]),
                        User = reader["user"].ToString(),
                        Description = reader["description"].ToString(),
                        ActionName = reader["action_name"].ToString(),
                        ActionFields = reader["action_field"].ToString(),
                        ReactionName = reader["reaction_name"].ToString(),
                        ReactionFields = reader["reaction_field"].ToString(),
                        Activated = Convert.ToBoolean(reader["activated"])
                    };
                }
            }
            return task;
        }

        public void AddTask(TaskModel task)
        {
            using (MySqlConnection conn = GetConnection())
            {
                string insertValues = "";
                insertValues += "'" + task.User + "', ";
                insertValues += "'" + task.Description + "', ";
                insertValues += "'" + task.ActionName + "', ";
                insertValues += "'" + task.ActionFields + "', ";
                insertValues += "'" + task.ReactionName + "', ";
                insertValues += "'" + task.ReactionFields + "', ";
                insertValues += "'" + ((task.Activated) ? (1) : (0)) + "'";

                conn.Open();
                MySqlCommand cmd = new MySqlCommand("INSERT INTO task(user, description, action_name, action_field, reaction_name, reaction_field, activated) VALUES(" + insertValues + ")", conn);
                cmd.ExecuteNonQuery();
            }
        }

        public void RemoveTask(long id)
        {
            using (MySqlConnection conn = GetConnection())
            {
                conn.Open();
                string request = "DELETE FROM task WHERE id = '" + id + "'";
                Console.WriteLine(request);
                MySqlCommand cmd = new MySqlCommand(request, conn);
                cmd.ExecuteNonQuery();
            }
        }

        public void UpdateTask(TaskModel task)
        {
            using (MySqlConnection conn = GetConnection())
            {
                string updateValues = "activated='" + ((task.Activated) ? (1) : (0)) + "'";

                conn.Open();
                MySqlCommand cmd = new MySqlCommand("UPDATE task SET " + updateValues + " WHERE id = '" + task.Id + "'", conn);
                cmd.ExecuteNonQuery();
            }
        }

        public List<UserModel> GetAllUsers()
        {
            List<UserModel> list = new List<UserModel>();

            using (MySqlConnection conn = GetConnection())
            {
                conn.Open();
                MySqlCommand cmd = new MySqlCommand("SELECT * FROM user", conn);

                using (var reader = cmd.ExecuteReader())
                {
                    while (reader.Read())
                    {
                        list.Add(new UserModel()
                        {
                            Id = Convert.ToInt32(reader["id"]),
                            UserName = reader["username"].ToString(),
                            Password = reader["password"].ToString(),
                            IsAdmin = Convert.ToBoolean(reader["is_admin"])
                        });
                    }
                }
            }
            return list;
        }

        public void AddUser(UserModel user)
        {
            using (MySqlConnection conn = GetConnection())
            {
                string insertValues = "";
                insertValues += "'" + user.UserName + "', ";
                insertValues += "SHA1('" + user.Password + "'), ";
                insertValues += "'" + ((user.IsAdmin) ? (1) : (0)) + "'";

                conn.Open();
                MySqlCommand cmd = new MySqlCommand("INSERT INTO user(username, password, is_admin) VALUES(" + insertValues + ")", conn);
                cmd.ExecuteNonQuery();
            }
        }

        public bool CheckUserPassword(string username, string passwd)
        {
            bool ret;
            using (MySqlConnection conn = GetConnection())
            {
                conn.Open();
                MySqlCommand cmd = new MySqlCommand("SELECT password FROM user WHERE username='" + username + "'", conn);
                using (var reader = cmd.ExecuteReader())
                {
                    if (!reader.Read())
                        ret = false;
                    else
                    {
                        if (reader["password"].ToString().Equals(passwd))
                            ret = true;
                        else
                            ret = false;
                    }
                }
            }
            return ret;
        }

        public string GetHashPassword(string passwd)
        {
            string passwdHash;
            using (MySqlConnection conn = GetConnection())
            {
                conn.Open();
                string DbHash = "SHA1('" + passwd + "')";
                MySqlCommand cmd = new MySqlCommand("SELECT " + DbHash, conn);
                using (var reader = cmd.ExecuteReader())
                {
                    reader.Read();
                    passwdHash = reader[DbHash].ToString();
                }
            }
            return passwdHash;
        }

        public void RemoveUser(long id)
        {
            using (MySqlConnection conn = GetConnection())
            {
                conn.Open();
                string request = "DELETE FROM user WHERE id = '" + id + "'";
                MySqlCommand cmd = new MySqlCommand(request, conn);
                cmd.ExecuteNonQuery();
            }
        }

        public void UpdateUser(UserModel user)
        {
            using (MySqlConnection conn = GetConnection())
            {
                string updateValues = "";
                updateValues += "username='" + user.UserName + "', ";
                updateValues += "password=SHA1('" + user.Password + "'), ";
                updateValues += "is_admin='" + ((user.IsAdmin) ? (1) : (0)) + "'";

                conn.Open();
                MySqlCommand cmd = new MySqlCommand("UPDATE user SET " + updateValues + " WHERE id = '" + user.Id + "'", conn);
                cmd.ExecuteNonQuery();
            }
        }

        public bool UserAlreadyExist(string username)
        {
            bool ret;
            using (MySqlConnection conn = GetConnection())
            {
                conn.Open();
                MySqlCommand cmd = new MySqlCommand("SELECT * from user WHERE username='" + username + "'", conn);
                using (var reader = cmd.ExecuteReader())
                {
                    if (!reader.Read())
                        ret = false;
                    else
                        ret = true;
                }
            }
            return ret;
        }
    }
}