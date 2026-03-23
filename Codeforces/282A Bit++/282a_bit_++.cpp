#include <iostream>

using namespace std;

int main() {
    short x = 0;
    short n;
    string statement;

    cin >> n;

    while(--n > -1) {
        cin >> statement;

        if(statement[0] == '+' || statement[2] == '+') {
            ++x;
        } else {
            --x;
        }
    }

    cout << x << endl;

    return 0;
}