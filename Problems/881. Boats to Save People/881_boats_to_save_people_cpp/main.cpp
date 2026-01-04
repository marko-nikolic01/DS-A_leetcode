#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numRescueBoats(vector<int>& people, int limit) {
    int boats = 0;

    sort(people.begin(), people.end());

    int i = 0;
    for(int j = people.size() - 1; i <= j; --j) {
        if(people[i] + people[j] <= limit) {
            ++i;
        }

        ++boats;
    }

    return boats;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> people, int limit, int expected) {
    cout << "People: ";
    printArray(people);

    cout << "Limit: " << limit << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << numRescueBoats(people, limit) << endl;

    cout << endl;
}

int main() {
    test({1, 2}, 3, 1);
    test({3, 2, 2, 1}, 3, 3);
    test({3, 5, 3, 4}, 5, 4);
    test({2, 2, 2, 2}, 3, 4);
    test({1, 1, 1, 1, 1}, 2, 3);

    return 0;
}
