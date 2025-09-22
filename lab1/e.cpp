#include <iostream>
#include <queue>
using namespace std;


int main() {

    queue<int> q1, q2;
    for(int i = 0; i < 5; i++) {
        int x; 
        cin >> x;
        q1.push(x);
    }

    for(int i = 0; i < 5; i++) {
        int x;
        cin >> x;
        q2.push(x);
    }

    int m = 0;



    for(int i = 0; i < 1000000; i++) {

        if(q1.empty()) {
            cout << "Nursik " << m;
            return 0;
        }
        if(q2.empty()) { 
            cout << "Boris " << m;
            return 0;
        }

        int v1 = q1.front(); q1.pop();
        int v2 = q2.front(); q2.pop();

        if(v1 == 0 && v2 == 9) {
            q1.push(v1);
            q1.push(v2);
        }

        else if(v2 == 0 && v1 == 9) {
            q2.push(v1);
            q2.push(v2);
        }

        else if(v1 > v2) {
            q1.push(v1);
            q1.push(v2);
        }

        else {
            q2.push(v1);
            q2.push(v2);
        }
        m++;
    }
    cout << "blin nichya";
    return 0;
}