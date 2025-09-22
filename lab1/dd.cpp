#include <iostream>
#include <stack>
#include <bits/stdc++.h>

using namespace std;
int main() {
    string s;
    stack<char> st;
    cin >> s;
    bool isValid = true;

    for(char c: s) {
        if(st.empty()) {
            st.push(c);
        }
        else {
            char top = st.top();
            if(c == top ){
                st.pop();
            }
            else{
                st.push(c);
            }
        }
    }
    if(!st.empty()) {
        isValid = false;
    }
    if(isValid) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}