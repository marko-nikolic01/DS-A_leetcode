#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

class LFUCache {
    private:
        unordered_map<int, list<pair<int, int>>> frequencies;
        unordered_map<int, pair<int, list<pair<int, int>>::iterator>> cache;
        int capacity;
        int minf;

        void insert(int key, int frequency, int value) {
            frequencies[frequency].push_back({key, value});
            cache[key] = {frequency, --frequencies[frequency].end()};
        }

    public:
        LFUCache(int capacity) : capacity(capacity), minf(0) {}

        int get(int key) {
            const auto it = cache.find(key);

            if(it == cache.end()) {
                return -1;
            }

            const int f = it->second.first;
            const auto iter = it->second.second;
            const pair<int, int> kv = *iter;

            frequencies[f].erase(iter);

            if(frequencies[f].empty()) {
                frequencies.erase(f);

                if(minf == f) {
                    ++minf;
                }
            }

            insert(key, f + 1, kv.second);

            return kv.second;
        }

        void put(int key, int value) {
            if(capacity <= 0) {
                return;
            }

            const auto it = cache.find(key);

            if(it != cache.end()) {
                it->second.second->second = value;
                get(key);

                return;
            }

            if(capacity == cache.size()) {
                cache.erase(frequencies[minf].front().first);
                frequencies[minf].pop_front();

                if(frequencies[minf].empty()) {
                    frequencies.erase(minf);
                }
            }

            minf = 1;
            insert(key, 1, value);
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

    LFUCache* lfuCache;

    vector<string> results;
    for(int i = 0; i < commands.size(); i++) {
        if(commands[i] == "LFUCache") {
            lfuCache = new LFUCache(inputs[i][0]);
            results.push_back("null");
        } else if(commands[i] == "get") {
            results.push_back(to_string(lfuCache->get(inputs[i][0])));
        } else if(commands[i] == "put") {
            lfuCache->put(inputs[i][0], inputs[i][1]);
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
    test({"LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"}, {{2}, {1, 1}, {2, 2}, {1}, {3, 3}, {2}, {3}, {4, 4}, {1}, {3}, {4}}, {"null", "null", "null", "1", "null", "-1", "3", "null", "-1", "3", "4"});
    test({"LFUCache", "put", "get", "put", "get", "get"}, {{1}, {1, 1}, {1}, {2, 2}, {1}, {2}}, {"null", "null", "1", "null", "-1", "2"});
    test({"LFUCache", "put", "put", "put", "get", "get", "get"}, {{3}, {1, 1}, {2, 2}, {3, 3}, {1}, {2}, {3}}, {"null", "null", "null", "null", "1", "2", "3"});
    test({"LFUCache", "put", "put", "get", "put", "get"}, {{2}, {1, 10}, {1, 20}, {1}, {2, 30}, {2}}, {"null", "null", "null", "20", "null", "30"});
    test({"LFUCache", "get", "put", "get"}, {{0}, {1}, {1, 1}, {1}}, {"null", "-1", "null", "-1"});

    return 0;
}
