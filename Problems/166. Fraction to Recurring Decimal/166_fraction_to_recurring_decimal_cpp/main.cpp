#include <iostream>
#include <unordered_map>

using namespace std;

string fractionToDecimal(int numerator, int denominator) {
    if(numerator == 0) {
        return "0";

    }

    string fraction;

    if((numerator < 0) ^ (denominator < 0)) {
        fraction.push_back('-');
    }


    unordered_map<long, short> map;
    long dividend = llabs((long)numerator);
    long divisor = llabs((long)denominator);
    long remainder = dividend % divisor;

    fraction.append(to_string(dividend / divisor));

    if(remainder == 0) {
        return fraction;
    }

    fraction.push_back('.');

    while(remainder != 0) {
        if(map.count(remainder)) {
            fraction.insert(map[remainder], "(");
            fraction.push_back(')');
            break;
        }

        map[remainder] = fraction.size();
        remainder *= 10;
        fraction.append(to_string(remainder / divisor));
        remainder %= divisor;
    }

    return fraction;
}

void test(int numerator, int denominator, string expected) {
    cout << "Numerator: " << numerator << endl;

    cout << "Denominator: " << denominator << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << fractionToDecimal(numerator, denominator) << endl;

    cout << endl;
}

int main() {
    test(1, 2, "0.5");
    test(2, 1, "2");
    test(4, 333, "0.(012)");
    test(10, 10, "1");
    test(10, 3, "3.(3)");

    return 0;
}
