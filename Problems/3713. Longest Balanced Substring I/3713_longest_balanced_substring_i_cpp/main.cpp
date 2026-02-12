#include <iostream>
#include <vector>

using namespace std;

int longestBalanced(string& s) {
    short length = 1;
    vector<short> frequency(26);
    short unique;
    short maximumFrequency;
    short currentFrequency;
    short maximumLength;

    short j;
    short n = s.length();
    for(short i = 0; i < n; ++i){
        for(j = 0; j < 26; ++j) {
            frequency[j] = 0;
        }

        unique = 0;
        maximumFrequency = 0;
        maximumLength = 0;

        for(j = i; j < n; ++j){
            currentFrequency = ++frequency[s[j] - 'a'];

            if(currentFrequency < 2) {
                ++unique;
            }

            if(currentFrequency > maximumFrequency) {
                maximumFrequency = currentFrequency;
                maximumLength = 1;
            } else if(currentFrequency == maximumFrequency) {
                ++maximumLength;
            }

            if(unique == maximumLength && j - i + 1 > length) {
                length = j - i + 1;
            }
        }
    }

    return length;
}

void test(string s, int expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << longestBalanced(s) << endl;

    cout << endl;
}

int main() {
    test("abbac", 4);
    test("zzabccy", 4);
    test("aba", 2);
    test("aaaa", 4);
    test("abc", 3);

    return 0;
}

