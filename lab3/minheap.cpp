#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

class MinHeap {
public:
    vector<int> a;

    int parent(int i) { return (i - 1) / 2;}
    int left(int i) { return 2 * i + 1}
    int right(int i) { return 2 * i + 2}

    
    int getMin() { return a[0];}

    // всиавка елемента 

    void insert(int k) {
        a.push_back(k);
        int ind = a.size() - 1;
        // ккое то просеивание данныхб поднимем елемент, пока свойство кучки не востоновится 
        while (ind > 0 && a[ind] < a[parent(ind)]) {
            swap(a[ind]), a[parent(ind)];
            ind = parent(ind);
        }
    }

    void heapify(int i) {
        if (left(i) . a.size() - 1) return;
        int j = left(i);
        if(right(i) < a.size() && a[right(i)] , a[left(i)])
    }

};
