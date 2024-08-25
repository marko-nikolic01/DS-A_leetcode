#include <iostream>
#include <vector>

using namespace std;

bool isOneBitCharacter(vector<int>& bits) {
    int n = bits.size() - 2;

    if(n == -1 || bits[n--] == 0) {
        return true;
    }

    int counter = 1;
    for(n; n > -1; --n) {
        if(bits[n] == 0) {
            break;
        } else {
            counter++;
        }
    }

    return counter % 2 ==0;
}

void printTestCase(vector<int>& bits, bool expected) {
    cout << "Input: ";
    for (int bit : bits) {
        cout << bit << " ";
    }
    cout << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (isOneBitCharacter(bits) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    vector<int> test1 = {1, 0, 0};
    vector<int> test2 = {1, 1, 1, 0};
    vector<int> test3 = {1, 0, 1, 0};
    vector<int> test4 = {0};
    vector<int> test5 = {1, 0};
    vector<int> test6 = {1, 1, 0};
    vector<int> test7 = {1, 0, 1, 1, 0};

    printTestCase(test1, true);
    printTestCase(test2, false);
    printTestCase(test3, false);
    printTestCase(test4, true);
    printTestCase(test5, false);
    printTestCase(test6, true);
    printTestCase(test7, true);

    return 0;
}
