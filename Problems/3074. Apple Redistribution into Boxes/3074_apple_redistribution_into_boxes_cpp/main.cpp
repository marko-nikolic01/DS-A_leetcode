#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
    short apples = 0;

    sort(capacity.begin(), capacity.end(), greater<int>());

    short i;
    for(i = apple.size() - 1; i > -1; --i) {
        apples += apple[i];
    }

    for(++i; apples > 0; ++i) {
        apples -= capacity[i];
    }

    return i;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> apple, vector<int> capacity, int expected) {
    cout << "Apples: ";
    printArray(apple);

    cout << "Capacities: ";
    printArray(capacity);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minimumBoxes(apple, capacity) << endl;

    cout << endl;
}

int main() {
    test({1, 3, 2}, {4, 3, 1, 5, 2}, 2);
    test({5, 5, 5}, {2, 4, 2, 7}, 4);
    test({10}, {3, 3, 3, 3, 3}, 4);
    test({2, 2, 2, 2}, {1, 1, 1, 1, 10}, 1);
    test({4, 6, 1}, {2, 2, 2, 2, 2, 2}, 6);
    test({1}, {1}, 1);

    return 0;
}
