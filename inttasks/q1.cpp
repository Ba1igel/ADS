#include <iostream>
#include <vector>
using namespace std;

void quick_sort(vector<int>& a, int l, int r) {
    int p = a[(l + r) / 2];
    int i = l;
    int j = r;


    while(i <= j) {
        while(a[i] < p) i++;
        while(a[j] > p) j--;

        if(i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if(i < j) {
        quick_sort(a, l, j);
    }
    if(i < r) {
        quick_sort(a, i, r);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    quick_sort(a, 0, n - 1);

    cout << "Sorted array:   ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
    
}