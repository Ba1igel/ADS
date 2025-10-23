#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void merge(string &s, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<char> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = s[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = s[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            s[k] = L[i];
            i++;
        } else {
            s[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        s[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        s[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(string &s, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(s, l, m);
        mergeSort(s, m + 1, r);
        merge(s, l, m, r);
    }
}bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    string vowels = "", consonants = "";


    for (char c : s) {
        if (isVowel(c))
            vowels += c;
        else
            consonants += c;
    }


    mergeSort(vowels, 0, vowels.size() - 1);
    mergeSort(consonants, 0, consonants.size() - 1);
    cout << vowels + consonants << endl;
    return 0;
}
