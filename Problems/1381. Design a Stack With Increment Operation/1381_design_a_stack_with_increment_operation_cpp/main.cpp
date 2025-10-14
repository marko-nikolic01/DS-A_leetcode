#include <iostream>
#include <vector>

using namespace std;

class CustomStack {
    private:
        vector<int> stack;
        short maxSize;

    public:
        CustomStack(int maxSize) : maxSize(maxSize) {}

        void push(int x) {
            if(stack.size() < maxSize) {
                stack.push_back(x);
            }
        }

        int pop() {
            if(stack.size() < 1) {
                return -1;
            }

            int value = stack.back();
            stack.pop_back();

            return value;
        }

        void increment(int k, int val) {
            if(stack.size() < k) {
                k = stack.size();
            }

            for(--k; k > -1; --k) {
                stack[k] += val;
            }
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

    CustomStack* customStack;

    vector<string> results;
    for(int i = 0; i < commands.size(); i++) {
        if(commands[i] == "CustomStack") {
            customStack = new CustomStack(inputs[i][0]);
            results.push_back("null");
        } else if(commands[i] == "push") {
            customStack->push(inputs[i][0]);
            results.push_back("null");
        } else if(commands[i] == "pop") {
            results.push_back(to_string(customStack->pop()));
        } else if(commands[i] == "increment") {
            customStack->increment(inputs[i][0], inputs[i][1]);
            results.push_back("null");
        }
    }

    cout << "Expected: ";
    printArray(expected);

    cout << "Results: ";
    printArray(results);

    cout << endl;
}

int main() {
    test({"CustomStack", "push", "push", "pop", "push", "push", "push", "increment", "increment", "pop", "pop", "pop", "pop"}, {{3}, {1}, {2}, {}, {2}, {3}, {4}, {5, 100}, {2, 100}, {}, {}, {}, {}}, {"null", "null", "null", "2", "null", "null", "null", "null", "null", "103", "202", "201", "-1"});
    test({"CustomStack", "push", "push", "push", "push", "pop", "pop", "pop"}, {{2}, {10}, {20}, {30}, {40}, {}, {}, {}}, {"null", "null", "null", "null", "null", "20", "10", "-1"});
    test({"CustomStack", "push", "push", "increment", "pop", "pop"}, {{5}, {5}, {10}, {1, 100}, {}, {}}, {"null", "null", "null", "null", "10", "105"});
    test({"CustomStack", "push", "push", "increment", "pop", "pop"}, {{3}, {1}, {2}, {5, 50}, {}, {}}, {"null", "null", "null", "null", "52", "51"});
    test({"CustomStack", "pop", "push", "pop", "pop"}, {{1}, {}, {5}, {}, {}}, {"null", "-1", "null", "5", "-1"});

    return 0;
}
