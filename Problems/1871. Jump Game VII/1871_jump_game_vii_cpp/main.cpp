#include <iostream>
#include <vector>

using namespace std;

bool canReach(string s, int minJump, int maxJump) {
    int n = s.length();
    vector<int> jumps(n--, 0);
    int canJump = 1;

    --jumps[0];
    --minJump;

    for(int i = 0; i < n; ++i) {
        if(s[i] < '1' && canJump > 0 && i + minJump < n) {
            ++jumps[i + minJump];
            --jumps[min(i + maxJump, n)];
        }

        canJump += jumps[i];
    }

    return s[n] < '1' && canJump > 0;
}

void test(string s, int minJump, int maxJump, bool expected) {
    cout << "String: " << s << endl;

    cout << "Minimum jump: " << minJump << endl;

    cout << "Maximum jump: " << maxJump << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (canReach(s, minJump, maxJump) ? "true" : "false") << endl;

    cout << endl;
}

int main()
{
    test("011010", 2, 3, true);
    test("01101110", 2, 3, false);
    test("01", 1, 1, false);
    test("00", 1, 1, true);
    test("010", 1, 2, true);
    test("0000000000", 2, 3, true);

    return 0;
}
