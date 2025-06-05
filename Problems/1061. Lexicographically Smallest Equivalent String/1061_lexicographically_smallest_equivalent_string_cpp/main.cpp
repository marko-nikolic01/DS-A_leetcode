#include <iostream>
#include <functional>

using namespace std;

string smallestEquivalentString(string s1, string s2, string baseStr) {
    int parent[26];

    short i;
    for(i = 0; i < 26; i++) {
        parent[i] = i;
    }

    function<int(int)> find = [&](int x) {
        while(parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }

        return x;
    };

    short a;
    short b;
    short ra;
    short rb;

    for(i = 0; i < s1.size(); i++) {
        a = s1[i] - 'a';
        b = s2[i] - 'a';
        ra = find(a);
        rb = find(b);

        if (ra != rb) {
            parent[max(ra, rb)] = min(ra, rb);
        }
    }

    for(char &c : baseStr) {
        c = char(find(c - 'a') + 'a');
    }

    return baseStr;
}

void test(string s1, string s2, string baseStr, string expected) {
    cout << "String 1: " << "\"" << s1 << "\"" << endl;

    cout << "String 2: " << "\"" << s2 << "\"" << endl;

    cout << "Base string: " << "\"" << baseStr << "\"" << endl;

    cout << "Expected: " << "\"" << expected << "\"" << endl;

    cout << "Result: " << "\"" << smallestEquivalentString(s1, s2, baseStr) << "\"" << endl;

    cout << endl;
}

int main() {
    test("parker", "morris", "parser", "makkek");
    test("hello", "world", "hold", "hdld");
    test("leetcode", "programs", "sourcecode", "aauaaaaada");
    test("abc", "cde", "eed", "aab");
    test("aab", "bcc", "bbb", "aaa");

    return 0;
}
