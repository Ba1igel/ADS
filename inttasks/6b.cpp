#include <iostream>
#include <vector>
using namespace std;

void quick_sort(vector<int>& a, int l, int r) {
    int p = a[(l + r)  /2];
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
    if(i < r)
        quick_sort(a, i, r);
}
int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(k);
    for(int i = 0; i < k; i++) {
        cin >> b[i];
    }

    quick_sort(a, 0, n - 1);
    quick_sort(b, 0, k - 1);
    int i = 0;
    int j = 0;
    while(i < n && j < k){
        if(a[i] == b[j]) {
            cout << a[i] << " ";
            i++, j++;
        }
        else if( a[i] < b[j]) {
            i++;
        }
        else 
            j++;

    }
}