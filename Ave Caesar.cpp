#include <bits/stdc++.h>

using namespace std;
bool check(const string& s) {
    vector<map<char, int>> trie;
    trie.resize(1);
    string ss;
    for(char c: s) {
        if(ss.empty() || c >= ss.back()) {
            ss.push_back(c);
        } else {
            int current = 0;
            for(char cc: ss) {
                if(trie[current].upper_bound(cc) != trie[current].end()) {
                    return false;
                }
                if(trie[current].find(cc) == trie[current].end()) {
                    trie[current][cc] = trie.size();
                    trie.resize(trie.size() + 1);
                }
                current = trie[current][cc];
            }
            if(trie[current].size() > 0) {
                return false;
            }
            ss.clear();
            ss.push_back(c);
            
        }
    }
    int current = 0;
    for(char cc: ss) {
        if(trie[current].upper_bound(cc) != trie[current].end()) {
            return false;
        }
        if(trie[current].find(cc) == trie[current].end()) {
            trie[current][cc] = trie.size();
            trie.resize(trie.size() + 1);
        }
        current = trie[current][cc];
    }
    if(trie[current].size() > 0) {
        return false;
    }
    ss.clear();
    return true;
}
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        putchar('0' + check(s));
    }
    return 0;
}