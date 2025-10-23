#include <iostream>
using namespace std;

void merge(int array[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = array[l + i];
    for (int j = 0; j < n2; j++) R[j] = array[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) array[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) array[k++] = L[i++];
    while (j < n2) array[k++] = R[j++];
}

void mergeSort(int array[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);
        merge(array, l, m, r);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    int* array = new int[n];
    for (int i = 0; i < n; i++) cin >> array[i];

    mergeSort(array, 0, n - 1);

    for (int i = 0; i < n; i++) cout << array[i] << " ";
    cout << "\n";

    delete[] array;
    return 0;
}