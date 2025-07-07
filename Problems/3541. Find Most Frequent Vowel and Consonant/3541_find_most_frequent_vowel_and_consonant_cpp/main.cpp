#include <iostream>
#include <vector>

using namespace std;

int maxFreqSum(string s) {
    vector<short> letters(26, 0);

    short i;
    for(i = s.length() - 1; i > -1; --i) {
        ++letters[s[i] - 'a'];
    }

    short maxVowels = 0;
    short maxConsonants = 0;

    for(i = 0; i < 26; ++i) {
        if(i == 0 || i == 4 || i == 8 || i == 14 || i == 20) {
            if(letters[i] > maxVowels) {
                maxVowels = letters[i];
            }
        } else if(letters[i] > maxConsonants) {
            maxConsonants = letters[i];
        }
    }

    return maxVowels + maxConsonants;
}


void test(string s, int expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxFreqSum(s) << endl;

    cout << endl;
}

int main() {
    test("successes", 6);
    test("aeiaeia", 3);
    test("bcdfg", 1);
    test("aaaaa", 5);
    test("aaeeiibbcc", 4);

    return 0;
}
