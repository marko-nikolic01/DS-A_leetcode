#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSatisfaction(vector<int>& satisfaction) {
    sort(satisfaction.begin(), satisfaction.end());

    int maximumSatisfaction = 0;
    int satisfactionSum = 0;

    for(short i = satisfaction.size() - 1; i > -1; --i) {
        if(satisfactionSum > -satisfaction[i]) {
            satisfactionSum += satisfaction[i];
            maximumSatisfaction += satisfactionSum;
        }
    }

    return maximumSatisfaction;
}

void test(vector<int> satisfaction, int expected) {
    cout << "Satisfaction: ";
    for (int value : satisfaction) {
        cout << value << " ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    int result = maxSatisfaction(satisfaction);
    cout << "Result: " << result << endl;

    cout << endl;
}

int main() {
    test({-1, -8, 0, 5, -9}, 14);
    test({4, 3, 2}, 20);
    test({-1, -4, -5}, 0);
    test({-2, 5, -1, 3, 0}, 33);
    test({10, -5, 0, -3, 7}, 67);
    test({-10, -20, -30}, 0);
    test({1, 2, 3, 4, 5}, 55);
    test({-3, -2, -1, 1}, 1);

    return 0;
}
