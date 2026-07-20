#include <iostream>
#include <vector>

using namespace std;

bool canReach(vector<int>& start, vector<int>& target) {
    return ((start[0] + target[0] + start[1] + target[1]) & 1) < 1;
}

void test(vector<int> start, vector<int> target, bool expected) {
    cout << "Start: " << "[" << start[0] << ", " << start[1] << "]" << endl;

    cout << "Target: " << "[" << target[0] << ", " << target[1] << "]" << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (canReach(start, target) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test({1, 1}, {2, 2}, true);
    test({4, 5}, {6, 6}, false);
    test({0, 0}, {0, 0}, true);
    test({0, 0}, {1, 0}, false);
    test({7, 7}, {0, 0}, true);

    return 0;
}
