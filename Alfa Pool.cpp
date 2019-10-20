#include <bits/stdc++.h>

using namespace std;

int main() {
    const int base = 1e9 + 7;
    const int max = 1e5;
    vector<long long> F(max + 1, 0);
    F[0] = 1;
    for(int i = 1; i <= max; i++) {
        F[i] = 0;
        for(int j = 2; j - 1 <= i; j<<=1) {
            F[i] = (F[i] + F[i - j + 1]) % base;
        }
    }
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if(t == 0) {
            cout << "1\n";
        } else {
            cout << (F[t]*2)%base<< endl;
            
        }
    }
    return 0;
}