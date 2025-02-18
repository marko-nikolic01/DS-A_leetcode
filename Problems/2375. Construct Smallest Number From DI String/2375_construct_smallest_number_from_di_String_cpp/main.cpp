#include <iostream>

using namespace std;

string smallestNumber(string pattern) {
    char max = '1';

    short n = pattern.length();
    pattern.push_back(' ');

    short j;
    for(short i = 0; i < n; ++i) {
        while(pattern[i] == 'I') {
            pattern[i++] = max++;
        }

        j = i;
        while(pattern[j] == 'D') {
            ++max;
            ++j;
        }

        pattern[i] = max++;

        while(++i <= j) {
            pattern[i] = pattern[i - 1] - 1;
        }

        --i;
    }

    if(pattern[n] == ' ') {
        pattern[n] = max;
    }

    return pattern;
}

void test(string pattern, string expected) {
    cout << "Pattern: " << pattern << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << smallestNumber(pattern) << endl;

    cout << endl;
}

int main() {
    test("I", "12");
    test("D", "21");
    test("II", "123");
    test("DD", "321");
    test("ID", "132");
    test("DI", "213");
    test("DID", "2143");
    test("IIIDIDDD", "123549876");
    test("DDDIII", "4321567");

    return 0;
}
