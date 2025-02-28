#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string shortestCommonSupersequence(string str1, string str2) {
    short n1 = str1.length();
    short n2 = str2.length();

    short longestSubsequence = 0;
    vector<vector<short>> longestSubsequences(++n1, vector<short>(++n2));

    short i = 0;
    for(i; i < n1; ++i) {
        longestSubsequences[i][0] = i;
    }

    short j = 0;
    for(j; j < n2; ++j) {
        longestSubsequences[0][j] = j;
    }

    for(i = 1; i < n1; ++i) {
        for(j = 1; j < n2; ++j) {
            if(str1[i - 1] == str2[j - 1]) {
                longestSubsequences[i][j] = longestSubsequences[i - 1][j - 1] + 1;
            } else {
                longestSubsequences[i][j] = min(longestSubsequences[i - 1][j], longestSubsequences[i][j - 1]) + 1;
            }
        }
    }

    string shortestSupersequence = "";

    i = --n1;
    j = --n2;
    while(i > 0 && j > 0) {
        if(str1[i - 1] == str2[j - 1]) {
            shortestSupersequence.push_back(str1[--i]);
            --j;
        } else if(longestSubsequences[i - 1][j] < longestSubsequences[i][j - 1]) {
            shortestSupersequence.push_back(str1[--i]);
        } else {
            shortestSupersequence.push_back(str2[--j]);
        }
    }

    while(i > 0) {
        shortestSupersequence.push_back(str1[--i]);
    }

    while(j > 0) {
        shortestSupersequence.push_back(str2[--j]);
    }

    reverse(shortestSupersequence.begin(), shortestSupersequence.end());

    return shortestSupersequence;
}

void test(string str1, string str2, string expected) {
    cout << "String 1: " << "\"" << str1 << "\"" << endl;

    cout << "String 2: " << "\"" << str2 << "\"" << endl;

    cout << "Expected: " << "\"" << expected << "\"" << endl;

    cout << "Result: " << "\"" << shortestCommonSupersequence(str1, str2) << "\"" << endl;

    cout << endl;
}

int main() {
    test("abac", "cab", "cabac");
    test("aaaaaaaa", "aaaaaaaa", "aaaaaaaa");
    test("abc", "ac", "abc");
    test("geek", "eke", "geeke");
    test("xyz", "abcd", "xyzabcd");

    return 0;
}
