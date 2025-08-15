#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<double> judgePoint24(double a, double b) {
    vector<double> res = {a + b, a - b, b - a, a * b};

    if(fabs(b) > 0.000001) {
        res.push_back(a / b);
    }

    if(fabs(a) > 0.000001) {
        res.push_back(b / a);
    }

    return res;
}

bool judgePoint24(vector<double>& nums) {
    short n = nums.size();
    if(n == 1) {
        return fabs(nums[0] - 24.0) < 0.000001;
    }

    vector<double> next;

    short j;
    short k;
    for(short i = 0; i < n; ++i) {
        for(j = 0; j < n; ++j) {
            if(i == j) {
                continue;
            }

            next.resize(0);

            for(k = 0; k < n; ++k) {
                if(k != i && k != j) {
                    next.push_back(nums[k]);
                }
            }

            for(double value : judgePoint24(nums[i], nums[j])) {
                next.push_back(value);

                if(judgePoint24(next)) {
                    return true;
                }

                next.pop_back();
            }
        }
    }

    return false;
}

bool judgePoint24(vector<int>& cards) {
    vector<double> nums = {(double)cards[0], (double)cards[1], (double)cards[2], (double)cards[3]};

    return judgePoint24(nums);
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> cards, bool expected) {
    cout << "Cards: ";
    printArray(cards);

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (judgePoint24(cards) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test({4, 1, 8, 7}, true);
    test({1, 2, 1, 2}, false);
    test({3, 3, 8, 8}, true);
    test({1, 5, 5, 5}, true);
    test({9, 9, 9, 9}, false);

    return 0;
}
