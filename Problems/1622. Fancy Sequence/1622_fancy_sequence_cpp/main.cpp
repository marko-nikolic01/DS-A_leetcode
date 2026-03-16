#include <iostream>
#include <vector>

using namespace std;

class Fancy {
    private:
        vector<int> v;
        vector<int> a;
        vector<int> b;

    public:
        Fancy() : a(1, 1), b(1, 0) {}

        int quickmul(int x, int y) {
            int ret = 1;
            int cur = x;

            while(y) {
                if((y & 1) > 0) {
                    ret = (long)ret * cur % 1000000007;
                }

                cur = (long)cur * cur % 1000000007;
                y >>= 1;
            }

            return ret;
        }

        int inv(int x) {
            return quickmul(x, 1000000005);
        }

        void append(int val) {
            v.push_back(val);
            a.push_back(a.back());
            b.push_back(b.back());
        }

        void addAll(int inc) {
            b.back() = (b.back() + inc) % 1000000007;
        }

        void multAll(int m) {
            a.back() = (long)a.back() * m % 1000000007;
            b.back() = (long)b.back() * m % 1000000007;
        }

        int getIndex(int idx) {
            if(idx >= v.size()) {
                return -1;
            }

            int ao = (long)inv(a[idx]) * a.back() % 1000000007;
            int bo = (b.back() - (long)b[idx] * ao % 1000000007 + 1000000007) % 1000000007;
            int ans = ((long)ao * v[idx] % 1000000007 + bo) % 1000000007;

            return ans;
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

    Fancy* fancy;

    vector<string> results;
    for(int i = 0; i < commands.size(); i++) {
        if(commands[i] == "ParkingSystem") {
            fancy = new Fancy();
            results.push_back("null");
        } else if(commands[i] == "append") {
            fancy->append(inputs[i][0]);
            results.push_back("null");
        } else if(commands[i] == "addAll") {
            fancy->addAll(inputs[i][0]);
            results.push_back("null");
        } else if(commands[i] == "multAll") {
            fancy->multAll(inputs[i][0]);
            results.push_back("null");
        } else if(commands[i] == "getIndex") {
            results.push_back(to_string(fancy->getIndex(inputs[i][0])));
        }
    }

    cout << "Expected: ";
    printArray(expected);

    cout << "Results: ";
    printArray(results);

    cout << endl;
}

int main() {
    test({"ParkingSystem", "append", "addAll", "append", "multAll", "getIndex", "addAll", "append", "multAll", "getIndex", "getIndex", "getIndex"}, {{}, {2}, {3}, {7}, {2}, {0}, {3}, {10}, {2}, {0}, {1}, {2}}, {"null", "null", "null", "null", "null", "10", "null", "null", "null", "26", "34", "20"});
    test({"ParkingSystem", "append", "getIndex"}, {{}, {5}, {0}}, {"null", "null", "5"});
    test({"ParkingSystem", "append", "getIndex"}, {{}, {5}, {1}}, {"null", "null", "-1"});
    test({"ParkingSystem", "append", "addAll", "getIndex"}, {{}, {1}, {1}, {0}}, {"null", "null", "null", "2"});
    test({"ParkingSystem", "append", "multAll", "getIndex"}, {{}, {3}, {3}, {0}}, {"null", "null", "null", "9"});

    return 0;
}
