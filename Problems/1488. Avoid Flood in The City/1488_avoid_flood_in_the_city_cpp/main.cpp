#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

vector<int> avoidFlood(vector<int>& rains) {
    int n = rains.size();
    vector<int> actions(n--);
    unordered_map<int, vector<int>> lakes;
    unordered_map<int, bool> isLakeFull;

    int i;
    for(i = n++; i > -1; --i) {
        if(rains[i] > 0) {
            lakes[rains[i]].push_back(i);
            isLakeFull[rains[i]] = false;
        }
    }

    priority_queue<int, vector<int>, greater<int>> dryings;

    unordered_map<int, vector<int>>::iterator it;
    for(i = 0; i < n; ++i) {
        if(rains[i] < 1) {
            if(!dryings.empty()) {
                actions[i] = rains[dryings.top()];
                isLakeFull[actions[i]] = false;
                dryings.pop();
            } else {
                actions[i] = lakes.begin()->first;
            }
        } else if(isLakeFull[rains[i]]) {
            return {};
        } else {
            actions[i] = -1;
            isLakeFull[rains[i]] = true;

            it = lakes.find(rains[i]);
            it->second.pop_back();

            if(!it->second.empty()) {
                dryings.push(it->second.back());
            }
        }
    }

    return actions;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> rains, vector<int> expected) {
    cout << "Rains: ";
    printArray(rains);

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(avoidFlood(rains));

    cout << endl;
}

int main() {
    test({1, 2, 3, 4}, {-1, -1, -1, -1});
    test({1, 2, 0, 0, 2, 1}, {-1, -1, 2, 1, -1, -1});
    test({1, 2, 0, 1, 2}, {});
    test({69, 0, 0, 0, 69}, {-1, 69, 69, 69, -1});
    test({1, 0, 2, 0, 2, 1}, {-1, 1, -1, 2, -1, -1});

    return 0;
}
