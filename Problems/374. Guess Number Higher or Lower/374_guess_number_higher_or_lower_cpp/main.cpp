#include <iostream>

using namespace std;

int guess(int num) {
    static int picked = 6;
    if (num < picked) return 1;
    if (num > picked) return -1;
    return 0;
}

int guessNumber(int n) {
    int a = 1;

    while(a <= n) {
        int middle = a + (n - a) / 2;

        int result = guess(middle);
        if(result == 0) {
            return middle;
        } else if (result == 1) {
            a = ++middle;
        } else {
            n = --middle;
        }
    }

    return -1;
}

void testGuessNumber(int n, int expected) {
    int result = guessNumber(n);
    cout << "Range: " << n << endl;
    cout << "Expected: " << expected << endl;
    cout << "Result: " << result << endl;
    cout << endl;
}

int main() {
    testGuessNumber(10, 6);
    testGuessNumber(15, 6);
    testGuessNumber(6, 6);
    testGuessNumber(100, 6);

    return 0;
}
