#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

class FreqStack {
    private:
        map<short, map<short, int>> frequencies;
        unordered_map<int, short> elements;
        unordered_map<int, vector<short>> positions;
        short position;

    public:
        FreqStack() : position(-1) {}

        void push(int val) {
            short frequency = ++elements[val];

            if(frequency > 1) {
                frequencies[frequency - 1].erase(positions[val].back());

                if(frequencies[frequency - 1].empty()) {
                    frequencies.erase(frequency - 1);
                }
            }

            frequencies[frequency][++position] =val;
            positions[val].push_back(position);
        }

        int pop() {
            int val = frequencies.rbegin()->second.rbegin()->second;
            short frequency = --elements[val];
            short previousPosition = positions[val].back();

            frequencies[frequency + 1].erase(previousPosition);

            if(frequencies[frequency + 1].empty()) {
                frequencies.erase(frequency + 1);
            }

            if(frequency < 1) {
                elements.erase(val);
                positions.erase(val);
            } else {
                positions[val].pop_back();
                previousPosition = positions[val].back();

                frequencies[frequency][previousPosition] = val;
            }

            return val;
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

    FreqStack* freqStack;

    vector<string> results;
    for(int i = 0; i < commands.size(); i++) {
        if(commands[i] == "FreqStack") {
            freqStack = new FreqStack();
            results.push_back("null");
        } else if(commands[i] == "push") {
            freqStack->push(inputs[i][0]);
            results.push_back("null");
        } else if(commands[i] == "pop") {
            results.push_back(to_string(freqStack->pop()));
        }
    }

    cout << "Expected: ";
    printArray(expected);

    cout << "Results: ";
    printArray(results);

    cout << endl;
}

int main() {
    test({"FreqStack", "push", "push", "push", "push", "push", "push", "pop", "pop", "pop", "pop"}, {{}, {5}, {7}, {5}, {7}, {4}, {5}, {}, {}, {}, {}}, {"null", "null", "null", "null", "null", "null", "null", "5", "7", "5", "4"});
    test({"FreqStack", "push", "pop"}, {{}, {5}, {}}, {"null", "null", "5"});
    test({"FreqStack", "push", "push", "pop"}, {{}, {7}, {8}, {}}, {"null", "null", "null", "8"});
    test({"FreqStack", "push", "push", "pop", "pop"}, {{}, {5}, {5}, {}, {}}, {"null", "null", "null", "5", "5"});
    test({"FreqStack", "push", "push", "pop"}, {{}, {3}, {4}, {}}, {"null", "null", "null", "4"});

    return 0;
}
