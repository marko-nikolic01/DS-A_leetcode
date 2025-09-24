#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool canCross(vector<int>& stones) {
    unordered_map<int, unordered_set<int>> stoneJumps;
    unordered_map<int, unordered_set<int>>::iterator stoneJump;
    stoneJumps[0].insert(1);

    unordered_set<int>::iterator it;
    short n = stones.size() - 1;
    for(short i = 0; i <= n; ++i) {
        stoneJump = stoneJumps.find(stones[i]);

        if(stoneJump == stoneJumps.end()) {
            continue;
        }

        for(it = stoneJump->second.begin(); it != stoneJump->second.end(); ++it) {
            if(stones[i] + *it > stones[n]) {
                continue;
            }

            if(*it > 1) {
                stoneJumps[stones[i] + *it].insert(*it - 1);
            }
            stoneJumps[stones[i] + *it].insert(*it);
            stoneJumps[stones[i] + *it].insert(*it + 1);
        }
    }

    return !stoneJumps[stones[n]].empty();
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> stones, bool expected) {
    cout << "Stones: ";
    printArray(stones);

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (canCross(stones) ? "true" : "false") << endl;

    cout << endl;
}


int main() {
    test({0, 1, 3, 5, 6, 8, 12, 17}, true);
    test({0, 1, 2, 3, 4, 8, 9, 11}, false);
    test({0, 1}, true);
    test({0, 2}, false);
    test({0, 1, 2, 3, 5, 8, 13, 21}, false);

    return 0;
}
