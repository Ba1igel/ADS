#include <iostream>
#include <vector>
using namespace std;

void quick_sort(vector<char>& a, int l, int r) { 
    int p = a[(l + r) / 2];
    int i = l;
    int j = r;


    while(i < j) {
        while((a[i] <  p)) i++;
        while((a[j] > p)) j--;

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
    int n;
    cin >> n;
    vector<char> k(n);
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }
    char s;
    cin >> s;

    quick_sort(k, 0, n-1);
    char e = k[0];
    for (int i = 0; i < n; i++) {
        if(k[i] > s) {
            e = k[i];
            break;
        }
    }
    cout << e;
    return 0;
    
}