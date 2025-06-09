#include <iostream>

using namespace std;

int findKthNumber(int n, long prefix1, long prefix2) {
    int steps = 0;

    while(prefix1 <= n) {
        steps += min((long)(n + 1), prefix2) - prefix1;
        prefix1 *= 10;
        prefix2 *= 10;
    }

    return steps;
}

int findKthNumber(int n, int k) {
    int current = 1;
    --k;

    while(k > 0) {
        int step = findKthNumber(n, current, current + 1);

        if(step <= k) {
            ++current;
            k -= step;
        } else {
            current *= 10;
            --k;
        }
    }

    return current;
}

void test(int n, int k, int expected) {
    cout << "n: " << n << endl;

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << findKthNumber(n, k) << endl;

    cout << endl;
}


int main() {
    test(13, 2, 10);
    test(1, 1, 1);
    test(304089173, 87099045, 178389137);
    test(100, 10, 17);
    test(1000, 100, 188);
    test(5000, 2500, 3248);

    return 0;
}
