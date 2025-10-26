#include <iostream>
#include <string>
#include <vector>
using namespace std;

int convert(string s){
    int d = stoi(s.substr(0,2));
    int m = stoi(s.substr(3, 2));
    int y = stoi(s.substr(6, 4));
    return y * 10000 + m * 100 + d;
}


void qs(vector<string>& s, int l, int r) {
    int p = convert(s[(l + r) / 2]);
    int i = l;
    int j = r;

    while(i < j) {
        while(convert(s[i]) < p) i++;
        while(convert(s[j]) > p) j--;

        if(i <= j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
    if(l < j){
        qs(s, l , j);
    }
    if(i < r){
        qs(s, i, r);
    }
}
int main() {
    int n;
    cin >> n;
    vector<string> dd(n);
    for(int i = 0; i < n; i++){
        cin >> dd[i];
    }
    qs(dd, 0, n - 1);
    cout << endl;
    for(int i = 0; i < n; i++){
        cout << dd[i] << endl;
    }
}