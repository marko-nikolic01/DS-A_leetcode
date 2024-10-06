#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node* connect(Node* root) {
    if(!root) {
        return root;
    }

    queue<Node*> nodes;
    nodes.push(root);

    while(!nodes.empty()) {
        Node* next = nullptr;

        for(int i = nodes.size(); i > 0; --i) {
            nodes.front()->next = next;

            if(nodes.front()->right) {
                nodes.push(nodes.front()->right);
            }

            if(nodes.front()->left) {
                nodes.push(nodes.front()->left);
            }

            next = nodes.front();

            nodes.pop();
        }
    }

    return root;
}

void printTreeLevelByLevel(Node* root) {
    if (!root) {
        cout << endl;
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; ++i) {
            Node* current = q.front();
            q.pop();
            cout << current->val << " ";

            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
        cout << endl;
    }
}

void printTreeLevels(Node* root) {
    Node* levelStart = root;
    while (levelStart) {
        Node* current = levelStart;
        levelStart = nullptr;

        while (current) {
            cout << current->val << " ";
            if (!levelStart && current->left) {
                levelStart = current->left;
            }
            current = current->next;
        }
        cout << "# ";
    }
    cout << endl;
}

void runTest(Node* root, const string& expected) {
    cout << "Tree:" << endl;
    printTreeLevelByLevel(root);

    cout << "Expected: " << expected << endl;

    connect(root);
    cout << "Result:   ";
    printTreeLevels(root);

    cout << endl;
}

int main() {
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->right->right = new Node(6);
    string expected1 = "1 # 2 3 # 4 5 6 # ";
    runTest(root1, expected1);

    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    string expected2 = "1 # 2 3 # ";
    runTest(root2, expected2);

    Node* root3 = new Node(1);
    string expected3 = "1 # ";
    runTest(root3, expected3);

    Node* root4 = nullptr;
    string expected4 = "";
    runTest(root4, expected4);

    return 0;
}
