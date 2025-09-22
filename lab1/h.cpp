#include <iostream> 
using namespace std;

bool IsPrime(int x) {

    if(x < 2) return false;
    if(x == 2) return true;
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0) {
            return false;
        }
    }
    return true;
}

int main () {

    int n;
    cin >> n;

    if(IsPrime(n)){
        cout << "YES";
    }
    else {
        cout << "NO";
    }
}