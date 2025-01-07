#include <iostream>
#include <vector>

using namespace std;

int countGoodNodes(vector<vector<int>>& tree, int node, int parent, int& goodNodes) {
    int nodes = 1;
    bool isGoodNode = true;

    int i = tree[node].size();
    if(i > 0) {
        for(--i; i > -1; --i) {
            if(tree[node][i] != parent) {
                int subtreeNodes = countGoodNodes(tree, tree[node][i], node, goodNodes);
                nodes += subtreeNodes;

                for(--i; i > -1; --i) {
                    if(tree[node][i] != parent) {
                        int currentSubtreeNodes = countGoodNodes(tree, tree[node][i], node, goodNodes);
                        nodes += currentSubtreeNodes;

                        if(currentSubtreeNodes != subtreeNodes) {
                            isGoodNode = false;

                            for(--i; i > -1; --i) {
                                if(tree[node][i] != parent) {
                                    currentSubtreeNodes = countGoodNodes(tree, tree[node][i], node, goodNodes);
                                    nodes += currentSubtreeNodes;
                                }
                            }

                            break;
                        }
                    }
                }

                break;
            }
        }
    }

    if(isGoodNode) {
        ++goodNodes;
    }

    return nodes;
}

int countGoodNodes(vector<vector<int>>& edges) {
    int i = edges.size();
    vector<vector<int>> tree(i + 1);

    for(--i; i > -1; --i) {
        tree[edges[i][0]].push_back(edges[i][1]);
        tree[edges[i][1]].push_back(edges[i][0]);
    }

    int goodNodes = 0;

    countGoodNodes(tree, 0, -1, goodNodes);

    return goodNodes;
}

void runTest(vector<vector<int>> edges, int expected) {
    cout << "Edges: ";
    for (vector<int> edge : edges) {
        cout << "[" << edge[0] << " " << edge[1] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countGoodNodes(edges) << endl;

    cout << endl;
}

int main() {
    vector<vector<int>> edges1 = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}};
    runTest(edges1, 7);

    vector<vector<int>> edges2 = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {0, 5}, {1, 6}, {2, 7}};
    runTest(edges2, 5);

    vector<vector<int>> edges3 = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {3, 7}, {3, 8}};
    runTest(edges3, 7);

    vector<vector<int>> edges4 = {{0, 1}, {1, 2}, {1, 3}, {1, 4}, {0, 5}, {5, 6}, {6, 7}, {7, 8}, {0, 9}, {9, 10}, {9, 12}, {10, 11}};
    runTest(edges4, 12);

    vector<vector<int>> edges5 = {{0, 1}};
    runTest(edges5, 2);

    return 0;
}
