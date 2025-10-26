#include <iostream>
#include <vector>
using namespace std;

bool isV(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool firstg(char a, char b) {
    bool va = isV(a);
    bool vb = isV(b);
    if(va && !vb) return true;
    if(!va && vb) return false;
    return a < b;

}

void quick_sort(vector<char>& a, int l, int r) { 
    int p = a[(l + r) / 2];
    int i = l;
    int j = r;


    while(i < j) {
        while(firstg(a[i], p)) i++;
        while(firstg(p, a[j])) j--;

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
    quick_sort(k, 0, n - 1);

    cout << "Sorted array:   ";
    for (int i = 0; i < n; i++) {
        cout << k[i] << " ";
    }
    cout << endl;
    return 0;
    
}