#include <iostream>
#include <deque>
#include <vector>
#include <string>

using namespace std;
int main() {

    deque<int> dq;
    vector<int> res;
    string sim;

    while(cin >> sim) {
        if(sim == "!") {
            break;
        }

        else if(sim == "+") {
            int x;
            cin >> x;
            dq.push_front(x);
        }

        else if(sim =="-") {
            int x;
            cin >> x;
            dq.push_back(x);
        }

        else if(sim == "*") {
            if(!dq.empty()) {
                int s = dq.front() + dq.back();
                res.push_back((s));
                dq.pop_front();
                if(!dq.empty()) {
                    dq.pop_back();
                }
            }
        }

    }
    for(int x : res) {
        cout << x << endl;
    }
    if(dq.empty()) {
        cout << "error";
    }


}