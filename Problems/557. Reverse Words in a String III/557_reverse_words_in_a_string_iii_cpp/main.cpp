#include <iostream>
#include <vector>

using namespace std;

string reverseWords(string s) {
    int n = s.length();

    if(n == 1) {
        return s;
    }

    int a = -1;
    for(int i = 0; i <= n; ++i) {
        if(a == -1 && i != n && s[i] != ' ') {
            a = i;
            continue;
        } else if(s[i] == ' ' || i == n) {
            int b = i - 1;

            while(a < b) {
                char temp = s[a];
                s[a++] = s[b];
                s[b--] = temp;
            }

            a = -1;
        }
    }

    return s;
}

void test() {
    vector<pair<string, string>> testCases = {
        {"Let's take LeetCode contest", "s'teL ekat edoCteeL tsetnoc"},
        {"God Ding", "doG gniD"},
        {"hello world", "olleh dlrow"},
        {"a", "a"},
        {"a b c d", "a b c d"}
    };

    for (auto& testCase : testCases) {
        string input = testCase.first;
        string expected = testCase.second;
        string result = reverseWords(input);

        cout << "Input: \"" << input << "\"" << endl;
        cout << "Expected: \"" << expected << "\"" << endl;
        cout << "Result: \"" << result << "\"" << endl;
        cout << endl;
    }
}

int main()
{
    test();
    return 0;
}
