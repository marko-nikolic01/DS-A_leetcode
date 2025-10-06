#include <iostream>
#include <vector>

using namespace std;

bool partition(string& s, short left, short right) {
    while(left < right) {
        if(s[left++] != s[right--]) {
            return false;
        }
    }

    return true;
}

void partition(string& s, vector<vector<string>>& partitions, vector<short>& partitionStarts) {
    partitions.push_back({});

    short iS = 0;
    short n;
    short nS = s.length();
    short nPartitions = partitionStarts.size() - 1;
    for(short iPartitions = 0; iPartitions <= nPartitions; ++iPartitions) {
        partitions.back().push_back("");

        n = iPartitions == nPartitions ? nS : partitionStarts[iPartitions + 1];
        while(iS < n) {
            partitions.back().back().push_back(s[iS++]);
        }
    }
}

void partition(string& s, vector<vector<string>>& partitions, vector<short>& partitionStarts, short i) {
    short n = s.length();
    if(i == n--) {
        partitionStarts.pop_back();
    }

    for(i; i <= n; ++i) {
        if(partition(s, partitionStarts.back(), i)) {
            if(i == n) {
                partition(s, partitions, partitionStarts);
            } else {
                partitionStarts.push_back(++i);
                partition(s, partitions, partitionStarts, i--);
                partitionStarts.pop_back();
            }
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> partitions;
    vector<short> partitionStarts(1, 0);

    partition(s, partitions, partitionStarts, 0);

    return partitions;
}

void test(string s, vector<vector<string>> expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "Expected: ";
    for(vector<string> e : expected) {
        cout << "[";
        for(int i = 0; i < e.size(); ++i) {
            cout << "\"" << e[i] << "\"";
            if(i < e.size() - 1) {
                cout << ", ";
            }
        }
        cout << "] ";
    }
    cout << endl;

    cout << "Result: ";
    for(vector<string> result : partition(s)) {
        cout << "[";
        for(int i = 0; i < result.size(); ++i) {
            cout << "\"" << result[i] << "\"";
            if(i < result.size() - 1) {
                cout << ", ";
            }
        }
        cout << "] ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    test("aab", {{"a", "a", "b"}, {"aa", "b"}});
    test("a", {{"a"}});
    test("aba", {{"a", "b", "a"}, {"aba"}});
    test("aa", {{"a", "a"}, {"aa"}});
    test("abba", {{"a", "b", "b", "a"}, {"a", "bb", "a"}, {"abba"}});
    test("abcd", {{"a", "b", "c", "d"}});

    return 0;
}
