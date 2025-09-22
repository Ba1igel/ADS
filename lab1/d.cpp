#include <iostream>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    stack<char> st;
    cin >> s;

    bool isValid = true;
    for(char c : s) {
        if(c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
        
        else { 
            if (st.empty()) {
                isValid = false;
                break;
            }

            char top = st.top();
            if ((c == ')' && top != '(') || ( c == '}' && top != '{') || (c == ']' && top != '[') ) {
                isValid = false;
                break;
            }
            st.pop();
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