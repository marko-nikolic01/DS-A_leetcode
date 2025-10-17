#include <iostream>
#include <vector>

using namespace std;

int countVowelStrings(int n) {
    vector<int> vowels(5, 1);

    short i;
    while(--n > 0) {
        for(i = 1; i < 5; ++i) {
            vowels[i] += vowels[i - 1];
        }
    }

    return vowels[0] + vowels[1] + vowels[2] + vowels[3] + vowels[4];
}

void test(int n, int expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countVowelStrings(n) << endl;

    cout << endl;
}

int main() {
    test(1, 5);
    test(2, 15);
    test(3, 35);
    test(4, 70);
    test(33, 66045);
    test(50, 316251);

    return 0;
}
