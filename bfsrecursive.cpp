#include<iostream>
using namespace std;
const int MAX = 100;
int adj[MAX][MAX];
bool visited[MAX];
int numVertices;

void bfsrecursive(int queue[] , int&front ,int&rear){
    if(front>rear){
        return;
    }

    int current=queue[front];
    front++;
    cout<<current<<" ";

    for(int i=0;i<numVertices;i++){
        if(adj[current][i] == 1 && !visited[i]){
            visited[i]=true;
            rear++;
            queue[rear]=i;
        }
    }
    bfsrecursive(queue , front ,rear);
}

void bfs(){
    int queue[MAX];
    int front=0,rear=-1;

    for(int i=0;i<numVertices;i++){
        visited[i]=false;
    }

    for(int i=0;i<numVertices;i++){
        if(!visited[i]){
            visited[i]=true;
            rear++;
            queue[rear]=i;
            bfsrecursive(queue,front,rear);
        }
    }
}

int main(){
    cout<<"Enter No. of vertices:";
    cin>>numVertices;

    cout<<"Enter adjancency matrix:";
    for(int i=0;i<numVertices;i++){
        for(int j=0;j<numVertices;j++){
            cin>>adj[i][j];
        }
    }

    cout<<"BFS TRAVERSAL:";
    bfs();
    return 0;
}