#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void findRotateSteps(string& ring, string& key, vector<vector<short>>& letters, vector<short>& steps, vector<short>& nextSteps, short i) {
    short letter1;
    short letter2;

    short j;
    short n = letters[key[i] - 'a'].size();
    for(j = n - 1; j > -1; --j) {
        nextSteps[letters[key[i] - 'a'][j]] = SHRT_MAX;
    }

    short k;
    short m = ring.length();
    for(j = letters[key[i - 1] - 'a'].size() - 1; j > -1; --j) {
        for(k = 0; k < n; ++k) {
            if(letters[key[i - 1] - 'a'][j] < letters[key[i] - 'a'][k]) {
                letter1 = letters[key[i - 1] - 'a'][j];
                letter2 = letters[key[i] - 'a'][k];
            } else {
                letter1 = letters[key[i] - 'a'][k];
                letter2 = letters[key[i - 1] - 'a'][j];
            }

            nextSteps[letters[key[i] - 'a'][k]] = min((int)nextSteps[letters[key[i] - 'a'][k]], steps[letters[key[i - 1] - 'a'][j]] + min(letter2 - letter1, letter1 + m - letter2));
        }
    }
}

short findRotateSteps(vector<vector<short>>& letters, vector<short>& steps, short letter) {
    short step = steps[letters[letter][0]];

    for(short i = letters[letter].size() - 1; i > 0; --i) {
        if(steps[letters[letter][i]] < step) {
            step = steps[letters[letter][i]];
        }
    }

    return step;
}

int findRotateSteps(string ring, string key) {
    short n = ring.length();
    vector<vector<short>> letters(26);
    vector<short> steps1(n);
    vector<short> steps2(n);

    short i;
    for(i = n - 1; i > -1; --i) {
        letters[ring[i] - 'a'].push_back(i);
    }

    for(i = letters[key[0] - 'a'].size() - 1; i > -1; --i) {
        steps1[letters[key[0] - 'a'][i]] = min((int)letters[key[0] - 'a'][i], n - letters[key[0] - 'a'][i]);
    }

    n = key.length();
    for(i = 1; i < n; ++i) {
        if((i & 1) > 0) {
            findRotateSteps(ring, key, letters, steps1, steps2, i);
        } else {
            findRotateSteps(ring, key, letters, steps2, steps1, i);
        }
    }

    return n + ((i & 1) > 0 ? findRotateSteps(letters, steps1, key[n - 1] - 'a') : findRotateSteps(letters, steps2, key[n - 1] - 'a'));
}

void test(string ring, string key, int expected) {
    cout << "Ring: " << "\"" << ring << "\"" << endl;

    cout << "Key: " << "\"" << key << "\"" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << findRotateSteps(ring, key) << endl;

    cout << endl;
}

int main() {
    test("godding", "gd", 4);
    test("godding", "godding", 13);
    test("aaaaa", "aaa", 3);
    test("abcde", "ea", 4);
    test("ababcab", "bca", 7);

    return 0;
}
