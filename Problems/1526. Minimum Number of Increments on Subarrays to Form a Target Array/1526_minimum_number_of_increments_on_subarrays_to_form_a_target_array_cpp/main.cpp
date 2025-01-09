#include <iostream>
#include <vector>

using namespace std;

int minNumberOperations(vector<int>& target) {
    int max = target.back();
    int operations = 0;

    int n = target.size();
    for(int i = target.size() - 2; i > -1; --i) {
        if(target[i] < max) {
            operations += max - target[i];
        }

        max = target[i];
    }

    return operations + max;
}

void testFunction(vector<int> target, int expected) {
    cout << "Target: ";
    for(int t : target) {
        cout << t << " ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minNumberOperations(target) << endl;

    cout << endl;
}

int main() {
    testFunction({1, 2, 3, 2, 1}, 3);
    testFunction({3, 1, 1, 2}, 4);
    testFunction({3, 1, 5, 4, 2}, 7);
    testFunction({4, 3, 2, 1}, 4);
    testFunction({1, 1, 1, 1}, 1);
    testFunction({5, 1, 1, 1, 5}, 9);

    return 0;
}
