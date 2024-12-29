#include <iostream>
#include <vector>
#include <unordered_map>
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

int findFrequentTreeSum(TreeNode* root, unordered_map<int, int>& sums, int& maxFrequency) {
    int sum = root->val;

    if(root->left) {
        sum += findFrequentTreeSum(root->left, sums, maxFrequency);
    }

    if(root->right) {
        sum += findFrequentTreeSum(root->right, sums, maxFrequency);
    }

    if(sums.find(sum) == sums.end()) {
        sums[sum] = 1;
    } else if(++sums[sum] > maxFrequency) {
        maxFrequency = sums[sum];
    }

    return sum;
}

vector<int> findFrequentTreeSum(TreeNode* root) {
    unordered_map<int, int> sums;
    int maxFrequency = 1;

    findFrequentTreeSum(root, sums, maxFrequency);

    vector<int> mostFrequentSums;

    for(unordered_map<int, int>::iterator it = sums.begin(); it != sums.end(); ++it) {
        if(it->second == maxFrequency) {
            mostFrequentSums.push_back(it->first);
        }
    }

    return mostFrequentSums;
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

void test(TreeNode* root, vector<int> expected) {
    cout << "Tree: ";
    printTree(root);

    cout << "Expected: ";
    for (int e : expected) {
        cout << e << " ";
    }
    cout << endl;

    cout << "Result: ";
    for (int result : findFrequentTreeSum(root)) {
        cout << result << " ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(5);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(-3);
    test(root1, {4, -3, 2});

    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(-5);
    test(root2, {2});

    TreeNode* root3 = new TreeNode(1);
    root3->left = new TreeNode(-1);
    root3->right = new TreeNode(1);
    test(root3, {1});

    TreeNode* root4 = new TreeNode(-1);
    root4->left = new TreeNode(-1);
    root4->right = new TreeNode(-1);
    test(root4, {-1});

    TreeNode* root5 = new TreeNode(1);
    root5->left = new TreeNode(2);
    root5->right = new TreeNode(3);
    test(root5, {6, 3, 2});

    TreeNode* root6 = new TreeNode(1);
    root6->left = new TreeNode(-1);
    root6->right = new TreeNode(2);
    root6->right->left = new TreeNode(-1);
    test(root6, {1, -1});

    return 0;
}
