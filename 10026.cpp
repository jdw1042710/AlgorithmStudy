#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int N;
vector<vector<int>> board;

void Input();
void Solution();

bool IsSameColor(char colorA, char colorB, bool isBlind)
{
    if(isBlind && colorA != colorB)
    {
        if(colorA == 'R') return colorB == 'G';
        if(colorA == 'G') return colorB == 'R';
        return false;
    }
    return colorA == colorB; 
}

void Spread(int y, int x, bool isBlind, vector<vector<bool>>& visited)
{
    int dirX[4] = { -1, 1, 0, 0};
    int dirY[4] = { 0, 0, -1, 1};
    char val = board[y][x];
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = true;
    while(!q.empty())
    {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();
        for(int i = 0; i < 4; ++i)
        {
            int nextY = curY + dirY[i];
            int nextX = curX + dirX[i];
            int adjVal = board[nextY][nextX];
            if(visited[nextY][nextX]) continue;
            if(!IsSameColor(val, adjVal, isBlind)) continue;
            q.push({nextY, nextX});
            visited[nextY][nextX] = true;
        }
    }
}

int CountAreaNum(bool isBlind)
{
    int result = 0;
    vector<vector<bool>> visited(N + 2, vector<bool>(N + 2, false));
    for(int i = 1; i <= N; ++i)
    {
        for(int j = 1; j <= N; ++j)
        {
            if(!visited[i][j])
            {
                Spread(i, j, isBlind, visited);
                ++result;
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
    board = vector<vector<int>>(N + 2, vector<int>(N + 2, 0));
    for(int i = 1; i <= N; ++i)
    {
        for(int j = 1; j <= N; ++j)
        {
            char color;
            cin >> color;
            board[i][j] = color;
        }
        cin.ignore();
    }
}

void Solution()
{
    Input();
    pair<int, int> result = {0, 0};
    result.first = CountAreaNum(false);
    result.second = CountAreaNum(true);
    cout << result.first << ' ' << result.second << endl;
}