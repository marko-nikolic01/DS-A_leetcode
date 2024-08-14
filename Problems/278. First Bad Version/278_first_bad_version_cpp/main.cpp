#include <iostream>

using namespace std;

bool isBadVersion(int version) {
    int badVersion = 4;
    return version >= badVersion;
}

int firstBadVersion(int n) {
    int a = 1;
    int bad = -1;

    while(a <= n) {
        int middle = a + (n - a) / 2;

        if(isBadVersion(middle)) {
            bad = middle;
            n = --middle;
        } else {
            a = ++middle;
        }
    }

    return bad;
}

void testFirstBadVersion(int n, int expected) {
    int result = firstBadVersion(n);
    cout << "n: " << n << ", Expected: " << expected << ", Result: " << result << endl << endl;
}

int main()
{
    testFirstBadVersion(5, 4);
    testFirstBadVersion(10, 4);
    testFirstBadVersion(4, 4);

    return 0;
}
