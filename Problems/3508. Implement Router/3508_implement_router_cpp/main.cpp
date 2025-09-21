#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <array>
#include <algorithm>

using namespace std;

class Router {
    private:
        using int3 = array<int, 3>;
        deque<int3> q;
        unordered_map<int, deque<int>> byDest;
        unordered_set<long> seen;
        size_t memoryLimit;

        long pack(int x, int y) {
            return ((long)x << 32) | y;
        }

    public:
        Router(size_t memoryLimit): memoryLimit(memoryLimit) {}

        bool addPacket(int source, int destination, int timestamp) {
            if(!q.empty() && timestamp == q.back()[0]) {
                long key = pack(source, destination);
                if(seen.count(key)) {
                    return 0;
                }
            }
            else {
                seen.clear();
            }

            if(q.size() == memoryLimit) {
                auto old = q.front();
                q.pop_front();

                auto& qq = byDest[old[2]];
                if(!qq.empty()) {
                    qq.pop_front();
                }

                if(old[0]==timestamp) {
                    seen.erase(pack(old[1], old[2]));
                }
            }

            q.push_back({timestamp, source, destination});
            byDest[destination].push_back(timestamp);
            seen.insert(pack(source, destination));

            return 1;
        }

        vector<int> forwardPacket() {
            if(q.empty()) {
                return {};
            }

            auto x = q.front();
            q.pop_front();

            auto& qq = byDest[x[2]];
            if(!qq.empty()) {
                qq.pop_front();
            }

            if(q.back()[0]==x[0]) {
                seen.erase(pack(x[1], x[2]));
            }

            return {x[1], x[2], x[0]};
        }

        int getCount(int destination, int startTime, int endTime) {
            auto& qq = byDest[destination];
            auto itL = lower_bound(qq.begin(), qq.end(), startTime);
            auto itR = upper_bound(qq.begin(), qq.end(), endTime);

            return itR - itL;
        }
};

void printArray(vector<string> array) {
    for(string a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<string> commands, vector<vector<int>> inputs, vector<string> expected) {
    cout << "Commands: ";
    printArray(commands);

    cout << "Inputs: ";
    for(int i = 0; i < inputs.size(); ++i) {
        cout << "[";
        for(int j = 0; j < inputs[i].size(); ++j) {
            cout << inputs[i][j];
            if(j != inputs[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "] ";
    }
    cout << endl;

    Router* router;

    vector<string> results;
    for(int i = 0; i < commands.size(); i++) {
        if(commands[i] == "Router") {
            router = new Router(inputs[i][0]);
            results.push_back("null");
        } else if(commands[i] == "addPacket") {
            results.push_back(router->addPacket(inputs[i][0], inputs[i][1], inputs[i][2]) ? "true" : "false");
        } else if(commands[i] == "forwardPacket") {
            vector<int> result = router->forwardPacket();
            if(result.empty()) {
                results.push_back("[]");
            } else {
                results.push_back("[" + to_string(result[0]) + ", " + to_string(result[1]) + ", " + to_string(result[2]) + "]");
            }
        } else if(commands[i] == "getCount") {
            results.push_back(to_string(router->getCount(inputs[i][0], inputs[i][1], inputs[i][2])));
        }
    }

    cout << "Expected: ";
    printArray(expected);

    cout << "Results:  ";
    printArray(results);

    cout << endl;
}

int main() {
    test({"Router", "addPacket", "addPacket", "addPacket", "addPacket", "addPacket", "forwardPacket", "addPacket", "getCount"}, {{3}, {1, 4, 90}, {2, 5, 90}, {1, 4, 90}, {3, 5, 95}, {4, 5, 105}, {}, {5, 2, 110}, {5, 100, 110}}, {"null", "true", "true", "false", "true", "true", "[2, 5, 90]", "true", "1"});
    test({"Router", "addPacket", "forwardPacket", "forwardPacket"}, {{2}, {7, 4, 90}, {}, {}}, {"null", "true", "[7, 4, 90]", "[]"});
    test({"Router", "addPacket", "addPacket", "getCount"}, {{4}, {4, 2, 1}, {3, 2, 1}, {2, 1, 1}}, {"null", "true", "true", "2"});
    test({"Router", "addPacket", "addPacket", "forwardPacket", "getCount"}, {{2}, {5, 2, 4}, {4, 2, 4}, {}, {2, 4, 4}}, {"null", "true", "true", "[5, 2, 4]", "1"});
    test({"Router", "addPacket", "addPacket", "addPacket", "getCount", "getCount", "addPacket", "forwardPacket", "addPacket"}, {{5}, {2, 3, 1}, {5, 2, 5}, {2, 3, 5}, {3, 4, 4}, {3, 5, 5}, {3, 2, 5}, {}, {2, 3, 5}}, {"null", "true", "true", "true", "0", "1", "true", "[2, 3, 1]", "false"});
    test({"Router", "addPacket", "getCount", "forwardPacket", "getCount", "addPacket", "getCount"}, {{5}, {4, 2, 1}, {2, 1, 1}, {}, {2, 1, 1}, {4, 2, 1}, {2, 1, 1}}, {"null", "true", "1", "[4, 2, 1]", "0", "true", "1"});

    return 0;
}
