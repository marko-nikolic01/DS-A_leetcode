#include <iostream>
#include <vector>
#include <stack>

using namespace std;

string robotWithString(string s) {
    vector<int> occurences(26, 0);

    for(char c : s) {
        ++occurences[c - 'a'];
    }

    vector<char> stack;
    string smallestString;
    char minCharacter = 'a';

    for(char c : s) {
        stack.push_back(c);
        --occurences[c - 'a'];

        while (minCharacter != 'z' && occurences[minCharacter - 'a'] == 0) {
            minCharacter++;
        }

        while(!stack.empty() && stack.back() <= minCharacter) {
            smallestString.push_back(stack.back());
            stack.pop_back();
        }
    }

    return smallestString;
}

void test(string s, string expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "Expected: " << "\"" << expected << "\"" << endl;

    cout << "Result: " << "\"" << robotWithString(s) << "\"" << endl;

    cout << endl;
}

int main() {
    test("zza", "azz");
    test("bac", "abc");
    test("bdda", "addb");
    test("cba", "abc");
    test("abacb", "aabbc");

    return 0;
}
