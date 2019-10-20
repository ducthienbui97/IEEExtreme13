#include <iostream>
#include <bits/stdc++.h> 

using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> pr;
    deque<int> arr;
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        arr.push_back(t);
    }
    for(int i = 0; i < m; i++) {
        int t;
        cin >> t;
        pr.push(t);
    }
    
    while(!arr.empty() && !pr.empty()) {
        if(arr.front() < pr.top()) {
            cout << arr.front() << ' ';
            arr.pop_front();
        }
        else {
            cout << pr.top() <<' ';
            pr.pop();
        }
    }
    while(!arr.empty()) {
        cout << arr.front() << ' ';
        arr.pop_front();
    }
    while(!pr.empty()) {
        cout << pr.top() <<' ';
        pr.pop();   
    }
    
    return 0;
}