// qucik sort 

#include <iostream>
#include <vector>
using namespace std;

void quick_sort(vector<char>& a, int l, int r) { 
    int p = a[(l + r) / 2];
    int i = l;
    int j = r;  
    while(i < j) {
        while((a[i] < p)) i++;
        while((a[j] > p)) j--;

        if(i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if(l < j) {
        quick_sort(a, l, j);
    }