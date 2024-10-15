#include "Task.h"

Task::Task(const std::string& description) : description(description), complete(false) {}

std::string Task::getDescription() const {
    return description;
}

bool Task::isComplete() const {
    return complete;
}

void Task::markAsComplete() {
    complete = true;
}

void Task::markAsIncomplete() {
    complete = false;
}
