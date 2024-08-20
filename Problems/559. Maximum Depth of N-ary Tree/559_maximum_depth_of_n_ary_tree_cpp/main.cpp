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

int maxDepth(Node* root) {
    if(!root) {
        return 0;
    }

    int depth = 1;

    int n = root->children.size();
    for(int i = 0; i < n; ++i) {
        int childDepth = maxDepth(root->children[i]);

        if(++childDepth > depth) {
            depth = childDepth;
        }
    }

    return depth;
}

void printTree(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        while (levelSize--) {
            Node* node = q.front();
            q.pop();
            cout << node->val << " ";
            for (Node* child : node->children) {
                q.push(child);
            }
        }
        cout << endl;
    }
}

void test() {
    Node* root1 = new Node(1, {
        new Node(3, { new Node(5), new Node(6) }),
        new Node(2),
        new Node(4)
    });
    cout << "Tree 1:" << endl;
    printTree(root1);
    cout << "Expected Depth: 3" << endl;
    cout << "Result: " << maxDepth(root1) << endl;
    cout << endl;

    Node* root2 = new Node(1, {
        new Node(2, { new Node(3, { new Node(4) }) }),
        new Node(5)
    });
    cout << "Tree 2:" << endl;
    printTree(root2);
    cout << "Expected Depth: 4" << endl;
    cout << "Result: " << maxDepth(root2) << endl;
    cout << endl;

    Node* root3 = new Node(1);
    cout << "Tree 3:" << endl;
    printTree(root3);
    cout << "Expected Depth: 1" << endl;
    cout << "Result: " << maxDepth(root3) << endl;
    cout << endl;

    Node* root4 = new Node(1, {
        new Node(2),
        new Node(3),
        new Node(4, { new Node(5), new Node(6, { new Node(7) }) })
    });
    cout << "Tree 4:" << endl;
    printTree(root4);
    cout << "Expected Depth: 4" << endl;
    cout << "Result: " << maxDepth(root4) << endl;
}

int main()
{
    test();
    return 0;
}
