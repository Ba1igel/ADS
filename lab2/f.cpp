#include <iostream>
#include <deque>

using namespace std;

int main () {

    int n;
    cin >> n;

    deque<int> dq;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        dq.push_back(x);
    }

    
    int number, pos;
    cin >> number >> pos;


    if(pos <= dq.size()) {
        dq.insert(dq.begin() + pos, number);
    }

    for(int i = 0; i < dq.size(); i++) {
        cout << dq[i] << " ";
    }

    
}