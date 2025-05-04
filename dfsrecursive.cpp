#include <iostream>
using namespace std;

int G[10][10], visited[10], n; 

void DFS(int i) {
    cout << i << " ";
    visited[i] = 1;

    for (int j = 0; j < n; j++) {
        if (!visited[j] && G[i][j] == 1) {
            DFS(j);
        }
    }
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix of the graph:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> G[i][j];
        }
    }

    
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    cout << "DFS traversal starting from vertex 0:\n";
    DFS(0);

    return 0;
}