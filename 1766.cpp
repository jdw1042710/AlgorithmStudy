#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;

void Solution();

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    cin.ignore();
    Solution();
}

void Solution()
{
    vector<vector<int>> graph = vector<vector<int>>(N + 1, vector<int>());
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> inDegree = vector<int>(N + 1, 0);
    // for(int i = 1; i < N; ++i)
    // {
    //     graph[i].push_back(i + 1);
    // }
    for(int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        cin.ignore();
        graph[a].push_back(b);
        ++inDegree[b];
    }
    for(int i = 1; i <= N; ++i)
    {
        if(inDegree[i] == 0)
            pq.push(i);
    }
    while(!pq.empty())
    {
        int num = pq.top();
        pq.pop();
        for(auto adj : graph[num])
        {
            --inDegree[adj];
            if(inDegree[adj] == 0)
                pq.push(adj);
        }
        cout << num << ' ';
    }
}
