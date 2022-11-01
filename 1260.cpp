#include <iostream>
#include <list>

using namespace std;

void DFS(int v, int N, const bool gragh[1001][1001], bool isVisited[1001]){
    if(isVisited[v]){
        return;
    }
    cout << v << " ";
    isVisited[v] = true;
    for (int i = 1; i <= N; i++){
        if(gragh[v][i] && !isVisited[i]){
            DFS(i, N, gragh, isVisited);
        }
    }
}

void BFS(int V, int N, const bool gragh[1001][1001], bool isVisited[1001]){
    list<int> q;
    q.push_back(V);
    isVisited[V] = true;
    while (!q.empty()){
        int v = q.front();
        q.pop_front();

        cout << v << " ";
        for (int i = 1; i<= N; i++){
            if(gragh[v][i] && !isVisited[i]){
                isVisited[i] = true;
                q.push_back(i);
            }
        }
    }
}

int main(){
    bool graph[1001][1001] = {false};
    bool isVisited[1001] = {false};
    int N, M, V;
    cin >> N >> M >> V;
    cin.ignore();
    for (int i = 0; i < M; i++){
        int temp_a, temp_b;
        cin >> temp_a >> temp_b;
        cin.ignore();
        graph[temp_a][temp_b] = true;
        graph[temp_b][temp_a] = true;
    }

    DFS(V, N, graph, isVisited);
    cout << endl;
    for (int i = 1; i <= N; i++){
        isVisited[i] = false;
    }

    BFS(V, N, graph, isVisited);
}