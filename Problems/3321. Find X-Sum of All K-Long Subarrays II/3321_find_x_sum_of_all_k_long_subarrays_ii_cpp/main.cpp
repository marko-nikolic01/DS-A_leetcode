#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

using namespace std;

vector<long long> findXSum(vector<int>& nums, int k, int x) {
    int n = nums.size();
    vector<long long> xSums(n - k + 1, 0);
    map<int, set<int>> occurences;
    map<int, set<int>> xOccurences;
    unordered_map<int, int> numbers;
    vector<int> xNumbers;
    int left;
    long occurences1;
    long occurences2;
    int number1;
    int number2;

    int i;
    for(i = 0; i < k; ++i) {
        occurences[numbers[nums[i]]].erase(nums[i]);

        if(occurences[numbers[nums[i]]].empty()) {
            occurences.erase(numbers[nums[i]]);
        }

        occurences[++numbers[nums[i]]].insert(nums[i]);
    }

    int iX = 0;
    map<int, set<int>>::reverse_iterator it;
    set<int>::reverse_iterator jt;
    map<int, set<int>>::iterator kt;
    set<int>::iterator lt;
    for(it = occurences.rbegin(); iX < x && it != occurences.rend(); ++it) {
        for(jt = it->second.rbegin(); iX < x && jt != it->second.rend(); ++jt) {
            xSums[0] += (long)it->first * (*jt);
            xOccurences[it->first].insert(*jt);
            ++iX;

            xNumbers.push_back(*jt);
        }
    }

    int j;
    for(j = xNumbers.size() - 1; j > -1; --j) {
        occurences[numbers[xNumbers[j]]].erase(xNumbers[j]);

        if(occurences[numbers[xNumbers[j]]].empty()) {
            occurences.erase(numbers[xNumbers[j]]);
        }
    }

    int iXSum = 0;
    for(i; i < n; ++i) {
        ++iXSum;
        xSums[iXSum] = xSums[iXSum - 1];

        left = i - k;
        if(nums[left] == nums[i]) {
            continue;
        }

        if(xOccurences.find(numbers[nums[left]]) != xOccurences.end() && xOccurences[numbers[nums[left]]].find(nums[left]) != xOccurences[numbers[nums[left]]].end()) {
            xOccurences[numbers[nums[left]]].erase(nums[left]);

            if(xOccurences[numbers[nums[left]]].empty()) {
                xOccurences.erase(numbers[nums[left]]);
            }

            xSums[iXSum] -= (long)numbers[nums[left]] * nums[left];
            --iX;
        } else {
            occurences[numbers[nums[left]]].erase(nums[left]);

            if(occurences[numbers[nums[left]]].empty()) {
                occurences.erase(numbers[nums[left]]);
            }
        }

        if(xOccurences.find(numbers[nums[i]]) != xOccurences.end() && xOccurences[numbers[nums[i]]].find(nums[i]) != xOccurences[numbers[nums[i]]].end()) {
            xOccurences[numbers[nums[i]]].erase(nums[i]);

            if(xOccurences[numbers[nums[i]]].empty()) {
                xOccurences.erase(numbers[nums[i]]);
            }

            xSums[iXSum] -= (long)numbers[nums[i]] * nums[i];
            --iX;
        } else {
            occurences[numbers[nums[i]]].erase(nums[i]);

            if(occurences[numbers[nums[i]]].empty()) {
                occurences.erase(numbers[nums[i]]);
            }
        }

        if(--numbers[nums[left]] > 0) {
            occurences[numbers[nums[left]]].insert(nums[left]);
        } else {
            numbers.erase(nums[left]);
        }

        occurences[++numbers[nums[i]]].insert(nums[i]);

        xNumbers.resize(0);
        for(it = occurences.rbegin(); iX < x && it != occurences.rend(); ++it) {
            for(jt = it->second.rbegin(); iX < x && jt != it->second.rend(); ++jt) {
                xSums[iXSum] += (long)it->first * (*jt);
                xOccurences[it->first].insert(*jt);
                ++iX;

                xNumbers.push_back(*jt);
            }
        }

        for(j = xNumbers.size() - 1; j > -1; --j) {
            occurences[numbers[xNumbers[j]]].erase(xNumbers[j]);

            if(occurences[numbers[xNumbers[j]]].empty()) {
                occurences.erase(numbers[xNumbers[j]]);
            }
        }

        it = occurences.rbegin();
        kt = xOccurences.begin();
        if(it != occurences.rend()) {
            occurences1 = it->first;
            occurences2 = kt->first;
            jt = it->second.rbegin();
            lt = kt->second.begin();
            number1 = *jt;
            number2 = *lt;

            if(occurences1 > occurences2 || (occurences1 == occurences2 && number1 > number2)) {
                xSums[iXSum] += occurences1 * number1 - occurences2 * number2;
                xOccurences[occurences2].erase(number2);
                occurences[occurences1].erase(number1);
                xOccurences[occurences1].insert(number1);
                occurences[occurences2].insert(number2);

                if(xOccurences[occurences2].empty()) {
                    xOccurences.erase(occurences2);
                }

                if(occurences[occurences1].empty()) {
                    occurences.erase(occurences1);
                }
            }
        }
    }

    return xSums;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void printArray(vector<long long> array) {
    for(long long a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int k, int x, vector<long long> expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "k: " << k << endl;

    cout << "x: " << x << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result:   ";
    printArray(findXSum(nums, k, x));

    cout << endl;
}

int main() {
    test({1, 1, 2, 2, 3, 4, 2, 3}, 6, 2, {6, 10, 12});
    test({3, 8, 7, 8, 7, 5}, 2, 2, {11, 15, 15, 15, 12});
    test({1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000}, 6, 1, {6000000000});
    test({1, 9, 10, 4}, 2, 1, {9, 10, 10});
    test({5, 4, 1, 1, 1}, 3, 1, {5, 2, 3});
    test({1, 2, 3}, 2, 1, {2, 3});
    test({5, 5, 5}, 2, 2, {10, 10});
    test({2, 1, 2, 1}, 3, 2, {5, 4});

    return 0;
}
