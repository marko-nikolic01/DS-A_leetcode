#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> subdomainVisits(vector<string>& cpdomains) {
    unordered_map<string, int> domains;
    string domain;
    int visits;

    short j;
    short k;
    short n;
    for(short i = cpdomains.size() - 1; i > -1; --i) {
        visits = 0;

        j = 0;
        n = cpdomains[i].size();
        while(cpdomains[i][j] != ' ') {
            visits = 10 * visits + cpdomains[i][j++] - '0';
        }

        domain.resize(0);

        k = 0;
        while(++j < n) {
            if(cpdomains[i][j] == '.' && k < 1) {
                k = j;
            }

            domain.push_back(cpdomains[i][j]);
        }

        domains[domain] += visits;
        domain.resize(0);

        j = k;
        k = 0;
        while(++j < n) {
            if(cpdomains[i][j] == '.' && k < 1) {
                k = j;
            }

            domain.push_back(cpdomains[i][j]);
        }

        domains[domain] += visits;

        if(k > 0) {
            domain.resize(0);

            j = k;
            k = 0;
            while(++j < n) {
                if(cpdomains[i][j] == '.' && k < 1) {
                    k = j;
                }

                domain.push_back(cpdomains[i][j]);
            }

            domains[domain] += visits;
        }
    }

    vector<string> stats(domains.size(), "");

    k = 0;
    for(unordered_map<string, int>::iterator it = domains.begin(); it != domains.end(); ++it) {
        visits = 1;
        while(visits <= it->second) {
            visits *= 10;
        }
        visits /= 10;

        while(visits > 0) {
            stats[k].push_back(it->second / visits + '0');
            it->second %= visits;
            visits /= 10;
        }

        stats[k].push_back(' ');

        n = it->first.size();
        for(j = 0; j < n; ++j) {
            stats[k].push_back(it->first[j]);
        }

        ++k;
    }

    return stats;
}

void printArray(vector<string> array) {
    for(string a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<string> cpdomains, vector<string> expected) {
    cout << "Domains: ";
    printArray(cpdomains);

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(subdomainVisits(cpdomains));

    cout << endl;
}

int main() {
    test({"9001 discuss.leetcode.com"}, {"9001 discuss.leetcode.com", "9001 leetcode.com", "9001 com"});
    test({"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"}, {"900 google.mail.com", "901 mail.com", "951 com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org", "5 org"});
    test({"10 a.b.com"}, {"10 a.b.com", "10 b.com", "10 com"});
    test({"5 code.leetcode.com", "5 leetcode.com"}, {"5 code.leetcode.com", "10 leetcode.com", "10 com"});
    test({"7 x.y.z"}, {"7 x.y.z", "7 y.z", "7 z"});

    return 0;
}
