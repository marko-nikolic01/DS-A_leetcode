#include <iostream>

using namespace std;

int possibleStringCount(string word) {
    short count = 1;

    for(short i = word.length() - 2; i > -1; --i) {
        if(word[i] == word[i + 1]) {
            ++count;
        }
    }

    return count;
}

void test(string word, int expected) {
    cout << "Word: " << "\"" << word << "\"" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << possibleStringCount(word) << endl;

    cout << endl;
}

int main() {
    test("abbcccc", 5);
    test("abcd", 1);
    test("aaaa", 4);
    test("aabb", 3);
    test("a", 1);

    return 0;
}
