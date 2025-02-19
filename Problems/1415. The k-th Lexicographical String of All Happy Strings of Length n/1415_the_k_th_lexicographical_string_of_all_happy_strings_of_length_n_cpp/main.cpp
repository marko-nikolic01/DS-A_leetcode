#include <iostream>
#include <vector>

using namespace std;

string getHappyString(int n, int k) {
    short count = 3 * (1 << (n - 1));

    if(k > count) {
        return "";
    }

    string happyString(n, ' ');
    vector<vector<char>> next = {{'b', 'c'}, {'a', 'c'}, {'a', 'b'}};

    count /= 3;
    happyString[0] = k > count ? (k > 2 * count ? 'c' : 'b') : 'a';
    k %= count;

    short i = 0;
    while(k > 0) {
        count >>= 1;
        happyString[i++ + 1] = k > count ? next[happyString[i] - 'a'][1] : next[happyString[i] - 'a'][0];
        k %= count;
    }

    while(++i < n) {
        happyString[i] = next[happyString[i - 1] - 'a'][1];
    }

    return happyString;
}

void test(int n, int k, const string& expected) {
    cout << "n: " << n << endl;

    cout << "k: " << k << endl;

    cout << "Expected: " << "\"" << expected << "\"" << endl;

    cout << "Result: " << "\"" << getHappyString(n, k) << "\"" << endl;

    cout << endl;
}

int main() {
    test(1, 3, "c");
    test(1, 4, "");
    test(3, 9, "cab");
    test(10, 100, "abacbabacb");
    test(4, 12, "bacb");

    return 0;
}
