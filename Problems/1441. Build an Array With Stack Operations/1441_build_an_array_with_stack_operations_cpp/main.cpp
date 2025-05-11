#include <iostream>
#include <vector>

using namespace std;

vector<string> buildArray(vector<int>& target, int n) {
    vector<string> operations;
    short currentNumber = 1;

    n = target.size();
    for(short i = 0; i < n; ++i) {
        while(currentNumber++ < target[i]) {
            operations.push_back("Push");
            operations.push_back("Pop");
        }
        operations.push_back("Push");
    }

    return operations;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void printArray(vector<string> array) {
    for(string a : array) {
        cout << "\"" << a << "\"" << " ";
    }
    cout << endl;
}

void test(vector<int> target, int n, vector<string> expected) {
    cout << "Target: ";
    printArray(target);

    cout << "n: " << n << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(buildArray(target, n));

    cout << endl;
}

int main() {
    test({1, 3}, 3, {"Push", "Push", "Pop", "Push"});
    test({1, 2, 3}, 3, {"Push", "Push", "Push"});
    test({1, 2}, 4, {"Push", "Push"});
    test({2, 3, 4}, 4, {"Push", "Pop", "Push", "Push", "Push"});
    test({1, 3, 4}, 5, {"Push", "Push", "Pop", "Push", "Push"});
    return 0;
}
