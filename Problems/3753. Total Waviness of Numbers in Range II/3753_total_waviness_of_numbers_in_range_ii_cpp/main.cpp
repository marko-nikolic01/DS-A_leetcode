#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct State {
    int previous;
    int current;
    int tight;
    int lead;
    long count;
    long sum;
};

long totalWaviness(long num) {
    if(num < 100) {
        return 0;
    }

    long waviness = 0;
    string s = to_string(num);
    vector<State> currentStates;
    vector<State> nextStates;
    long count[2][2][11][11];
    long sum[2][2][11][11];
    int limit;
    int maxDigit;
    int digit;
    int newLead;
    int newPrevious;
    int newCurrent;
    int newTight;
    long add;
    short lead;
    short previous;
    short current;

    currentStates.push_back({10, 10, 1, 1, 1, 0});

    int j;
    short n = s.size();
    int m;
    for(short i = 0; i < n; ++i) {
        nextStates.clear();
        memset(count, 0, sizeof(count));
        memset(sum, 0, sizeof(sum));
        limit = s[i] - '0';

        m = currentStates.size();
        for(j = 0; j < m; ++j) {
            maxDigit = currentStates[j].tight ? limit : 9;
            for(digit = 0; digit <= maxDigit; ++digit) {
                newLead = currentStates[j].lead && (digit == 0);
                newPrevious = currentStates[j].current;
                newCurrent = newLead ? 10 : digit;
                newTight = currentStates[j].tight && (digit == maxDigit);
                add = 0;

                if(!newLead && currentStates[j].previous != 10 && currentStates[j].current != 10 && ((currentStates[j].previous < currentStates[j].current && currentStates[j].current > digit) || (currentStates[j].previous > currentStates[j].current && currentStates[j].current < digit))) {
                    add = currentStates[j].count;
                }

                count[newTight][newLead][newPrevious][newCurrent] += currentStates[j].count;
                sum[newTight][newLead][newPrevious][newCurrent] += currentStates[j].sum + add;
            }
        }

        for(short tight = 0; tight < 2; ++tight) {
            for(lead = 0; lead < 2; ++lead) {
                for(previous = 0; previous < 11; ++previous) {
                    for(current = 0; current < 11; ++current) {
                        if(count[tight][lead][previous][current] != 0) {
                            nextStates.push_back({previous, current, tight, lead, count[tight][lead][previous][current], sum[tight][lead][previous][current]});
                        }
                    }
                }
            }
        }

        currentStates.swap(nextStates);
    }

    n = currentStates.size();
    for(j = 0; j < n; ++j) {
        waviness += currentStates[j].sum;
    }

    return waviness;
}

long long totalWaviness(long long num1, long long num2) {
    return totalWaviness(num2) - totalWaviness(--num1);
}

void test(long long num1, long long num2, long long expected) {
    cout << "Number 1: " << num1 << endl;

    cout << "Number 2: " << num2 << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << totalWaviness(num1, num2) << endl;

    cout << endl;
}

int main() {
    test(120, 130, 3);
    test(198, 202, 3);
    test(4848, 4848, 2);
    test(100, 105, 5);
    test(121, 131, 3);

    return 0;
}
