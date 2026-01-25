#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
    vector<vector<int>> changes(26, vector<int>(26, -1));
    vector<int> costs(26);
    short letter1;
    short letter2;

    int i;
    for(i = original.size() - 1; i > -1; --i) {
        original[i] -= 'a';
        changed[i] -= 'a';

        if(changes[original[i]][changed[i]] < 0 || cost[i] < changes[original[i]][changed[i]]) {
            changes[original[i]][changed[i]] = cost[i];
        }
    }

    priority_queue<pair<int, short>, vector<pair<int, short>>, greater<pair<int, short>>> traversal;
    int currentCost;
    short letter;

    short j;
    for(i = 0; i < 26; ++i) {
        for(j = 0; j < 26; ++j) {
            costs[j] = -1;
        }

        costs[i] = 0;
        traversal.push({0, i});

        while(!traversal.empty()) {
            currentCost = traversal.top().first;
            letter = traversal.top().second;
            traversal.pop();

            if(costs[letter] < currentCost) {
                continue;
            }

            for(j = 0; j < 26; ++j) {
                if(changes[letter][j] > 0 && (costs[j] < 0 || currentCost + changes[letter][j] < costs[j])) {
                    costs[j] = currentCost + changes[letter][j];
                    traversal.push({costs[j], j});
                }
            }
        }

        for(j = 0; j < 26; ++j) {
            changes[i][j] = costs[j];
        }
    }

    long costSum = 0;

    for(i = source.length() - 1; i > -1; --i) {
        source[i] -= 'a';
        target[i] -= 'a';

        if(changes[source[i]][target[i]] < 0) {
            return -1;
        }

        costSum += changes[source[i]][target[i]];
    }

    return costSum;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void printArray(vector<char> array) {
    for(char a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(string source, string target, vector<char> original, vector<char> changed, vector<int> cost, long long expected) {
    cout << "Source: " << "\"" << source << "\"" << endl;

    cout << "Target: " << "\"" << target << "\"" << endl;

    cout << "Original: ";
    printArray(original);

    cout << "Changed: ";
    printArray(changed);

    cout << "Costs: ";
    printArray(cost);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minimumCost(source, target, original, changed, cost) << endl;

    cout << endl;
}

int main() {
    test("abcd", "acbe", {'a', 'b', 'c', 'c', 'e', 'd'}, {'b', 'c', 'b', 'e', 'b', 'e'}, {2, 5, 5, 1, 2, 20}, 28);
    test("aaaa", "bbbb", {'a', 'c'}, {'c', 'b'}, {1, 2}, 12);
    test("abcd", "abce", {'a'}, {'e'}, {10000}, -1);
    test("abc", "abc", {'a', 'b'}, {'b', 'c'}, {5, 7}, 0);
    test("xyz", "aaa", {'x', 'y', 'z'}, {'a', 'a', 'a'}, {3, 4, 5}, 12);

    return 0;
}
