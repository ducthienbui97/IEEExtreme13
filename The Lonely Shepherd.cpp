#include <bits/stdc++.h>

using namespace std;
int n, k;
vector<vector<int>> d;
pair<int,int> cut;
int dfs(int u, int p) {
    int s = 1;
    for(int v: d[u]) if(v != p) 
        s += dfs(v, u);
    if(s == k && p) {
        cut = {u, p};
    }
    return s;
}
vector<int> root;
int findRoot(int u) {
    if(u==root[u]) {
        return u;
    }
    return root[u] = findRoot(root[u]);
}
int main() {
    cin >> n >> k;
    d.resize(n + 1);
    set<pair<int,int>> edges;
    root.resize(n + 1);
    for(int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        edges.insert({x, y});
        d[x].push_back(y);
        d[y].push_back(x);
    }
    dfs(1, 0);
    if(cut.first == 0 || cut.second == 0)  {
        cout << -1;
    } else {
        edges.erase(cut);
        edges.erase({cut.second, cut.first});
        for(int i = 1; i<= n; i++)
            root[i] = i;
        for(auto&e: edges) {
            root[findRoot(e.first)] = root[findRoot(e.second)];
        }
        unordered_map<int, vector<int>> gr;
        for(int i = 1; i<= n; i++)
            gr[findRoot(i)].push_back(i);
        for(auto& x: gr) {
            if(x.second.size() == k) {
                for(auto v: x.second) {
                    cout << "flip " << v << endl;
                }
            }
        }
        cout << "cut " << cut.first << " " << cut.second << endl;
    }
    return 0;
}