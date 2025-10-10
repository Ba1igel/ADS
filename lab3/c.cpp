#include <iostream>
#include <vector>

using namespace std;

int countm(int a, int d, int a1, int d1, vector<int> v) {
    int count = 0;
    for( int x : v) {
        if((a <= x && x <= d) || (a1 <= x && x <= d1)) {
            count++;
        }
    }
    return count;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n);

    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    while(q--) {
        int a, d, a1, d1;
        cin >> a >> d >> a1 >> d1;
        cout << countm(a, d, a1, d1, v) << endl;
    }
}