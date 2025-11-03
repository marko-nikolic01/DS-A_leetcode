#include <iostream>
#include <vector>

using namespace std;

int minCost(string colors, vector<int>& neededTime) {
    int time = 0;
    int timeSum;

    int iMaximumTime;
    for(int i = colors.size() - 1; i > -1; --i) {
        timeSum = neededTime[i];

        iMaximumTime = i;
        while(--i > -1 && colors[i] == colors[iMaximumTime]) {
            timeSum += neededTime[i];

            if(neededTime[i] > neededTime[iMaximumTime]) {
                iMaximumTime = i;
            }
        }
        ++i;

        time += timeSum - neededTime[iMaximumTime];
    }

    return time;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(string colors, vector<int> neededTime, int expected) {
    cout << "Colors: " << colors << endl;

    cout << "Needed time: ";
    printArray(neededTime);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minCost(colors, neededTime) << endl;

    cout << endl;
}

int main() {
    test("abaac", {1, 2, 3, 4, 5}, 3);
    test("abc", {1, 2, 3}, 0);
    test("aabaa", {1, 2, 3, 4, 1}, 2);
    test("aaaa", {4, 3, 2, 1}, 6);
    test("aaabbbab", {1, 2, 3, 4, 5, 6, 7, 8}, 12);

    return 0;
}
