#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
    for(int i = dist.size() - 1; i > -1; --i) {
        dist[i] = dist[i] / speed[i] + (dist[i] % speed[i] > 0 ? 1 : 0);
    }

    sort(dist.begin(), dist.end(), greater<int>());

    speed[0] = 0;

    for(int i = dist.size() - 1; i > -1 && dist[i] - speed[0] > 0; --i) {
        speed[0]++;
    }

    return speed[0];
}

void test(vector<int> dist, vector<int> speed, int expected) {
    cout << "Distances: ";
    for (int d : dist) {
        cout << d << " ";
    }
    cout << endl;

    cout << "Speeds: ";
    for (int s : speed) {
        cout << s << " ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << eliminateMaximum(dist, speed) << endl;

    cout << endl;
}

int main() {
    test({1, 3, 5}, {1, 1, 1}, 3);
    test({2, 4, 3}, {2, 1, 2}, 3);
    test({3, 5, 7}, {3, 2, 1}, 3);
    test({10, 5, 7}, {3, 2, 1}, 3);
    test({10, 8, 6}, {5, 4, 3}, 2);
    test({10, 10, 10}, {20, 20, 20}, 1);

    return 0;
}
