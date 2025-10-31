
#include <bits/stdc++.h>
using namespace std;
bool compareLength(const string &a, const string &b) {
    return a.size() < b.size();
}

int main() {
    int t;
    cin >> t;
    string s;
    cin.ignore();
    for(int i = 0; i < t; i++) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<string> kucha;
        string w;
        while (ss >> w){
            kucha.push_back(w);
        }
        stable_sort(kucha.begin(), kucha.end(), compareLength);

        for(auto &w : kucha) {
            cout << w << " ";
        }
        cout << endl;
    }
    return 0;

}