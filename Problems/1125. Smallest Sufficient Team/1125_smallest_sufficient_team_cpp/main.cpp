#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

long smallestSufficientTeam(unordered_set<short>& groupSkills, vector<short>& peopleSkills, vector<pair<long, short>>& groups, vector<pair<long, short>>& nextGroups, short& neededSkills, short& people) {
    short i;
    short n = groups.size();
    for(i = --n; i > -1; --i) {
        if((groups[i].second & neededSkills) == neededSkills) {
            return groups[i].first;
        }
    }

    short skill;

    nextGroups.resize(0);

    short j;
    for(i = n; i > -1; --i) {
        for(j = people; j > -1; --j) {
            skill = groups[i].second | peopleSkills[j];

            if(groupSkills.find(skill) == groupSkills.end()) {
                nextGroups.push_back({groups[i].first | (1L << j), skill});
                groupSkills.insert(skill);
            }
        }
    }

    return smallestSufficientTeam(groupSkills, peopleSkills, nextGroups, groups, neededSkills, people);
}

vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
    unordered_map<string, short> skills;
    short neededSkills = 0;

    short n;
    for(n = req_skills.size() - 1; n > -1; --n) {
        skills[req_skills[n]] = n;
        neededSkills |= 1 << n;
    }

    n = people.size();
    unordered_set<short> groupSkills;
    vector<short> peopleSkills(n, 0);
    vector<pair<long, short>> groups1;
    vector<pair<long, short>> groups2;

    groupSkills.insert(0);
    groups1.push_back({0, 0});

    short j;
    for(short i = --n; i > -1; --i) {
        for(j = people[i].size() - 1; j > -1; --j) {
            peopleSkills[i] |= 1 << skills[people[i][j]];
        }
    }

    long teamMembers = smallestSufficientTeam(groupSkills, peopleSkills, groups1, groups2, neededSkills, n);

    vector<int> team;

    n = 0;
    while(teamMembers > 0) {
        if((teamMembers & 1) > 0) {
            team.push_back(n);
        }

        teamMembers >>= 1;
        ++n;
    }

    return team;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void printArray(vector<string> array) {
    for(string a : array) {
        cout << "\"" << a << "\"" << " ";
    }
    cout << endl;
}

void test(vector<string> req_skills, vector<vector<string>> people, vector<int> expected) {
    cout << "Required skills: ";
    printArray(req_skills);

    cout << "People: ";
    for(vector<string> person : people) {
        cout << "[";
        for(int i = 0; i < person.size(); ++i) {
            cout << "\"" << person[i] << "\"";
            if(i != person.size() - 1) {
                cout << ", ";
            }
        }
        cout << "] ";
    }
    cout << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(smallestSufficientTeam(req_skills, people));

    cout << endl;
}

int main() {
    test({"java", "nodejs", "reactjs"}, {{"java"}, {"nodejs"}, {"nodejs", "reactjs"}}, {0, 2});
    test({"algorithms", "math", "java", "reactjs", "csharp", "aws"}, {{"algorithms", "math", "java"}, {"algorithms", "math", "reactjs"}, {"java", "csharp", "aws"}, {"reactjs", "csharp"}, {"csharp", "math"}, {"aws", "java"}}, {1, 2});
    test({"wieaul", "cxota", "frq", "knngtpip", "junne", "ctniuowumlcrhh"}, {{"wieaul"}, {"wieaul", "frq", "junne", "ctniuowumlcrhh"}, {"wieaul"}, {}, {"knngtpip"}, {}, {"frq", "knngtpip"}, {"cxota"}, {"ctniuowumlcrhh"}, {}}, {1, 6, 7});
    test({"python"}, {{"python"}}, {0});
    test({"html", "css"}, {{"html"}, {"css"}}, {0, 1});

    return 0;
}
