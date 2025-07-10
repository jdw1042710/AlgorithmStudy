#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, Start, End;
const long long INF = 10000000001LL;
vector<vector<pair<int, int>>> adjacent;
vector<vector<pair<int, int>>> rev_adjacent;
vector<long long> cost;
vector<int> inDegree;

void Input();
void Solution();

void CalculateCost(int start)
{
    cost = vector<long long>(N, 0);
    queue<int> q;
    q.push(start);
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        for(size_t i = 0; i < adjacent[cur].size(); ++i)
        {
            int next = adjacent[cur][i].first;
            long long next_cost = cost[cur] + adjacent[cur][i].second;
            cost[next] = max(cost[next], next_cost);
            inDegree[next] -= 1;
            if(inDegree[next] == 0)
                q.push(next);
        }
    }
}

int CountRoad(int end)
{
    int result = 0;
    vector<bool> visited(N, false);
    queue<int> q;
    q.push(end);
    visited[end] = true;
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        for(size_t i = 0; i < rev_adjacent[cur].size(); ++i)
        {
            int next = rev_adjacent[cur][i].first;
            long long next_cost = cost[cur] - rev_adjacent[cur][i].second;
            if(next_cost == cost[next])
            {
                ++result;
                if(!visited[next])
                {
                    q.push(next);
                    visited[next] = true;
                }
            }
        }
    }
    return result;
} 

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
    rev_adjacent = vector<vector<pair<int, int>>>(N);
    inDegree = vector<int>(N, 0);
    cin >> m;
    cin.ignore();
    
    for(int i = 0; i < m; ++i)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        --from; --to;
        cin.ignore();
        adjacent[from].push_back({to, weight});
        rev_adjacent[to].push_back({from, weight});
        inDegree[to] += 1;
    }
    cin >> Start >> End;
    --Start; --End;
    cin.ignore();
}

void Solution()
{
    Input();

    int road_result;
    CalculateCost(Start);
    road_result = CountRoad(End);
    cout << cost[End] << '\n' << road_result << endl;
}