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

void postorder(Node* root, vector<int>& traversal) {
    if(!root) {
        return;
    }

    int n = root->children.size();
    for(int i = 0; i < n; ++i) {
        postorder(root->children[i], traversal);
    }

    traversal.push_back(root->val);
}

vector<int> postorder(Node* root) {
    vector<int> traversal;

    postorder(root, traversal);

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

    vector<int> result = postorder(root);

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
    vector<int> expected1 = {5, 6, 3, 2, 4, 1};
    runTestCase(root1, expected1);

    Node* root2 = new Node(1, {
        new Node(2),
        new Node(3, { new Node(6), new Node(7, { new Node(11, { new Node(14) }) }) }),
        new Node(4, { new Node(8, { new Node(12) }) }),
        new Node(5, { new Node(9, { new Node(13) }), new Node(10) })
    });
    vector<int> expected2 = {2, 6, 14, 11, 7, 3, 12, 8, 4, 13, 9, 10, 5, 1};
    runTestCase(root2, expected2);

    Node* root3 = nullptr;
    vector<int> expected3 = {};
    runTestCase(root3, expected3);

    return 0;
}
