#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> fizzBuzz(int n) {
    vector<string> fizzBuzz(n, "");

    for(int i = 1; i <= n; ++i) {
        if(i % 3 != 0 && i % 5 != 0) {
            fizzBuzz[i - 1] = to_string(i);
        } else {
            if(i % 3 == 0) {
                fizzBuzz[i - 1] += "Fizz";
            }

            if(i % 5 == 0) {
                fizzBuzz[i - 1] += "Buzz";
            }
        }
    }

    return fizzBuzz;
}

void runTest(int n, const vector<string>& expected) {
    vector<string> result = fizzBuzz(n);
    cout << "n = " << n << endl;
    cout << "Expected: ";
    for (const string& s : expected) {
        cout << s << " ";
    }
    cout << endl;

    cout << "Result:   ";
    for (const string& s : result) {
        cout << s << " ";
    }
    cout << endl;
    cout << endl;
}

int main()
{
    runTest(3, {"1", "2", "Fizz"});
    runTest(5, {"1", "2", "Fizz", "4", "Buzz"});
    runTest(15, {"1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz", "Buzz", "11", "Fizz", "13", "14", "FizzBuzz"});

    return 0;
}
