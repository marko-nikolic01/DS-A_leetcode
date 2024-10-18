#include <iostream>
#include <vector>

using namespace std;

int chalkReplacer(vector<int>& chalk, int k) {
    long chalkCycle = 0;

    int n = chalk.size();
    for(int i = 0; i < n; ++i) {
        chalkCycle += chalk[i];
    }

    k %= chalkCycle;

    for(int i = 0; i < n; ++i) {
        if(chalk[i] > k) {
            return i;
        }
        k -= chalk[i];
    }

    return 0;
}

void test(vector<int> chalk, int k, int expected) {
    cout << "Chalk: ";
    for (int amount : chalk) {
        cout << amount << " ";
    }
    cout << endl;

    cout << "Total chalk: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << chalkReplacer(chalk, k) << endl;

    cout << endl;
}

int main()
{
    test({5, 1, 5}, 22, 0);
    test({3, 4, 5, 1}, 10, 2);
    test({2, 3, 4}, 12, 1);
    test({1, 2, 3, 4, 5}, 20, 2);
    test({1, 1, 1, 1}, 5, 1);
    test({10, 20, 30}, 5, 0);

    return 0;
}
