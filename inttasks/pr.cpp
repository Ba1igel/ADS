#include <iostream>
#include <vector>
using namespace std;
void qs(vector<int>& a, int l, int r){
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
    if(l < j) {
        qs(a, l, j);
    }
    if(i < r) {
        qs(a, i, r);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    qs(a, 0, n - 1);
    int target;
    cin >> target;


    int index = 0;
    for(int i = 0; i < n; i++) {
        if(target == a[i]){
            index = i;
            break;
        }

    }
    
    cout << index + 1 << endl;
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}