#include <iostream>
#include <vector>

using namespace std;

int numWays(vector<string>& words, string target) {
    int maxWordLength = 0;
    for(int i = words.size() - 1; i > -1; --i) {
        if(words[i].length() > maxWordLength) {
            maxWordLength = words[i].length();
        }
    }

    int n = target.length();
    if(n > maxWordLength) {
        return 0;
    }

    vector<vector<int>> letters(26, vector<int>(maxWordLength, 0));
    for(int i = words.size() - 1; i > -1; --i) {
        for(int j = words[i].length() - 1; j > -1; --j) {
            ++letters[words[i][j] - 'a'][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(maxWordLength, 0));
    maxWordLength -= n - 1;
    for(int i = 0; i < maxWordLength; ++i) {
        dp[0][i] = letters[target[0] - 'a'][i];
    }
    for(int i = 1; i < n; ++i) {
        long previousSum = 0;
        for(int j = 0; j < i; ++j) {
            previousSum += dp[i - 1][j];
        }

        ++maxWordLength;
        for(int j = i; j < maxWordLength; ++j) {
            dp[i][j] = (previousSum * letters[target[i] - 'a'][j]) % 1000000007;
            previousSum += dp[i - 1][j];
        }
    }

    --n;
    int ways = 0;
    for(--maxWordLength; maxWordLength >= n; --maxWordLength) {
        ways = (ways + dp[n][maxWordLength]) % 1000000007;
    }

    return ways;
}

void test(vector<string>& words, string target, int expected) {
    cout << "Words: ";
    for(string word : words) {
        cout << "\"" << word << "\" ";
    }
    cout << endl;

    cout << "Target: \"" << target << "\"" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << numWays(words, target) << endl;

    cout << endl;
}

int main() {
    vector<string> words1 = {"acca", "bbbb", "caca"};
    string target1 = "aba";
    test(words1, target1, 6);

    vector<string> words2 = {"abba", "baab"};
    string target2 = "bab";
    test(words2, target2, 4);

    vector<string> words3 = {"abba", "baab"};
    string target3 = "babbbb";
    test(words3, target3, 0);

    vector<string> words4 = {"aaa", "aaa", "aaa"};
    string target4 = "aaa";
    test(words4, target4, 27);

    vector<string> words5 = {"abc"};
    string target5 = "abc";
    test(words5, target5, 1);

    vector<string> words6 = {"abcd", "efgh", "ijkl"};
    string target6 = "abcd";
    test(words6, target6, 1);

    vector<string> words7 = {"abcd", "efgh"};
    string target7 = "ae";
    test(words7, target7, 0);

    vector<string> words8 = {"efgh", "ijkl"};
    string target8 = "abcd";
    test(words8, target8, 0);

    return 0;
}
