#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
    int n = tasks.size(), m = workers.size();
    sort(tasks.begin(), tasks.end());
    sort(workers.begin(), workers.end());

    auto check = [&](int mid) -> bool {
        int p = pills;
        deque<int> ws;
        int ptr = m - 1;
        for (int i = mid - 1; i >= 0; --i) {
            while (ptr >= m - mid && workers[ptr] + strength >= tasks[i]) {
                ws.push_front(workers[ptr]);
                --ptr;
            }
            if (ws.empty()) {
                return false;
            }
            else if (ws.back() >= tasks[i]) {
                ws.pop_back();
            } else {
                if (!p) {
                    return false;
                }
                --p;
                ws.pop_front();
            }
        }
        return true;
    };

    int left = 1, right = min(m, n), ans = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (check(mid)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> tasks, vector<int> workers, int pills, int strength, int expected) {
    cout << "Tasks: ";
    printArray(tasks);

    cout << "Workers: ";
    printArray(workers);

    cout << "Pills: " << pills << endl;

    cout << "Strength: " << strength << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxTaskAssign(tasks, workers, pills, strength) << endl;

    cout << endl;
}

int main() {
    test({1, 2, 3}, {3, 3, 3}, 0, 0, 3);
    test({5, 4}, {0, 0, 0}, 1, 5, 1);
    test({10, 15, 30}, {0, 10, 10, 10, 10}, 3, 10, 2);
    test({8, 9, 10}, {1, 2, 3}, 2, 5, 1);
    test({10, 20, 30}, {1, 1, 1, 50, 50}, 5, 50, 3);

    return 0;
}
