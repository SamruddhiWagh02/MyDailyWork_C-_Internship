#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

void displayMenu() {
    cout << "\nTo-Do List Manager\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
}

void addTask(vector<Task>& tasks) {
    Task newTask;
    cout << "Enter the task description: ";
    cin.ignore(); 
    getline(cin, newTask.description);
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "Task '" << newTask.description << "' added successfully!" << endl;
}

void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to show." << endl;
        return;
    }

    cout << "\nTasks:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].description 
             << " - " << (tasks[i].completed ? "Completed" : "Pending") << endl;
    }
}

void markTaskCompleted(vector<Task>& tasks) {
    viewTasks(tasks);
    size_t taskIndex;
    cout << "Enter the number of the task to mark as completed: ";
    cin >> taskIndex;
    if (taskIndex > 0 && taskIndex <= tasks.size()) {
        --taskIndex; // Convert to 0-based index
        tasks[taskIndex].completed = true;
        cout << "Task '" << tasks[taskIndex].description << "' marked as completed!" << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

void removeTask(vector<Task>& tasks) {
    viewTasks(tasks);
    size_t taskIndex;
    cout << "Enter the number of the task to remove: ";
    cin >> taskIndex;
    if (taskIndex > 0 && taskIndex <= tasks.size()) {
        --taskIndex; // Convert to 0-based index
        cout << "Task '" << tasks[taskIndex].description << "' removed successfully!" << endl;
        tasks.erase(tasks.begin() + taskIndex);
    } else {
        cout << "Invalid task number." << endl;
    }
}

int main() {
    vector<Task> tasks;
    int choice;

    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "Exiting... Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
        }
    }

    return 0;
}
