#include <iostream>
#include <vector>

using namespace std;

int countGoodStrings(int low, int high, int zero, int one) {
    vector<int> dp(++high, 0);
    dp[0] = 1;

    if(one != zero) {
        if(one < zero) {
            int temp = zero;
            zero = one;
            one = temp;
        }

        for(int i = zero; i < one; ++i) {
            dp[i] = dp[i - zero];
        }
    }

    for(int i = one; i < low; ++i) {
        dp[i] = (dp[i - zero] + dp[i - one]) % 1000000007;
    }

    int goodStrings = 0;
    for(low; low < high; ++low) {
        dp[low] = (dp[low - zero] + dp[low - one]) % 1000000007;
        goodStrings = (goodStrings + dp[low]) % 1000000007;
    }

    return goodStrings;
}

void test(int low, int high, int zero, int one, int expected) {
    cout << "Low: " << low << endl;

    cout << "High: " << high << endl;

    cout << "Zero: " << zero << endl;

    cout << "One: " << one << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countGoodStrings(low, high, zero, one) << endl;

    cout << endl;
}

int main() {
    test(3, 3, 1, 1, 8);
    test(2, 3, 1, 2, 5);
    test(2, 5, 2, 3, 5);
    test(6, 6, 3, 4, 1);
    test(3, 5, 1, 2, 16);
    test(1, 2, 1, 2, 3);
    test(4, 6, 3, 3, 4);

    return 0;
}
