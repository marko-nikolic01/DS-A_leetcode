#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(int x) {
    if(x < 0) {
        return false;
    }

    long tempX = x;
    long reverseX = 0;

    while(tempX > 0) {
        int digit = tempX % 10;
        tempX /= 10;
        reverseX = reverseX * 10 + digit;
    }

    if(x == reverseX) {
        return true;
    }

    return false;
}

int main()
{
    int x = 121;

    bool result = isPalindrome(x);

    if(result) {
        cout << x << " is a palindrome number." << endl;
    } else {
        cout << x << " isn't a palindrome number." << endl;
    }
    return 0;
}
