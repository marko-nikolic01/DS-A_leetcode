#include <iostream>

using namespace std;

int maxDistance(string moves) {
    int x = 0;
    int y = 0;
    int any = 0;

    for(int i = moves.size() - 1; i > -1; --i) {
        if(moves[i] == 'U') {
            ++y;
        } else if(moves[i] == 'D') {
            --y;
        } else if(moves[i] == 'L') {
            --x;
        } else if(moves[i] == 'R') {
            ++x;
        } else {
            ++any;
        }
    }

    return abs(x) + abs(y) + any;
}

void test(string moves, int expected) {
    cout << "Moves: " << moves << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxDistance(moves) << endl;

    cout << endl;
}

int main() {
    test("L_D_", 4);
    test("U_R", 3);
    test("___", 3);
    test("UD_", 1);
    test("UDLR", 0);
    test("_DDDD", 5);

    return 0;
}
