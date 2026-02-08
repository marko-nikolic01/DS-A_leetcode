#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string frequencySort(string s) {
    vector<pair<int, char>> letters(62);

    int i;
    for(i = 0; i < 26; ++i) {
        letters[i].first = 0;
        letters[i].second = 'a' + i;
        letters[i + 26].first = 0;
        letters[i + 26].second = 'A' + i;
    }

    for(i = 0; i < 10; ++i) {
        letters[i + 52].first = 0;
        letters[i + 52].second = '0' + i;
    }

    for(i = s.length() - 1; i > -1; --i) {
        ++letters[s[i] - (s[i] < 'A' ? -'\x04' : (s[i] < 'a' ? '\'' : 'a'))].first;
    }

    sort(letters.begin(), letters.end());

    int j = -1;
    for(i = 61; i > -1 && letters[i].first > 0; --i) {
        while(--letters[i].first > -1) {
            s[++j] = letters[i].second;
        }
    }

    return s;
}

void test(string s, string expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "Expected: " << "\"" << expected << "\"" << endl;

    cout << "Result: " << "\"" << frequencySort(s) << "\"" << endl;

    cout << endl;
}

int main() {
    test("tree", "eetr");
    test("cccaaa", "cccaaa");
    test("Aabb", "bbaA");
    test("2a554442f544asfasssffffasss", "sssssssffffff44444aaaa55522");
    test("112233", "332211");
    test("abAB123", "baBA321");

    return 0;
}
