using System.Collections.Generic;
using Webserver.Models.Account;

namespace Webserver.Models
{
    public class TaskRepository
    {
        private AccountContext context;

        public TaskRepository(AccountContext context)
        {
            this.context = context;
        }

        public List<TaskModel> GetTasks()
        {
            return context.GetAllTasks();
        }

        public List<TaskModel> GetTasksActivated()
        {
            return context.GetTasksActivated();
        }

        public List<TaskModel> GetTasksByUser(string user)
        {
            return context.GetTasksByUser(user);
        }

        public TaskModel GetTaskByID(long id)
        {
            return context.FindTask(id);
        }

        public void InsertTask(TaskModel student)
        {
            context.AddTask(student);
        }

        public void DeleteTask(long taskID)
        {
            context.RemoveTask(taskID);
        }

        public void UpdateTask(TaskModel task)
        {
            context.UpdateTask(task);
        }
    }
}