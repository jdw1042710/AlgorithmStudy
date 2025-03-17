#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
const long long INF = 987654321;
const int startCity = 0;
vector<vector<int>> graph;
vector<vector<long long>> cache;

void Solution();

long long TSP(int city, long long visited);

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;
    cin.ignore();
    for(int i = 0; i < N; ++i)
    {
        graph.push_back(vector<int>());
        for(int j = 0; j < N; ++j)
        {
            int value;
            cin >> value;
            graph[i].push_back(value);
        }
        cin.ignore();
    }
    Solution();
}

void Solution()
{
    cache = vector<vector<long long>>(N, vector<long long>(1 << N, -1));
    cout << TSP(startCity, 1 << startCity);
}

long long TSP(int city, long long visited)
{
    if(visited == (1 << N) - 1) return graph[city][startCity] == 0 ? INF : graph[city][startCity];
    long long& ret = cache[city][visited];
    if(ret != -1) return ret;
    // cout << "visited: " << city << endl;;
    ret = INF;
    for(int next = 0; next < N; ++next)
    {
        if(visited & (1 << next) || graph[city][next] == 0) continue;
        ret = min(ret, (long long)graph[city][next] + TSP(next, visited | 1 << next));
    }
    return ret;
}