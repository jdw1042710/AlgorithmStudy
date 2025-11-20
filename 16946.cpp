
#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int N, M;
const int MOD = 10;

vector<vector<int>> graph;
vector<vector<int>> id;
vector<int> spaceSize;

void Input();
void Solution();

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    Solution();
}

int GetID()
{
    static int global_id = 0;
    return global_id++;
}

bool IsValid(int row, int col)
{
    return row >= 0 && row < N && col >= 0 && col < M;
}

int dirR[4] = {-1, 0, 1, 0};
int dirC[4] = {0, 1, 0, -1};

int BFS(int row, int col, vector<vector<bool>>& visited)
{
    int ret = 0;
    int curId = GetID();
    queue<pair<int, int>> q;
    visited[row][col] = true;
    q.push({row, col});
    while(!q.empty())
    {
        int curR = q.front().first;
        int curC = q.front().second;
        q.pop();
        ret += 1;
        ret %= MOD;
        id[curR][curC] = curId;
        for(int dir = 0; dir < 4; ++dir)
        {
            int nextR = curR + dirR[dir];
            int nextC = curC + dirC[dir];
            if(!IsValid(nextR, nextC)) continue;
            if(graph[nextR][nextC] != 0) continue;
            if(visited[nextR][nextC]) continue;
            visited[nextR][nextC] = true;
            q.push({nextR, nextC});
        }
    }

    return ret;
}

void Input()
{
    cin >> N >> M;
    cin.ignore();
    graph = vector<vector<int>>(N, vector<int>(M));
    id = vector<vector<int>>(N, vector<int>(M, -1));

    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            char val;
            cin >> val;
            graph[i][j] = val - '0';
        }
        cin.ignore();
    }

    spaceSize.clear();
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            if(graph[i][j] == 0 && !visited[i][j])
            {
                spaceSize.push_back(BFS(i, j, visited));
            }
        }
    }
}

void Solution()
{
    Input();

    // for(int i = 0; i < N; ++i)
    // {
    //     for(int j = 0; j < M; ++j)
    //     {
    //         cout << adjEmptySpaceSize[i][j];
    //     }
    //     cout << '\n';
    // }
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            int val = 0;
            if(graph[i][j] == 1)
            {
                val = 1;
                set<int> searched_id;
                for(int dir = 0; dir < 4; ++dir)
                {
                    int nextR = i + dirR[dir];
                    int nextC = j + dirC[dir];
                    if(!IsValid(nextR, nextC)) continue;
                    int nextId = id[nextR][nextC];
                    if(graph[nextR][nextC] != 0) continue;
                    if(searched_id.find(nextId) != searched_id.end()) continue;
                    val += spaceSize[nextId];
                    val %= MOD;
                    searched_id.insert(nextId);
                }
            }
            cout << val;
        }
        cout << '\n';
    }
}