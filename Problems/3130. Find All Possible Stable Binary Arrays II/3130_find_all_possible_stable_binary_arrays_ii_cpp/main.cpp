#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int numberOfStableArrays(int zero, int one, int limit) {
    vector<vector<vector<int>>> memo(zero + 1, vector<vector<int>>(one + 1, vector<int>(2, -1)));

    function<int(int, int, int)> dp = [&](int zero, int one, int lastBit) -> int {
        if(zero == 0) {
            return lastBit == 0 || one > limit ? 0 : 1;
        } else if (one == 0) {
            return lastBit == 1 || zero > limit ? 0 : 1;
        }

        if(memo[zero][one][lastBit] == -1) {
            int result = 0;

            if (lastBit == 0) {
                result = (dp(zero - 1, one, 0) + dp(zero - 1, one, 1)) % 1000000007;

                if(zero > limit) {
                    result = (result - dp(zero - limit - 1, one, 1) + 1000000007) % 1000000007;
                }
            } else {
                result = (dp(zero, one - 1, 0) + dp(zero, one - 1, 1)) % 1000000007;

                if(one > limit) {
                    result = (result - dp(zero, one - limit - 1, 0) + 1000000007) % 1000000007;
                }
            }

            memo[zero][one][lastBit] = result % 1000000007;
        }

        return memo[zero][one][lastBit];
    };

    return (dp(zero, one, 0) + dp(zero, one, 1)) % 1000000007;
}

void test(int zero, int one, int limit, int expected) {
    cout << "Zeros: " << zero << endl;

    cout << "Ones: " << one << endl;

    cout << "Limit: " << limit << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << numberOfStableArrays(zero, one, limit) << endl;

    cout << endl;
}

int main() {
    test(1, 1, 2, 2);
    test(1, 2, 1, 1);
    test(3, 3, 2, 14);
    test(2, 2, 4, 6);
    test(3, 3, 1, 2);

    return 0;
}
