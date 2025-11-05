#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class RecentCounter {
    private:
        queue<int> requests;
    public:
        RecentCounter() {}

        int ping(int t) {
            requests.push(t);

            while(requests.front() + 3000 < t) {
                requests.pop();
            }

            return requests.size();
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

    RecentCounter* recentCounter;

    vector<string> results;
    for(int i = 0; i < commands.size(); i++) {
        if(commands[i] == "RecentCounter") {
            recentCounter = new RecentCounter();
            results.push_back("null");
        } else if(commands[i] == "ping") {
            results.push_back(to_string(recentCounter->ping(inputs[i][0])));
        }
    }

    cout << "Expected: ";
    printArray(expected);

    cout << "Results: ";
    printArray(results);

    cout << endl;
}

int main() {
    test({"RecentCounter", "ping", "ping", "ping", "ping"}, {{}, {1}, {100}, {3001}, {3002}}, {"null", "1", "2", "3", "3"});
    test({"RecentCounter", "ping", "ping", "ping"}, {{}, {50}, {3050}, {6100}}, {"null", "1", "2", "1"});
    test({"RecentCounter", "ping", "ping", "ping", "ping"}, {{}, {10}, {3010}, {3020}, {6000}}, {"null", "1", "2", "2", "3"});
    test({"RecentCounter", "ping", "ping"}, {{}, {1000}, {2000}}, {"null", "1", "2"});
    test({"RecentCounter", "ping", "ping", "ping", "ping", "ping"}, {{}, {5}, {6}, {7}, {5000}, {8000}}, {"null", "1", "2", "3", "1", "2"});

    return 0;
}
