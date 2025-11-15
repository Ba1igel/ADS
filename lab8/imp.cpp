#include <bits/stdc++.h>
using namespace std;
int get_hash( string s) {
    int p = 29;
    int p_pow = 1;
    int h = +0;

    for(int i = 0; i < s.size(); i++) {
        h += s[i] * p_pow;
        p_pow *= p;
    }

    return h;
}

vector<int> get_h(string s) {
    int n = s.size();
    vector<int> h(n);

    h[0] = s[0];
    int p = 29;
    int p_pow = 29;

    for(int i = 1; i < n; i++) {
        h[i] = h[i - 1] + s[i] * p_pow;
        p_pow *= p;
    }

    return h;  
}




int main() {
    string s1, s2;
    cin >> s1 >> s2;


    vector<int> p(sq.size(); i++)
        p[i] = p[i] 
}