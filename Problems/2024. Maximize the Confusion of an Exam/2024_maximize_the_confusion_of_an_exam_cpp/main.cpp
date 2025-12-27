#include <iostream>

using namespace std;

int maxConsecutiveAnswers(string answerKey, int k) {
    int answers = 1;
    int trueFlipsLeft = k;
    int falseFlipsLeft = k;
    k = answerKey.length();
    int trueRight = k;
    int falseRight = --trueRight;

    while(--k > -1) {
        if(answerKey[k] > 'S') {
            if(--falseFlipsLeft < 0) {
                ++falseFlipsLeft;

                while(answerKey[falseRight] < 'G') {
                    --falseRight;
                }
                --falseRight;
            }
        } else {
            if(--trueFlipsLeft < 0) {
                ++trueFlipsLeft;

                while(answerKey[trueRight] > 'S') {
                    --trueRight;
                }
                --trueRight;
            }
        }

        if(trueRight - k + 1 > answers) {
            answers = trueRight - k + 1;
        }

        if(falseRight - k + 1 > answers) {
            answers = falseRight - k + 1;
        }
    }

    return answers;
}

void test(string answerKey, int k, int expected) {
    cout << "Answer keys: " << answerKey << endl;

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxConsecutiveAnswers(answerKey, k) << endl;

    cout << endl;
}

int main() {
    test("TTFF", 2, 4);
    test("TFFT", 1, 3);
    test("TTFTTFTT", 1, 5);
    test("FFFF", 2, 4);
    test("TFTFTF", 1, 3);

    return 0;
}
