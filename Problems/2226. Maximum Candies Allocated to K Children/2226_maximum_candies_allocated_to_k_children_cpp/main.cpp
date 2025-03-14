#include <iostream>
#include <vector>

using namespace std;

bool canAllocateCandies(vector<int>& candies, long long k, int numOfCandies) {
    long long int maxNumOfChildren = 0;

    for(int pileIndex = 0; pileIndex < candies.size(); pileIndex++) {
        maxNumOfChildren += candies[pileIndex] / numOfCandies;
    }

    return maxNumOfChildren >= k;
}

int maximumCandies(vector<int>& candies, long long k) {
    int maxCandiesInPile = 0;
    for(int i = 0; i < candies.size(); i++) {
        maxCandiesInPile = max(maxCandiesInPile, candies[i]);
    }

    int left = 0;
    int right = maxCandiesInPile;

    while(left < right) {
        int middle = (left + right + 1) / 2;

        if(canAllocateCandies(candies, k, middle)) {
            left = middle;
        } else {
            right = middle - 1;
        }
    }

    return left;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> candies, long long k, int expected) {
    cout << "Candies: ";
    printArray(candies);

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maximumCandies(candies, k) << endl;

    cout << endl;
}

int main() {
    test({5, 8, 6}, 3, 5);
    test({2, 5}, 11, 0);
    test({1, 1, 1}, 5, 0);
    test({1, 2, 3, 4}, 10, 1);
    test({100000000}, 10000000, 10);

    return 0;
}
