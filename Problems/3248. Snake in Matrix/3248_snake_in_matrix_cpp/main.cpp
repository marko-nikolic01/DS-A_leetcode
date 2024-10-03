#include <iostream>
#include <vector>

using namespace std;

int finalPositionOfSnake(int n, vector<string>& commands) {
    int position = 0;

    for(int i = commands.size() - 1; i > -1; --i) {
        if(commands[i][0] == 'D') {
            position += n;
        } else if(commands[i][0] == 'U') {
            position -= n;
        } else if(commands[i][0] == 'R') {
            position++;
        } else {
            position--;
        }
    }

    return position;
}

void runTest(int n, vector<string> commands, int expected) {
    cout << "n: " << n << endl;

    cout << "commands: [";
    for (size_t i = 0; i < commands.size(); ++i) {
        cout << commands[i];
        if (i < commands.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << finalPositionOfSnake(n, commands) << endl;

    cout << endl;
}

int main()
{
    runTest(3, {"DOWN", "RIGHT", "UP", "LEFT"}, 0);
    runTest(3, {"DOWN", "DOWN", "RIGHT"}, 7);
    runTest(4, {"RIGHT", "RIGHT", "DOWN"}, 6);
    runTest(5, {"DOWN", "DOWN", "DOWN", "RIGHT"}, 16);
    runTest(2, {"RIGHT", "DOWN", "LEFT", "UP"}, 0);

    return 0;
}
