#include <iostream>
using namespace std;

int main() {

    int t; 
    cin >> t;                       
    int a[t];
    for (int i = 0; i < t; i++) {
        cin >> a[i];                
    }

    int n, m;
    cin >> n >> m;                  
    int arr[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int k = 0; k < t; k++) {
        bool found = false;
        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == a[k]) {
                    cout << i << " " << j << endl;
                    found = true;
                    break;
                }
            }
        }
        if (!found) {
            cout << -1 << endl;
        }
    }

    return 0;
}
