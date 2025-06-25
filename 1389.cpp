#include <iostream>
#include <vector>
#include <queue>
#include <cstring>


using namespace std;

int N, M, INF = 987654321;
int graph[100][100];

void Input();
void Solution();
int GetKevNum(int start);

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}

void Input()
{
    memset(graph, 0, sizeof(graph));
    cin >> N >> M;
    cin.ignore();
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        cin.ignore();
        --a; --b;
        graph[a][b] = graph[b][a] = 1;
    }
}

void Solution()
{
    Input();
    int answer = 0, minKevNum = INF;
    for(int i = 0; i < N; ++i)
    {
        int curKevNum = GetKevNum(i);
        if(minKevNum > curKevNum)
        {
            answer = i + 1;
            minKevNum = curKevNum;
        }
    }
    cout << answer << endl;
}

int GetKevNum(int start)
{
    vector<bool> visited = vector<bool>(N, false);
    vector<int> distance = vector<int>(N, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
    distance[start] = 0;
    pq.push({0, start});
    int result = 0;
    while(!pq.empty())
    {
        int curDist = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(visited[cur]) continue;
        visited[cur] = true;
        result += distance[cur];
        for(int next = 0; next < N; ++next)
        {
            if(visited[next]) continue;
            if(graph[cur][next] == 0) continue;
            int nextDist = curDist + graph[cur][next];
            if(distance[next] <= nextDist) continue;
            distance[next] = nextDist;
            pq.push({-nextDist, next}); 
        }
    }
    return result;
}
