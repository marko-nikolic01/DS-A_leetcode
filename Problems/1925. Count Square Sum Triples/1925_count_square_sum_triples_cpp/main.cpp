#include <iostream>
#include <unordered_set>

using namespace std;

int countTriples(int n) {
    short triples = 0;
    unordered_set<int> squares;

    short j;
    for(j = n; j > 0; --j) {
        squares.insert(j * j);
    }

    for(short i = n; i > 0; --i) {
        for(j = n; j > 0; --j) {
            if(squares.find(i * i + j * j) != squares.end()) {
                ++triples;
            }
        }
    }

    return triples;
}

void test(int n, int expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countTriples(n) << endl;

    cout << endl;
}

int main()
{
    test(5, 2);
    test(10, 4);
    test(3, 0);
    test(20, 12);
    test(25, 16);
    test(1, 0);
    test(250, 330);
    test(100, 104);

    return 0;
}
