#include <iostream>
#include <vector>

using namespace std;

int countLargestGroup(int n) {
    vector<short> groups(1);
    short nGroups = 0;
    short largestGroupSize = 0;
    short largestGroups = 0;
    short digitSum;
    short number;

    short i;
    for(i = 1; i <= n; ++i) {
        number = i;
        digitSum = 0;
        while(number > 0) {
            digitSum += number % 10;
            number /= 10;
        }

        if(nGroups < digitSum) {
            groups.push_back(0);
            ++nGroups;
        }

        if(++groups[digitSum] > largestGroupSize) {
            largestGroupSize = groups[digitSum];
            largestGroups = 1;
        } else if(groups[digitSum] == largestGroupSize) {
            ++largestGroups;
        }
    }

    return largestGroups;
}

void test(int n, int expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countLargestGroup(n) << endl;

    cout << endl;
}

int main() {
    test(1, 1);
    test(2, 2);
    test(13, 4);
    test(24, 5);
    test(10000, 1);

    return 0;
}
