#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

class EventManager {
    private:
        map<int, set<int>> priorities;
        unordered_map<int, int> eventPriorities;

        void addEvent(int eventId, int priority) {
            priorities[priority].insert(eventId);
            eventPriorities[eventId] = priority;
        }

        void removeEvent(int eventId) {
            int priority = eventPriorities[eventId];

            priorities[priority].erase(eventId);
            if(priorities[priority].empty()) {
                priorities.erase(priority);
            }

            eventPriorities.erase(eventId);
        }

    public:
        EventManager(vector<vector<int>>& events) {
            for(int i = events.size() - 1; i > -1; --i) {
                addEvent(events[i][0], events[i][1]);
            }
        }

        void updatePriority(int eventId, int newPriority) {
            removeEvent(eventId);
            addEvent(eventId, newPriority);
        }

        int pollHighest() {
            if(priorities.empty()) {
                return -1;
            }

            int eventId = *priorities.rbegin()->second.begin();

            removeEvent(eventId);

            return eventId;
        }
};

void printArray(vector<string> array) {
    for(string a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<string> commands, vector<vector<vector<int>>> inputs, vector<string> expected) {
    cout << "Commands: ";
    printArray(commands);

    cout << "Inputs: ";
    for(int i = 0; i < inputs.size(); ++i) {
        cout << "[";
        for(int j = 0; j < inputs[i].size(); ++j) {
            cout << "[";
            for(int k = 0; k < inputs[i][j].size(); ++k) {
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

    EventManager* eventManager;

    vector<string> results;
    for(int i = 0; i < commands.size(); i++) {
        if(commands[i] == "EventManager") {
            eventManager = new EventManager(inputs[i]);
            results.push_back("null");
        } else if(commands[i] == "updatePriority") {
            eventManager->updatePriority(inputs[i][0][0], inputs[i][0][1]);
            results.push_back("null");
        } else if(commands[i] == "pollHighest") {
            results.push_back(to_string(eventManager->pollHighest()));
        }
    }

    cout << "Expected: ";
    printArray(expected);

    cout << "Results: ";
    printArray(results);

    cout << endl;
}

int main() {
    test({"EventManager", "pollHighest", "updatePriority", "pollHighest", "pollHighest"}, {{{5,7},{2,7},{9,4}}, {}, {{9,7}}, {}, {}}, {"null", "2", "null", "5", "9"});
    test({"EventManager", "pollHighest", "pollHighest", "pollHighest"}, {{{4,1},{7,2}}, {}, {}, {}}, {"null", "7", "4", "-1"});
    test({"EventManager", "pollHighest", "pollHighest"}, {{{1,1}}, {}, {}}, {"null", "1", "-1"});
    test({"EventManager", "pollHighest", "pollHighest"}, {{{3,5},{1,5}}, {}, {}}, {"null", "1", "3"});
    test({"EventManager", "updatePriority", "pollHighest"}, {{{1,1},{2,2}}, {{1,10}}, {}}, {"null", "null", "1"});

    return 0;
}
