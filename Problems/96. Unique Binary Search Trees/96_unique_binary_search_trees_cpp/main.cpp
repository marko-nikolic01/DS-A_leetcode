#include <iostream>
#include <vector>

using namespace std;

int numTrees(int n, vector<int>& mem) {
    if(mem[n - 1] > 0) {
        return mem[--n];
    }

    int trees = numTrees(n - 1, mem);

    for(int i = 2; i <= n / 2; ++i) {
        trees += numTrees(i - 1, mem) * numTrees(n - i, mem);
    }

    trees *= 2;

    if(n % 2 == 1) {
        int temp = numTrees((n - 1) / 2, mem);
        trees += temp * temp;
    }

    mem[--n] = trees;

    return trees;
}

int numTrees(int n) {
    vector<int> mem(19, 0);
    mem[0] = 1;

    return numTrees(n, mem);
}

void test(int n, int expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << numTrees(n) << endl;

    cout << endl;
}

int main() {
    test(1, 1);
    test(2, 2);
    test(3, 5);
    test(4, 14);
    test(5, 42);
    test(6, 132);
    test(7, 429);
    test(8, 1430);
    test(9, 4862);
    test(10, 16796);
    test(11, 58786);
    test(12, 208012);
    test(13, 742900);
    test(14, 2674440);
    test(15, 9694845);
    test(16, 35357670);
    test(17, 129644790);
    test(18, 477638700);
    test(19, 1767263190);

    return 0;
}
