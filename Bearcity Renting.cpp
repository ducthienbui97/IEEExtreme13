#include <bits/stdc++.h>

using namespace std;
int findRoot(int u, vector<int>& root) {
    if(u == root[u])
        return u;
    return root[u] = findRoot(root[u], root);
}
int cnt = 0;
int dfs(int u, int p, unordered_map<int, unordered_map<int, int>>& d, 
    unordered_map<int, int>& low, unordered_map<int, int>& vs) {
        low[u] = vs[u] = ++cnt;
        int ans = 0;
        for(auto& pp: d[u]) if(pp.first != p) {
            int v = pp.first;
            if(vs[v]) low[u] = min(low[u], low[v]);
            else {
                ans += dfs(v, u, d, low, vs);
                low[u] = min(low[u], low[v]);
                if(pp.second == 1 && low[v] >= vs[v]) {
                    ans++;
                }
            }
        }
        return ans;
    }

int main() {
    int n,m;
    cin >> n >> m;
    vector<pair<int, pair<int,int>>> edges(m);
    vector<int> r(n + 1);
    for(int i = 1; i <= n; i++)
        r[i] = i;
    for(int i = 0 ; i < m; i++) {
        cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
    }
    int ans = 0;;
    sort(edges.begin(), edges.end());
    for(int i = 0; i < m;) {
        unordered_map<int, unordered_map<int, int>> d;
        unordered_map<int, int> low;
        unordered_set<int> nodes;
        unordered_map<int, int> vs;
        int j;
        for(j = i; j < m && edges[i].first == edges[j].first; j++) {
            int x = findRoot(edges[j].second.first, r);
            int y = findRoot(edges[j].second.second, r);
            if(x != y) {
                d[x][y] ++;
                d[y][x] ++;
            }
            nodes.insert(x);
            nodes.insert(y);
        }
        cnt = 0;
        for(auto& v: nodes)
        if(!vs[v])
        ans += dfs(v, -1, d, low, vs);
        for(j = i; j < m && edges[i].first == edges[j].first; j++) {
            int x = findRoot(edges[j].second.first, r);
            int y = findRoot(edges[j].second.second, r);
            r[x] = y;
        }
        i = j;
    }
    cout << ans << endl;
    return 0;
}