int main() {

    string s1, s2;
    cin >> s1 >> s2;

    stack<char> st1, st2;

    for(char c : s1) {
        st1.push(c);
        if(c == '#'){
            st1.pop();
        }
    }

    for(char c : s2) {
        st2.push(c);
        if(c == '#'){
            st2.pop();
        }
    }
    

    if(s1 == s2) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}


#include <iostream>
#include <stack>
#include <string>
using namespace std;

string srav(string s) {
    string ns = "";
    for(char c : s) {
        if(c == '#'){
            if(!ns.empty()) ns.pop_back();
        }
        else {
            ns.push_back(c);
        }
    }
    return ns;
}

int main() {

    string s1, s2;
    cin >> s1 >> s2;

    if(srav(s1) == srav(s2)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}