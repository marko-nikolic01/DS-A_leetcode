#include <iostream>
#include <unordered_map>

using namespace std;

string minWindow(string s, string t) {
    unordered_map<char, int> letters;
    short distinctLetters = 0;

    for(int i = t.length() - 1; i > -1; --i) {
        if(letters.find(t[i]) == letters.end()) {
            letters[t[i]] = 1;
            ++distinctLetters;
        } else {
            ++letters[t[i]];
        }
    }

    int start = -1;
    int length = 100001;

    for(int left = s.length(), right = --left; left > -1; --left) {
        if(letters.find(s[left]) != letters.end() && --letters[s[left]] == 0) {
            if(--distinctLetters < 1) {
                while(true) {
                    if(letters.find(s[right]) != letters.end() && ++letters[s[right]] == 1) {
                        ++distinctLetters;
                        --right;
                        break;
                    }
                    --right;
                }

                if(right - left + 2 < length) {
                    start = left;
                    length = right - left + 2;
                }
            }
        }
    }

    if(start < 0) {
        return "";
    }

    for(int i = 0; i < length; ++i) {
        s[i] = s[start + i];
    }

    s.resize(length);

    return s;
}

void test(string s, string t, string expected) {
    cout << "s: \"" << s << "\"" << endl;

    cout << "t: \"" << t << "\"" << endl;

    cout << "Expected: \"" << expected << "\"" << endl;

    cout << "Result: \"" << minWindow(s, t) << "\"" << endl;

    cout << endl;
}

int main() {
    test("ADOBECODEBANC", "ABC", "BANC");
    test("a", "a", "a");
    test("a", "aa", "");
    test("AAABBBCCC", "ABC", "ABBBC");
    test("ADOBECODEBANC", "A", "A");
    test("ab", "b", "b");
    test("bba", "ab", "ba");

    return 0;
}
