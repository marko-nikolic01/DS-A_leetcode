#include <iostream>
#include <vector>

using namespace std;

int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> candies(n);
    candies[0] = 1;

    int candy = 1;

    for(int i = 1; i < n; ++i) {
        if(ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
            candy += candies[i];
        } else {
            candies[i] = 1;
            ++candy;
        }
    }

    for(n -= 2; n > -1; --n) {
        if(ratings[n] > ratings[n + 1] && candies[n] <= candies[n + 1]) {
            candy -= candies[n];
            candies[n] = candies[n + 1] + 1;
            candy += candies[n];
        }
    }

    return candy;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> ratings, int expected) {
    cout << "Ratings: ";
    printArray(ratings);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << candy(ratings) << endl;

    cout << endl;
}

int main() {
    test({1, 0, 2}, 5);
    test({1, 2, 2}, 4);
    test({1, 3, 4, 5, 2}, 11);
    test({5, 4, 3, 2, 1}, 15);
    test({1, 2, 87, 87, 87, 2, 1}, 13);

    return 0;
}
