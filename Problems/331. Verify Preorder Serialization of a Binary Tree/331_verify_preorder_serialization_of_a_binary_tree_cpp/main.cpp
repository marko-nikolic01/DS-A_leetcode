#include <iostream>
#include <vector>

using namespace std;

bool isValidSerialization(string preorder) {
    vector<bool> traversal = {true};
    short nTraversal = 0;

    short i = 0;
    short n = preorder.length();
    while(i < n) {
        if(nTraversal < 0) {
            return false;
        }

        if(preorder[i] != '#') {
            while(++i < n && preorder[i] != ',') {}

            if(traversal[nTraversal]) {
                traversal.pop_back();
                --nTraversal;
            } else {
                traversal[nTraversal] = true;
            }

            traversal.push_back(false);
            ++nTraversal;

            ++i;
        } else {
            if(traversal[nTraversal]) {
                traversal.pop_back();
                --nTraversal;
            } else {
                traversal[nTraversal] = true;
            }

            i += 2;
        }
    }

    return nTraversal < 0;
}

void test(string preorder, bool expected) {
    cout << "Preorder traversal: " << preorder << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (isValidSerialization(preorder) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test("9,3,4,#,#,1,#,#,2,#,6,#,#", true);
    test("1,#", false);
    test("9,#,#,1", false);
    test("#", true);
    test("9,3,4,#,#,1,#,#,#", true);

    return 0;
}
