#include <iostream>

using namespace std;

void complexNumberMultiply(string& num, short& number, short& i, char end) {
    bool isNegative;

    if(num[++i] == '-') {
        isNegative = true;
    } else {
        isNegative = false;
        --i;
    }

    while(num[++i] != end) {
        number = 10 * number + num[i] - '0';
    }

    if(isNegative) {
        number = -number;
    }
}

void complexNumberMultiply(string& num, short& real, short& imaginary) {
    short i = -1;

    complexNumberMultiply(num, real, i, '+');
    complexNumberMultiply(num, imaginary, i, 'i');
}

void complexNumberMultiply(short number, string& num) {
    if(number < 0) {
        num.push_back('-');
        number = -number;
    } else if(number < 1) {
        num.push_back('0');
        return;
    }

    int powerOf10 = 1;
    while(powerOf10 <= number) {
        powerOf10 *= 10;
    }
    powerOf10 /= 10;

    while(powerOf10 > 0) {
        num.push_back(number / powerOf10 + '0');
        number %= powerOf10;
        powerOf10 /= 10;
    }
}

void complexNumberMultiply(short real, short imaginary, string& num) {
    complexNumberMultiply(real, num);
    num.push_back('+');
    complexNumberMultiply(imaginary, num);
    num.push_back('i');
}

string complexNumberMultiply(string num1, string num2) {
    short real;
    short imaginary;
    short real1 = 0;
    short real2 = 0;
    short imaginary1 = 0;
    short imaginary2 = 0;

    complexNumberMultiply(num1, real1, imaginary1);
    complexNumberMultiply(num2, real2, imaginary2);

    real = real1 * real2 - imaginary1 * imaginary2;
    imaginary = real1 * imaginary2 + real2 * imaginary1;
    num1.resize(0);
    complexNumberMultiply(real, imaginary, num1);

    return num1;
}

void test(string num1, string num2, string expected) {
    cout << "Number 1: " << num1 << endl;

    cout << "Number 2: " << num2 << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << complexNumberMultiply(num1, num2) << endl;

    cout << endl;
}

int main() {
    test("1+1i", "1+1i", "0+2i");
    test("1+-1i", "1+-1i", "0+-2i");
    test("78+-76i", "-86+72i", "-1236+12152i");
    test("0+0i", "5+-3i", "0+0i");
    test("-3+2i", "1+-4i", "5+14i");

    return 0;
}
