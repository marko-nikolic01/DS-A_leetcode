#include <iostream>

using namespace std;

int main() {
    short n;
    string word;

    cin >> n;

    while(--n > -1) {
        cin >> word;

        if(word.length() < 11) {
            cout << word << endl;
        } else {
            cout << word[0] << word.length() - 2 << word.back() << endl;
        }
    }

    return 0;
}