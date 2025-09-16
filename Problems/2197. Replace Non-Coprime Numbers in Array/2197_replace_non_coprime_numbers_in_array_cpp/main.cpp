#include <iostream>
#include <vector>

using namespace std;

int replaceNonCoprimes(int a, int b) {
    int temp;

    while(b > 0) {
        temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

int replaceNonCoprimes(int a, int b, int gcd) {
    return (long)a * b / gcd;
}

vector<int> replaceNonCoprimes(vector<int>& nums) {
    vector<int> numbersLeft = {nums[0]};
    int number;
    int gcd;
    int lcm;

    int n = nums.size();
    for(int i = 1; i < n; ++i) {
        number = numbersLeft.back();
        gcd = replaceNonCoprimes(nums[i], number);

        if(gcd > 1) {
            numbersLeft.pop_back();
            lcm = replaceNonCoprimes(nums[i], number, gcd);

            while(!numbersLeft.empty()) {
                number = numbersLeft.back();
                gcd = replaceNonCoprimes(lcm, number);

                if(gcd > 1) {
                    numbersLeft.pop_back();
                    lcm = replaceNonCoprimes(lcm, number, gcd);
                } else {
                    break;
                }
            }

            numbersLeft.push_back(lcm);
        } else {
            numbersLeft.push_back(nums[i]);
        }
    }

    return numbersLeft;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, vector<int> expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(replaceNonCoprimes(nums));

    cout << endl;
}

int main() {
    test({6, 4, 3, 2, 7, 6, 2}, {12, 7, 6});
    test({2, 2, 1, 1, 3, 3, 3}, {2, 1, 1, 3});
    test({31, 97561, 97561, 97561, 97561, 97561, 97561, 97561, 97561}, {31, 97561});
    test({5, 7, 11, 13}, {5, 7, 11, 13});
    test({4, 4, 4, 4}, {4});
    test({2, 6, 3, 9}, {18});

    return 0;
}
