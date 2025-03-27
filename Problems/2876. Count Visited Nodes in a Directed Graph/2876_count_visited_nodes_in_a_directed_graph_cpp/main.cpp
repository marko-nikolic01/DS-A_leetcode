#include <iostream>
#include <vector>

using namespace std;

vector<int> countVisitedNodes(vector<int>& edges) {
    int n = edges.size();
    vector<int> visited(n, 0);

    int order;
    int visitedNodes;
    int cycleVisitedNodes;
    int currentNode;

    for(--n; n > -1; --n) {
        if(visited[n] == 0) {
            order = -1;
            visited[n] = -1;

            currentNode = edges[n];
            while(visited[currentNode] == 0) {
                visited[currentNode] = --order;
                currentNode = edges[currentNode];
            }

            if(visited[currentNode] < 0) {
                visitedNodes = visited[currentNode];
                cycleVisitedNodes = visitedNodes - --order;
                visitedNodes = -visitedNodes + cycleVisitedNodes;

                while(visited[currentNode] < 0) {
                    visited[currentNode] = cycleVisitedNodes;
                    currentNode = edges[currentNode];
                }
            } else {
                visitedNodes = visited[currentNode] - --order;
            }

            currentNode = n;
            while(visited[currentNode] < 0) {
                visited[currentNode] = --visitedNodes;
                currentNode = edges[currentNode];
            }
        }
    }

    return visited;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> edges, vector<int> expected) {
    cout << "Edges: ";
    printArray(edges);

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(countVisitedNodes(edges));

    cout << endl;
}

int main() {
    test({1, 2, 0, 0}, {3, 3, 3, 4});
    test({1, 2, 3, 4, 0}, {5, 5, 5, 5, 5});
    test({2, 0, 1, 4, 3}, {3, 3, 3, 2, 2});
    test({1, 0}, {2, 2});
    test({1, 2, 3, 4, 5, 0}, {6, 6, 6, 6, 6, 6});
    test({3, 6, 1, 0, 5, 7, 4, 3}, {2, 7, 8, 2, 5, 4, 6, 3});

    return 0;
}
