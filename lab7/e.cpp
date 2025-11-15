// #include <bits/stdc++.h>
// using namespace std;

// struct Row {
//     vector<int> data;
//     int sum;
// };

// bool compareRows(const Row &a, const Row &b) {
//     if (a.sum != b.sum)
//         return a.sum > b.sum; 
//     return a.data < b.data;  
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n, m;
//     cin >> n >> m;

//     vector<Row> rows+;

//     for (int i = 0; i < n; i++) {
//         rows[i].data.resize(m);
//         int total = 0;
//         for (int j = 0; j < m; j++) {
//             cin >> rows[i].data[j];
//             total += rows[i].data[j];
//         }
//         rows[i].sum = total;
//     }

//     sort(rows.begin(), rows.end(), compareRows);

//     for (auto &r : rows) {
//         for (int x : r.data) cout << x << " ";
//         cout << "\n";
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

struct Row {
    vector<int> data;
    int sum;
};

bool compareRows(const Row &a, const Row &b) {
    if (a.sum != b.sum)
        return a.sum > b.sum;
    return a.data < b.data;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Row> rows(n);

    for (int i = 0; i < n; i++) {
        int total = 0;
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            rows[i].data.push_back(x);  // <-- ehhu тут крч вмесо  resize(j)
            total += x;
        }
        rows[i].sum = total;
    }

    sort(rows.begin(), rows.end(), compareRows);

    for (auto &r : rows) {
        for (int x : r.data) cout << x << " ";
        cout << "\n";
    }

    return 0;
}
