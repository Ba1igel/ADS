#include <iostream>
#include <vector>
using namespace std;


void heapify(vector<double>& a, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] < a[smallest])
        smallest = left;
    if (right < n && a[right] < a[smallest])
        smallest = right;

    if (smallest != i) {
        swap(a[i], a[smallest]);
        heapify(a, n, smallest);
    }
}


void buildHeap(vector<double>& a) {
    int n = a.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
}


double extractMin(vector<double>& a, int& n) {
    double root = a[0];
    a[0] = a[n - 1];
    n--;
    heapify(a, n, 0);
    return root;
}


void insert(vector<double>& a, int& n, double val) {
    n++;
    if (n > (int)a.size()) a.push_back(val);
    else a[n - 1] = val;

    int i = n - 1;
    while (i > 0 && a[i] < a[(i - 1) / 2]) {
        swap(a[i], a[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int main() {
    int n;
    double k;
    cin >> n >> k;

    vector<double> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    buildHeap(a);
    int heapSize = n;
    int mixes = 0;

    while (heapSize > 1 && a[0] < k) {
        double x = extractMin(a, heapSize);
        double y = extractMin(a, heapSize);
        double newMix = x + y / 2.0; 
        insert(a, heapSize, newMix);
        mixes++;
    }

    if (a[0] >= k)
        cout << mixes << endl;
    else
        cout << -2 << endl;

    return 0;
}
