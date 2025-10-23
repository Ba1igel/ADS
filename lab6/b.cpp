#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;

    int a[n], b[m];
    for(int i = 0 ; i < n;i++){
        cin >> a[i];
    }
    for(int i = 0 ; i < m;i++){
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + m);
    int i = 0;
    int j = 0;
    bool tap = false;

    while(i < n && j < m) {
        if (a[i] ==b[j]) {
            cout << a[i] << " ";
            tap = true;
            i++; j++;
        }
        else if(a[i] < b[j]) {
            i++;
        }
        else j++;
        
    }

    return 0;
}