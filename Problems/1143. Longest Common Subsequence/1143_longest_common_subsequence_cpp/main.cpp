#include <iostream>
#include <vector>

using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    short longestSubsequence = 0;

    short n1 = text1.length();
    short n2 = text2.length();

    vector<vector<short>> longestSubsequences(n1, vector<short>(n2));
    longestSubsequences[0][0] = text1[0] == text2[0] ? 1 : 0;

    short i = 0;
    for(i; i < n1; ++i) {
        if(text1[i] == text2[0]) {
            ++longestSubsequence;
            break;
        }

        longestSubsequences[i][0] = 0;
    }

    for(i; i < n1; ++i) {
        longestSubsequences[i][0] = 1;
    }

    short j = 0;
    for(j; j < n2; ++j) {
        if(text2[j] == text1[0]) {
            longestSubsequence = 1;
            break;
        }

        longestSubsequences[0][j] = 0;
    }

    for(j; j < n2; ++j) {
        longestSubsequences[0][j] = 1;
    }

    for(i = 1; i < n1; ++i) {
        for(j = 1; j < n2; ++j) {
            if(text1[i] == text2[j]) {
                longestSubsequences[i][j] = longestSubsequences[i - 1][j - 1];

                if(++longestSubsequences[i][j] > longestSubsequence) {
                    longestSubsequence = longestSubsequences[i][j];
                }
            } else {
                longestSubsequences[i][j] = max(longestSubsequences[i - 1][j], longestSubsequences[i][j - 1]);
            }
        }
    }

    return longestSubsequence;
}

void test(string text1, string text2, int expected) {
    cout << "String 1: " << "\"" << text1 << "\"" << endl;

    cout << "String 2: " << "\"" << text2 << "\"" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << longestCommonSubsequence(text1, text2) << endl;

    cout << endl;
}

int main() {
    test("abcde", "ace", 3);
    test("abc", "abc", 3);
    test("abc", "def", 0);
    test("bluemoon", "lmoon", 5);
    test("abcdef", "fbdamnce", 3);

    return 0;
}
