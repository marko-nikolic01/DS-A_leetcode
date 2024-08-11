#include <iostream>

using namespace std;

bool isPalindrome(string s) {
    int a = 0;
    int b = s.length() - 1;

    while(a < b) {
        char firstLetter = s[a];
        if(firstLetter > 90) {
            firstLetter -= 32;
        }
        if(!((firstLetter >= 48 && firstLetter <= 57) || (firstLetter >= 65 && firstLetter <= 90))) {
            a++;
            continue;
        }

        char secondLetter = s[b];
        if(secondLetter > 90) {
            secondLetter -= 32;
        }
        if(!((secondLetter >= 48 && secondLetter <= 57) || (secondLetter >= 65 && secondLetter <= 90))) {
            b--;
            continue;
        }

        if(firstLetter != secondLetter) {
            return false;
        }
        a++;
        b--;
    }
    return true;
}

int main() {
    cout << "Is palindrome (\"A man, a plan, a canal, Panama\"): " << (isPalindrome("A man, a plan, a canal, Panama") ? "true" : "false") << endl;
    cout << "Is palindrome (\"race a car\"): " << (isPalindrome("race a car") ? "true" : "false") << endl;
    cout << "Is palindrome (\"No 'x' in Nixon\"): " << (isPalindrome("No 'x' in Nixon") ? "true" : "false") << endl;
    cout << "Is palindrome (\"hello\"): " << (isPalindrome("hello") ? "true" : "false") << endl;
    cout << "Is palindrome (\"A man, a plan, a canal, Panama\"): " << (isPalindrome("A man, a plan, a canal, Panama") ? "true" : "false") << endl;

    return 0;
}
