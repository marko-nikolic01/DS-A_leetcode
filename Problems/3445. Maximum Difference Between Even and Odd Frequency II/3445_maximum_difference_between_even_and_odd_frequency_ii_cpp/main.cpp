#include <iostream>
#include <climits>

using namespace std;

int maxDifference(string s, int k) {
    auto getStatus = [](int cnt_a, int cnt_b) -> int {
        return ((cnt_a & 1) << 1) | (cnt_b & 1);
    };

    int ans = INT_MIN;

    char b;
    int n = s.size();
    for(char a = '0'; a <= '4'; ++a) {
        for(b = '0'; b <= '4'; ++b) {
            if(a == b) {
                continue;
            }

            int best[4] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX};
            int cnt_a = 0, cnt_b = 0;
            int prev_a = 0, prev_b = 0;
            int left = -1;

            for(int right = 0; right < n; ++right) {
                cnt_a += (s[right] == a);
                cnt_b += (s[right] == b);

                while(right - left >= k && cnt_b - prev_b >= 2) {
                    int left_status = getStatus(prev_a, prev_b);
                    best[left_status] = min(best[left_status], prev_a - prev_b);
                    ++left;
                    prev_a += (s[left] == a);
                    prev_b += (s[left] == b);
                }

                int right_status = getStatus(cnt_a, cnt_b);

                if(best[right_status ^ 0b10] != INT_MAX) {
                    ans = max(ans, cnt_a - cnt_b - best[right_status ^ 0b10]);
                }
            }
        }
    }

    return ans;
}

void test(string s, int k, int expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxDifference(s, k) << endl;

    cout << endl;
}

int main() {
    test("12233", 4, -1);
    test("1122211", 3, 1);
    test("110", 3, -1);
    test("012340123401234", 5, 1);
    test("4441444444", 3, -1);

    return 0;
}
