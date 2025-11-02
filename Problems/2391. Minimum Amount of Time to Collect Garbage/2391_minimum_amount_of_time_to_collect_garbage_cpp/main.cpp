#include <iostream>
#include <vector>

using namespace std;

int garbageCollection(vector<string>& garbage, vector<int>& travel) {
    vector<int> travelTimes(3, 0);
    int time = 0;
    short material;

    travel.push_back(0);

    short j;
    int n = garbage.size();
    for(int i = 0; i < n; ++i) {
        j = garbage[i].size();
        time += j;

        for(--j; j > -1; --j) {
            material = garbage[i][j] == 'M' ? 0 : (garbage[i][j] == 'P' ? 1 : 2);
            time += travelTimes[material];
            travelTimes[material] = 0;
        }

        for(++j; j < 3; ++j) {
            travelTimes[j] += travel[i];
        }
    }

    return time;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void printArray(vector<string> array) {
    for(string a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<string> garbage, vector<int> travel, int expected) {
    cout << "Garbage: ";
    printArray(garbage);

    cout << "Travel times: ";
    printArray(travel);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << garbageCollection(garbage, travel) << endl;

    cout << endl;
}

int main() {
    test({"G", "P", "GP", "GG"}, {2, 4, 3}, 21);
    test({"MMM", "PGM", "GP"}, {3, 10}, 37);
    test({"G", "G", "G"}, {4, 6}, 13);
    test({"MPG", "PGM", "GPM"}, {1, 1}, 15);
    test({"PM", "G", "PMG"}, {3, 2}, 21);
    test({"G", "G", "G", "G"}, {5, 5, 5}, 19);

    return 0;
}
