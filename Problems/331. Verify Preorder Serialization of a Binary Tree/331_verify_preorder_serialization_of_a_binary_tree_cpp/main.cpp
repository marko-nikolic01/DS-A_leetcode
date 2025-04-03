#include <iostream>
#include <vector>

using namespace std;

bool isValidSerialization(string preorder) {
    short capacity = 1;

    short i = 0;
    short n = preorder.length();
    while(i < n) {
        if(capacity < 1) {
            return false;
        }

        if(preorder[i] != '#') {
            while(++i < n && preorder[i] != ',') {}

            ++capacity;
            ++i;
        } else {
            --capacity;
            i += 2;
        }
    }

    return capacity < 1;
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
