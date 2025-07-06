#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class FindSumPairs {
    private:
        vector<int>& nums2;
        unordered_map<int, int> occurences1;
        unordered_map<int, int> occurences2;

    public:
        FindSumPairs(vector<int>& nums1, vector<int>& nums2) : nums2(nums2) {
            int n = nums1.size();
            for(--n; n > -1; --n) {
                ++occurences1[nums1[n]];
            }

            for(n = nums2.size() - 1; n > -1; --n) {
                ++occurences2[nums2[n]];
            }
        }

        void add(int index, int val) {
            --occurences2[nums2[index]];
            nums2[index] += val;
            ++occurences2[nums2[index]];
        }

        int count(int tot) {
            int pairs = 0;

            for(unordered_map<int, int>::iterator it = occurences1.begin(); it != occurences1.end(); ++it) {
                pairs += it->second * occurences2[tot - it->first];
            }

            return pairs;
        }
};

void printArray(vector<string> array) {
    for(string a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<string> commands, vector<vector<vector<int>>> inputs, vector<string> expected) {
    cout << "Commands: ";
    for(string command : commands) {
        cout << command << " ";
    }
    cout << endl;

    cout << "Inputs: ";
    for(vector<vector<int>> input : inputs) {
        cout << "[";
        for(int i = 0; i < input.size(); ++i) {
            cout << "[";
            for(int j = 0; j < input[i].size(); ++j) {
                cout << input[i][j];
                if (j != input[i].size() - 1) {
                    cout << " ";
                }
            }
            cout << "]";
            if(i != input.size() - 1) {
                cout << ", ";
            }
        }
        cout << "] ";
    }
    cout << endl;

    FindSumPairs* findSumPairs;

    vector<string> results;
    for(int i = 0; i < commands.size(); i++) {
        if(commands[i] == "FindSumPairs") {
            findSumPairs = new FindSumPairs(inputs[i][0], inputs[i][1]);
            results.push_back("null");
        } else if(commands[i] == "add") {
            findSumPairs->add(inputs[i][0][0], inputs[i][0][1]);
            results.push_back("null");
        } else if(commands[i] == "count") {
            results.push_back(to_string(findSumPairs->count(inputs[i][0][0])));
        }
    }

    cout << "Expected: ";
    printArray(expected);

    cout << "Results: ";
    printArray(results);

    cout << endl;
}

int main() {
test({"FindSumPairs", "count", "add", "count", "count", "add", "add", "count"}, {{{1, 1, 2, 2, 2, 3}, {1, 4, 5, 2, 5, 4}}, {{7}}, {{3, 2}}, {{8}}, {{4}}, {{0, 1}}, {{1, 1}}, {{7}}}, {"null", "8", "null", "2", "1", "null", "null", "11"});
    test({"FindSumPairs", "count", "add", "count"}, {{{1, 2}, {3, 4}}, {{5}}, {{1, 1}}, {{6}}}, {"null", "2", "null", "1"});
    test({"FindSumPairs", "count", "add", "add", "count"}, {{{2, 3}, {1, 2}}, {{5}}, {{1, 1}}, {{1, 2}}, {{7}}}, {"null", "1", "null", "null", "1"});
    test({"FindSumPairs", "count", "add", "count"}, {{{2, 2, 2}, {2, 2, 2}}, {{4}}, {{0, 1}}, {{5}}}, {"null", "9", "null", "3"});
    test({"FindSumPairs", "count"}, {{{1, 1}, {5, 5}}, {{3}}}, {"null", "0"});
    test({"FindSumPairs", "count", "add", "add", "add", "count"}, {{{1, 1}, {1, 1}}, {{5}}, {{0, 1}}, {{1, 2}}, {{1, 1}}, {{5}}}, {"null", "0", "null", "null", "null", "2"});

    return 0;
}
