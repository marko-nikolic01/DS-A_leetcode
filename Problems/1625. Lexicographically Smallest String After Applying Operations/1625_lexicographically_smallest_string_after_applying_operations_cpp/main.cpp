#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

void findLexSmallestString(string& s, string& smallest, unordered_set<string>& visited, int& a, int& b) {
    if(visited.find(s) != visited.end()) {
        return;
    }
    visited.insert(s);

    short n = s.length();
    for(short i = 0; i < n; ++i) {
        if(s[i] != smallest[i]) {
            if(s[i] < smallest[i]) {
                smallest = s;
            }

            break;
        }
    }

    string t = s;
    for(--n; n > -1; n -= 2) {
        t[n] = '0' + (t[n] - '0' + a) % 10;
    }
    findLexSmallestString(t, smallest, visited, a, b);

    t = s;
    rotate(t.rbegin(), t.rbegin() + b, t.rend());
    findLexSmallestString(t, smallest, visited, a, b);
}

string findLexSmallestString(string s, int a, int b) {
    unordered_set<string> visited;
    string smallest = s;

    findLexSmallestString(s, smallest, visited, a, b);

    return smallest;
}

void test(string s, int a, int b, string expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "a: " << a << endl;

    cout << "b: " << b << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << findLexSmallestString(s, a, b) << endl;

    cout << endl;
}

int main() {
    test("5525", 9, 2, "2050");
    test("74", 5, 1, "24");
    test("0011", 4, 2, "0011");
    test("123456", 3, 2, "103254");
    test("9876", 1, 3, "0022");

    return 0;
}
