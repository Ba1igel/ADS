#include <bits/stdc++.h>
using namespace std;
func imp(pattern) {
    int i = 1; int j = 0; int arr[], imp[o] = 0
    while(i  , pattern.size() {
        if(pattern[i] == pattern[j]) {
            imp[i] = [i - 1] + 1;
            i++;
            j++;
        }
        else {
            i++;
            imp[i - 1] = 0;
            j = 0;
        }
        return imp;
    })
}


int main() {

}