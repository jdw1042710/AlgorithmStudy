#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, Start, End;
const long long INF = 10000000001LL;
vector<vector<pair<int, int>>> adjacent;

void Input();
void Solution();

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}

void Input()
{
    cin >> N;
    cin.ignore();
    int m;
    adjacent = vector<vector<pair<int, int>>>(N);
    cin >> m;
    cin.ignore();
    
    for(int i = 0; i < m; ++i)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        --from; --to;
        cin.ignore();
        adjacent[from].push_back({to, weight});
    }
    cin >> Start >> End;
    --Start; --End;
    cin.ignore();
}

void Solution()
{
    Input();

    vector<bool> visited(N, false);
    vector<long long> cost(N, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>> pq;
    cost[Start] = 0;
    pq.push({0, Start});
    while(!pq.empty())
    {
        int cur = pq.top().second;
        long long cur_cost = -pq.top().first;
        pq.pop();
        if(visited[cur]) continue;
        visited[cur] = true;
        for(size_t i = 0; i < adjacent[cur].size(); ++i)
        {
            int next = adjacent[cur][i].first;
            long long next_cost = cur_cost + adjacent[cur][i].second;
            if(visited[next] || cost[next] < next_cost) continue;
            cost[next] = next_cost;
            pq.push({-next_cost, next});
        }
    }

    cout << cost[End] << endl;
}