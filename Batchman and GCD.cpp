#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int ans = 0;
    vector<int> d(100001, 0);
    for(int i = 0 ; i < n; i++) {
        int x;
        cin >> x;
        d[x] ++;
    }
    for(int i = 1; i < 100001; i++) {
        vector<int> v;
        for(int j = i; j < 100001; j+= i) if(d[j]) {
            v.push_back(j/i);
        }
        if(v.size() > 0) {
            int gcd = v[0];
            for(auto& u: v) {
                gcd = __gcd(gcd, u);
            }
            if(gcd == 1) {
                ans ++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}