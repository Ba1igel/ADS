#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main () {
    
    int n, m; 
    cin >> n >> m;
    deque<string> dq;
    for(int i = 0; i < n; i++) 
    {
        string s; 
        cin >> s;
        dq.push_back(s);
        
    }
    for(int i = 0; i < m; i++) 
    {
        dq.push_back(dq.front());
        dq.pop_front();
    }

    for(int i = 0; i < dq.size(); i++) 
    {
        cout << dq[i] << " ";
    }
    for(int i = 0; i < dq.size(); i++) 
    {
        cout << dq[i] << " ";
    }
}



