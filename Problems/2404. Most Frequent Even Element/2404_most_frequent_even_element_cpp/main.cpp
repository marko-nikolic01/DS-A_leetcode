#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int mostFrequentEven(vector<int>& nums) {
    unordered_map<int, int> evenElements;

    int mostFrequentEvenElement = -1;

    for(int i = nums.size() - 1; i > -1; --i) {
        if(nums[i] % 2 == 0) {
            if(evenElements.find(nums[i]) == evenElements.end()) {
                evenElements[nums[i]] = 1;
            } else {
                evenElements[nums[i]]++;
            }

            if((evenElements[nums[i]] > evenElements[mostFrequentEvenElement]) || (evenElements[nums[i]] == evenElements[mostFrequentEvenElement] && nums[i] < mostFrequentEvenElement)) {
                mostFrequentEvenElement = nums[i];
            }
        }
    }

    return mostFrequentEvenElement;
}

void test(vector<int> input, int expected) {
    cout << "Input: ";
    for (int num : input) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << mostFrequentEven(input) << endl;

    cout << endl;
}

int main() {
    test({1, 2, 2, 3, 4}, 2);
    test({5, 7, 8, 8, 6, 6, 4, 4}, 4);
    test({1, 3, 5, 7}, -1);
    test({2, 4, 2, 4, 6}, 2);
    test({2, 2, 2, 0, 4, 4}, 2);
    test({2}, 2);
    test({4, 2}, 2);
    test({0}, 0);

    return 0;
}
