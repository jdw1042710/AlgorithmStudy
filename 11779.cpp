#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int N, M, S, E;
const long long INF = 100000ll * 100000ll + 1ll;
vector<vector<pair<int, int>>> adjacence;

void Input();
void Solution();

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}

void Input()
{
    cin >> N;
    cin.ignore();
    cin >> M;
    cin.ignore();
    adjacence = vector<vector<pair<int, int>>>(N + 1, vector<pair<int, int>>());
    for(int i = 0; i < M; ++i)
    {
        int s, e, c;
        cin >> s >> e >> c;
        cin.ignore();
        adjacence[s].push_back({e, c});
    }
    cin >> S >> E;
    cin.ignore();
}

void Solution()
{
    Input();
    vector<bool> visited(N + 1, false);
    vector<long long> costs(N + 1, INF);
    vector<int> ex_vertex(N + 1, -1);
    costs[S] = 0;
    ex_vertex[S] = S;
    priority_queue<pair<long long, int>> pq;
    pq.push({0, S});
    while(!pq.empty())
    {
        long long cost = -pq.top().first;
        int vertex = pq.top().second;
        pq.pop();
        if(visited[vertex]) continue;
        visited[vertex] = true;
        if(vertex == E) break;
        for(const auto next : adjacence[vertex])
        {
            int next_vertex = next.first;
            if(visited[next_vertex]) continue;
            long long next_cost = cost + next.second;
            if(next_cost > costs[next_vertex]) continue;
            costs[next_vertex] = next_cost;
            ex_vertex[next_vertex] = vertex;
            pq.push({-next_cost, next_vertex});
        }
    }

    vector<int> rev_route({E});
    int cur = E;
    while(ex_vertex[cur] != cur)
    {
        cur = ex_vertex[cur];
        rev_route.push_back(cur);
    }
    cout << costs[E] << endl;
    cout << rev_route.size() << endl;
    for(auto iter = rev_route.rbegin(); iter != rev_route.rend(); ++iter)
    {
        cout << (*iter) << ' ';
    }
    cout << endl;
}
