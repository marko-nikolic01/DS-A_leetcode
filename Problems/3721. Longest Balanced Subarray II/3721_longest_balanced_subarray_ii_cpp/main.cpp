#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct LazyTag {
    int to_add = 0;

    LazyTag& operator+=(const LazyTag& other) {
        this->to_add += other.to_add;

        return *this;
    }

    bool has_tag() const {
        return to_add != 0;
    }

    void clear() {
        to_add = 0;
    }
};

struct SegmentTreeNode {
    int min_value = 0;
    int max_value = 0;
    LazyTag lazy_tag;
};

class SegmentTree {
public:
    int n;
    vector<SegmentTreeNode> tree;

    SegmentTree(const vector<int>& data) : n(data.size()) {
        tree.resize(n * 4 + 1);
        build(data, 1, n, 1);
    }

    void add(int l, int r, int val) {
        LazyTag tag{val};
        update(l, r, tag, 1, n, 1);
    }

    int find_last(int start, int val) {
        return start > n ? -1 : find(start, n, val, 1, n, 1);
    }

private:
    inline void apply_tag(int i, const LazyTag& tag) {
        tree[i].min_value += tag.to_add;
        tree[i].max_value += tag.to_add;
        tree[i].lazy_tag += tag;
    }

    inline void pushdown(int i) {
        if(tree[i].lazy_tag.has_tag()) {
            LazyTag tag = tree[i].lazy_tag;
            apply_tag(i << 1, tag);
            apply_tag(i << 1 | 1, tag);
            tree[i].lazy_tag.clear();
        }
    }

    inline void pushup(int i) {
        tree[i].min_value = min(tree[i << 1].min_value, tree[i << 1 | 1].min_value);
        tree[i].max_value = max(tree[i << 1].max_value, tree[i << 1 | 1].max_value);
    }

    void build(const vector<int>& data, int l, int r, int i) {
        if(l == r) {
            tree[i].min_value = tree[i].max_value = data[l - 1];

            return;
        }

        int mid = l + ((r - l) >> 1);
        build(data, l, mid, i << 1);
        build(data, mid + 1, r, i << 1 | 1);
        pushup(i);
    }

    void update(int target_l, int target_r, const LazyTag& tag, int l, int r, int i) {
        if(target_l <= l && r <= target_r) {
            apply_tag(i, tag);

            return;
        }

        pushdown(i);
        int mid = l + ((r - l) >> 1);

        if(target_l <= mid) {
            update(target_l, target_r, tag, l, mid, i << 1);
        }

        if(target_r > mid) {
            update(target_l, target_r, tag, mid + 1, r, i << 1 | 1);
        }

        pushup(i);
    }

    int find(int target_l, int target_r, int val, int l, int r, int i) {
        if(tree[i].min_value > val || tree[i].max_value < val) {
            return -1;
        }

        if(l == r) {
            return l;
        }

        pushdown(i);
        int mid = l + ((r - l) >> 1);

        if(target_r >= mid + 1) {
            int res = find(target_l, target_r, val, mid + 1, r, i << 1 | 1);

            if (res != -1) {
                return res;
            }
        }

        if(l <= target_r && mid >= target_l) {
            return find(target_l, target_r, val, l, mid, i << 1);
        }

        return -1;
    }
};

int longestBalanced(vector<int>& nums) {
    map<int, queue<int>> occurrences;
    auto sgn = [](int x) {
        return (x % 2) == 0 ? 1 : -1;
    };

    int len = 0;
    vector<int> prefix_sum(nums.size(), 0);

    prefix_sum[0] = sgn(nums[0]);
    occurrences[nums[0]].push(1);

    int i;
    for(i = 1; i < nums.size(); ++i) {
        prefix_sum[i] = prefix_sum[i - 1];
        auto& occ = occurrences[nums[i]];

        if(occ.empty()) {
            prefix_sum[i] += sgn(nums[i]);
        }

        occ.push(i + 1);
    }

    SegmentTree seg(prefix_sum);

    for(i = 0; i < nums.size(); ++i) {
        len = max(len, seg.find_last(i + len, 0) - i);

        auto next_pos = nums.size() + 1;
        occurrences[nums[i]].pop();

        if(!occurrences[nums[i]].empty()) {
            next_pos = occurrences[nums[i]].front();
        }

        seg.add(i + 1, next_pos - 1, -sgn(nums[i]));
    }

    return len;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int k, int expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << longestBalanced(nums) << endl;

    cout << endl;
}

int main() {
    test({2, 5, 4, 3}, 0, 4);
    test({3, 2, 2, 5, 4}, 0, 5);
    test({1, 2, 3, 2}, 0, 3);
    test({2, 4, 6}, 0, 0);
    test({1, 2}, 0, 2);

    return 0;
}
