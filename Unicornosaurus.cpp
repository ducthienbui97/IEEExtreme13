#include <bits/stdc++.h>

using namespace std;
const int maxSize = 1e5 + 20;
long long F[maxSize];
long long lazy[maxSize << 3];
long long getMin(const long long& x, const long long& y) {
    if(x < 0)
        return y;
    if(y < 0)
        return x;
    return min(x, y);
}
long long getVal(int node, int l, int r, int u) {
    if(u == 0) {
        return 0;
    }
    if(l > u || r < u) {
        return - 1;
    }
    if(l == r) {
        F[l] = getMin(lazy[node], F[l]);
        // cout << lazy[node] <<"-->" <<F[l] <<" "<<l << endl;
        return F[l];
    }
    
    lazy[2*node] = getMin(lazy[node], lazy[2*node]);
    lazy[2*node + 1] = getMin(lazy[2*node + 1], lazy[node]);

    return getMin(getVal(2*node, l, (l + r)/2, u),
            getVal(2*node + 1, (l+r)/2 + 1, r, u));
}

void setVal(int node, int l, int r, int u, int v, long long val) {
    if(l > v || r < u) {
        return;
    }
    if(u <= l && r <= v) {
        lazy[node] = getMin(lazy[node], val);
        return;
    }
    setVal(2*node, l, (l+r)/2, u, v, val);
    setVal(2*node + 1, (l+r)/2 + 1, r, u, v, val);
}
int main() {
    memset(F, -1, sizeof(F));
    memset(lazy, -1, sizeof(lazy));
    int s, n, m;
    cin >> n >> m >> s;
    vector<int> broken(s + 1, 0);
    vector<vector<pair<int,int>>> magic(s + 1);
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        broken[l] ++;
        if(r <= s) {
            broken[r + 1]--;
        }
    }
    int ss = 0;
    for(int& v: broken) {
        v = ss = ss + v;
        if(v > 1) {
            v = 1;
        }
    }
    for(int i = 0; i < m; i++) {
        int l,r,c;
        cin >> l >> r >> c;
        magic[l].push_back({r, c});
    }
    for(int i = 1; i <= s; i++) {
        long long f = getVal(1, 1, s, i - 1);
        if(f >= 0) {
            for(int j = 0; j < magic[i].size(); j++) {
                int r = magic[i][j].first;
                int c = magic[i][j].second;
                setVal(1, 1, s, i, r, f + c);
            }
            if(!broken[i]) {
                setVal(1, 1, s, i, i, f);
            }
        }
    }
    cout << getVal(1, 1, s, s);
    return 0;
}