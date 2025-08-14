#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int N, M;
vector<vector<int>> graph;

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
    cin >> N >> M;
    cin.ignore();
    graph = vector<vector<int>>(N + 2, vector<int>(M + 2, 0));
    for(int i = 1; i <= N; ++i)
    {
        for(int j = 1; j <= M; ++j)
        {
            char val;
            cin >> val;
            graph[i][j] = val - '0';
        }
        cin.ignore();
    }
}

void Solution()
{
    Input();
    int dirY[4] = {0, -1, 0, 1};
    int dirX[4] = {-1, 0, 1, 0};
    vector<vector<bool>> visited(N + 2, vector<bool>(M + 2, false));
    queue<pair<int ,pii>> q;
    q.push({1, {1, 1}});
    visited[1][1] = true;
    int result = -1;
    while(!q.empty())
    {
        int step = q.front().first;
        int curY = q.front().second.first;
        int curX = q.front().second.second;
        q.pop();
        if(curY == N && curX == M)
        {
            result = step;
            break;
        }
        for(int i = 0; i < 4; ++i)
        {
            int nextY = curY + dirY[i];
            int nextX = curX + dirX[i];
            if(!graph[nextY][nextX]) continue;
            if(visited[nextY][nextX]) continue;

            visited[nextY][nextX] = true;
            q.push({step + 1, {nextY, nextX}});
        }
    }
    cout << result << endl;
}