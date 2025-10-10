#include <iostream>
#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main () {
    int n, s;
    cin >> n >> s;
    vector<int> a(n), prefix(n + 1, 0);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        prefix[i + 1] = prefix[i] + a[i];
    }

    int min_l = INT_MAX;

    for(int i = 0; i < n; i ++) {
        int target = prefix[i] + s;
        auto it = lower_bound(prefix.begin(), prefix.end(), target);
        if (it != prefix.end()) {
            int j = it - prefix.begin();
            min_l = min(min_l, j - i);
        }
    }

    cout << min_l << endl;
}