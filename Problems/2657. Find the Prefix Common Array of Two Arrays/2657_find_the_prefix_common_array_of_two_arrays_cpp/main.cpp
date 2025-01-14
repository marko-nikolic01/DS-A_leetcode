#include <iostream>
#include <vector>

using namespace std;

vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    short n = A.size();
    vector<bool> found(n, false);

    short count = n;
    short temp;

    for(--n; n > -1; --n) {
        temp = count;

        if(!found[--A[n]]) {
            --count;
            found[A[n]] = true;
        }

        if(!found[--B[n]]) {
            --count;
            found[B[n]] = true;
        }

        A[n] = temp;
    }

    return A;
}

void test(vector<int> A, vector<int> B, const vector<int>& expected) {
    cout << "A: ";
    for(int a : A) {
        cout << a << " ";
    }
    cout << endl;

    cout << "B: ";
    for(int b : B) {
        cout << b << " ";
    }
    cout << endl;

    cout << "Expected: ";
    for(int e : expected) {
        cout << e << " ";
    }
    cout << endl;

    cout << "Result: ";
    for(int result : findThePrefixCommonArray(A, B)) {
        cout << result << " ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    test({1, 3, 2, 4}, {3, 1, 2, 4}, {0, 2, 3, 4});
    test({2, 3, 1}, {3, 1, 2}, {0, 1, 3});
    test({1, 2, 3, 4, 5}, {5, 4, 3, 2, 1}, {0, 0, 1, 3, 5});
    test({4, 3, 2, 1}, {1, 2, 3, 4}, {0, 0, 2, 4});
    test({1, 2, 3}, {1, 2, 3}, {1, 2, 3});
    test({3, 1, 4, 2}, {4, 2, 3, 1}, {0, 0, 2, 4});

    return 0;
}
