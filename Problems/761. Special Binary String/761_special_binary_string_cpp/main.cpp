#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string makeLargestSpecial(string s) {
    int count = 0;
    vector<string> result;

    int i = 0;
    int n = s.length();
    for(short j = 0; j < n; ++j) {
        count += (s[j] == '1') ? 1 : -1;

        if(count == 0) {
            result.push_back('1' + makeLargestSpecial(s.substr(i + 1, j - i - 1)) + '0');
            i = j + 1;
        }
    }

    sort(result.begin(), result.end(), greater<string>());
    s.resize(0);

    n = result.size();
    for(i = 0; i < n; ++i) {
        s += result[i];
    }

    return s;
}

void test(string s, string expected) {
    cout << "s: " << s << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << makeLargestSpecial(s) << endl;

    cout << endl;
}

int main() {
    test("11011000", "11100100");
    test("10", "10");
    test("111000", "111000");
    test("101100", "110010");
    test("1101001100", "1101001100");

    return 0;
}
