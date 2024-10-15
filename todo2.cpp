#include<iostream>
#include<string>
using namespace std;



struct Task {
    std::string description;
    Task* next;
};


void addTask(Task*& head, const std::string& taskDescription) {
    Task* newTask = new Task;
    newTask->description = taskDescription;
    newTask->next = nullptr;

    if (head == nullptr) {
        head = newTask;
    } else {
        Task* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newTask;
    }
}


void viewTasks(Task* head) {
    Task* temp = head;
    while (temp != nullptr) {
        std::cout << temp->description << std::endl;
        temp = temp->next;
    }
}

void deleteTask(Task*& head, const std::string& taskDescription) {
    Task* temp = head;
    Task* prev = nullptr;

    if (temp != nullptr && temp->description == taskDescription) {
        head = temp->next;
        delete temp;
        return;
    }

    while (temp != nullptr && temp->description != taskDescription) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        return;
    }

    prev->next = temp->next;
    delete temp;
}

int main() {
    Task* head = nullptr;
    std::string taskDescription;

    while (true) {
        std::cout << "To-Do List Manager\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Delete Task\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter task description: ";
                std::cin.ignore();
                std::getline(std::cin, taskDescription);
                addTask(head, taskDescription);
                break;
            case 2:
                std::cout << "Tasks:\n";
                viewTasks(head);
                break;
            case 3:
                std::cout << "Enter task description to delete: ";
                std::cin.ignore();
                std::getline(std::cin, taskDescription);
                deleteTask(head, taskDescription);
                break;
            case 4:
                std::cout << "Exiting..." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}