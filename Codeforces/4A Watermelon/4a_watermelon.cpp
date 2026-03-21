#include <iostream>

using namespace std;

void watermelon(int w) {
    cout << (w > 2 && (w & 1) < 1 ? "YES" : "NO") << endl;
}

int main() {
    int w;
    cin >> w;

    watermelon(w);

    return 0;
}