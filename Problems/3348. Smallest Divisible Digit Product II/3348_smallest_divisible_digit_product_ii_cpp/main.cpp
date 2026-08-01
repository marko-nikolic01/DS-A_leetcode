#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

string smallestNumber(string num, long long t) {
    long temp = t;

    int i;
    for(i = 2; i < 10; ++i) {
        while(temp % i == 0) {
            temp /= i;
        }
    }

    if(temp > 1) {
        return "-1";
    }

    int n = num.length();
    vector<long> rem(n + 1);
    int pos = --n;
    long tNow;
    short k;

    rem[0] = t;

    for(i = 0; i <= n; ++i) {
        if (num[i] == '0') {
            pos = i;

            break;
        }

        rem[i + 1] = rem[i] / gcd(rem[i], num[i] - '0');
    }

    if(rem[++n] == 1) {
        return num;
    }

    int j;
    for(i = pos; i > -1; --i) {
        while(++num[i] <= '9') {
            tNow = rem[i] / gcd(rem[i], num[i] - '0');
            k = 9;

            for(j = n - 1; j > i; --j) {
                while(tNow % k > 0) {
                    --k;
                }

                tNow /= k;
                num[j] = '0' + k;
            }

            if(tNow == 1) {
                return num;
            }
        }
    }

    string answer;

    for(i = 9; i > 1; --i) {
        while(t % i == 0) {
            answer += '0' + i;
            t /= i;
        }
    }

    answer += string(max(n + 1 - (int)answer.length(), 0), '1');
    reverse(answer.begin(), answer.end());

    return answer;
}

void test(string num, int t, string expected) {
    cout << "Number: " << num << endl;

    cout << "t: " << t << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << smallestNumber(num, t) << endl;

    cout << endl;
}

int main() {
    test("1234", 256, "1488");
    test("12355", 50, "12355");
    test("11111", 26, "-1");
    test("999", 1, "999");
    test("15", 5, "15");

    return 0;
}
