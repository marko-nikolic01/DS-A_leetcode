#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

long repairCars(vector<int>& ranks, int cars) {
    unordered_map<int, int> count;
    for (int rank : ranks) {
        count[rank] += 1;
    }

    auto comp = [](vector<long>& a, vector<long>& b) {
        return a[0] > b[0];
    };
    priority_queue<vector<long>, vector<vector<long>>, decltype(comp)>
        minHeap(comp);

    for (auto it : count) {
        int rank = it.first;
        minHeap.push({rank, rank, 1, it.second});
    }

    long time = 0;
    while (cars > 0) {
        vector<long> current = minHeap.top();
        minHeap.pop();
        time = current[0];
        int rank = current[1];
        long n = current[2];
        int mechCount = current[3];

        cars -= mechCount;

        n += 1;

        minHeap.push({rank * n * n, rank, n, mechCount});
    }

    return time;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> ranks, int cars, int expected) {
    cout << "Ranks: ";
    printArray(ranks);

    cout << "Cars: " << cars << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << repairCars(ranks, cars) << endl;

    cout << endl;
}

int main() {
    test({4, 2, 3, 1}, 10, 16);
    test({5, 1, 8}, 6, 16);
    test({2, 2, 2}, 6, 8);
    test({3}, 3, 27);
    test({1, 2, 3, 4, 5}, 15, 27);

    return 0;
}
