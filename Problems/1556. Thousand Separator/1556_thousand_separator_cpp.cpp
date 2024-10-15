#include <iostream>

using namespace std;

string thousandSeparator(int n) {
    if(n == 0) {
        return "0";
    }

    string thousandSeparatedNumber = "";

    while(n > 0) {
        thousandSeparatedNumber = (char)(n % 10 + 48) + thousandSeparatedNumber;
        n /= 10;

        if(n > 0) {
            thousandSeparatedNumber = (char)(n % 10 + 48) + thousandSeparatedNumber;
            n /= 10;
        }

        if(n > 0) {
            thousandSeparatedNumber = (char)(n % 10 + 48) + thousandSeparatedNumber;
            n /= 10;
        }

        if(n > 0) {
            thousandSeparatedNumber = '.' + thousandSeparatedNumber;
        }
    }

    return thousandSeparatedNumber;
}

void test(int n, const string& expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << thousandSeparator(n) << endl;

    cout << endl;
}

int main() {
    test(0, "0");
    test(1000, "1.000");
    test(1234567890, "1.234.567.890");
    test(987654321, "987.654.321");
    test(1000000, "1.000.000");
    test(100, "100");
    test(999, "999");
    test(10001, "10.001");
    test(10000000, "10.000.000");
    test(1, "1");
    test(12345, "12.345");
    test(100, "100");

    return 0;
}
