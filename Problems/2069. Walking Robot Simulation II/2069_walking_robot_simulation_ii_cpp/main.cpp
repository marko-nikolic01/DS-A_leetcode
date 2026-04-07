#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Robot {
    private:
        bool moved = false;
        int idx = 0;
        vector<pair<int, int>> pos;
        vector<int> dir;
        unordered_map<int, string> to_dir = {{0, "East"}, {1, "North"}, {2, "West"}, {3, "South"}};

    public:
        Robot(int width, int height) {
            short i;
            for(i = 0; i < width; ++i) {
                pos.emplace_back(i, 0);
                dir.emplace_back(0);
            }

            for(i = 1; i < height; ++i) {
                pos.emplace_back(width - 1, i);
                dir.emplace_back(1);
            }

            for(i = width - 2; i >= 0; --i) {
                pos.emplace_back(i, height - 1);
                dir.emplace_back(2);
            }

            for(i = height - 2; i > 0; --i) {
                pos.emplace_back(0, i);
                dir.emplace_back(3);
            }

            dir[0] = 3;
        }

        void step(int num) {
            moved = true;
            idx = (idx + num) % pos.size();
        }

        vector<int> getPos() {
            return {pos[idx].first, pos[idx].second};
        }

        string getDir() {
            if (!moved) {
                return "East";
            }

            return to_dir[dir[idx]];
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

    Robot* robot;

    vector<string> results;
    for(int i = 0; i < commands.size(); i++) {
        if(commands[i] == "Robot") {
            robot = new Robot(inputs[i][0], inputs[i][1]);
            results.push_back("null");
        } else if(commands[i] == "step") {
            robot->step(inputs[i][0]);
            results.push_back("null");
        } else if(commands[i] == "getPos") {
            vector<int> result = robot->getPos();
            results.push_back("[" + to_string(result[0]) + ", " + to_string(result[1]) + "]");
        } else if(commands[i] == "getDir") {
            results.push_back(robot->getDir());
        }
    }

    cout << "Expected: ";
    printArray(expected);

    cout << "Results: ";
    printArray(results);

    cout << endl;
}

int main() {
    test({"Robot", "step", "step", "getPos", "getDir", "step", "step", "step", "getPos", "getDir"}, {{6, 3}, {2}, {2}, {}, {}, {2}, {1}, {4}, {}, {}}, {"null", "null", "null", "[4, 0]", "East", "null", "null", "null", "[1, 2]", "West"});
    test({"Robot", "getPos", "getDir"}, {{3, 3}, {}, {}}, {"null", "[0, 0]", "East"});
    test({"Robot", "step", "getPos", "getDir"}, {{3, 3}, {8}, {}, {}}, {"null", "null", "[0, 0]", "South"});
    test({"Robot", "getPos", "getDir"}, {{6, 3}, {}, {}}, {"null", "[0, 0]", "East"});
    test({"Robot", "step", "getPos", "getDir"}, {{6, 3}, {14}, {}, {}}, {"null", "null", "[0, 0]", "South"});

    return 0;
}
