#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class NumberContainers {
    private:
        unordered_map<int, int> container;
        unordered_map<int, set<int>> numberOccurences;

    public:
        NumberContainers() {}

        void change(int index, int number) {
            if(container.find(index) != container.end()) {
                numberOccurences[container[index]].erase(index);
            }

            container[index] = number;
            numberOccurences[number].insert(index);
        }

        int find(int number) {
            return numberOccurences[number].empty() ? -1 : *numberOccurences[number].begin();
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
    for(string command : commands) {
        cout << command << " ";
    }
    cout << endl;

    cout << "Inputs: ";
    for(vector<int> input : inputs) {
        cout << "[";
        for(int i = 0; i < input.size(); i++) {
            cout << input[i];
            if (i != input.size() - 1) {
                cout << " ";
            }
        }
        cout << "] ";
    }
    cout << endl;

    NumberContainers* numberContainers;

    vector<string> results;
    for(int i = 0; i < commands.size(); i++) {
        if(commands[i] == "NumberContainers") {
            numberContainers = new NumberContainers();
            results.push_back("null");
        } else if(commands[i] == "find") {
            results.push_back(to_string(numberContainers->find(inputs[i][0])));
        } else if(commands[i] == "change") {
            numberContainers->change(inputs[i][0], inputs[i][1]);
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
    test({"NumberContainers", "find", "change", "change", "change", "change", "find", "change", "find"}, {{}, {10}, {2, 10}, {1, 10}, {3, 10}, {5, 10}, {10}, {1, 20}, {10}}, {"null", "-1", "null", "null", "null", "null", "1", "null", "2"});
    test({"NumberContainers", "change", "change", "find", "change", "find", "find"}, {{}, {5, 50}, {7, 50}, {50}, {5, 100}, {50}, {100}}, {"null", "null", "null", "5", "null", "7", "5"});
    test({"NumberContainers", "change", "change", "find", "find"}, {{}, {10, 200}, {10, 300}, {200}, {300}}, {"null", "null", "null", "-1", "10"});
    test({"NumberContainers", "find"}, {{}, {500}}, {"null", "-1"});
    test({"NumberContainers", "change", "change", "change", "find", "find", "find"}, {{}, {2, 10}, {2, 20}, {2, 30}, {10}, {20}, {30}}, {"null", "null", "null", "null", "-1", "-1", "2"});

    return 0;
}

