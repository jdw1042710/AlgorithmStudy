#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
#include <functional>

using namespace std;

int n, m, x;
const long long INF = (1 << 29);
vector<vector<int>> graph;
vector<int> cost;
vector<int> cost_reversed;


void Solution();
void Dijkstra(bool isReversed = false);

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    // cout << INF << endl;

    cin >> n >> m >> x;
    cin.ignore();
    graph = vector<vector<int>>(n, vector<int>(n, INF));
    for(int i = 0; i < m; i++)
    {
        int start, end, edge;
        cin >> start >> end >> edge;
        cin.ignore();
        // graph[start][end] = edge;
        graph[start - 1][end - 1] = edge;
    }
    Solution();
}     

void Solution()
{
    cost = vector<int>(n, INF);
    cost_reversed = vector<int>(n , INF);
    cost[x - 1] = 0;
    cost_reversed[x - 1] = 0;
    // cout << "Going" << endl;
    Dijkstra(false);
    // cout << endl;
    // cout << "Turn Back" << endl;
    Dijkstra(true);
    int result = 0;
    for(int i = 0; i < n; ++i)
    {
        result = max(result, cost[i] + cost_reversed[i]);
    }
    cout << result;
}

void Dijkstra(bool isReversed)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int ,int>>> pq;
    vector<bool> visited = vector<bool>(n, false);
    pq.push({0, x - 1});
    while(!pq.empty())
    {
        int node, node_cost;
        node = pq.top().second;
        node_cost = pq.top().first;
        pq.pop();
        visited[node] = true;
        // cout << "current : " << node + 1 << endl;
        // cout << "visit :";
        for(int i = 0; i < n; i++)
        {
            int edge = isReversed ? graph[i][node] : graph[node][i];
            int& i_cost = isReversed ? cost_reversed[i] : cost[i];
            if(visited[i])
                continue;
            int new_value = node_cost + edge;
            if(i_cost > new_value)
            {
                // cout << ' ' << i + 1;
                i_cost = new_value;
                pq.push({new_value, i});
            }
        }
        // cout << endl;
    }
}