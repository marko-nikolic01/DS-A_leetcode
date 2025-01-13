#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int maxEqualFreq(vector<int>& nums) {
    unordered_map<int, int> numberOccurences;
    numberOccurences[nums[0]] = 1;

    unordered_map<int, int> occurences;
    occurences[1] = 1;

    int max = 1;

    int n = nums.size();
    for(int i = 1; i < n; ++i) {
        if(numberOccurences.find(nums[i]) == numberOccurences.end()) {
            numberOccurences[nums[i]] = 1;
            if(occurences.find(1) == occurences.end()) {
                occurences[1] = 1;
            } else {
                ++occurences[1];
            }
        } else {
            if(--occurences[numberOccurences[nums[i]]] < 1) {
                occurences.erase(numberOccurences[nums[i]]);
            }

            if(occurences.find(++numberOccurences[nums[i]]) == occurences.end()) {
                occurences[numberOccurences[nums[i]]] = 1;
            } else {
                ++occurences[numberOccurences[nums[i]]];
            }
        }

        if(numberOccurences.size() == 1) {
            max = i + 1;
        } else if(occurences.size() == 2) {
            unordered_map<int, int>::iterator it2 = occurences.begin();
            unordered_map<int, int>::iterator it1 = it2++;

            if(it2->first > it1->first) {
                unordered_map<int, int>::iterator temp = it1;
                it1 = it2;
                it2 = temp;
            }

            if((it1->first - it2->first == 1 && it1->second == 1) || (it2->first == 1 && it2->second == 1)) {
                max = i + 1;
            }
        } else if(occurences.size() == 1 && occurences.begin()->first == 1) {
            max = i + 1;
        }
    }

    return max;
}


void test(vector<int> nums, int expected) {
    cout << "Input: ";
    for(int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxEqualFreq(nums) << endl;

    cout << endl;
}

int main() {
    test({2, 2, 1, 1, 5, 3, 3, 5}, 7);
    test({1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5}, 13);
    test({1, 2, 3, 1, 2, 3, 4, 4, 4, 4, 1, 2, 3, 5, 6}, 13);
    test({1, 1, 1, 2, 2, 2}, 5);
    test({1, 2}, 2);
    test({1, 1, 1, 1}, 4);
    test({1, 2, 3, 4}, 4);

    return 0;
}
