#include <iostream>
#include <vector>

using namespace std;

string numberToWords(int num) {
    if(num < 1) {
        return "Zero";
    }

    vector<string> digits = {
        "One", "Two", "Three", "Four", "Five",
        "Six", "Seven", "Eight", "Nine", "Ten",
        "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
        "Sixteen", "Seventeen","Eighteen", "Nineteen"
    };

    vector<string> tens = {
        "Twenty", "Thirty", "Forty", "Fifty", "Sixty",
        "Seventy", "Eighty", "Ninety"
    };

    string word = "";
    bool shouldPlaceSpace = false;

    int temp = num / 1000000000;
    if(temp > 0) {
        shouldPlaceSpace = true;

        word.append(digits[temp - 1]);
        word.push_back(' ');
        word.append("Billion");

        num %= 1000000000;
    }

    temp = num / 100000000;
    if(temp > 0) {
        if(shouldPlaceSpace) {
            word.push_back(' ');
        } else {
            shouldPlaceSpace = true;
        }

        word.append(digits[temp - 1]);
        word.push_back(' ');
        word.append("Hundred ");

        num %= 100000000;

        int temp = num / 1000000;
        if(temp > 19) {
            word.append(tens[temp / 10 - 2]);
            word.push_back(' ');

            temp %= 10;
        }

        if(temp > 0) {
            word.append(digits[temp - 1]);
            word.push_back(' ');
        }

        word.append("Million");

        num %= 1000000;
    }

    temp = num / 1000000;
    if(temp > 0) {
        if(shouldPlaceSpace) {
            word.push_back(' ');
        } else {
            shouldPlaceSpace = true;
        }

        if(temp > 19) {
            word.append(tens[temp / 10 - 2]);
            word.push_back(' ');

            temp %= 10;
        }

        if(temp > 0) {
            word.append(digits[temp - 1]);
            word.push_back(' ');
        }

        word.append("Million");

        num %= 1000000;
    }

    temp = num / 100000;
    if(temp > 0) {
        if(shouldPlaceSpace) {
            word.push_back(' ');
        } else {
            shouldPlaceSpace = true;
        }

        word.append(digits[temp - 1]);
        word.push_back(' ');
        word.append("Hundred ");

        num %= 100000;

        int temp = num / 1000;
        if(temp > 19) {
            word.append(tens[temp / 10 - 2]);
            word.push_back(' ');

            temp %= 10;
        }

        if(temp > 0) {
            word.append(digits[temp - 1]);
            word.push_back(' ');
        }

        word.append("Thousand");

        num %= 1000;
    }

    temp = num / 1000;
    if(temp > 0) {
        if(shouldPlaceSpace) {
            word.push_back(' ');
        } else {
            shouldPlaceSpace = true;
        }

        if(temp > 19) {
            word.append(tens[temp / 10 - 2]);
            word.push_back(' ');

            temp %= 10;
        }

        if(temp > 0) {
            word.append(digits[temp - 1]);
            word.push_back(' ');
        }

        word.append("Thousand");

        num %= 1000;
    }

    temp = num / 100;
    if(temp > 0) {
        if(shouldPlaceSpace) {
            word.push_back(' ');
        }

        word.append(digits[temp - 1]);
        word.push_back(' ');
        word.append("Hundred");

        num %= 100;

        if(num > 19) {
            word.push_back(' ');
            word.append(tens[num / 10 - 2]);

            num %= 10;
        }

        if(num > 0) {
            word.push_back(' ');
            word.append(digits[num - 1]);
        }

        return word;
    }

    if(num > 0) {
        if(shouldPlaceSpace) {
            word.push_back(' ');
        }

        if(num > 19) {
            word.append(tens[num / 10 - 2]);

            num %= 10;
            if(num > 0) {
                word.push_back(' ');
                word.append(digits[num - 1]);
            }
        } else if(num > 0) {
            word.append(digits[num - 1]);
        }
    }

    return word;
}

void test(int num, string expected) {
    cout << "Number: " << num << endl;

    cout << "Expected: " << "\"" << expected << "\"" << endl;

    cout << "Result: " << "\"" << numberToWords(num) << "\"" << endl;

    cout << endl;
}

int main() {
    test(0, "Zero");
    test(5, "Five");
    test(19, "Nineteen");
    test(20, "Twenty");
    test(123, "One Hundred Twenty Three");
    test(12345, "Twelve Thousand Three Hundred Forty Five");
    test(1234567, "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven");
    test(1000000, "One Million");
    test(1000000000, "One Billion");
    test(2147483647, "Two Billion One Hundred Forty Seven Million Four Hundred Eighty Three Thousand Six Hundred Forty Seven");
}
