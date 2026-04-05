#include <iostream>
#include <vector>

using namespace std;

double averageWaitingTime(vector<vector<int>>& customers) {
    double waitingTime = 0;
    int time = 0;

    int n = customers.size();
    for(int i = 0; i < n; ++i) {
        if(customers[i][0] > time) {
            time = customers[i][0];
        }

        time += customers[i][1];
        waitingTime += time - customers[i][0];
    }

    return waitingTime / n;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<vector<int>> customers, double expected) {
    cout << "Customers: ";
    for(vector<int> customer : customers) {
        cout << "[" << customer[0] << ", " << customer[1] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << averageWaitingTime(customers) << endl;

    cout << endl;
}

int main() {
    test({{1, 2}, {2, 5}, {4, 3}}, 5);
    test({{5, 2}, {5, 4}, {10, 3}, {20, 1}}, 3.25);
    test({{1, 1}, {2, 1}, {3, 1}}, 1);
    test({{1, 3}, {4, 3}, {7, 3}}, 3);
    test({{1, 2}, {5, 2}, {10, 2}}, 2);

    return 0;
}
