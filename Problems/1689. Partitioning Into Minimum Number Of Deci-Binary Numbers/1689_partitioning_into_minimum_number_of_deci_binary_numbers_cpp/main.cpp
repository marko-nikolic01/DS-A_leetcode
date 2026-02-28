#include <iostream>

using namespace std;

int minPartitions(string n) {
    char digit = 0;

    for(int i = n.length() - 1; i > -1 && digit < '9'; --i) {
        if(n[i] > digit) {
            digit = n[i];
        }
    }

    return digit - '0';
}

void test(string n, int expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minPartitions(n) << endl;

    cout << endl;
}

int main() {
    test("32", 3);
    test("82734", 8);
    test("27346209830709182346", 9);
    test("1", 1);
    test("999999", 9);

    return 0;
}
