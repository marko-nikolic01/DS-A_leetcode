#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool sortVowels(char s) {
    return s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u' || s == 'A' || s == 'E' || s == 'I' || s == 'O' || s == 'U';
}

string sortVowels(string s) {
    unordered_map<char, int> vowelOccurences;

    int i;
    int n = s.length();
    for(i = --n; i > -1; --i) {
        if(sortVowels(s[i])) {
            ++vowelOccurences[s[i]];
        }
    }

    vector<char> vowels = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
    i = 9;

    for(n; n > -1; --n) {
        if(sortVowels(s[n])) {
            while(vowelOccurences[vowels[i]] < 1) {
                --i;
            }

            s[n] = vowels[i];
            --vowelOccurences[vowels[i]];
        }
    }

    return s;
}

void test(string s, string expected) {
    cout << "String: " << s << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << sortVowels(s) << endl;

    cout << endl;
}

int main() {
    test("lEetcOde", "lEOtcede");
    test("lYmpH", "lYmpH");
    test("UpjPbEnOj", "EpjPbOnUj");
    test("aeiouAEIOU", "AEIOUaeiou");
    test("zxcvb", "zxcvb");

    return 0;
}
