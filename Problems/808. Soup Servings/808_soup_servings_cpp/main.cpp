#include <iostream>
#include <unordered_map>

using namespace std;

double soupServings(int a, int b, unordered_map<int, unordered_map<int, double>>& probabilities) {
    if(a <= 0) {
        if(b <= 0) {
            return 0.5;
        } else {
            return 1;
        }
    } else if(b <= 0) {
        return 0;
    }

    if(probabilities[a].find(b) != probabilities[a].end()) {
        return probabilities[a][b];
    }

    double probabilityA0B0 = (soupServings(a - 4, b, probabilities) + soupServings(a - 3, b - 1, probabilities) + soupServings(a - 2, b - 2, probabilities) + soupServings(a - 1, b - 3, probabilities)) / 4;
    probabilities[a][b] = probabilityA0B0;

    return probabilityA0B0;
}

double soupServings(int n) {
    unordered_map<int, unordered_map<int, double>> probabilities;

    n = n / 25 + (n % 25 > 0 ? 1 : 0);

    for(int i = 1; i < n; ++i) {
        if(soupServings(i, i, probabilities) > 0.99999) {
            return 1;
        }
    }

    return soupServings(n, n, probabilities);
}

void test(int n, double expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << soupServings(n) << endl;

    cout << endl;
}

int main() {
    test(50, 0.625);
    test(100, 0.71875);
    test(660295675, 1);
    test(3505, 0.999924);
    test(200, 0.796875);
    test(1000, 0.976565);
    test(5000, 1);

    return 0;
}
