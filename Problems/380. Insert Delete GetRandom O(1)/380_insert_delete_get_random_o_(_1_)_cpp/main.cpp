#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class RandomizedSet {
    private:
        vector<int> v;
        unordered_map<int, int> mp;

    public:
        RandomizedSet() {}

        bool insert(int val) {
            if(mp.find(val) != mp.end()) {
                return false;
            }

            v.push_back(val);
            mp[val] = v.size() - 1;

            return true;
        }


        bool remove(int val) {
            if(mp.find(val) == mp.end()) {
                return false;
            }

            unordered_map<int, int>::iterator it = mp.find(val);

            v[it->second] = v.back();
            v.pop_back();
            mp[v[it->second]] = it->second;
            mp.erase(val);

            return true;
        }


        int getRandom() {
            return v[rand() % v.size()];
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

    RandomizedSet* randomizedSet;

    vector<string> results;
    for(int i = 0; i < commands.size(); i++) {
        if(commands[i] == "RandomizedSet") {
            randomizedSet = new RandomizedSet();
            results.push_back("null");
        } else if(commands[i] == "insert") {
            results.push_back((randomizedSet->insert(inputs[i][0])) ? "true" : "false");
        } else if(commands[i] == "remove") {
            results.push_back((randomizedSet->remove(inputs[i][0])) ? "true" : "false");
        } else if(commands[i] == "getRandom") {
            results.push_back(to_string(randomizedSet->getRandom()));
        }
    }

    cout << "Expected: ";
    printArray(expected);

    cout << "Results: ";
    printArray(results);

    cout << endl;
}

int main() {
    test({"RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"}, {{}, {1}, {2}, {2}, {}, {1}, {2}, {}}, {"null", "true", "false", "true", "2", "true", "false", "2"});
    test({"RandomizedSet", "insert", "insert", "getRandom", "getRandom"}, {{}, {5}, {10}, {}, {}}, {"null", "true", "true", "10", "10"});
    test({"RandomizedSet", "insert", "insert", "remove"}, {{}, {1}, {2}, {1}}, {"null", "true", "true", "true"});
    test({"RandomizedSet", "insert", "insert", "insert", "remove", "getRandom"}, {{}, {3}, {3}, {5}, {3}, {}}, {"null", "true", "false", "true", "true", "5"});
    test({"RandomizedSet", "insert", "getRandom", "insert", "getRandom"}, {{}, {7}, {}, {7}, {}}, {"null", "true", "7", "false", "7"});

    return 0;
}
