#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class RideSharingSystem {
    private:
        queue<short> riders;
        queue<short> drivers;
        vector<bool> cancellations;

    public:
        RideSharingSystem() : cancellations(1001, false) {}

        void addRider(int riderId) {
            riders.push(riderId);
            cancellations[riderId] = false;
        }

        void addDriver(int driverId) {
            drivers.push(driverId);
        }

        vector<int> matchDriverWithRider() {
            while(!riders.empty() && cancellations[riders.front()]) {
                riders.pop();
            }

            if(riders.empty() || drivers.empty()) {
                return {-1, -1};
            }

            vector<int> match = {drivers.front(), riders.front()};
            riders.pop();
            drivers.pop();

            return match;
        }

        void cancelRider(int riderId) {
            cancellations[riderId] = true;
        }
};

void printArray(vector<string> array) {
    for(string a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<string> commands, vector<vector<int>> inputs, vector<string> expected) {
    cout << "Commands: ";
    printArray(commands);

    cout << "Inputs: ";
    for(int i = 0; i < inputs.size(); ++i) {
        cout << "[";
        for(int j = 0; j < inputs[i].size(); ++j) {
            cout << inputs[i][j];
            if(j != inputs[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "] ";
    }
    cout << endl;

    RideSharingSystem* rideSharingSystem;

    vector<string> results;
    for(int i = 0; i < commands.size(); i++) {
        if(commands[i] == "RideSharingSystem") {
            rideSharingSystem = new RideSharingSystem();
            results.push_back("null");
        } else if(commands[i] == "addRider") {
            rideSharingSystem->addRider(inputs[i][0]);
            results.push_back("null");
        } else if(commands[i] == "addDriver") {
            rideSharingSystem->addDriver(inputs[i][0]);
            results.push_back("null");
        } else if(commands[i] == "matchDriverWithRider") {
            vector<int> result = rideSharingSystem->matchDriverWithRider();
            results.push_back("[" + to_string(result[0]) + ", " + to_string(result[1]) + "]");
        } else if(commands[i] == "cancelRider") {
            rideSharingSystem->cancelRider(inputs[i][0]);
            results.push_back("null");
        }
    }

    cout << "Expected: ";
    printArray(expected);

    cout << "Results: ";
    printArray(results);

    cout << endl;
}

int main() {
    test({"RideSharingSystem", "addRider", "addDriver", "addRider", "matchDriverWithRider", "addDriver", "cancelRider", "matchDriverWithRider", "matchDriverWithRider"}, {{}, {3}, {2}, {1}, {}, {5}, {3}, {}, {}}, {"null", "null", "null", "null", "[2, 3]", "null", "null", "[5, 1]", "[-1, -1]"});
    test({"RideSharingSystem", "addRider", "addDriver", "addDriver", "matchDriverWithRider", "addRider", "cancelRider", "matchDriverWithRider"}, {{}, {8}, {8}, {6}, {}, {2}, {2}, {}}, {"null", "null", "null", "null", "[8, 8]", "null", "null", "[-1, -1]"});
    test({"RideSharingSystem", "addDriver", "cancelRider", "addRider", "matchDriverWithRider"}, {{}, {2}, {1}, {1}, {}}, {"null", "null", "null", "null", "[2, 1]"});
    test({"RideSharingSystem", "addRider", "addDriver", "matchDriverWithRider"}, {{}, {10}, {20}, {}}, {"null", "null", "null", "[20, 10]"});
    test({"RideSharingSystem", "addRider", "cancelRider", "addDriver", "matchDriverWithRider"}, {{}, {4}, {4}, {7}, {}}, {"null", "null", "null", "null", "[-1, -1]"});

    return 0;
}
