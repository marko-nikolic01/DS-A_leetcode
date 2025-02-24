#include <iostream>
#include <vector>

using namespace std;

void mostProfitablePath(vector<vector<int>>& tree, vector<int>& bobPath, int node, int parent, int& bob) {
    bobPath.push_back(node);

    if(node == bob) {
        return;
    }

    for(int i = tree[node].size() - 1; i > -1; --i) {
        if(tree[node][i] != parent) {
            mostProfitablePath(tree, bobPath, tree[node][i], node, bob);

            if(bobPath.back() == bob) {
                return;
            }
        }
    }

    bobPath.pop_back();
}

void mostProfitablePath(vector<vector<int>>& tree, vector<int>& amount, vector<int>& bobPath, int node, int parent, int& bobIndex, int currentIncome, int& income) {
    int tempAmount;

    if(bobIndex > -1) {
        tempAmount = amount[bobPath[bobIndex]];
        amount[bobPath[bobIndex]] = 0;

        currentIncome += node == bobPath[bobIndex] ? tempAmount / 2 : amount[node];
    } else {
        currentIncome += amount[node];
    }

    int i = tree[node].size();
    if(node != 0 && i == 1) {
        if(currentIncome > income) {
            income = currentIncome;
        }
    } else {
        --bobIndex;
        for(--i; i > -1; --i) {
            if(tree[node][i] != parent) {
                mostProfitablePath(tree, amount, bobPath, tree[node][i], node, bobIndex, currentIncome, income);
            }
        }
        ++bobIndex;
    }

    if(bobIndex > -1) {
        amount[bobPath[bobIndex]] = tempAmount;
    }
}

int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
    int n = edges.size();
    vector<vector<int>> tree(n + 1);

    for(--n; n > -1; --n) {
        tree[edges[n][0]].push_back(edges[n][1]);
        tree[edges[n][1]].push_back(edges[n][0]);
    }

    vector<int> bobPath;
    mostProfitablePath(tree, bobPath, 0, 0, bob);

    n = -2147483648;
    bob = bobPath.size() - 1;
    mostProfitablePath(tree, amount, bobPath, 0, 0, bob, 0, n);

    return n;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<vector<int>> edges, int bob, vector<int> amount, int expected) {
    cout << "Edges: ";
    for(vector<int> edge : edges) {
        cout << "[" << edge[0] << " " << edge[1] << "] ";
    }
    cout << endl;

    cout << "Bob: " << bob << endl;

    cout << "Amounts: ";
    printArray(amount);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << mostProfitablePath(edges, bob, amount) << endl;

    cout << endl;
}

int main() {
    test({{0, 1}, {1, 2}, {1, 3}, {3, 4}}, 3, {-2, 4, 2, -4, 6}, 6);
    test({{0, 1}}, 1, {-7280, 2350}, -7280);
    test({{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}}, 5, {-10, -20, -30, -40, -50, 100}, -60);
    test({{0, 1}, {1, 2}, {2, 3}, {1, 4}}, 4, {-5, 10, -10, 20, -30}, 10);
    test({{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}}, 6, {-8, 2, 4, 10, -6, -12, 14}, 4);
    test({{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}}, 6, {-100, 20, 30, 40, 50, 60, 70}, -30);

    return 0;
}
