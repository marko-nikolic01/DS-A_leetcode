#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<string> removeSubfolders(vector<string>& folder) {
    unordered_set<string> folders;

    for(int i = folder.size() - 1; i > -1; --i) {
        folders.insert(folder[i]);
    }

    vector<string> mainFolders;
    string currentFolder = "/";

    short j;
    short n;
    for(int i = folder.size() - 1; i > -1; --i) {
        currentFolder.resize(1);

        n = folder[i].size();
        j = 1;
        for(j; j < n; ++j) {
            if(folder[i][j] == '/' && folders.find(currentFolder) != folders.end()) {
                break;
            }

            currentFolder.push_back(folder[i][j]);
        }

        if(j == n) {
            mainFolders.push_back(currentFolder);
        }
    }

    return mainFolders;
}

void test(vector<string> folder, vector<string> expected) {
    cout << "Folders: ";
    for (const auto& f : folder) {
        cout << f << " ";
    }
    cout << endl;

    cout << "Expected: ";
    for (const auto& e : expected) {
        cout << e << " ";
    }
    cout << endl;

    cout << "Result: ";
    for (const auto& r : removeSubfolders(folder)) {
        cout << r << " ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    test({"/a", "/a/b", "/c/d", "/c/d/e", "/c/f"}, {"/c/f", "/c/d", "/a"});
    test({"/a", "/a/b/c", "/a/b/d"}, {"/a"});
    test({"/a/b/c", "/a/b/ca", "/a/b/d"}, {"/a/b/d", "/a/b/ca", "/a/b/c"});
    test({"/a", "/a/b", "/a/b/c", "/a/b/c/d", "/a/e"}, {"/a"});
    test({"/a/b", "/a"}, {"/a"});

    return 0;
}
