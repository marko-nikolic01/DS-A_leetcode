#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool isNStraightHand(vector<int>& hand, int groupSize) {
    if(groupSize < 2) {
        return true;
    }

    vector<pair<int, short>> groups;
    unordered_map<short, vector<int>> next;
    short group;

    sort(hand.begin(), hand.end());

    for(short i = hand.size() - 1; i > -1; --i) {
        if(next.find(hand[i]) != next.end()) {
            group = next[hand[i]].back();
            next[hand[i]].pop_back();

            if(next[hand[i]].empty()) {
                next.erase(hand[i]);
            }

            --groups[group].first;

            if(++groups[group].second < groupSize) {
                next[groups[group].first].push_back(group);
            }
        } else {
            groups.push_back({--hand[i], 1});
            next[hand[i]].push_back(groups.size() - 1);
        }
    }

    return next.empty();
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> hand, int groupSize, bool expected) {
    cout << "Hand: ";
    printArray(hand);

    cout << "Group size: " << groupSize << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (isNStraightHand(hand, groupSize) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test({1, 2, 3, 6, 2, 3, 4, 7, 8}, 3, true);
    test({1, 2, 3, 4, 5}, 4, false);
    test({1, 2, 3, 3, 4, 4, 5, 6}, 4, true);
    test({3, 2, 1, 2, 3, 4, 3, 4, 5, 9, 10, 11}, 3, true);
    test({1, 2, 3, 4}, 3, false);
    test({1, 2, 3}, 1, true);
    test({1, 1, 2, 2, 3, 3}, 3, true);
    test({1, 2, 3, 4, 5, 6}, 4, false);

    return 0;
}
