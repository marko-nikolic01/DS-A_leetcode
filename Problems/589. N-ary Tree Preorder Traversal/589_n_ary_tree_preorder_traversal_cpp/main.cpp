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

void preorder(Node* root, vector<int>& traversal) {
     if(!root) {
        return;
     }

     traversal.push_back(root->val);

     int n = root->children.size();
     for(int i = 0; i < n; ++i) {
        preorder(root->children[i], traversal);
     }
}

vector<int> preorder(Node* root) {
     vector<int> traversal;

     preorder(root, traversal);

     return traversal;
}

void printTree(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            Node* curr = q.front();
            q.pop();
            cout << curr->val << " ";
            for (Node* child : curr->children) {
                q.push(child);
            }
        }
        cout << endl;
    }
}

void runTestCase(Node* root, vector<int> expected) {
    cout << "Tree:" << endl;
    printTree(root);

    cout << "Expected: ";
    for (int val : expected) {
        cout << val << " ";
    }
    cout << endl;

    vector<int> result = preorder(root);

    cout << "Result: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    cout << endl;
}

int main() {
    Node* root1 = new Node(1, {
        new Node(3, { new Node(5), new Node(6) }),
        new Node(2),
        new Node(4)
    });
    vector<int> expected1 = {1, 3, 5, 6, 2, 4};
    runTestCase(root1, expected1);

    Node* root2 = new Node(1, {
        new Node(2),
        new Node(3, { new Node(6), new Node(7, { new Node(11, { new Node(14) }) }) }),
        new Node(4, { new Node(8, { new Node(12) }) }),
        new Node(5, { new Node(9, { new Node(13) }), new Node(10) })
    });
    vector<int> expected2 = {1, 2, 3, 6, 7, 11, 14, 4, 8, 12, 5, 9, 13, 10};
    runTestCase(root2, expected2);

    Node* root3 = nullptr;
    vector<int> expected3 = {};
    runTestCase(root3, expected3);

    return 0;
}
