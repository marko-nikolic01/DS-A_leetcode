#include <iostream>
#include <vector>

using namespace std;

int numberOfAlternatingGroups(vector<int>& colors, int k) {
    int group = 1;

    int i = 1;
    int n = colors.size();
    for(i;i < n; ++i) {
        if(colors[i] == colors[i - 1]) {
            break;
        }

        ++group;
    }

    if(i == n) {
        return (n & 1) > 0 ? ++n - k : n;
    } else if(colors[n - 1] != colors[0]) {
        ++group;

        for(n -= 2; true; --n) {
            if(colors[n] == colors[n + 1]) {
                break;
            }

            ++group;
        }

        ++n;
    }

    int alternatingGroups = 0;

    if(group >= k) {
        alternatingGroups += ++group - k;
    }

    for(i; i < n; ++i) {
        group = 1;

        while(++i < n && colors[i] != colors[i - 1]) {
            ++group;
        }

        if(group >= k) {
            alternatingGroups += ++group - k;
        }

        --i;
    }

    return alternatingGroups;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> colors, int k, int expected) {
    cout << "Tiles: ";
    printArray(colors);

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << numberOfAlternatingGroups(colors, k) << endl;

    cout << endl;
}

int main() {
    test({0,1,0,1,0}, 3, 3);
    test({0,1,0,0,1,0,1}, 6, 2);
    test({1,1,0,1}, 4, 0);
    test({1,0,1,0,1,0,1,0}, 4, 8);
    test({0,0,1,0,1,0,1,1}, 3, 4);
    test({1,0,1,0,1,1,0,1,0,1,0}, 5, 7);

    return 0;
}
