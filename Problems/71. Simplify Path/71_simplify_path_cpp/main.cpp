#include <iostream>
#include <vector>

using namespace std;

string simplifyPath(string path) {
    vector<string> paths;

    string currentPath = "";
    int dots = 0;

    int n = path.size();
    for(int i = 1; i < n; ++i) {
        if(path[i] == '/') {
            if(dots == 2 && currentPath.size() == 2) {
        if(paths.size() > 0) {
            paths.resize(paths.size() - 1);
        }
    } else if ((dots != 1  && currentPath.size() > 0) || (dots == 1 && currentPath.size() > 1)) {
        paths.push_back(currentPath);
    }
            dots = 0;
            currentPath = "";
        } else if(path[i] != '/') {
            currentPath += path[i];

            if(path[i] == '.') {
                dots++;
            }
        }
    }

    if(dots == 2 && currentPath.size() == 2) {
        if(paths.size() > 0) {
            paths.resize(paths.size() - 1);
        }
    } else if ((dots != 1  && currentPath.size() > 0) || (dots == 1 && currentPath.size() > 1)) {
        paths.push_back(currentPath);
    }

    currentPath = "/";

    n = paths.size();
    for(int i = 0; i < n; ++i) {
        currentPath += paths[i];
        if(i < n - 1) {
            currentPath += '/';
        }
    }

    return currentPath;
}

void runTest(string path, string expected) {
    cout << "Path: " << path << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << simplifyPath(path) << endl;

    cout << endl;
}

int main() {
    runTest("/home/", "/home");
    runTest("/../", "/");
    runTest("/home//foo/", "/home/foo");
    runTest("/a/./b/../../c/", "/c");
    runTest("/a/../../b/../c//.//", "/c");
    runTest("/a//b////c/d//././/..", "/a/b/c");
    runTest("/...", "/...");
    runTest("/.hidden", "/.hidden");
    runTest("/", "/");

    return 0;
}
