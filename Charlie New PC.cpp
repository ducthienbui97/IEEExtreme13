#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<long long> possibleSum;
vector<vector<int>> components;

void buildPossibleSum(int idx,
    const int& from, const int& to, 
    long long current, const long long& maxVal) {
    if(current > maxVal) {
        return;
    }
    if(idx == to) {
        possibleSum.push_back(current);
    } else {
        for(auto& v: components[idx]) {
            buildPossibleSum(idx + 1, from, to, current + v, maxVal);
        }
    }
}

void buildOutput(int idx,
    const int& from, const int& to, 
    long long current, const long long& maxVal, long long& ans) {
    if(current + *possibleSum.begin() > maxVal) {
        return;
    }
    if(idx == to) {
        long long rem = maxVal - current;
        int find = upper_bound(possibleSum.begin(), possibleSum.end(), rem) - possibleSum.begin();
        if(find > 0 && current + possibleSum[find - 1] <= maxVal && current + possibleSum[find - 1] > ans) {
            ans = current + possibleSum[find - 1];
        }
    } else {
        for(auto& v: components[idx]) {
            buildOutput(idx + 1, from, to, current + v, maxVal, ans);
        }
    }
}
    

long long solve() {
    possibleSum.clear();
    long long b;
    int n;
    cin >> b;
    cin >> n;
    components.resize(n);
    for(auto i = 0; i < n; i++) {
        int k;
        cin >> k;
        components[i].resize(k);
    }
    for(auto  i = 0; i < n; i++) {
        for(auto j = 0; j < components[i].size(); j++){
            cin >> components[i][j];
        }
    }
    long long ans = 0;
    if(n == 1) {
        for(auto& v: components[0]) {
            if(v <= b && v > ans) {
                ans = v;
            }
        }
    }
    else {
        int half = n/2;
        buildPossibleSum(0, 0, half, 0, b);
        if(possibleSum.size() > 0) {
            sort(possibleSum.begin(), possibleSum.end());
            buildOutput(half, half, n, 0, b, ans);
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cout << solve() << "\n";
    }
    return 0;
}