#include <iostream>

using namespace std;
pair<int,int> root[111][111];
int cnt[111][111];
bool activated[111][111];
pair<int,int> findroot(int x,int y) {
    auto p = root[x][y];
    if(p.first == x && p.second == y) 
        return p;
    p = findroot(p.first, p.second);
    root[x][y] = p;
    return p;
}
void join(int x1, int y1, int x2, int y2) {
    if(!activated[x2][y2])
        return;
    auto p = findroot(x2, y2);
    if(p.first == x1 && p.second == y1) {
        cnt[x1][y1] -= 2;
    } else {
        cnt[x1][y1] += cnt[p.first][p.second] - 2;
        root[p.first][p.second] = {x1,y1};
    }
}
void activate(int x,int y) {
    cnt[x][y] = 6;
    
    join(x, y, x - 1, y);
    join(x, y, x + 1, y);
    join(x, y, x, y -1);
    join(x, y, x, y + 1);
    if(x & 1) {
        join(x, y, x - 1, y - 1);
        join(x, y, x + 1, y - 1);
    } else {
        join(x, y, x - 1, y + 1);
        join(x, y, x + 1, y + 1);
    }
    activated[x][y] =true;
}
int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) 
    for(int j =1;  j <= m; j++)
        root[i][j] = {i,j};
    for(int i = 1; i <= n; i++) {
        int k;
        if(i&1) 
            for(int j = 1; j <= m; j++) {
                cin >> k;  
                if(k) 
                    activate(i, j);
            }
        else 
            for(int j = 1; j < m; j++) {
                cin >> k;
                if(k)
                    activate(i, j);
            }
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        string s;
        int x, y;
        cin >> s >> x >> y;
        if(s[0] == 'a') {
            activate(x, y);
        } else {
            auto p = findroot(x, y);
            cout << cnt[p.first][p.second] << endl;
        }
    }
    return 0;
}