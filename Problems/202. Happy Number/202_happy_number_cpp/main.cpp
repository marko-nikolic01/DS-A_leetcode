#include <iostream>
#include <unordered_set>

using namespace std;

bool isHappy(int n) {
    unordered_set<int> sums;

    while(n != 1) {
        int sum = 0;
        while(n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        n = sum;

        if(sums.find(sum) != sums.end()) {
            return false;
        }
        sums.insert(sum);
    }

    return true;
}

int main() {
    cout << "Test case 1: Expected: true Result: " << (isHappy(19) ? "true" : "false") << endl << endl;
    cout << "Test case 2: Expected: false Result: " << (isHappy(2) ? "true" : "false") << endl << endl;
    cout << "Test case 3: Expected: true Result: " << (isHappy(1) ? "true" : "false") << endl << endl;
    cout << "Test case 4: Expected: false Result: " << (isHappy(20) ? "true" : "false") << endl << endl;
    cout << "Test case 5: Expected: true Result: " << (isHappy(7) ? "true" : "false") << endl << endl;

    return 0;
}
