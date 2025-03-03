#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int n, m, x;
const long long INF = (1 << 29);
// vector<vector<int>> graph;
vector<vector<long long>> cache;


void Solution();

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    // cout << INF << endl;

    cin >> n >> m >> x;
    cin.ignore();
    // graph = vector<vector<int>>(n, vector<int>(n, -1));
    cache = vector<vector<long long>>(n, vector<long long>(n, INF));
    for(int i = 0; i < m; i++)
    {
        int start, end, edge;
        cin >> start >> end >> edge;
        cin.ignore();
        // graph[start][end] = edge;
        cache[start - 1][end - 1] = edge;
    }
    Solution();
}     

void Solution()
{
    for(int k = 0; k < n; ++k)
    {
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(i == j)
                {
                    cache[i][j] = 0;
                    continue;
                }
                cache[i][j] = min(cache[i][j], cache[i][k] + cache[k][j]);
            }
        }
    }
    // find max;
    long long result = 0;
    for(int i = 0; i < n; ++i)
    {
        result = max(result, cache[i][x - 1] + cache[x - 1][i]);
    }

    cout << result;
}
