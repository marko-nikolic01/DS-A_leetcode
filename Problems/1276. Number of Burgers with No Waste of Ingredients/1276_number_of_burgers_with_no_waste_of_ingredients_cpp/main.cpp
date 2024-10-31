#include <iostream>
#include <vector>

using namespace std;

vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
    tomatoSlices = tomatoSlices - 2 * cheeseSlices;

    if(tomatoSlices < 0 || tomatoSlices % 2 > 0) {
        return {};
    }

    tomatoSlices /= 2;

    if(tomatoSlices > cheeseSlices) {
        return {};
    }

    return {tomatoSlices, cheeseSlices - tomatoSlices};
}

void test(int tomatoSlices, int cheeseSlices, const vector<int>& expected) {
    cout << "Tomato slices: " << tomatoSlices << endl;

    cout << "Cheese slices: " << cheeseSlices << endl;

    cout << "Expected: [";
    for (size_t i = 0; i < expected.size(); ++i) {
        cout << expected[i];
        if (i < expected.size() - 1) cout << " ";
    }
    cout << "]" << endl;

    cout << "Result: [";
    const vector<int>& result = numOfBurgers(tomatoSlices, cheeseSlices);
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i < result.size() - 1) cout << " ";
    }
    cout << "]" << endl;

    cout << endl;
}

int main() {
    test(16, 7, {1, 6});
    test(17, 4, {});
    test(4, 1, {1, 0});
    test(0, 0, {0, 0});
    test(2, 1, {0, 1});
    test(8, 4, {0, 4});
    test(12, 4, {2, 2});

    return 0;
}
