#include <iostream>
#include <unordered_set>

using namespace std;

int passwordStrength(string password) {
    int strength = 0;
    int lowercase = 0;
    int uppercase = 0;
    short digits = 0;
    unordered_set<char> special;

    for(int i = password.length() - 1; i > -1; --i) {
        if(password[i] > '`') {
            if((lowercase & (1 << (password[i] - 'a'))) < 1) {
                ++strength;
                lowercase |= 1 << (password[i] - 'a');
            }
        } else if(password[i] > '@') {
            if((uppercase & (1 << (password[i] - 'A'))) < 1) {
                strength += 2;
                uppercase |= 1 << (password[i] - 'A');
            }
        } else if(password[i] > '/' && password[i] < ':') {
            if((digits & (1 << (password[i] - '0'))) < 1) {
                strength += 3;
                digits |= 1 << (password[i] - '0');
            }
        } else if(special.find(password[i]) == special.end()) {
            strength += 5;
            special.insert(password[i]);
        }
    }

    return strength;
}

void test(string password, int expected) {
    cout << "Password: " << "\"" << password << "\"" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << passwordStrength(password) << endl;

    cout << endl;
}

int main() {
    test("aA1!", 11);
    test("bbB11#", 11);
    test("aabbcc", 3);
    test("!@#$!@#$", 20);
    test("aAbB12!@", 22);

    return 0;
}
