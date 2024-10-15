#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
private:
    std::string description;
    bool complete;

public:
    Task(const std::string& description);

    std::string getDescription() const;
    bool isComplete() const;
    void markAsComplete();
    void markAsIncomplete();
};

#endif // TASK_H
