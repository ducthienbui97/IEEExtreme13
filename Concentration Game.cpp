#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    vector<vector<int>> v(n + 1);
    for(int i = 1; i <= n; i++) {
        cout << i <<" "<<i + n << endl;
        int x, y;
        cin >> s;
        if(s != "MATCH") {
            x = stoi(s);
            cin  >> y;
            v[x].push_back(i);
            v[y].push_back(i + n);
            if(v[x].size() == 2) {
                cout << v[x][0] <<" "<<v[x][1] <<endl;
                v[x].clear();
                cin >> s;
            }
            if(v[y].size() == 2) {
                cout << v[y][0] <<" "<<v[y][1] << endl;
                v[y].clear();
                cin >> s;
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        if(v[i].size() == 2) {
            cout << v[i][0]<<" "<<v[i][1] << endl;
        }
    }
    cout << "-1" << endl;
    return 0;
}