#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

enum class State
{
    OPENED_AIR,
    CLOSED_AIR,
    CHEESE,
};

int N, M;
vector<vector<State>> board;
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
    board = vector<vector<State>>(N + 2, vector<State>(M + 2 , State::OPENED_AIR));
    for(int i = 1; i <= N; ++i)
    {
        for(int j = 1; j <= M; ++j)
        {
            int val;
            cin >> val;
            ++val;
            board[i][j] = static_cast<State>(val);
        }
        cin.ignore();
    }
}

int dirR[4] = {0, 1, 0, -1};
int dirC[4] = {1, 0, -1, 0};

bool IsValidIndex(int row, int col)
{
    return !(row < 0 || row >= N + 2 || col < 0 || col >= M + 2);
}

// template <typename T1, typename T2>
// void BFS(queue<pair<int, int>>& q, vector<vector<bool>>& visited, T1 condition , T2 doSomething)
// {
//     while(!q.empty())
//     {

//     }
// }

void Solution()
{
    Input();
    vector<vector<bool>> visited(N + 2, vector<bool>(M + 2, false));
    queue<pair<int, int>> candidates;
    visited[0][0] = true;
    candidates.push({0, 0});
    // auto checkClosedAir = [&](){};
    // auto changeClosedAir = [&](){};
    // BFS(q, visited, checkClosedAir, changeClosedAir);
    vector<vector<int>> cheeseAdjacency(N + 2, vector<int>(M + 2, 0));
    int result = -1;
    while(!candidates.empty())
    {
        queue<pair<int, int>> q;
        while(!candidates.empty())
        {
            board[candidates.front().first][candidates.front().second] = State::OPENED_AIR;
            q.push({candidates.front().first, candidates.front().second});
            candidates.pop();
        }
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int dir = 0; dir < 4; ++dir)
            {
                int next_row = row + dirR[dir];
                int next_col = col + dirC[dir];
                if(!IsValidIndex(next_row, next_col)) continue;
                if(visited[next_row][next_col]) continue;
                State next_val = board[next_row][next_col];
                if(next_val == State::OPENED_AIR)
                {
                    visited[next_row][next_col] = true;
                    q.push({next_row, next_col});
                }
                else if(next_val == State::CLOSED_AIR)
                {
                    board[next_row][next_col] = State::OPENED_AIR;
                    visited[next_row][next_col] = true;
                    q.push({next_row, next_col});
                }
                else // if (next_val == State::CHEESE)
                {
                    if(cheeseAdjacency[next_row][next_col] == 0)
                    {
                        ++cheeseAdjacency[next_row][next_col];
                    }
                    else
                    {
                        visited[next_row][next_col] = true;
                        candidates.push({next_row, next_col});
                    }
                }
            }
        }
        ++result;
    }
    cout << (result == -1 ? 0 : result) << endl;
}