#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
vector<vector<pair<int, int>>> graph;

class LCA
{
    vector<vector<pair<int, int>>> tree;
    int height;
    vector<vector<int>> parents;
    vector<vector<long long>> dists;
    vector<int> depths;
    vector<bool> visited;

public:
    LCA(vector<vector<pair<int, int>>> _graph)
    {
        tree = _graph;
        height = ceil(log2(tree.size()));
    }

public:
    void Init()
    {
        int n = tree.size();
        int h = height;
        parents = vector<vector<int>>(n, vector<int>(h));
        dists = vector<vector<long long>>(n, vector<long long>(h));
        depths = vector<int>(n);
        visited = vector<bool>(n, false);
        DFS(0, 0);
        for(int j = 1; j < h; ++j)
        {
            for(int i = 0; i < n; ++i)
            {
                int prevP = parents[i][j - 1];
                long long prevD = dists[i][j-1];
                parents[i][j] = parents[prevP][j - 1];
                dists[i][j] = prevD + dists[prevP][j - 1];
            }
        }
    }

    long long GetDistance(int a, int b)
    {
        int result = 0;
        if(depths[a] < depths[b]) swap(a, b);
        for(int i = height - 1; i >= 0; --i)
        {
            if(depths[a] - depths[b] >= (1 << i))
            {
                result += dists[a][i];
                a = parents[a][i];
            }
        }

        if(a == b) return result;

        for(int i = height - 1; i >= 0; --i)
        {
            if(parents[a][i] != parents[b][i])
            {
                result += (dists[a][i] + dists[b][i]);
                a = parents[a][i];
                b = parents[b][i];
            }
        }
        result += (dists[a][0] + dists[b][0]);
        return result;
    }

private:

    void DFS(int node, int depth)
    {
        visited[node] = true;
        depths[node] = depth;
        int n = tree[node].size();
        for(int i = 0; i < n; ++i)
        {
            int next = tree[node][i].first;
            int weight = tree[node][i].second;
            if(visited[next]) continue;
            parents[next][0] = node;
            dists[next][0] = weight;
            DFS(next, depth + 1);
        }
    }

};

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
    graph = vector<vector<pair<int, int>>>(N);
    for(int i = 0; i < N-1; ++i)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        cin.ignore();
        --from; --to;
        graph[from].push_back({to, weight});
        graph[to].push_back({from, weight});
    }
}

void Solution()
{
    Input();
    LCA lca(graph);
    lca.Init();

    int M;
    cin >> M;
    cin.ignore();
    for(int i = 0; i < M; ++i)
    {
        int from, to;
        cin >> from >> to;
        cin.ignore();
        --from; --to;
        cout << lca.GetDistance(from, to) << endl;
    }
}
