#include <iostream>
#include <vector>

using namespace std;

int longestPalindrome(vector<string>& words) {
    int palindrome = 0;
    vector<vector<int>> occurences(26, vector<int>(26, 0));

    int i;
    for(i = words.size() - 1; i > -1; --i) {
        if(occurences[words[i][1] - 'a'][words[i][0] - 'a'] > 0) {
            ++palindrome;
            --occurences[words[i][1] - 'a'][words[i][0] - 'a'];
        } else {
            ++occurences[words[i][0] - 'a'][words[i][1] - 'a'];
        }
    }

    palindrome <<= 2;

    for(i = 0; i < 26; ++i) {
        if(occurences[i][i] > 0) {
            palindrome += 2;;
            break;
        }
    }

    return palindrome;
}

void printArray(vector<string> array) {
    for(string a : array) {
        cout << "\"" << a << "\"" << " ";
    }
    cout << endl;
}

void test(vector<string> words, int expected) {
    cout << "Words: ";
    printArray(words);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << longestPalindrome(words) << endl;

    cout << endl;
}

int main()
{
    test({"lc", "cl", "gg"}, 6);
    test({"ab", "ty", "yt", "lc", "cl", "ab"}, 8);
    test({"cc", "ll", "xx"}, 2);
    test({"aa", "bb", "cc", "dd", "aa", "cc", "dd"}, 14);
    test({"ab", "ba", "cd", "dc", "ee", "ee"}, 12);

    return 0;
}
