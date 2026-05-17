#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int minJumps(vector<int>& arr) {
    unsigned short jumps = 0;
    unsigned short n = arr.size();
    unordered_map<int, vector<unsigned short>> groups;
    vector<bool> visited(n, false);
    queue<unsigned short> traversal;

    int i;
    for(i = --n; i > -1; --i) {
        groups[arr[i]].push_back(i);
    }

    traversal.push(0);
    visited[0] = true;

    unsigned short j;
    unordered_map<int, vector<unsigned short>>::iterator it;
    while(!traversal.empty()) {
        for(i = traversal.size(); i > 0; --i) {
            j = traversal.front();
            traversal.pop();

            if(j == n) {
                return jumps;
            } else if(!visited[j + 1]) {
                traversal.push(j + 1);
                visited[j + 1] = true;
            }

            if(j > 0 && !visited[j - 1]) {
                traversal.push(j - 1);
                visited[j - 1] = true;
            }

            for(it = groups.find(arr[j]); !it->second.empty(); it->second.pop_back()) {
                if(it->second.back() != j) {
                    traversal.push(it->second.back());
                    visited[it->second.back()] = true;
                }
            }
        }

        ++jumps;
    }

    return 0;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> arr, int expected) {
    cout << "Array: ";
    printArray(arr);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minJumps(arr) << endl;

    cout << endl;
}

int main() {
    test({100, -23, -23, 404, 100, 23, 23, 23, 3, 404}, 3);
    test({7}, 0);
    test({7, 6, 9, 6, 9, 6, 9, 7}, 1);
    test({5, 5, 5, 5, 5, 5}, 1);
    test({1, 2, 3, 4, 5}, 4);

    return 0;
}
