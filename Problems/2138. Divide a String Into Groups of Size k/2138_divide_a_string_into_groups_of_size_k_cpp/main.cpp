#include <iostream>
#include <vector>

using namespace std;

vector<string> divideString(string s, int k, char fill) {
    short n = s.length();
    short iDivision = n % k > 0 ? n / k + 1 : n / k;
    vector<string> divisions(iDivision, string(k, fill));
    iDivision = 0;
    short iDivisionCharacter;

    for(short i = 0; i < n; ++i) {
        for(iDivisionCharacter = 0; i < n && iDivisionCharacter < k; ++iDivisionCharacter) {
            divisions[iDivision][iDivisionCharacter] = s[i++];
        }

        ++iDivision;
        --i;
    }

    return divisions;
}


void test(string s, int k, char fill, vector<string> expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "k: " << k << endl;

    cout << "Fill: " << "\"" << fill << "\"" << endl;

    cout << "Expected: ";
    for(string e : expected) {
        cout << "\"" << e << "\" ";
    }
    cout << endl;

    cout << "Result: ";
    for(string result : divideString(s, k, fill)) {
        cout << "\"" << result << "\" ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    test("abcdefghi", 3, 'x', {"abc", "def", "ghi"});
    test("abcdefghij", 3, 'x', {"abc", "def", "ghi", "jxx"});
    test("a", 2, 'z', {"az"});
    test("abcde", 4, 'y', {"abcd", "eyyy"});
    test("helloworld", 5, 'q', {"hello", "world"});

    return 0;
}
