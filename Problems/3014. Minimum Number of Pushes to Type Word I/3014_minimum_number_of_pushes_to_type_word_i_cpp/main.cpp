#include <iostream>

using namespace std;

int minimumPushes(string word) {
    word[0] = word.length();

    if(word[0] > 24) {
        return 48 + 4 * (word[0] % 24);
    }

    if(word[0] > 16) {
        return 24 + 3 * (word[0] - 16);
    }

    if(word[0] > 8) {
        return 8 + 2 * (word[0] - 8);
    }

    return word[0];
}

void test(string word, int expected) {
    cout << "Word: \"" << word << "\"" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minimumPushes(word) << endl;

    cout << endl;
}

int main() {
    test("a", 1);
    test("abcdefg", 7);
    test("abcdefgh", 8);
    test("abcdefghi", 10);
    test("abcdefghijklmnop", 24);
    test("abcdefghijklmnopqrstuv", 42);
    test("abcdefghijklmnopqrstuvwx", 48);
    test("abcdefghijklmnopqrstuvwxyz", 56);

    return 0;
}
