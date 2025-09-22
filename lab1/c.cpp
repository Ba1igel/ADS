#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {

    string s1, s2;
    cin >> s1 >> s2;

    stack<char> st1, st2;

    for(char c : s1) {
        if(c == '#'){
            if(!st1.empty()) st1.pop();
        }
        else {
            st1.push(c);
        }
    }

    for(char c : s2) {
        if(c == '#'){
            if(!st2.empty()) st2.pop();
        }
        else {
            st2.push(c);
        }
    }
    

    if(st1 == st2) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}