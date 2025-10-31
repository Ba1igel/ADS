#include <bits/stdc++.h>
using namespace std;
void quick_sort(vector<int>& a, int l, int r) {
    int p = a[(l + r) / 2];
    int i = l;
    int j = r;


    while(i < j) {
        while(a[i] < p) i++;
        while(a[j] > p) j--;


        if(i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if(l < j) {
        quick_sort(a, l, j);
    }
    if(i < r) {
        quick_sort(a, i, r);
    }
}

int main() {
    int n, k;
    cin >> n;
    vector<int> a(n);
    vector<int> l;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        l.push_back(a[i]);
    }
    cin >> k;
    vector<int> b(k);
    for(int j = 0; j < k; j++) {
        cin >> b[j];
        l.push_back(b[j]);
    }
    quick_sort(l, 0, l.size() - 1);
    for(int j = 0; j < l.size(); j++) {
        cout << l[j] << " ";
    }
}