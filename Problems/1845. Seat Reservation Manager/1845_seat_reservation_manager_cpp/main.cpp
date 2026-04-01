#include <iostream>
#include <vector>
#include <set>

using namespace std;

class SeatManager {
    private:
        set<int> seats;

    public:
        SeatManager(int n) {
            while(n > 0) {
                seats.insert(n--);
            }
        }

        int reserve() {
            int seat = *seats.begin();

            seats.erase(seat);

            return seat;
        }

        void unreserve(int seatNumber) {
            seats.insert(seatNumber);
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

    SeatManager* seatManager;

    vector<string> results;
    for(int i = 0; i < commands.size(); i++) {
        if(commands[i] == "SeatManager") {
            seatManager = new SeatManager(inputs[i][0]);
            results.push_back("null");
        } else if(commands[i] == "reserve") {
            results.push_back(to_string(seatManager->reserve()));
        } else if(commands[i] == "unreserve") {
            seatManager->unreserve(inputs[i][0]);
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
    test({"SeatManager", "reserve", "reserve", "unreserve", "reserve", "reserve", "reserve", "reserve", "unreserve"}, {{5}, {}, {}, {2}, {}, {}, {}, {}, {5}}, {"null", "1", "2", "null", "2", "3", "4", "5", "null"});
    test({"SeatManager", "reserve"}, {{1}, {}}, {"null", "1"});
    test({"SeatManager", "reserve", "unreserve", "reserve"}, {{1}, {}, {1}, {}}, {"null", "1", "null", "1"});
    test({"SeatManager", "reserve", "reserve"}, {{3}, {}, {}}, {"null", "1", "2"});
    test({"SeatManager", "reserve", "unreserve", "reserve", "reserve"}, {{3}, {}, {1}, {}, {}}, {"null", "1", "null", "1", "2"});

    return 0;
}
