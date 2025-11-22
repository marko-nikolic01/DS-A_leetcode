#include <iostream>
#include <vector>

using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    short iStack = 0;
    short iPushed = 0;
    short n = pushed.size();
    for(short iPopped = 0; iPopped < n; ++iPopped) {
        if(iStack > -1 && pushed[iStack] == popped[iPopped]) {
            --iStack;
        } else {
            while(++iPushed < n && pushed[iPushed] != popped[iPopped]) {
                pushed[++iStack] = pushed[iPushed];
            }

            if(iPushed == n) {
                return false;
            }
        }
    }

    return true;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> pushed, vector<int> popped, bool expected) {
    cout << "Pushed: ";
    printArray(pushed);

    cout << "Popped: ";
    printArray(popped);

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (validateStackSequences(pushed, popped) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test({1, 2, 3, 4, 5}, {4, 5, 3, 2, 1}, true);
    test({1, 2, 3, 4, 5}, {4, 3, 5, 1, 2}, false);
    test({1}, {1}, true);
    test({2, 1, 0}, {1, 2, 0}, true);
    test({1, 2, 3}, {3, 1, 2}, false);

    return 0;
}
