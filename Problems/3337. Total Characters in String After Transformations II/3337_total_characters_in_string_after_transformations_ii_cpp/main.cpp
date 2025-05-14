#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct Mat {
    Mat() { memset(a, 0, sizeof(a)); }
    Mat(const Mat& that) {
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                a[i][j] = that.a[i][j];
            }
        }
    }
    Mat& operator=(const Mat& that) {
        if (this != &that) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    a[i][j] = that.a[i][j];
                }
            }
        }
        return *this;
    }

    int a[26][26];
};

Mat operator*(const Mat& u, const Mat& v) {
    Mat w;
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            for (int k = 0; k < 26; ++k) {
                w.a[i][j] =
                    (w.a[i][j] + (long long)u.a[i][k] * v.a[k][j]) % 1000000007;
            }
        }
    }
    return w;
}

Mat I() {
    Mat w;
    for (int i = 0; i < 26; ++i) {
        w.a[i][i] = 1;
    }
    return w;
}

Mat quickmul(const Mat& x, int y) {
    Mat ans = I(), cur = x;
    while (y) {
        if (y & 1) {
            ans = ans * cur;
        }
        cur = cur * cur;
        y >>= 1;
    }
    return ans;
}

int lengthAfterTransformations(string s, int t, vector<int>& nums) {
    Mat T;
    for (int i = 0; i < 26; ++i) {
        for (int j = 1; j <= nums[i]; ++j) {
            T.a[(i + j) % 26][i] = 1;
        }
    }
    Mat res = quickmul(T, t);
    int ans = 0;
    vector<int> f(26);
    for (char ch : s) {
        ++f[ch - 'a'];
    }
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            ans = (ans + (long long)res.a[i][j] * f[j]) % 1000000007;
        }
    }
    return ans;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(string s, int t, vector<int> nums, int expected) {
    int result = lengthAfterTransformations(s, t, nums);
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "t: " << t << endl;

    cout << "Numbers: ";
    printArray(nums);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << lengthAfterTransformations(s, t, nums) << endl;

    cout << endl;
}

int main() {
    test("abcyy", 2, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2}, 7);
    test("azbk", 1, {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}, 8);
    test("z", 5, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 1);
    test("leetcode", 3, {2, 3, 1, 4, 2, 3, 1, 2, 1, 3, 2, 1, 2, 3, 2, 1, 3, 1, 2, 1, 3, 2, 1, 4, 1, 2}, 59);
    test("abcxyz", 1, {25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25}, 150);

    return 0;
}
