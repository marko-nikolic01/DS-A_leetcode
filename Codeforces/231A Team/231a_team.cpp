#include <iostream>

using namespace std;

int main() {
    short solutions = 0;
    short n;
    short friend1;
    short friend2;
    short friend3;

    cin >> n;

    while(--n > -1) {
        cin >> friend1;
        cin >> friend2;
        cin >> friend3;

        if(friend1 + friend2 + friend3 > 1) {
            ++solutions;
        }
    }

    cout << solutions << endl;

    return 0;
}