#include <iostream>
#include <deque>
using namespace std;

int main() {
    int k;
    cin >> k;
    for(int i = 0; i < k; i++) {
        int n;
        cin >> n;
        deque<int> dq;
        for (int i = n; i >= 1; --i) {
            dq.push_front(i);
            for (int j = 0; j < i; ++j) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << dq[i] << " "; 
        }
    }
    return 0;
}
