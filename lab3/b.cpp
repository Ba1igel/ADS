#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<long long> a;

bool can(long long mid) {
    long long sum = 0;
    int blocks = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] > mid) return false;
        if (sum + a[i] > mid) {
            blocks++;
            sum = a[i];
        } else {
            sum += a[i];
        }
    }
    return blocks <= k;
}

int main() {
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    long long left = *max_element(a.begin(), a.end());
    long long right = accumulate(a.begin(), a.end(), 0LL);

    while (left < right) {
        long long mid = left + (right - left) / 2;
        if (can(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    cout << left << endl;
    return 0;
}
