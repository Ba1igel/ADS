#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());


    int max_count = 1, count = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i-1]) count++;
        else count = 1;
        if (count > max_count) max_count = count;
    }

    count = 1;
    for (int i = 1; i <= n; i++) {
        if (i < n && a[i] == a[i-1]) {
            count++;
        } else {
            if (count == max_count) cout << a[i-1] << " ";
            count = 1;
        }
    }
}