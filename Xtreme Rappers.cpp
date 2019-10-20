#include <iostream>

using namespace std;

long long get(long long x, long long y) {
    if(x == 0 || y == 0) {
        return 0;
    }
    if(x == y) {
        if(x == 1) 
            return 0;
        if(x == 2) 
            return 1;
        
        return (x/3)*2 + get(x%3, y%3);
    }
    if(x < y)
        return get(y, x);
    long long m = min(x - y, y);
    return m + get(x - 2*m, y - m);
}

int main() {
    long long a,b;
    cin >> a >> b;
    cout << get(a, b);
    return 0;
}