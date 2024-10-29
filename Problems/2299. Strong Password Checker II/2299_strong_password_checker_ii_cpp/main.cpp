#include <iostream>

using namespace std;

bool strongPasswordCheckerII(string password) {
    int n = password.length();
    if(n < 8) {
        return false;
    }

    bool lowercase = false;
    bool uppercase = false;
    bool digit = false;
    bool special = false;

    if(password[--n] >= 'a' && password[n] <= 'z') {
        lowercase = true;
    } else if(password[n] >= 'A' && password[n] <= 'Z') {
        uppercase = true;
    } else if(password[n] >= '0' && password[n] <= '9') {
        digit = true;
    } else {
        special = true;
    }

    for(--n; n > -1; --n) {
        if(password[n] == password[n + 1]) {
            return false;
        } else if(password[n] >= 'a' && password[n] <= 'z') {
            lowercase = true;
        } else if(password[n] >= 'A' && password[n] <= 'Z') {
            uppercase = true;
        } else if(password[n] >= '0' && password[n] <= '9') {
            digit = true;
        } else {
            special = true;
        }
    }

    return lowercase && uppercase && digit && special;
}

void test(string password, bool expected) {
    cout << "Password: \"" << password << "\"" << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result:   " << (strongPasswordCheckerII(password) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test("Aa1@abcd", true);
    test("Aa1@aabc", false);
    test("Aa1@abc", false);
    test("MarKO!01", true);
    test("abcdefghi", false);
    test("ABC123!@", false);
    test("aBcD!123", true);
    test("abcde123@", false);
    test("ABCDE123@", false);
    test("Aabb!@12", false);

    return 0;
}
