#include <iostream>
#include <deque>
using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    deque<char> dq;
    for (char c : s) dq.push_back(c);

    while (true) {
        bool hS = false, hK = false;
        for (char c : dq) {
            if (c == 'S') hS = true;
            if (c == 'K') hK = true;
        }
        if (!hS || !hK) break; // одна команда исчезла

        char a = dq.front(); dq.pop_front();
        char b = dq.front(); dq.pop_front();

        if (a == b) {
            dq.push_back(a);
            dq.push_back(b);
        } else if (a == 'S' && b == 'K') {
            dq.push_back('S'); // S победил
        } else if (a == 'K' && b == 'S') {
            dq.push_back('K'); // K победил
        }
    }

    if (!dq.empty()) {
        if (dq.front() == 'S') cout << "SAKAYANAGI";
        else cout << "KATSURAGI";
    }
}



/*
#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    string s;
    cin >> s;

    deque<char> dq;
    for(char c : s ) dq.push_back(c);
    while(true){

        bool hS = false; bool hK = false;
        for(char c : dq) {
            if(c == 'S') hS = true;
            if(c == 'K') hK = true;
        }

        if(!hS || !hK) break;
    
        char a =dq.front(): dq.pop_front();
        char b = dq.back(); dq.pop_back();

        if(a == b)
        
    }
    if (!dq.empty()) {
        if (dq.front() == 'S') cout << "SAKAYANAGI";
        else cout << "KATSURAGI";
    }


}
*/