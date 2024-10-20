#include <iostream>
#include <vector>

using namespace std;

int finalValueAfterOperations(vector<string>& operations) {
    int x = 0;

    for(int i = operations.size() - 1; i > -1; --i) {
        if(operations[i][1] == '+') {
            x++;
        } else {
            x--;
        }
    }

    return x;
}

void runTestCase(vector<string> operations, int expected) {
    cout << "Operations: ";
    for (string op : operations) {
        cout << op << " ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << finalValueAfterOperations(operations) << endl;

    cout << endl;
}

int main() {
    runTestCase({"--X", "X++", "X++"}, 1);
    runTestCase({"++X", "++X", "X--"}, 1);
    runTestCase({"X++", "++X", "--X", "--X"}, 0);
    runTestCase({"++X", "--X", "X++", "X--"}, 0);
    runTestCase({"X++", "X++", "--X", "--X", "++X"}, 1);
    runTestCase({"X++", "X++", "++X"}, 3);
    runTestCase({"X--", "X--", "--X"}, -3);

    return 0;
}
