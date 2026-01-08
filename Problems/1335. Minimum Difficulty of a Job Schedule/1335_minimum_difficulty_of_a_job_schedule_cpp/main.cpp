#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minDifficulty(vector<int>& jobDifficulty, int d) {
    short n = jobDifficulty.size();
    if(n < d) {
        return -1;
    }

    vector<int> difficultyByDay(n);
    vector<int> previousDifficultyByDay(n);
    short maxPreviousTask = 0;

    short i;
    for(i = 0; i < n; ++i) {
        if(jobDifficulty[i] > maxPreviousTask) {
            maxPreviousTask = jobDifficulty[i];
        }

        difficultyByDay[i] = maxPreviousTask;
    }

    short j;
    for(short day = 1; day < d; ++day) {
        for(i = 0; i < n; ++i) {
            previousDifficultyByDay[i] = difficultyByDay[i];
            difficultyByDay[i] = INT_MAX;
        }

        for(i = day; i < n; ++i) {
            maxPreviousTask = 0;

            for(j = i; j >= day; --j) {
                if(jobDifficulty[j] > maxPreviousTask) {
                    maxPreviousTask = jobDifficulty[j];
                }

                if(previousDifficultyByDay[j - 1] + maxPreviousTask < difficultyByDay[i]) {
                    difficultyByDay[i] = previousDifficultyByDay[j - 1] + maxPreviousTask;
                }
            }
        }

    }

    return difficultyByDay[--n];
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> jobDifficulty, int d, int expected) {
    cout << "Job difficulties: ";
    printArray(jobDifficulty);

    cout << "Days: " << d << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minDifficulty(jobDifficulty, d) << endl;

    cout << endl;
}

int main() {
    test({ 6, 5, 4, 3, 2, 1 }, 2, 7);
    test({ 9, 9, 9 }, 4, -1);
    test({ 1, 1, 1 }, 3, 3);
    test({ 7, 1, 7, 1, 7, 1 }, 3, 15);
    test({ 11, 111, 22, 222, 33, 333, 44, 444 }, 6, 843);

    return 0;
}

