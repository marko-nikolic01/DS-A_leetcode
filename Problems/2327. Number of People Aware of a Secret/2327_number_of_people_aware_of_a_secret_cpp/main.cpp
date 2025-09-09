#include <iostream>
#include <vector>

using namespace std;

int peopleAwareOfSecret(int n, int delay, int forget) {
    int peopleWithSecret = 1;
    int peopleWhoShareSecret = 0;
    vector<int> shareSecret(n, 0);
    vector<int> forgetSecret(n, 0);

    if(delay < n) {
        ++shareSecret[delay];
    }

    if(forget < n) {
        ++forgetSecret[forget];
    }

    for(short i = delay; i < n; ++i) {
        peopleWhoShareSecret = ((peopleWhoShareSecret + shareSecret[i]) % 1000000007 - forgetSecret[i] + 1000000007) % 1000000007;
        peopleWithSecret = ((peopleWithSecret + peopleWhoShareSecret) % 1000000007 - forgetSecret[i] + 1000000007) % 1000000007;

        if(i + delay < n) {
            shareSecret[i + delay] = (shareSecret[i + delay] + peopleWhoShareSecret) % 1000000007;
        }

        if(i + forget < n) {
            forgetSecret[i + forget] = (forgetSecret[i + forget] + peopleWhoShareSecret) % 1000000007;
        }
    }

    return peopleWithSecret;
}

void test(int n, int delay, int forget, int expected) {
    cout << "n: " << n << endl;

    cout << "Delay: " << delay << endl;

    cout << "Forget: " << forget << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << peopleAwareOfSecret(n, delay, forget) << endl;

    cout << endl;
}

int main() {
    test(6, 2, 4, 5);
    test(4, 1, 3, 6);
    test(684, 18, 496, 653668527);
    test(2, 1, 2, 2);
    test(10, 4, 5, 1);

    return 0;
}
