#include <iostream>

using namespace std;

bool punishmentNumber(int number, int& targetSum, int sum) {
    if(number < 1 && sum == targetSum) {
        return true;
    }

    int powerOf10 = 1;

    while(number > 0) {
        sum += powerOf10 * (number % 10);
        number /= 10;

        if(sum > targetSum) {
            return false;
        } else if(punishmentNumber(number, targetSum, sum)) {
            return true;
        }

        powerOf10 *= 10;
    }

    return false;
}

int punishmentNumber(int n) {
    int sum = 1;

    for(n; n > 1; --n) {
        if(punishmentNumber(n * n, n, 0)) {
            sum += n * n;
        }
    }

    return sum;
}

void test(int n, int expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << punishmentNumber(n) << endl;

    cout << endl;
}

int main()
{
    test(1, 1);
    test(5, 1);
    test(10, 182);
    test(20, 182);
    test(37, 1478);
    test(50, 3503);
    test(69, 6528);
    test(100, 41334);
    test(500, 772866);
    test(1000, 10804657);

    return 0;
}
