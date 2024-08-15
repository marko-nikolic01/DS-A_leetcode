#include <iostream>
#include <vector>

using namespace std;

void reverseString(vector<char>& s) {
    int n = s.size();

    for(int i = 0; i < n / 2; ++i) {
        char temp = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = temp;
    }
}

int main() {
    vector<char> s1 = {'h', 'e', 'l', 'l', 'o'};
    cout << "String: ";
    for(char c : s1) cout << c;
    cout << endl;
    reverseString(s1);
    cout << "Reversed: ";
    for(char c : s1) cout << c;
    cout << endl;
    cout << endl;

    vector<char> s2 = {'H', 'a', 'n', 'n', 'a', 'h'};
    cout << "String: ";
    for(char c : s2) cout << c;
    cout << endl;
    reverseString(s2);
    cout << "Reversed: ";
    for(char c : s2) cout << c;
    cout << endl;

    return 0;
}
