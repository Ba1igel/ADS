#include <iostream>
#include <algorithm>

#include <deque>

using namespace std;

int main() {
    int n;
    cin >> n;
    string name, pri = "";

    deque<string> dq;
    for(int i = 0; i < n; i++) {
        cin >> name;

        if(name !=pri) {
            dq.push_back(name);
            pri = name;
        }

    }
    reverse(dq.begin(), dq.end());

    cout << "All in all: " << dq.size() <<  endl << "Students: " << endl;

    for (int i = 0; i < dq.size(); i++) {
        cout << dq[i] <<  " " << endl;
    }


}