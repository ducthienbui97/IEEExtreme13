#include <bits/stdc++.h>

using namespace std;

int main() {
    const int base = 1e9 + 7;
    const int max = 1e6;
    vector<long long> F(max + 1, 0);
    F[0] = 1;
    for(int i = 1; i <= max; i++) {
        F[i] = 0;
        for(int j = 2; j - 1 <= i; j<<=1) {
            F[i] = (F[i] + F[i - j + 1]) % base;
        }
    }
    for(int i = 1; i <= max; i++) {
        F[i] = (F[i]*2)%base;
    }
    vector<long long> S(max + 1, 0);
    S[0] = F[0];
    for(int i = 1; i<= max; i++) {
        S[i] = (S[i - 1] + F[i])%base;
    }
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a,b;
        cin >> a >> b;
        cout << (S[b] - (a? S[a - 1]: 0) + base) % base << endl;
    }
    return 0;
}