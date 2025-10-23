#include <bits/stdc++.h>
using namespace std;

class MinHeap {
    public:
    vector<int> a;

    int parent(int i) {
        return (i-1)/2;
    };
    int left(int i) {
        return i * 2 + 1;
    };
    int right(int i) {
        return i * 2 + 2;
    };
    int getMin() {
        return a[0];
    };

    int insert(int k) {
        a.push_back(k);
        int ind = a.size() - 1;

        while(ind > 0 && a[ind] < a[parent(ind)]) {
            swap(a[ind], a[parent(ind)]);
            ind = parent(ind);
        }
    }

    void heaPify(int i)
};

int main() {

}