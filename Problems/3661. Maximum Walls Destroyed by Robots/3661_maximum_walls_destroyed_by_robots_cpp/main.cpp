#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
    vector<pair<int, int>> robotDist;
    int rightPtr = 0;
    int leftPtr = 0;
    int curPtr = 0;
    int robotPtr = 0;
    int prevLeft = 0;
    int prevRight = 0;
    int prevNum = 0;
    int subLeft = 0;
    int subRight = 0;
    int robotPos;
    int robotDistVal;
    int pos1;
    int pos2;
    int leftBound;
    int leftPos;
    int currentLeft;
    int rightBound;
    int rightPos;
    int currentRight;
    int currentNum;
    int pos3;
    int newsubLeft;
    int newsubRight;

    int i;
    int n = robots.size();
    for(i = 0; i < n; ++i) {
        robotDist.push_back({robots[i], distance[i]});
    }

    sort(robotDist.begin(), robotDist.end());
    sort(walls.begin(), walls.end());

    int m = walls.size();
    for(i = 0; i < n; ++i) {
        robotPos = robotDist[i].first;
        robotDistVal = robotDist[i].second;

        while(rightPtr < m && walls[rightPtr] <= robotPos) {
            ++rightPtr;
        }

        pos1 = rightPtr;

        while(curPtr < m && walls[curPtr] < robotPos) {
            ++curPtr;
        }

        pos2 = curPtr;
        leftBound = (i >= 1) ? max(robotPos - robotDistVal, robotDist[i - 1].first + 1) : robotPos - robotDistVal;

        while(leftPtr < m && walls[leftPtr] < leftBound) {
            ++leftPtr;
        }

        leftPos = leftPtr;
        currentLeft = pos1 - leftPos;
        rightBound = (i < n - 1) ? min(robotPos + robotDistVal, robotDist[i + 1].first - 1) : robotPos + robotDistVal;

        while(rightPtr < m && walls[rightPtr] <= rightBound) {
            ++rightPtr;
        }

        rightPos = rightPtr;
        currentRight = rightPos - pos2;
        currentNum = 0;

        if(i > 0) {
            while(robotPtr < m && walls[robotPtr] < robotDist[i - 1].first) {
                ++robotPtr;
            }

            pos3 = robotPtr;
            currentNum = pos1 - pos3;
        }

        if(i == 0) {
            subLeft = currentLeft;
            subRight = currentRight;
        } else {
            newsubLeft = max(subLeft + currentLeft, subRight - prevRight + min(currentLeft + prevRight, currentNum));
            newsubRight = max(subLeft + currentRight, subRight + currentRight);
            subLeft = newsubLeft;
            subRight = newsubRight;
        }

        prevLeft = currentLeft;
        prevRight = currentRight;
        prevNum = currentNum;
    }

    return max(subLeft, subRight);
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> robots, vector<int> distance, vector<int> walls, int expected) {
    cout << "Robots: ";
    printArray(robots);

    cout << "Distances: ";
    printArray(distance);

    cout << "Walls: ";
    printArray(walls);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxWalls(robots, distance, walls) << endl;

    cout << endl;
}

int main() {
    test({4}, {3}, {1, 10}, 1);
    test({10, 2}, {5, 1}, {5, 2, 7}, 3);
    test({1, 2}, {100, 1}, {10}, 0);
    test({1, 10}, {5, 5}, {3, 7}, 2);
    test({5}, {1}, {5}, 1);

    return 0;
}
