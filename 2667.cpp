#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int N, id = 0;
vector<vector<int>> map;

void Input();
void Solution();

int Fill(pii start, int classifier, vector<vector<int>>& graph)
{
    int dirY[4] = {0, -1, 0, 1};
    int dirX[4] = {-1, 0, 1, 0};
    vector<vector<bool>> visited(graph.size() + 2, vector<bool>(graph[0].size(), false));
    queue<pii> q;
    q.push(start);
    visited[start.first][start.second] = true;
    int result = 0;
    while(!q.empty())
    {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        ++result;
        graph[curY][curX] = classifier;
        for(int i = 0; i < 4; ++i)
        {
            int nextY = curY + dirY[i];
            int nextX = curX + dirX[i];
            if(!graph[nextY][nextX]) continue;
            if(visited[nextY][nextX]) continue;

            visited[nextY][nextX] = true;
            q.push({nextY, nextX});
        }
    }
    return result;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}

void Input()
{
    cin >> N;
    cin.ignore();
    map = vector<vector<int>>(N + 2, vector<int>(N + 2, 0));
    for(int i = 1; i <= N; ++i)
    {
        for(int j = 1; j <= N; ++j)
        {
            char val;
            cin >> val;
            map[i][j] = val - '0';
        }
        cin.ignore();
    }
}

void Solution()
{
    Input();
    vector<int> result;
    id = 1;
    for(int i = 1; i <= N; ++i)
    {
        for(int j = 1; j <= N; ++j)
        {
            if(map[i][j] == 1)
            {
                int count = Fill({i, j}, ++id, map);
                result.push_back(count);
            }
        }
    }
    sort(result.begin(), result.end());
    cout << result.size() << endl;
    for(auto val : result)
    {
        cout << val << '\n';
    }
}