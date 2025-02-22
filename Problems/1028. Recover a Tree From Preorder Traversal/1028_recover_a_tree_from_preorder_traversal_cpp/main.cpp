#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* recoverFromPreorder(string traversal) {
    vector<TreeNode*> nodes = {new TreeNode()};
    short nNodes = 0;

    int i = 0;
    int n = traversal.size();

    short level;
    while(i < n) {
        level = 0;
        while(traversal[i] == '-') {
            ++level;
            ++i;
        }

        TreeNode* node = new TreeNode();
        while(i < n && traversal[i] != '-') {
            node->val = 10 * node->val + traversal[i++] - '0';
        }

        while(level < nNodes) {
            nodes.pop_back();
            --nNodes;
        }

        if(nodes[nNodes]->left) {
            nodes[nNodes]->right = node;
        } else {
            nodes[nNodes]->left = node;
        }

        nodes.push_back(node);
        ++nNodes;
    }

    return nodes[0]->left;
}

void printTree(TreeNode* root) {
    if (!root) {
        cout << endl;
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        cout << endl;
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* current = q.front();
            q.pop();

            if (current) {
                cout << current->val << " ";
                q.push(current->left);
                q.push(current->right);
            }
        }
    }
}

void test(string traversal, TreeNode* expected) {
    cout << "Traversal: " << traversal << endl;

    cout << "Expected:";
    printTree(expected);

    cout << "Result:";
    printTree(recoverFromPreorder(traversal));

    cout << endl;
}

int main() {
    string traversal1 = "1-2--3--4-5--6--7";
    TreeNode* expected1 = new TreeNode(1);
    expected1->left = new TreeNode(2);
    expected1->right = new TreeNode(5);
    expected1->left->left = new TreeNode(3);
    expected1->left->right = new TreeNode(4);
    expected1->right->left = new TreeNode(6);
    expected1->right->right = new TreeNode(7);
    test(traversal1, expected1);

    string traversal2 = "1-2--3---4-5--6---7";
    TreeNode* expected2 = new TreeNode(1);
    expected2->left = new TreeNode(2);
    expected2->left->left = new TreeNode(3);
    expected2->left->left->left = new TreeNode(4);
    expected2->right = new TreeNode(5);
    expected2->right->left = new TreeNode(6);
    expected2->right->left->left = new TreeNode(7);
    test(traversal2, expected2);

    string traversal3 = "1-401--349---90--88";
    TreeNode* expected3 = new TreeNode(1);
    expected3->left = new TreeNode(401);
    expected3->left->left = new TreeNode(349);
    expected3->left->left->left = new TreeNode(90);
    expected3->left->right = new TreeNode(88);
    test(traversal3, expected3);

    string traversal4 = "1-2--3---4----5-6--7---8";
    TreeNode* expected4 = new TreeNode(1);
    expected4->left = new TreeNode(2);
    expected4->left->left = new TreeNode(3);
    expected4->left->left->left = new TreeNode(4);
    expected4->left->left->left->left = new TreeNode(5);
    expected4->right = new TreeNode(6);
    expected4->right->left = new TreeNode(7);
    expected4->right->left->left = new TreeNode(8);
    test(traversal4, expected4);

    string traversal5 = "1-10--11---12----13-14--15";
    TreeNode* expected5 = new TreeNode(1);
    expected5->left = new TreeNode(10);
    expected5->left->left = new TreeNode(11);
    expected5->left->left->left = new TreeNode(12);
    expected5->left->left->left->left = new TreeNode(13);
    expected5->right = new TreeNode(14);
    expected5->right->left = new TreeNode(15);
    test(traversal5, expected5);

    return 0;
}
