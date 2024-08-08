#include <iostream>
#include <unordered_map>

using namespace std;

int climbStairs(int n, unordered_map<int, int> memorizedPositions) {
    if(n <= 2) {
        return n;
    }

    if(memorizedPositions.find(n) == memorizedPositions.end()) {
        memorizedPositions[n] = climbStairs(n - 1, memorizedPositions) + climbStairs(n - 2, memorizedPositions);
    }

    return memorizedPositions[n];
}

int climbStairs(int n) {
    unordered_map<int, int> memorizedPositions;

    return climbStairs(n, memorizedPositions);
}

int main()
{
    int n = 41;

    int result = climbStairs(n);

    cout << "Number of ways to climb " << n << " steps: " << result << "." << endl;
    return 0;
}
