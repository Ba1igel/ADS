#include <iostream>
#include <deque>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    deque<int> S, K;

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'S') S.push_back(i);
        else K.push_back(i);
    }

    while (!S.empty() && !K.empty()) {
        int s_front = S.front();
        int k_front = K.front();
        S.pop_front();
        K.pop_front();

        if (s_front < k_front) {
            S.push_back(s_front + n);
        } else {
            K.push_back(k_front + n);
        }
    }

    cout << (S.empty() ? "KATSURAGI" : "SAKAYANAGI") << endl;
}
