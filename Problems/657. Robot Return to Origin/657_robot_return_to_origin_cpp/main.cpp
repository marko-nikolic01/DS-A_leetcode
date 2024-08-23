#include <iostream>

using namespace std;

bool judgeCircle(string moves) {
    int x = 0;
    int y = 0;

    int n = moves.length();
    for(int i = 0; i < n; ++i) {
        if(moves[i] == 'U') {
            y++;
        } else if(moves[i] == 'D') {
            y--;
        } else if(moves[i] == 'R') {
            x++;
        } else {
            x--;
        }
    }

    return x == 0 && y == 0;
}

void runTest(string moves, bool expected) {
    bool result = judgeCircle(moves);
    cout << "Moves: " << moves << endl;
    cout << "Expected: " << (expected ? "true" : "false") << endl;
    cout << "Result: " << (result ? "true" : "false") << endl;
    cout << endl;
}

int main()
{
    runTest("UD", true);
    runTest("LL", false);
    runTest("RRDD", false);
    runTest("LDRRLRUULR", false);
    runTest("UDLR", true);

    return 0;
}
