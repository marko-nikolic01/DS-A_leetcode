#include <iostream>
#include <vector>

using namespace std;

int placedCoins(vector<vector<int>>& tree, vector<int>& cost, int node, int parent, vector<int>& costs5, vector<long long>& coins) {
    int nodes = 1;

    vector<int> subtreeCosts5 = {cost[node] > -1 ? cost[node] : 0, 0, 0, cost[node] < 0 ? cost[node] : 0, 0};

    for(int i = tree[node].size() - 1; i > -1; --i) {
        if(tree[node][i] != parent) {
            nodes += placedCoins(tree, cost, tree[node][i], node, subtreeCosts5, coins);
        }
    }

    if(subtreeCosts5[0] >= costs5[0]) {
        costs5[2] = costs5[1];
        costs5[1] = costs5[0];
        costs5[0] = subtreeCosts5[0];

        if(subtreeCosts5[1] >= costs5[1]) {
            costs5[2] = costs5[1];
            costs5[1] = subtreeCosts5[1];

            if(subtreeCosts5[2] > costs5[2]) {
                costs5[2] = subtreeCosts5[2];
            }
        } else if(subtreeCosts5[1] > costs5[2]) {
            costs5[2] = subtreeCosts5[1];
        }
    } else if(subtreeCosts5[0] >= costs5[1]) {
        costs5[2] = costs5[1];
        costs5[1] = subtreeCosts5[0];

        if(subtreeCosts5[1] > costs5[2]) {
            costs5[2] = subtreeCosts5[1];
        }
    } else if(subtreeCosts5[0] > costs5[2]) {
        costs5[2] = subtreeCosts5[0];
    }

    if(subtreeCosts5[3] <= costs5[3]) {
        costs5[4] = costs5[3];
        costs5[3] = subtreeCosts5[3];

        if(subtreeCosts5[4] < costs5[4]) {
            costs5[4] = subtreeCosts5[4];
        }
    } else if(subtreeCosts5[3] < costs5[4]) {
        costs5[4] = subtreeCosts5[3];
    }

    if(nodes < 3) {
        coins[node] = 1;
    } else {
        coins[node] = max((long long)subtreeCosts5[0] * subtreeCosts5[1] * subtreeCosts5[2], (long long)subtreeCosts5[0] * subtreeCosts5[3] * subtreeCosts5[4]);
    }

    return nodes;
}

vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
    int n = edges.size();
    vector<vector<int>> tree(++n);
    vector<long long> coins(n, 1);

    for(n -= 2; n > -1; --n) {
        tree[edges[n][0]].push_back(edges[n][1]);
        tree[edges[n][1]].push_back(edges[n][0]);
    }

    vector<int> max3Costs = {0, 0, 0, 0, 0};

    placedCoins(tree, cost, 0, 0, max3Costs, coins);

    return coins;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void printArray(vector<long long> array) {
    for(long long a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<vector<int>> edges, vector<int> cost, vector<long long> expected) {
    cout << "Edges: ";
    for(vector<int> edge : edges) {
        cout << "[" << edge[0] << " " << edge[1] << "] ";
    }
    cout << endl;

    cout << "Cost: ";
    printArray(cost);

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(placedCoins(edges, cost));

    cout << endl;
}

int main() {
    test({{0,1},{0,2},{0,3},{0,4},{0,5}}, {1,2,3,4,5,6}, {120,1,1,1,1,1});
    test({{0,1},{0,2},{1,3},{1,4},{1,5},{2,6},{2,7},{2,8}}, {1,4,2,3,5,7,8,-4,2}, {280,140,32,1,1,1,1,1,1});
    test({{0,1},{0,2}}, {1,2,-2}, {0,1,1});
    test({{0,1}}, {1,2}, {1,1});
    test({{0,2},{5,2},{1,5},{7,4},{4,8},{1,8},{1,6},{6,3},{9,3}}, {6,93,59,-14,1,-71,-87,95,16,-12}, {586815,141360,586815,1,1,586815,0,1,1520,1});

    return 0;
}
