#include <iostream>
#include <vector>

using namespace std;

vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
    vector<bool> isFriend(101, false);

    short i;
    short n = friends.size();
    for(i = --n; i > -1; --i) {
        isFriend[friends[i]] = true;
    }

    i = order.size();
    while(n > -1) {
        if(isFriend[order[--i]]) {
            friends[n--] = order[i];
        }
    }

    return friends;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> order, vector<int> friends, vector<int> expected) {
    cout << "Order: ";
    printArray(order);

    cout << "Friends: ";
    printArray(friends);

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(recoverOrder(order, friends));

    cout << endl;
}

int main() {
    test({3, 1, 2, 5, 4}, {1, 3, 4}, {3, 1, 4});
    test({1, 4, 5, 3, 2}, {2, 5}, {5, 2});
    test({6, 2, 4, 1, 5, 3}, {1, 3, 6}, {6, 1, 3});
    test({10, 9, 8, 7, 6, 5, 4, 3, 2, 1}, {2, 4, 6, 8, 10}, {10, 8, 6, 4, 2});
    test({1, 2, 3, 4, 5}, {1, 5}, {1, 5});

    return 0;
}
