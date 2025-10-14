#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<char>> board;
pair<int, int> start_pos;

void Input();
void Solution();

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}

void Input()
{
    cin >> N >> M;
    cin.ignore();
    board = vector<vector<char>>(N + 2, vector<char>(M + 2, 'X'));
    for(int i = 1; i <= N; ++i)
    {
        for(int j = 1; j <= M; ++j)
        {
            char val;
            cin >> val;
            board[i][j] = val;
            if(val == 'I')
            {
                start_pos = {i, j};
            }
        }
        cin.ignore();
    }

}

void Solution()
{
    Input();
    int dirR[4] = {0, 1, 0, -1};
    int dirC[4] = {1, 0, -1, 0};

    vector<vector<bool>> visited(N + 2, vector<bool>(M + 2, false));
    queue<pair<int, int>> q;
    visited[start_pos.first][start_pos.second] = true;
    q.push(start_pos);

    int result = 0;
    while(!q.empty())
    {
        int curR = q.front().first;
        int curC = q.front().second;
        q.pop();
        if(board[curR][curC] == 'P') 
            ++result;
        for(int i = 0; i < 4; ++i)
        {
            int nextR = curR + dirR[i];
            int nextC = curC + dirC[i];
            if(visited[nextR][nextC]) continue;
            if(board[nextR][nextC] == 'X') continue;
            visited[nextR][nextC] = true;
            q.push({nextR, nextC});
        }
    }
    if(result == 0)
        cout << "TT" << endl;
    else
        cout << result << endl;
}