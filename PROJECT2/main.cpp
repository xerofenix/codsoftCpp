#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Task
{
private:
    string description;
    bool complete;

public:
    Task(const string &description);

    string getDescription() const;
    bool isComplete() const;
    void markAsComplete();
    void markAsIncomplete();
};

Task::Task(const std::string &description) : description(description), complete(false) {}

string Task::getDescription() const
{
    return description;
}

bool Task::isComplete() const
{
    return complete;
}

void Task::markAsComplete()
{
    complete = true;
}

void Task::markAsIncomplete()
{
    complete = false;
}

int main()
{
    vector<Task> tasks;

    while (true)
    {
        cout << "Todo List Application\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Complete\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";

        int choice;
        cin >> choice;

        if (choice == 1)
        {
            string description;
            cout << "Enter task description: ";
            cin.ignore(); // Clear the newline character from previous input
            getline(cin, description);

            Task newTask(description);
            tasks.push_back(newTask);

            cout << "Task added!\n";
        }
        else if (choice == 2)
        {
            cout << "Tasks:\n";
            for (const Task &task : tasks)
            {
                cout << task.getDescription() << " - " << (task.isComplete() ? "Complete" : "Incomplete") << endl;
            }
        }
        else if (choice == 3)
        {
            // Mark task as complete
            // ...
        }
        else if (choice == 4)
        {
            // Remove task
            // ...
        }
        else if (choice == 5)
        {
            cout << "Exiting...\n";
            break;
        }
        else
        {
            cout << "Invalid choice. Please choose a valid option.\n";
        }
    }

    return 0;
}
