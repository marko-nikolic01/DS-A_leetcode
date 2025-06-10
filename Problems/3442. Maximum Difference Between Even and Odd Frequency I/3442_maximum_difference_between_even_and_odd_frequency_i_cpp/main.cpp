#include <iostream>
#include <vector>

using namespace std;

int maxDifference(string s) {
    vector<short> letters(26, 0);

    short i;
    for(i = s.length() - 1; i > -1; --i) {
        ++letters[s[i] - 'a'];
    }

    short maxOdd = 0;
    short minEven = 100;

    for(i = 0; i < 26; ++i) {
        if(letters[i] > 0) {
            if((letters[i] & 1) > 0) {
                if(letters[i] > maxOdd) {
                    maxOdd = letters[i];
                }
            } else if(minEven < 0 || letters[i] < minEven) {
                minEven = letters[i];
            }
        }
    }

    return maxOdd - minEven;
}

void test(string s, int expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxDifference(s) << endl;

    cout << endl;
}

int main() {
    test("aaaaabbc", 3);
    test("abcabcab", 1);
    test("aabbccddeeeeeffg", 3);
    test("zzzyyyxx", 1);
    test("aaabbbcccdde", 1);

    return 0;
}
