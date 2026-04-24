#include <iostream>

using namespace std;

int furthestDistanceFromOrigin(string moves) {
    short left = 0;
    short right = 0;

    short n = moves.length();
    for(short i = n - 1; i > -1; --i) {
        if(moves[i] == 'L') {
            ++left;
        } else if(moves[i] == 'R') {
            ++right;
        }
    }

    return n - (min(left, right) << 1);
}

void test(string moves, int expected) {
    cout << "Moves: " << moves << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << furthestDistanceFromOrigin(moves) << endl;

    cout << endl;
}

int main() {
    test("L_RL__R", 3);
    test("_R__LL_", 5);
    test("_______", 7);
    test("L", 1);
    test("R", 1);
    test("_", 1);
    test("LR", 0);

    return 0;
}
