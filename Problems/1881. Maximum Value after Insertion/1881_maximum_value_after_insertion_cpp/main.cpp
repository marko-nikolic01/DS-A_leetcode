#include <iostream>

using namespace std;

string maxValue(string n, int x) {
    int insertion;

    int l = n.length();

    if(n[0] == '-') {
        for(insertion = 1; insertion < l; ++insertion) {
            if(n[insertion] > x + 48) {
                break;
            }
        }
    } else {
        for(insertion = 0; insertion < l; ++insertion) {
            if(n[insertion] < x + 48) {
                break;
            }
        }
    }

    if(insertion == l) {
        n += x + 48;
    } else {
        char next = n[insertion];
        n[insertion++] = x + 48;
        for(insertion; insertion < l; ++insertion) {
            char temp = n[insertion];
            n[insertion] = next;
            next = temp;
        }
        n += next;
    }

    return n;
}

void test(string num, int x, string expected) {
    cout << "Number: " << num << endl;

    cout << "x: " << x << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxValue(num, x) << endl;

    cout << endl;
}

int main() {
    test("123", 5, "5123");
    test("469", 5, "5469");
    test("-234", 1, "-1234");
    test("-789", 4, "-4789");
    test("2", 9, "92");
    test("-3", 1, "-13");

    return 0;
}
