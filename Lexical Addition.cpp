#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int maxSize = 1e5;
    long long n, a, b;
    cin >> n >> a >> b;
    long long multi = n/b;
    long long rem = n % b;
    if(multi > maxSize){
        cout << "NO\n";
        return 0;
    }
    vector<long long> ans(multi, b);
    if(rem != 0) {
        for(int i = 0; i < multi; i++) {
            long long d = max(0ll, min(a - rem, b - a));
            rem += d;
            ans[i] -= d;
        }
        if(rem < a) {
            cout << "NO\n";
            return 0;
        }
    }
    
    cout <<"YES\n";
    if(rem != 0)
        cout << rem << ' ';
    for(auto&v : ans)
        cout << v << ' ';
    return 0;
}