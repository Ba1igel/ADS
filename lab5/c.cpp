#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void hepf(vector<int>& a, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && a[left] > a[largest])
        largest = left;
    if(right < n && a[right] > a[largest])
        largest = right;

    if(largest != i) {
        swap(a[i], a[largest]);
        hepf(a, n, largest);
    }
}

void stroibuild(vector<int>& a) {
    int n = a.size();
    for(int i = n / 2 - 1; i >= 0; i--)
        hepf(a, n, i);
}

int maxalptas(vector<int>& a, int& n){
    int root = a[0];
    a[0] = a[n - 1];
    n--;
    hepf(a, n, 0);
    return root;
}

void insert(vector<int>& a, int& n, int val) {
    n++;
    if(n > a.size()) a.push_back(val);
    else a[n - 1] = val;
    int i = n - 1;
    while (i > 0 && a[i] > a[(i - 1) / 2]) {
        swap(a[i], a[(i - 1) / 2]);
        i = (i-1) / 2;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }


    stroibuild(a);
    long long profit = 0;
    int heapsize = n;


    for(int i = 0; i < m; i++) {
        int top = maxalptas(a, heapsize);
        profit += top;
        top--;
        if (top > 0)
            insert(a, heapsize, top);
    }



    
    cout << profit << endl;
    return 0;
}

