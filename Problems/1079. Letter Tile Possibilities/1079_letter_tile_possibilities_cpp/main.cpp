#include <iostream>
#include <vector>

using namespace std;

void numTilePossibilities(string& tiles, short& possibilities, vector<bool>& isUsed) {
    int letters = 0;

    for(short i = tiles.size() - 1; i > -1; --i) {
        if(!isUsed[i] && (letters & (1 << (tiles[i] - 'A'))) < 1) {
            ++possibilities;

            isUsed[i] = true;
            letters |= 1 << (tiles[i] - 'A');

            numTilePossibilities(tiles, possibilities, isUsed);

            isUsed[i] = false;
        }
    }
}

int numTilePossibilities(string tiles) {
    short n = tiles.size();
    vector<bool> isUsed(n, false);

    n = 0;

    numTilePossibilities(tiles, n, isUsed);

    return n;
}

void test(string tiles, int expected) {
    cout << "Tiles: " << tiles << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << numTilePossibilities(tiles) << endl;

    cout << endl;
}

int main()
{
    test("AAB", 8);
    test("AAABBC", 188);
    test("V", 1);
    test("ABC", 15);
    test("AABB", 18);
    test("AAAA", 4);
    test("ABCDEFG", 13699);

    return 0;
}
