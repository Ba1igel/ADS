#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    int left = 1, right = *max_element(a.begin(), a.end());
    int answer = right;

    while (left <= right) {
        int mid = (left + right) / 2;
        int flights = 0;
        for (int x : a) {
            flights += (x + mid - 1) / mid;
        }

        if (flights <= k) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    if(answer == 0) {
        cout << 1;
    }
    else{
        cout << answer << endl;
    }
    return 0;
}
