#include <iostream>
#include <vector>

using namespace std;

bool checkPowersOfThree(int n) {
    vector<int> powersOfThree = {4782969, 1594323, 531441, 177147, 59049, 19683, 6561, 2187, 729, 243, 81, 27, 9, 3, 1};

    for(short i = 0; i < 15; ++i) {
        if(powersOfThree[i] <= n) {
            n -= powersOfThree[i];
        }
    }

    return n == 0;
}

void test(int n, bool expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (checkPowersOfThree(n) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test(12, true);
    test(91, true);
    test(21, false);
    test(3, true);
    test(10, true);
    test(100, false);
    test(59048, false);

    return 0;
}
