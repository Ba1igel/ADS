#include <iostream>
#include <vector>
using namespace std;

void quick_sort(vector<char>& a, int l, int r) { 
    int p = a[(l + r) / 2];
    int i = l;
    int j = r;


    while(i < j) {
        while((a[i] < p)) i++;
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
    vector<char> k;
    char x;
    while(cin >> x) {
        k.push_back(x);
    }
    quick_sort(k, 0, k.size() - 1);


    for (int i = 0; i < k.size(); i++) {
        cout << k[i];
    }
    cout << endl;
    return 0;
    
}