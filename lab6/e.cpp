#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));


    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];


    for (int j = 0; j < m; j++) {
        vector<int> stolb;
        for (int i = 0; i < n; i++)
            stolb.push_back(mat[i][j]);

        sort(stolb.begin(), stolb.end());  
        reverse(stolb.begin(), stolb.end()); 
        for (int i = 0; i < n; i++)
            mat[i][j] = stolb[i];
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }

    return 0;
}
