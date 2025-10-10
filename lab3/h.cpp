#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;  

    vector<long long> konec(n); 


    long long sum = 0;
    for (int i = 0; i < n; i++) {
        int len;
        cin >> len;
        sum += len;
        konec[i] = sum;
    }

    while (m--) {
        long long line;
        cin >> line;

        int blok = lower_bound(konec.begin(), konec.end(), line) - konec.begin() + 1;

        cout << blok << endl;
    }

    return 0;
}
