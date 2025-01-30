#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int magnificentSets(int n, vector<vector<int>>& edges) {
    vector<vector<int>> g(n+1);
    for(auto &e: edges){
        g[e[0]].push_back(e[1]);
        g[e[1]].push_back(e[0]);
    }

    vector<int> color(n+1, 0);

    auto bipBfs = [&](int start) {
        queue<int> q;
        q.push(start);
        color[start] = 1;
        vector<int> comp;

        while(!q.empty()){
            int u = q.front();
            q.pop();
            comp.push_back(u);
            for(int v : g[u]){
                if(!color[v]){
                    color[v] = -color[u];
                    q.push(v);
                } else if(color[v] == color[u]) {
                    return vector<int>();
                }
            }
        }
        return comp;
    };

    int ans = 0;

    for(int i = 1; i <= n; i++) {
        if (!color[i]) {
            auto comp = bipBfs(i);
            if (comp.empty()) return -1;

            int best = 0;

            for(auto &x: comp) {
                vector<int> dist(n+1, -1);
                dist[x] = 0;
                queue<int> q;
                q.push(x);

                while(!q.empty()){
                    int u = q.front();
                    q.pop();
                    for(int v : g[u]){
                        if (dist[v] < 0) {
                            dist[v] = dist[u] + 1;
                            q.push(v);
                        }
                    }
                }

                int layers = 0;
                for(auto &cnode : comp)
                    if (dist[cnode] >= 0)
                        layers = max(layers, dist[cnode]);

                best = max(best, layers + 1);
            }
            ans += best;
        }
    }
    return ans;
}

void test(int n, vector<vector<int>> edges, int expected) {
    cout << "n: " << n << endl;
    cout << "Edges: ";
    for(vector<int> edge : edges) {
        cout << "[" << edge[0] << " " << edge[1] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << magnificentSets(n, edges) << endl;

    cout << endl;
}

int main() {
    vector<vector<int>> edges1 = {{1,2},{1,4},{1,5},{2,6},{2,3},{4,6}};
    test(6, edges1, 4);

    vector<vector<int>> edges2 = {{1,2},{2,3},{3,1}};
    test(3, edges2, -1);

    vector<vector<int>> edges3 = {{1,2},{2,3},{3,4},{4,5}};
    test(5, edges3, 5);

    vector<vector<int>> edges4 = {{1,2},{2,3},{3,4},{4,5},{5,1}};
    test(5, edges4, -1);

    vector<vector<int>> edges5 = {{1,2},{2,3},{3,4},{4,5},{5,6},{6,7},{7,8}};
    test(8, edges5, 8);

    return 0;
}
