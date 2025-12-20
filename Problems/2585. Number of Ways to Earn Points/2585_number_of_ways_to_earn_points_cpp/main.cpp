#include <iostream>
#include <vector>

using namespace std;

int waysToReachTarget(int target, vector<vector<int>>& types) {
    vector<int> ways(target + 1, 0);
    short points;

    ++ways[0];

    short j;
    short k;
    for(short i = types.size() - 1; i > -1; --i) {
        for(j = target - types[i][1]; j > -1; --j) {
            points = types[i][1];

            for(k = 0; k < types[i][0] && j + points <= target; ++k) {
                ways[j + points] = (ways[j + points] + ways[j]) % 1000000007;
                points += types[i][1];
            }
        }
    }

    return ways[target];
}

void test(int target, vector<vector<int>> types, int expected) {
    cout << "Target: " << target << endl;

    cout << "Types: ";
    for(vector<int> type : types) {
        cout << "[" << type[0] << ", " << type[1] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << waysToReachTarget(target, types) << endl;

    cout << endl;
}

int main() {
    test(6, {{6, 1}, {3, 2}, {2, 3}}, 7);
    test(5, {{50, 1}, {50, 2}, {50, 5}}, 4);
    test(18, {{6, 1}, {3, 2}, {2, 3}}, 1);
    test(10, {{5, 2}}, 1);
    test(7, {{2, 2}, {1, 4}}, 0);

    return 0;
}
