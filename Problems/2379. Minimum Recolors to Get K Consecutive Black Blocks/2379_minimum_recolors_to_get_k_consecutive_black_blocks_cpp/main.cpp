#include <iostream>

using namespace std;

int minimumRecolors(string blocks, int k) {
    short white = 0;

    short i = blocks.length() - 1;
    short n = i - k;
    for(i; i > n; --i) {
        if(blocks[i] == 'W') {
            ++white;
        }
    }

    n = white;

    for(i; i > -1; --i) {
        if(blocks[i] == 'W') {
            if(blocks[i + k] == 'B') {
                ++white;
            }
        } else if(blocks[i + k] == 'W' && --white < n) {
            --n;
        }
    }

    return n;
}

void test(string blocks, int k, int expected) {
    cout << "Blocks: " << blocks << endl;

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minimumRecolors(blocks, k) << endl;

    cout << endl;
}

int main() {
    test("WBBWWBBWBW", 7, 3);
    test("WBWBBBW", 2, 0);
    test("WWWWWWWW", 4, 4);
    test("BBBBBB", 6, 0);
    test("BWBWBWBW", 3, 1);
    test("WWBWWBWWB", 5, 3);

    return 0;
}
