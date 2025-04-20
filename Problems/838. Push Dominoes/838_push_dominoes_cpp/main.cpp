#include <iostream>

using namespace std;

string pushDominoes(string dominoes) {
    int previousFalling = 0;

    int j;
    int n = dominoes.size();
    for(int i = 0; i < n; ++i) {
        if(dominoes[i] == 'L') {
            if((previousFalling & 1) > 0) {
                dominoes[i - (previousFalling >> 1) - 1] = '.';
            }

            j = i;
            previousFalling >>= 1;
            while(previousFalling > 0) {
                dominoes[--j] = 'L';
                --previousFalling;
            }
        } else if(dominoes[i] == 'R') {
            previousFalling = 0;
            while(++i < n && dominoes[i] == '.') {
                dominoes[i] = 'R';
                ++previousFalling;
            }
            --i;
        } else {
            previousFalling += 2;
        }
    }

    return dominoes;
}

void test(string dominoes, string expected) {
    cout << "Dominoes: " << dominoes << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << pushDominoes(dominoes) << endl;

    cout << endl;
}

int main() {
    test("RR.L", "RR.L");
    test(".L.R...LR..L..", "LL.RR.LLRRLL..");
    test("R.R.L", "RRR.L");
    test("..R...L..R.", "..RR.LL..RR");
    test("R.L", "R.L");

    return 0;
}
