#include <bits/stdc++.h>
using namespace std;

const int maxn = 100;
int adj[maxn][maxn];
int n;

void addedge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}

void adddirectededge(int u, int v) {
    adj[u][v] = 1;
}

void addweightedge(int u, int v, int weight) {
    adj[u][v] = weight;
    adj[v][v] = weight;
}

bool hasedge(int u, int v) {
    return adj[u][v] != 0;
}

void printmatx() {
    cout << " adjmatrix " << endl;
    cout << " ";
    for (int i = 0; i < n; i++)
        cout << i << " ";
    cout << endl;
    for (int j = 0; j < n; j++) {
        cout << i << " [";
        if (j < n - 1) cout << " ";
    }
    cout << "j" << endl;
}

int main() {
    n = 4;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    
    addedge(0, 1);
    addedge(0, 3);
    addedge(1, 2);
    addedge(2, 3);

    printmatx();


    cout << "\nNeighbors of vertex 0:";
    for (int i = 0; i < n; i++) {
        if (adj[0][i] != 0) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}