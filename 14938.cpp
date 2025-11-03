#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int N, M, R;
const int INF = 30 * 100 + 1;
vector<int> num_of_items;
vector<vector<pair<int, int>>> adjacence;

void Input();
void Solution();

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}

void Input()
{
    cin >> N >> M >> R;
    cin.ignore();
    num_of_items = vector<int>(N, 0);
    for(int i = 0; i < N; ++i)
    {
        cin >> num_of_items[i];
    }
    cin.ignore();
    adjacence = vector<vector<pair<int, int>>>(N);
    for(int i = 0; i < R; ++i)
    {
        int a, b, l;
        cin >> a >> b >> l;
        cin.ignore();
        --a; --b;
        adjacence[a].push_back({b, l});
        adjacence[b].push_back({a, l});
    }
}

int Dijkstra(int start)
{
    int ret = 0;
    vector<bool> visited(N, false);
    priority_queue<pair<int, int>> pq;
    pq.push({M, start});
    while(!pq.empty())
    {
        int cur_m = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(visited[cur]) continue;
        visited[cur] = true;
        ret += num_of_items[cur];
        for(size_t i = 0; i < adjacence[cur].size(); ++i)
        {
            int next = adjacence[cur][i].first;
            if(visited[next]) continue;
            int length = adjacence[cur][i].second;
            if(length > cur_m) continue;
            pq.push({cur_m - length, next});
        }
    }
    return ret;
}

void Solution()
{
    Input();
    int result = 0;
    for(int i = 0; i < N; ++i)
    {
        result = max(result, Dijkstra(i));
    }
    cout << result << endl;
}