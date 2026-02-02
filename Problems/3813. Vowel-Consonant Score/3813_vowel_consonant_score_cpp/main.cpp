#include <iostream>

using namespace std;

int vowelConsonantScore(string s) {
    short vowels = 0;
    short consonants = 0;

    for(short i = s.length() - 1; i > -1; --i) {
        if(s[i] > '9') {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                ++vowels;
            } else {
                ++consonants;
            }
        }
    }

    return consonants < 1 ? 0 : vowels / consonants;
}

void test(string s, int expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << vowelConsonantScore(s) << endl;

    cout << endl;
}

int main()
{
    test("cooear", 2);
    test("axeyizou", 1);
    test("au 123", 0);
    test("i3", 0);
    test("aux", 2);

    return 0;
}
