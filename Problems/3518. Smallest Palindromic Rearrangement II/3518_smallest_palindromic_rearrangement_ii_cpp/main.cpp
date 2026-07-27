#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long smallestPalindrome(long n, long m, long k) {
    long result = 1;

    m = min(m, n - m);
    for(long i = 1; i <= m; ++i) {
        result = result * (n - i + 1) / i;

        if(result > k) {
            return ++k;
        }
    }

    return result;
}

string smallestPalindrome(string s, int k) {
    int partition = s.length() >> 1;
    vector<int> bucket(26, 0);
    string left = "";
    long ways;

    int i;
    for(i = 0; i < partition; ++i) {
        ++bucket[s[i] - 'a'];
    }

    auto permutations = [&](int rem) {
        long ways = 1;

        for(short i = 0; i < 26; ++i) {
            if(bucket[i] > 0) {
                ways *= smallestPalindrome(rem, bucket[i], k);

                if(ways > k) {
                    break;
                }

                rem -= bucket[i];
            }

        }

        return ways;
    };

    long iStart = 1;
    for(int pos = 0; pos < partition; ++pos) {
        for(i = 0; i < 26; ++i) {
            if(bucket[i] > 0) {
                --bucket[i];

                long ways = permutations(partition - pos - 1);

                if(iStart + ways > k) {
                    left += (char)(i + 'a');

                    break;
                }

                ++bucket[i];
                iStart += ways;
            }
        }
    }

    if(left.length() < partition) {
        return "";
    }

    string mid = s.length() % 2 != 0 ? string(1, s[partition]) : "";
    string right = left;
    reverse(right.begin(), right.end());

    return left + mid + right;
}

void test(string s, int k, string expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "k: " << k << endl;

    cout << "Expected: " << "\"" << expected << "\"" << endl;

    cout << "Result: " << "\"" << smallestPalindrome(s, k) << "\"" << endl;

    cout << endl;
}

int main() {
    test("abba", 2, "baab");
    test("aa", 2, "");
    test("bacab", 1, "abcba");
    test("aabaa", 1, "aabaa");
    test("abcba", 2, "bacab");

    return 0;
}
