#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    int count = 0;


    for(int i = 0; i < n; i++) {
        int m;
        cin >> m;

        vector<int> charTable(26, 0);
        queue<char> dq;

        for(int j = 0; j < m; j++) {
            char c;
            cin >> c;
            int cInt = int(c);

            charTable[cInt - 97]++; 
            dq.push(c);

            while(!dq.empty() && charTable[int(dq.front()) - 97] > 1) {
                dq.pop();
            }
            
            if (dq.empty()) {
                cout << -1 << " ";
            } else {
                cout << dq.front() << " ";
            }
        }
        cout << endl;
    }

}