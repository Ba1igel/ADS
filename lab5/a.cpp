#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; ++i) {
        int len;
        cin >> len;
        pq.push(len);
    }

    long long total_cost = 0;
    while (pq.size() > 1) {
        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();
        int merged = first + second;
        total_cost += merged;
        pq.push(merged);
    }

    cout << total_cost << endl;
    return 0;
}
