#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int a = 0;
    int b = numbers.size() - 1;

    while(a < b) {
        if(numbers[a] + numbers[b] == target) {
            return {++a, ++b};
        } else if(numbers[a] + numbers[b] < target) {
            a++;
        } else {
            b--;
        }
    }

    return {0, 0};
}

void testTwoSum(vector<int> numbers, int target, vector<int> expected) {
    cout << "Input: [";
    for (size_t i = 0; i < numbers.size(); i++) {
        cout << numbers[i];
        if (i != numbers.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    cout << "Target: " << target << endl;

    cout << "Expected: [" << expected[0] << ", " << expected[1] << "]" << endl;

    vector<int> result = twoSum(numbers, target);
    cout << "Result: [" << result[0] << ", " << result[1] << "]" << endl;

    cout << endl;
}

int main() {
    testTwoSum({2, 7, 11, 15}, 9, {1, 2});
    testTwoSum({1, 3, 4, 6, 8}, 10, {3, 4});
    testTwoSum({1, 2, 3, 4, 5}, 6, {1, 5});
    testTwoSum({2, 3, 4}, 6, {1, 3});
    testTwoSum({5, 25, 75}, 100, {2, 3});

    return 0;
}
