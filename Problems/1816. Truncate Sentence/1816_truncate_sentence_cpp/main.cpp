#include <iostream>

using namespace std;

string truncateSentence(string s, int k) {
    s.push_back(' ');

    for(short i = 0; true; ++i) {
        if(s[i] == ' ' && --k < 1) {
            s.resize(i);

            break;
        }
    }

    return s;
}

void test(string s, int k, string expected) {
    cout << "Sentence: " << "\"" << s << "\"" << endl;

    cout << "k: " << k << endl;

    cout << "Expected: " << "\"" << expected << "\"" << endl;

    cout << "Result: " << "\"" << truncateSentence(s, k) << "\"" << endl;

    cout << endl;
}

int main() {
    test("Hello how are you Contestant", 4, "Hello how are you");
    test("What is the solution to this problem", 4, "What is the solution");
    test("chopper is not a tanuki", 5, "chopper is not a tanuki");
    test("Hello World", 1, "Hello");
    test("one two three", 3, "one two three");

    return 0;
}
