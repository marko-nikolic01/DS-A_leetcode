#include <iostream>

using namespace std;

int maximumGain(string s, int x, int y) {
    int points = 0;

    char character1;
    char character2;
    int character1Count = 0;
    int character2Count = 0;

    int i;
    if(x > y) {
        character1 = 'b';
        character2 = 'a';
    } else {
        character1 = 'a';
        character2 = 'b';

        i = x;
        x = y;
        y = i;
    }

    for(i = s.length() - 1; i > -1; --i) {
        if(s[i] == character1) {
            ++character1Count;
        } else if(s[i] == character2) {
            if(character1Count > 0) {
                points += x;
                --character1Count;
            } else {
                ++character2Count;
            }
        } else {
            points += min(character1Count, character2Count) * y;
            character1Count = 0;
            character2Count = 0;
        }
    }

    return points + min(character1Count, character2Count) * y;
}

void test(string s, int x, int y, int expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "x: " << x << endl;

    cout << "y: " << y << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maximumGain(s, x, y) << endl;

    cout << endl;
}

int main() {
    test("cdbcbbaaabab", 4, 5, 19);
    test("aabbaaxybbaabb", 5, 4, 20);
    test("ccccdddd", 3, 4, 0);
    test("abababab", 10, 1, 40);
    test("babaabbab", 3, 7, 24);

    return 0;
}
