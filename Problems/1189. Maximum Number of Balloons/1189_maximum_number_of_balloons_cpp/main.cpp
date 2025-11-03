#include <iostream>
#include <vector>

using namespace std;

int maxNumberOfBalloons(string text) {
    vector<short> letters(26, 0);

    for(short i = text.length() - 1; i > -1; --i) {
        ++letters[text[i] - 'a'];
    }

    return min(letters[0], min(letters[1], min((short)(letters[11] >> 1), min(letters[13], (short)(letters[14] >> 1)))));
}

void test(string text, int expected) {
    cout << "Letters: " << text << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxNumberOfBalloons(text) << endl;

    cout << endl;
}

int main() {
    test("nlaebolko", 1);
    test("loonbalxballpoon", 2);
    test("leetcode", 0);
    test("balloonballoonballoon", 3);
    test("bbaalllloooonnn", 2);

    return 0;
}
