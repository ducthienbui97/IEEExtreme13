#include <bits/stdc++.h>

using namespace std;
vector<int> cnt[4];
int calculate(const string& order, const string& input) {
    int ans = input.length();
    for(int first = 0; first < input.length(); first ++){
        vector<pair<int, pair<int,int>>> con;
        int f = first;
        for(int i = 0; i < 4; i++) {
            int c = order[i] - 'A';
            int sz = cnt[c].back();
            if(f + sz <= input.length()) {
                con.push_back({c, {f, f + sz - 1}});
            } else {
                con.push_back({c, {f, input.length() - 1}});
                con.push_back({c, {0, (f + sz)%input.length() - 1}});
            } 
            f = (f + sz)%input.length();
            
        }
        int correct = 0;
        for(auto&v: con) {
            int c = v.first;
            int l = v.second.first;
            int r = v.second.second;
            correct += cnt[c][r] - (l ? cnt[c][l - 1] : 0);
        }
        
        ans = min(ans, (int) input.length() - correct);
    }
    return ans;
}
int solve(){ 
    string s;
    cin >> s;
    int ans = s.length();
    for(int i = 0; i < 4; i++) 
        cnt[i].resize(s.length());
    for(int i = 0; i < s.length(); i++) {
        for(int j = 0; j < 4; j++) {
            cnt[j][i] = i ? cnt[j][i - 1] : 0;
        }        
        cnt[s[i] - 'A'][i]++;
    }
    ans = min(ans, calculate("ABCD", s));
    ans = min(ans, calculate("ABDC", s));
    ans = min(ans, calculate("ACBD", s));
    ans = min(ans, calculate("ACDB", s));
    ans = min(ans, calculate("ADBC", s));
    ans = min(ans, calculate("ADCB", s));
    return ans;
}
int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cout << solve() << '\n';
    }
    return 0;
}