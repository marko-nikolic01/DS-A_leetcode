#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <bitset>

using namespace std;

struct Node {
    long value;
    int left;
};

struct Pair {
    list<Node>::iterator first;
    list<Node>::iterator second;
    long cost;
    size_t firstLeft;
    size_t secondLeft;

    Pair() {}

    Pair(list<Node>::iterator fi, list<Node>::iterator se, long cost) : first(fi), second(se), firstLeft(fi->left), secondLeft(se->left), cost(cost) {}
};

int minimumPairRemoval(vector<int>& nums) {
    auto cmp = [](const auto& a, const auto& b) {
        return a.cost != b.cost ? a.cost > b.cost : a.firstLeft > b.firstLeft;
    };
    priority_queue<Pair, vector<Pair>, decltype(cmp)> pq(cmp);
    list<Node> nodes;
    bitset<100005> merged;

    int decreaseCount = 0;
    int count = 0;

    nodes.push_back({nums[0], 0});

    int n = nums.size();
    for(int i = 1; i < n; ++i) {
        nodes.push_back({nums[i], (int)i});

        auto curr = std::prev(nodes.end());
        auto prev = std::prev(curr);

        pq.push({prev, curr, prev->value + curr->value});

        if(nums[i - 1] > nums[i]) {
            decreaseCount++;
        }
    }

    while(decreaseCount > 0 && !pq.empty()) {
        auto top = pq.top();
        pq.pop();

        if(merged[top.firstLeft] || merged[top.secondLeft]) {
            continue;
        }

        auto first = top.first;
        auto second = top.second;
        auto cost = top.cost;

        if(first->value + second->value != cost) {
            continue;
        }

        ++count;

        if (first->value > second->value) {
            --decreaseCount;
        }

        list<Node>::iterator prev = (first == nodes.begin()) ? nodes.end() : std::prev(first);
        list<Node>::iterator next = std::next(second);

        if(prev != nodes.end()) {
            if(prev->value > first->value && prev->value <= cost) {
                --decreaseCount;
            }

            if (prev->value <= first->value && prev->value > cost) {
                ++decreaseCount;
            }

            pq.push({prev, first, prev->value + cost});
        }

        if(next != nodes.end()) {
            if(second->value > next->value && cost <= next->value) {
                --decreaseCount;
            }

            if(second->value <= next->value && cost > next->value) {
                ++decreaseCount;
            }

            pq.push({first, next, cost + next->value});
        }

        first->value = cost;
        merged[second->left] = 1;
        nodes.erase(second);
    }

    return count;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minimumPairRemoval(nums) << endl;

    cout << endl;
}

int main() {
    test({1, 1, 4, 1}, 2);
    test({5, 2, 3, 1}, 2);
    test({1, 2, 2}, 0);
    test({1, 1, 4, 4, 2, -4, -1}, 5);
    test({689, -360, 234, 673, 663, -741, 480, 860, -707, 209, 246, 792, 930, 696, -305}, 13);
    test({2, 2, -1, 3, -2, 2, 1, 1, 1, 0, -1}, 9);
    test({3, 3, 3, 3}, 0);
    test({10, -10, 5, -5, 0}, 4);

    return 0;
}
