#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

vector<vector<int>> levelOrder(Node* root) {
    if(!root) {
        return {};
    }

    vector<vector<int>> traversal;

    queue<Node*> nodes;
    nodes.push(root);

    while(!nodes.empty()) {
        vector<int> level;

        for(int i = nodes.size(); i > 0; --i) {
            level.push_back(nodes.front()->val);

            int n = nodes.front()->children.size();
            for(int j = 0; j < n; ++j) {
                nodes.push(nodes.front()->children[j]);
            }

            nodes.pop();
        }

        traversal.push_back(level);
    }

    return traversal;
}

void printTreeLevelByLevel(Node* root) {
    if (!root) return;

    queue<Node*> nodes;
    nodes.push(root);

    while (!nodes.empty()) {
        int levelSize = nodes.size();
        for (int i = 0; i < levelSize; ++i) {
            Node* currentNode = nodes.front();
            cout << currentNode->val << " ";
            nodes.pop();

            for (Node* child : currentNode->children) {
                nodes.push(child);
            }
        }
        cout << endl;
    }
}

void testLevelOrder(Node* root, const vector<vector<int>>& expected) {
    cout << "Tree:" << endl;
    printTreeLevelByLevel(root);

    cout << "Expected: ";
    for (const auto& level : expected) {
        cout << "[ ";
        for (int val : level) {
            cout << val << " ";
        }
        cout << "] ";
    }
    cout << endl;

    vector<vector<int>> result = levelOrder(root);
    cout << "Result: ";
    for (const auto& level : result) {
        cout << "[ ";
        for (int val : level) {
            cout << val << " ";
        }
        cout << "] ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    Node* root1 = new Node(1, {
        new Node(3, {new Node(5), new Node(6)}),
        new Node(2),
        new Node(4)
    });
    testLevelOrder(root1, {{1}, {3, 2, 4}, {5, 6}});

    Node* root2 = new Node(0, {
        new Node(1),
        new Node(2, {new Node(3)}),
        new Node(4)
    });
    testLevelOrder(root2, {{0}, {1, 2, 4}, {3}});

    Node* root3 = nullptr;
    testLevelOrder(root3, {});

    return 0;
}
