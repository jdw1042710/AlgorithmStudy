
#include <iostream>
#include <vector>

using namespace std;

int N, M;

vector<vector<int>> edge;

void Input();
void Solution();

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    Solution();
}

pair<int, int> GetDirection(char dir)
{
    pair<int, int> ret = {0, 0};
    switch(dir)
    {
    case 'U':
        ret.first = -1;
        break;
    case 'D':
        ret.first = 1;
        break;
    case 'L':
        ret.second = -1;
        break;
    case 'R':
        ret.second = 1;
        break;
    }
    return ret;
}

void Input()
{
    cin >> N >> M;
    cin.ignore();
    edge = vector<vector<int>>(N, vector<int>(M));
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            char c_dir;
            cin >> c_dir;
            pair<int, int> dir = GetDirection(c_dir);
            edge[i][j] = (i + dir.first) * M + (j + dir.second);
        }
        cin.ignore();
    }
}

bool DFS(int row, int col, vector<vector<int>>& visited)
{
    if(visited[row][col] == 1) return true;
    if(visited[row][col] == 2) return false;
    visited[row][col] = 1;
    bool ret = DFS(edge[row][col] / M, edge[row][col] % M, visited);
    visited[row][col] = 2;
    return ret;
}

void Solution()
{
    Input();
    int result = 0;
    vector<vector<int>> visited(N, vector<int>(M, 0)); // 0 : 방문X, 1 : 현재 사이클이 생성중, 2 : 이미 사이클이 생성됨
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            if(visited[i][j]) continue;
            bool isCycleCreated = DFS(i, j, visited);
            if(!isCycleCreated) continue;
            ++result;
        }
    }
    cout << result << endl;
}