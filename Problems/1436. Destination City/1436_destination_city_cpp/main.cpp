#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

string destCity(vector<vector<string>>& paths) {
    unordered_map<string, bool> cities;

    for(short i = paths.size() - 1; i > -1; --i) {
        cities[paths[i][0]] = false;

        if(cities.find(paths[i][1]) == cities.end()) {
            cities[paths[i][1]] = true;
        }
    }

    for(unordered_map<string, bool>::iterator it = cities.begin(); it != cities.end(); ++it) {
        if(it->second) {
            return it->first;
        }
    }

    return "";
}

void test(vector<vector<string>> paths, string expected) {
    cout << "Paths: ";
    for(vector<string> path : paths) {
        cout << "[" << "\"" << path[0] << "\"" << ", " << "\"" << path[1] << "\"" << "] ";
    }
    cout << endl;

    cout << "Expected: " << "\"" << expected << "\"" << endl;

    cout << "Result: " << "\"" << destCity(paths) << "\"" << endl;

    cout << endl;
}

int main() {
    test({{"London", "New York"}, {"New York", "Lima"}, {"Lima", "Sao Paulo"}}, "Sao Paulo");
    test({{"B", "C"}, {"D", "B"}, {"C", "A"}}, "A");
    test({{"A", "Z"}}, "Z");
    test({{"Belgrade", "Novi Sad"}, {"Novi Sad", "Subotica"}}, "Subotica");
    test({{"Belgrade", "Novi Sad"}}, "Novi Sad");

    return 0;
}
