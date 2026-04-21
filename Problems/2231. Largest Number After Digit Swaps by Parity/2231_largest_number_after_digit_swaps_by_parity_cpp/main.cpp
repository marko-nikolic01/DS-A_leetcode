#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int largestInteger(int num) {
    vector<short> odd;
    vector<short> even;
    int number = num;
    short digit;
    long poweOf10 = 1;

    while(number > 0) {
        digit = number % 10;
        number /= 10;
        ((digit & 1) < 1 ? even : odd).push_back(digit);
    }

    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    number = num;
    num = 0;

    short iOdd = -1;
    short iEven = -1;
    while(number > 0) {
        digit = number % 10;
        number /= 10;
        num += poweOf10 * ((digit & 1) < 1 ? even[++iEven] : odd[++iOdd]);
        poweOf10 *= 10;
    }

    return num;
}

void test(int num, int expected) {
    cout << "Number: " << num << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << largestInteger(num) << endl;

    cout << endl;
}

int main() {
    test(1234, 3412);
    test(65875, 87655);
    test(11, 11);
    test(1, 1);
    test(1000000000, 1000000000);

    return 0;
}
