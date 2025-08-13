#include <iostream>

using namespace std;

string largestGoodInteger(string num) {
    char biggest = '/';
    short streak = 1;

    for(short i = num.length() - 2; i > -1; --i) {
        if(num[i] == num[i + 1]) {
            if(++streak > 2 && num[i] > biggest) {
                biggest = num[i];
            }
        } else {
            streak = 1;
        }
    }

    if(biggest > '/') {
        num.resize(3);
        num[0] = biggest;
        num[1] = biggest;
        num[2] = biggest;
    } else {
        num.resize(0);
    }

    return num;
}

void test(string num, string expected) {
    cout << "Number: " << "\"" << num << "\"" << endl;

    cout << "Expected: " << "\"" << expected << "\"" << endl;

    cout << "Result: " << "\"" << largestGoodInteger(num) << "\"" << endl;

    cout << endl;
}

int main() {
    test("6777133339", "777");
    test("2300019", "000");
    test("42352338", "");
    test("111222333444", "444");
    test("5555", "555");

    return 0;
}
