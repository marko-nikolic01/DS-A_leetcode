#include <iostream>
#include <vector>

using namespace std;

int maxScoreSightseeingPair(vector<int>& values) {
    int score = 0;
    int current = values.back();

    for(int i = values.size() - 2; i > -1; --i) {
        if(--current + values[i] > score) {
            score = current + values[i];
        }

        if(values[i] > current) {
            current = values[i];
        }
    }

    return score;
}

void test(vector<int> values, int expected) {
    cout << "Sightseeing spots: ";
    for (int value : values) {
        cout << value << " ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxScoreSightseeingPair(values) << endl;

    cout << endl;
}

int main() {
    test({8, 1, 5, 2, 6}, 11);
    test({1, 2}, 2);
    test({1, 3, 5, 7, 9}, 15);
    test({4, 7, 2, 9, 5}, 14);
    test({10, 9, 8, 7, 6}, 18);
    test({6, 2, 4, 8, 10, 1}, 17);
    test({9, 7, 3, 1, 10}, 15);
    test({5, 8, 3, 2, 7, 6}, 12);
    test({1, 10, 1, 10, 1}, 18);
    test({7, 7, 7, 7, 7}, 13);
    test({1, 1}, 1);

    return 0;
}
