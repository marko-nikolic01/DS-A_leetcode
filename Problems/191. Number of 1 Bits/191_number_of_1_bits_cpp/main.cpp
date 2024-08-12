#include <iostream>

using namespace std;

int hammingWeight(int n) {
    int count = 0;

    while(n > 0) {
        count += n & 1;
        n >>= 1;
    }

    return count;
}

int main()
{
    cout << "Test Case 1: " << endl;
    int n1 = 11;
    cout << "Input: " << n1 << endl;
    cout << "Expected: 3" << endl;
    cout << "Result: " << hammingWeight(n1) << '\n' << endl;

    cout << "Test Case 2: " << endl;
    int n2 = 0;
    cout << "Input: " << n2 << endl;
    cout << "Expected: 0" << endl;
    cout << "Result: " << hammingWeight(n2) << '\n' << endl;

    cout << "Test Case 3: " << endl;
    int n3 = 4294967295;
    cout << "Input: " << n3 << endl;
    cout << "Expected: 32" << endl;
    cout << "Result: " << hammingWeight(n3) << '\n' << endl;

    return 0;
}
