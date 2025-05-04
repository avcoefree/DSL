#include <iostream>
using namespace std;

int main() {
    cout << "=====  Program to demonstrate the DFS Traversal on a Graph (Non-Recursive) =====\n\n";

    int cost[10][10] = {0}, visited[10] = {0}, visit[10] = {0}, stk[10];
    int i, j, k, n, e, top = 0, v;

    cout << "Enter the number of vertices in the Graph: ";
    cin >> n;

    cout << "Enter the number of edges in the Graph: ";
    cin >> e;

    cout << "Enter the start and end vertex of each edge:\n";
    for (k = 1; k <= e; k++) {
        cin >> i >> j;
        cost[i][j] = 1; 
    }

    cout << "Enter the initial vertex to start the DFS traversal with: ";
    cin >> v;

    cout << "\nThe DFS traversal on the given graph is:\n";
    cout << v << " ";
    visited[v] = 1;
    k = 1;

    while (k < n) {
        for (j = n; j >= 1; j--) {
            if (cost[v][j] != 0 && visited[j] == 0 && visit[j] == 0) {
                visit[j] = 1;
                stk[top++] = j; 
            }
        }

        if (top == 0) break; 

        v = stk[--top]; 
        cout << v << " ";
        visit[v] = 0;
        visited[v] = 1;
        k++;
    }

    cout << "\n\n";
    return 0;
}