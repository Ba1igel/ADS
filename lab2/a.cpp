#include <iostream>
#include <deque>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    deque<int> dq;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        dq.push_back(x);
    }

    int nix;
    cin >> nix;

    int index = 0;
    int min = abs(dq[0] - nix);

    for (int i = 1; i < dq.size(); i++) {
        int diff = abs(dq[i] - nix);
        if (diff < min) {
            min = diff;
            index = i;
        }
    }

    cout << index;
}
