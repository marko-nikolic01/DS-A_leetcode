#include <iostream>
#include <vector>

using namespace std;

class ProductOfNumbers {
    private:
        vector<int> products;
        int n;

    public:
        ProductOfNumbers() {
            products = {1};
            n = 0;
        }

        void add(int num) {
            if(num > 0) {
                products.push_back(products[n++] * num);
            } else {
                products.resize(1);
                n = 0;
            }
        }

        int getProduct(int k) {
            return k > n ? 0 : products[n] / products[n - k];
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
    for(string command : commands) {
        cout << command << " ";
    }
    cout << endl;

    cout << "Inputs: ";
    for(vector<int> input : inputs) {
        cout << "[";
        for(int i = 0; i < input.size(); i++) {
            cout << input[i];
            if (i != input.size() - 1) {
                cout << " ";
            }
        }
        cout << "] ";
    }
    cout << endl;

    ProductOfNumbers* productOfNumbers;

    vector<string> results;
    for(int i = 0; i < commands.size(); i++) {
        if(commands[i] == "ProductOfNumbers") {
            productOfNumbers = new ProductOfNumbers();
            results.push_back("null");
        } else if(commands[i] == "add") {
            productOfNumbers->add(inputs[i][0]);
            results.push_back("null");
        } else if(commands[i] == "getProduct") {
            results.push_back(to_string(productOfNumbers->getProduct(inputs[i][0])));
        }
    }

    cout << "Expected: ";
    printArray(expected);

    cout << "Results: ";
    printArray(results);

    cout << endl;
}

int main() {
    test({"ProductOfNumbers", "add", "add", "add", "getProduct", "getProduct", "add", "getProduct"}, {{}, {3}, {2}, {5}, {2}, {3}, {4}, {2}}, {"null", "null", "null", "null", "10", "30", "null", "20"});
    test({"ProductOfNumbers", "add", "add", "add", "add", "getProduct", "add", "getProduct"}, {{}, {3}, {0}, {2}, {5}, {3}, {4}, {2}}, {"null", "null", "null", "null", "null", "0", "null", "20"});
    test({"ProductOfNumbers", "add", "add", "add", "add", "getProduct", "add", "getProduct"}, {{}, {1}, {2}, {3}, {4}, {4}, {1}, {3}}, {"null", "null", "null", "null", "null", "24", "null", "12"});
    test({"ProductOfNumbers", "add", "add", "add", "getProduct", "add", "add", "getProduct"}, {{}, {0}, {4}, {5}, {2}, {3}, {1}, {5}}, {"null", "null", "null", "null", "20", "null", "null", "0"});
    test({"ProductOfNumbers", "add", "getProduct", "add", "getProduct"}, {{}, {10}, {1}, {0}, {1}}, {"null", "null", "10", "null", "0"});

    return 0;
}
