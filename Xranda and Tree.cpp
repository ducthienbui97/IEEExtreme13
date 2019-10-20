#include <bits/stdc++.h>

using namespace std;
const int base = 1e9 + 7;
vector<pair<int,pair<int,int>>> edges;
long long ans;
int n;
vector<int> root;
vector<int> sz;
int findRoot(int u) {
    if(root[u] == u) 
        return u;
    return root[u] = findRoot(root[u]);
}
int main() {
    ans = 0;
    cin >> n;
    root.resize(n + 1);
    sz.resize(n + 1, 1);
    for(int i = 1; i < n; i++) {
        int l, r, w;
        cin >> l >> r >> w;
        edges.push_back({w, {l, r}});
        root[i] = i;
    }
    root[n] = n;
    sort(edges.begin(), edges.end());
    for(auto& e: edges) {
        int l, r, w;
        w = e.first;
        l = findRoot(e.second.first);
        r = findRoot(e.second.second);
        ans = (ans + 1ll*w*sz[l]%base*sz[r]%base)%base;
        root[l] = r;
        sz[r] += sz[l];

    }
    cout << ans << endl;
    return 0;
}