#include <iostream>
#include <vector>

using namespace std;

int closestMeetingNode(vector<int>& edges, int node1, int node2) {
    int n = edges.size();
    vector<int> paths(n, -1);
    vector<short> visited(n, 0);
    int path = 0;

    while(node1 > -1) {
        if(visited[node1] > 0) {
            break;
        }
        ++visited[node1];

        paths[node1] = path++;
        node1 = edges[node1];
    }

    path = 0;

    while(node2 > -1) {
        if(visited[node2] > 1) {
            break;
        }
        visited[node2] += 2;

        if(path > paths[node2]) {
            paths[node2] = path;
        }
        ++path;
        node2 = edges[node2];
    }

    int node = -1;
    path = n;

    for(--n; n > -1; --n) {
        if(visited[n] > 2 && (paths[n] < path || (paths[n] == path && n < node))) {
            node = n;
            path = paths[n];
        }
    }

    return node;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> edges, int node1, int node2, int expected) {
    cout << "Edges: ";
    printArray(edges);

    cout << "Node 1: " << node1 << endl;

    cout << "Node 2: " << node2 << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << closestMeetingNode(edges, node1, node2) << endl;

    cout << endl;
}

int main() {
    test({2, 2, 3, -1}, 0, 1, 2);
    test({1, 2, -1}, 0, 2, 2);
    test({2, 0, 0}, 2, 0, 0);
    test({1, -1, 3, -1}, 0, 2, -1);
    test({1, 2, 0, 4, 5, 3}, 0, 3, -1);
    test({1, 2, 3, 4, 5, -1}, 0, 2, 2);

    return 0;
}
