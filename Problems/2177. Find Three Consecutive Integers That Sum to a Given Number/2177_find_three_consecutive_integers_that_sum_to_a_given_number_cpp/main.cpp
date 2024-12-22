#include <iostream>
#include <vector>

using namespace std;

vector<long long> sumOfThree(long long num) {
    if(num % 3 != 0) {
        return {};
    }

    num /= 3;
    return {--num, ++num, ++num};
}

void test(long long num, vector<long long> expected) {
    cout << "Number: " << num << endl;

    cout << "Expected: ";
    for (long long val : expected) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Result: ";
    for (long long val : sumOfThree(num)) {
        cout << val << " ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    test(33, {10, 11, 12});
    test(0, {-1, 0, 1});
    test(1, {});
    test(999999999999999, {333333333333332, 333333333333333, 333333333333334});
    test(1000000000000000, {});
    test(3, {0, 1, 2});
    test(1015, {});
    test(123456789012345, {41152263004114, 41152263004115, 41152263004116});
    test(27, {8, 9, 10});
    test(1000000000003, {});

    return 0;
}
