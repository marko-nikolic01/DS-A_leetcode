#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

class TaskManager {
    private:
        unordered_map<int, int> taskUsers;
        unordered_map<int, int> taskPriorities;
        map<int, set<int>> tasksByPriority;

    public:
        TaskManager(vector<vector<int>>& tasks) {
            for(int i = tasks.size() - 1; i > -1; --i) {
                add(tasks[i][0], tasks[i][1], tasks[i][2]);
            }
        }

        void add(int userId, int taskId, int priority) {
            taskUsers[taskId] = userId;
            taskPriorities[taskId] = priority;
            tasksByPriority[priority].insert(taskId);
        }

        void edit(int taskId, int newPriority) {
            int userId = taskUsers[taskId];
            rmv(taskId);
            add(userId, taskId, newPriority);
        }

        void rmv(int taskId) {
            int priority = taskPriorities[taskId];
            taskUsers.erase(taskId);
            taskPriorities.erase(taskId);
            tasksByPriority[priority].erase(taskId);

            if(tasksByPriority[priority].empty()) {
                tasksByPriority.erase(priority);
            }
        }

        int execTop() {
            if(tasksByPriority.empty()) {
                return -1;
            }

            int taskId = *tasksByPriority.rbegin()->second.rbegin();
            int userId = taskUsers[taskId];
            rmv(taskId);

            return userId;
        }
};

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void printArray(vector<string> array) {
    for(string a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void testTaskManager(vector<string> commands, vector<vector<vector<int>>> inputs, vector<string> expected) {
    cout << "Commands: ";
    printArray(commands);

    cout << "Inputs: ";
    for(int i = 0; i < inputs.size(); i++) {
        cout << "[";
        for(int j = 0; j < inputs[i].size(); j++) {
            cout << "[";
            for(int k = 0; k < inputs[i][j].size(); k++) {
                cout << inputs[i][j][k];
                if(k != inputs[i][j].size() - 1) {
                    cout << ", ";
                }
            }
            cout << "]";
            if(j != inputs[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "] ";
    }
    cout << endl;

    TaskManager* taskManager;

    vector<string> results;
    for(int i = 0; i < commands.size(); i++) {
        if(commands[i] == "TaskManager") {
            taskManager = new TaskManager(inputs[i]);
            results.push_back("null");
        } else if(commands[i] == "add") {
            taskManager->add(inputs[i][0][0], inputs[i][0][1], inputs[i][0][2]);
            results.push_back("null");
        } else if(commands[i] == "edit") {
            taskManager->edit(inputs[i][0][0], inputs[i][0][1]);
            results.push_back("null");
        } else if(commands[i] == "rmv") {
            taskManager->rmv(inputs[i][0][0]);
            results.push_back("null");
        } else if(commands[i] == "execTop") {
            results.push_back(to_string(taskManager->execTop()));
        }
    }

    cout << "Expected: ";
    printArray(expected);

    cout << "Results: ";
    printArray(results);

    cout << endl;
}

int main() {
    testTaskManager({"TaskManager", "add", "edit", "execTop", "rmv", "add", "execTop"}, {{{1, 101, 10}, {2, 102, 20}, {3, 103, 15}}, {{4, 104, 5}}, {{102, 8}}, {}, {{101}}, {{5, 105, 15}}, {}}, {"null", "null", "null", "3", "null", "null", "5"});
    testTaskManager({"TaskManager", "execTop"}, {{{1, 100, 10}}, {}}, {"null", "1"});
    testTaskManager({"TaskManager", "add", "execTop"}, {{}, {{1, 101, 5}}, {}}, {"null", "null", "1"});
    testTaskManager({"TaskManager", "add", "rmv", "execTop"}, {{}, {{2, 102, 8}}, {{102}}, {}}, {"null", "null", "null", "-1"});
    testTaskManager({"TaskManager", "add", "add", "execTop"}, {{}, {{1, 101, 10}}, {{2, 102, 10}}, {}}, {"null", "null", "null", "2"});

    return 0;
}
