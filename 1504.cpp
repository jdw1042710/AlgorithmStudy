#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, E, V1, V2;
const long long INF = 1000 * 200000 + 1;
vector<vector<pair<int, int>>> adjacent;

void Input();
void Solution();

void Dijkstra(int start, vector<long long>& result)
{
    vector<bool> visited(N, false);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>> pq;
    result = vector<long long>(N, INF);
    result[start] = 0;
    pq.push({0, start});
    while(!pq.empty())
    {
        long long cur, cur_cost;
        cur = pq.top().second;
        cur_cost = -pq.top().first;
        pq.pop();
        if(visited[cur]) continue;
        visited[cur] = true;
        for(size_t i = 0; i < adjacent[cur].size(); ++i)
        {
            long long next, next_cost;
            next = adjacent[cur][i].first;
            next_cost = cur_cost + adjacent[cur][i].second;
            if(visited[next]) continue;
            if(result[next] <= next_cost) continue;
            result[next] = next_cost;
            pq.push({-next_cost, next});
        }
    }
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}

void Input()
{
    cin >> N >> E;
    cin.ignore();
    adjacent = vector<vector<pair<int, int>>>(N);
    for(int i = 0; i < E; ++i)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        --from; --to;
        adjacent[from].push_back({to, weight});
        adjacent[to].push_back({from, weight});
        cin.ignore();
    }
    cin >> V1 >> V2;
    --V1; --V2;
}

void Solution()
{
    Input();
    long long result;
    vector<long long> dij_result_V1, dij_result_V2;
    Dijkstra(V1, dij_result_V1);
    Dijkstra(V2, dij_result_V2);
    result = min(dij_result_V1[0] + dij_result_V1[V2] + dij_result_V2[N - 1],
                dij_result_V2[0] + dij_result_V2[V1] + dij_result_V1[N - 1]);
    if(result >= INF)
        result = -1;
    
    cout << result << endl;
}