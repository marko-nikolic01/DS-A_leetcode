#include <iostream>
#include <vector>

using namespace std;

int getXORSum(vector<int>& arr1, vector<int>& arr2) {
    int xor1 = 0;
    int xor2 = 0;

    int i;
    for(i = arr1.size() - 1; i > -1; --i) {
        xor1 ^= arr1[i];
    }

    for(i = arr2.size() - 1; i > -1; --i) {
        xor2 ^= arr2[i];
    }

    return xor1 & xor2;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> arr1, vector<int> arr2, int expected) {
    cout << "Array 1: ";
    printArray(arr1);

    cout << "Array 2: ";
    printArray(arr2);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << getXORSum(arr1, arr2) << endl;

    cout << endl;
}

int main() {
    test({1, 2, 3}, {6, 5}, 0);
    test({12}, {4}, 4);
    test({7, 7, 7}, {7, 7}, 0);
    test({2147483647}, {1, 2, 4, 8}, 15);
    test({818492001,823729238,2261353,747144854,478230859,285970256,774747711,860954509,245631564,634746160}, {967900366,340837476}, 81790984);

    return 0;
}
