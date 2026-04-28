#include <iostream>
#include <vector>

using namespace std;

string largestNumber(vector<int>& cost, int target) {
    vector<string> dp(target + 1, "");

    dp[0].push_back('0');

    short j;
    short k;
    short n;
    for(short i = 0; i < target; ++i) {
        n = dp[i].length();
        if(n > 0) {
            for(j = 8; j > -1; --j) {
                if(i + cost[j] <= target && (n + 1 > dp[i + cost[j]].length() || (n + 1 == dp[i + cost[j]].length() && '1' + j > dp[i + cost[j]][0]))) {
                    dp[i + cost[j]].resize(n + 1);
                    dp[i + cost[j]][0] = '1' + j;

                    for(k = 0; k <= n; ++k) {
                        dp[i + cost[j]][k + 1] = dp[i][k];
                    }
                }
            }
        }
    }

    if(dp[target].length() < 2) {
        return "0";
    }

    dp[target].pop_back();

    return dp[target];
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> cost, int target, string expected) {
    cout << "Costs: ";
    printArray(cost);

    cout << "Target: " << target << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << largestNumber(cost, target) << endl;

    cout << endl;
}

int main() {
    test({4, 3, 2, 5, 6, 7, 2, 5, 5}, 9, "7772");
    test({7, 6, 5, 5, 5, 6, 8, 7, 8}, 12, "85");
    test({2, 4, 6, 2, 4, 6, 4, 4, 4}, 5, "0");
    test({1, 1, 1, 1, 1, 1, 1, 1, 1}, 3, "999");
    test({1, 2, 1, 2, 1, 2, 1, 2, 1}, 4, "9999");

    return 0;
}
