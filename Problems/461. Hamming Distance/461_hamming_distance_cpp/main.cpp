#include <iostream>
#include <bitset>

using namespace std;

int hammingDistance(int x, int y) {
    x ^= y;

    int distance = 0;
    while(x > 0) {
        distance += x & 1;
        x >>= 1;
    }

    return distance;
}

string toBinary(int n) {
    return bitset<32>(n).to_string();
}

void test(int x, int y, int expected) {
    int result = hammingDistance(x, y);
    cout << "x: " << x << "\t(" << toBinary(x) << ")"<< endl;
    cout << "y: " << y << "\t(" << toBinary(y) << ")" << endl;
    cout << "Expected: " << expected << endl;
    cout << "Result: " << result << endl;
    cout << endl;
}

int main() {
    test(1, 4, 2);
    test(2, 7, 2);
    test(10, 15, 2);
    test(0, 0, 0);
    test(255, 0, 8);

    return 0;
}


