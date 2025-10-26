#include <iostream>
using namespace std;

int a[10000];
void quick_sort(int l, int r) {
    //pivot midle
    int p = a[(l + r) / 2];
    int i = l;
    int j = r;
    // Секционирование массива
    while (i < j) {
        //нахлодим елемент который слева который должен быть справа
        while (a[i] < p) i++;
        //находим елемент который справа который должен быть слева
        while (a[j] > p) j--;

        //меняэм елементы местами
        if (i <= j) {
        swap(a[i], a[j]);
        i++;
        j--;
        }
    }
    if(l < j)
        quick_sort(l, j);

    if (i < r) 
        quick_sort(i, r);

}
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    quick_sort(0, n - 1);
    cout << endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << endl;
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}
