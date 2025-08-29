#include <iostream>
#include <vector>

using namespace std;

void maximumRequests(vector<short>& buildings, vector<vector<int>>& requests, int& maxRequests, short fulfilledRequests, short disbalance, short i) {
    if(i < 0) {
        if(disbalance < 1 && fulfilledRequests > maxRequests) {
            maxRequests = fulfilledRequests;
        }

        return;
    }

    if(--buildings[requests[i][0]] == -1) {
        ++disbalance;
    } else if(buildings[requests[i][0]] == 0) {
        --disbalance;
    }

    if(++buildings[requests[i][1]] == 1) {
        ++disbalance;
    } else if(buildings[requests[i][1]] == 0) {
        --disbalance;
    }

    maximumRequests(buildings, requests, maxRequests, fulfilledRequests + 1, disbalance, i -1);

    if(++buildings[requests[i][0]] == 1) {
        ++disbalance;
    } else if(buildings[requests[i][0]] == 0) {
        --disbalance;
    }

    if(--buildings[requests[i][1]] == -1) {
        ++disbalance;
    } else if(buildings[requests[i][1]] == 0) {
        --disbalance;
    }

    maximumRequests(buildings, requests, maxRequests, fulfilledRequests, disbalance, i - 1);
}

int maximumRequests(int n, vector<vector<int>>& requests) {
    vector<short> buildings(n, 0);
    n = 0;

    maximumRequests(buildings, requests, n, 0, 0, requests.size() - 1);

    return n;
}

void test(int n, vector<vector<int>> requests, int expected) {
    cout << "n: " << n << endl;

    cout << "Requests: ";
    for(vector<int> request : requests) {
        cout << "[" << request[0] << ", " << request[1] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maximumRequests(n, requests) << endl;

    cout << endl;
}

int main() {
    test(5, {{0, 1}, {1, 0}, {0, 1}, {1, 2}, {2, 0}, {3, 4}}, 5);
    test(3, {{0, 0}, {1, 2}, {2, 1}}, 3);
    test(4, {{0, 3}, {3, 1}, {1, 2}, {2, 0}}, 4);
    test(2, {{0, 1}}, 0);
    test(3, {{0, 1}, {1, 2}, {2, 0}, {0, 2}}, 3);

    return 0;
}
