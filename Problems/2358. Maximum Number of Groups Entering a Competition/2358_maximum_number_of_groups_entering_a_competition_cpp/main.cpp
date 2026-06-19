#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int maximumGroups(vector<int>& grades) {
    return ((1 + sqrt(1 + 8 * grades.size())) / 2) - 1;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> grades, int expected) {
    cout << "Grades: ";
    printArray(grades);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maximumGroups(grades) << endl;

    cout << endl;
}

int main() {
    test({10, 6, 12, 7, 3, 5}, 3);
    test({8, 8}, 1);
    test({1}, 1);
    test({1, 2, 3, 4, 5, 6}, 3);
    test({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 4);

    return 0;
}
