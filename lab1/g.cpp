#include <iostream>
using namespace std;

bool IsPrime(int num) {
    if(num < 2) return false;
    if(num == 2) return true;
    for(int i =2; i * i <= num; i++) {
        if(num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {

    int n;
    cin >> n;
    int c = 0;
    int numb = 2;
    int cc = 0;
    while(true) {
        bool prime = true;

        if(IsPrime(numb)) {
            c++;
            if(IsPrime(c)) {
                cc++;
                if(cc==n) {
                    cout << numb  << endl;
                    break;
                }
            }
        }
        numb++;
    }
}