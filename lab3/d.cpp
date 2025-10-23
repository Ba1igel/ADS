#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int countr(vector<int> &v, int l, int r) {
    auto it1 = lower_bound(v.begin(), v.end(), l);
    auto it2 = upper_bound(v.begin(), v.end(), r);

    return it2 - it1;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n);

    for(int i = 0; i < n; i++) {    
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    while(q--) {
        int a, d, a1, d1;
        cin >> a >> d >> a1 >> d1;
        

        int countik = 0;

        int aa = countr(v, a, d);
        int aaa = countr(v, a1, d1);
        

        if(max(a, a1) <= min(d, d1) ) {
            countik = countr(v, max(a, a1), min (d, d1));
        }

        int dudu = aa + aaa - countik;

        cout << dudu << endl;
    }

}