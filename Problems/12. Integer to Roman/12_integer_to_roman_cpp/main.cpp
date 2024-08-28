#include <iostream>

using namespace std;

string intToRoman(int num) {
    string roman = "";

    while(num >= 1000) {
        roman += "M";
        num -= 1000;
    }
    if(num >= 900) {
        roman += "CM";
        num -= 900;
    }

    if(num >= 500) {
        roman += "D";
        num -= 500;
    }
    if(num >= 400) {
        roman += "CD";
        num -= 400;
    }

    while(num >= 100) {
        roman += "C";
        num -= 100;
    }
    if(num >= 90) {
        roman += "XC";
        num -= 90;
    }

    if(num >= 50) {
        roman += "L";
        num -= 50;
    }
    if(num >= 40) {
        roman += "XL";
        num -= 40;
    }

    while(num >= 10) {
        roman += "X";
        num -= 10;
    }
    if(num >= 9) {
        roman += "IX";
        num -= 9;
    }

    if(num >= 5) {
        roman += "V";
        num -= 5;
    }
    if(num >= 4) {
        roman += "IV";
        num -= 40;
    }

    while(num >= 1) {
        roman += "I";
        num -= 1;
    }

    return roman;
}

void runTestCase(int num, const string& expected) {
    cout << "Input: " << num << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << intToRoman(num) << endl;

    cout << endl;
}

int main() {
    runTestCase(3, "III");
    runTestCase(4, "IV");
    runTestCase(9, "IX");
    runTestCase(58, "LVIII");
    runTestCase(1994, "MCMXCIV");

    return 0;
}
