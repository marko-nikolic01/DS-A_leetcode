#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
    int n = positions.size();
    vector<int> robots(n);

    int i;
    for(i = n - 1; i > -1; --i) {
        robots[i] = i;
    }

    sort(robots.begin(), robots.end(), [&](int& a, int& b) {
        return positions[a] < positions[b];
    });
    positions.resize(0);

    for(i = 0; i < n; ++i) {
        if(directions[robots[i]] == 'R') {
            positions.push_back(robots[i]);
        } else {
            while(!positions.empty()) {
                if(healths[robots[i]] > healths[positions.back()]) {
                    --healths[robots[i]];
                    healths[positions.back()] = 0;
                    positions.pop_back();
                } else if(healths[robots[i]] < healths[positions.back()]) {
                    healths[robots[i]] = 0;
                    --healths[positions.back()];
                    break;
                } else {
                    healths[robots[i]] = 0;
                    healths[positions.back()] = 0;
                    positions.pop_back();
                    break;
                }
            }
        }
    }

    int j = 0;
    for(i = 0; i < n; ++i) {
        if(healths[i] > 0) {
            healths[j++] = healths[i];
        }
    }

    healths.resize(j);

    return healths;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> positions, vector<int> healths, string directions, vector<int> expected) {
    cout << "Positions: ";
    printArray(positions);

    cout << "Healths: ";
    printArray(healths);

    cout << "Directions: " << directions << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(survivedRobotsHealths(positions, healths, directions));

    cout << endl;
}

int main() {
    test({5, 4, 3, 2, 1}, {2, 17, 9, 15, 10}, "RRRRR", {2, 17, 9, 15, 10});
    test({1, 2, 5, 6}, {10, 10, 11, 11}, "RLRL", {});
    test({3, 5, 2, 6}, {10, 10, 15, 12}, "RLRL", {14});
    test({3, 47}, {46, 26}, "LR", {46, 26});
    test({3, 8, 10, 15}, {5, 8, 6, 9}, "RLLR", {7, 6, 9});

    return 0;
}
