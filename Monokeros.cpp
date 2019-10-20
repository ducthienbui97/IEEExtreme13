#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    const int mx = 1e9 +10;
    set<pair<pair<int,int>, int> > nodes;
    nodes.insert({{-mx, mx}, 1});
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        auto id = nodes.lower_bound({{x + 1, x + 1}, 0});
        --id;
        int l = id->first.first;
        int r = id->first.second;
        int d = id->second;
        nodes.erase(id);
        nodes.insert({{l, x}, d + 1});
        if(x < r) {
            nodes.insert({{x + 1, r}, d + 1});
        }
        cout << d << ' ';
    }
    return 0;
}