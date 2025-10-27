#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

enum class State
{
    Empty = 0,
    Wall,
    Virus,
};

int N, M;
vector<vector<State>> initial_board;
vector<pair<int, int>> initial_virus;

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
    cin >> N >> M;
    cin.ignore();
    initial_board = vector<vector<State>>(N, vector<State>(M));
    initial_virus.clear();
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            int val;
            cin >> val;
            initial_board[i][j] = static_cast<State>(val);
            if(initial_board[i][j] == State::Virus)
                initial_virus.push_back({i, j});
        }
        cin.ignore();
    }
}

bool IsVaildCoord(int row, int col)
{
    return row >= 0 && row < N && col >= 0 && col < M;
}

void Spread(vector<vector<State>>& board)
{
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    queue<pair<int, int>> q;
    for(auto coord : initial_virus)
    {
        int row = coord.first;
        int col = coord.second;
        visited[row][col] = true;
        q.push({row, col});
    }
    int dirR[] = {0, 1, 0, -1};
    int dirC[] = {1, 0, -1, 0};
    while(!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for(int i = 0; i < 4; ++i)
        {
            int next_row = row + dirR[i];
            int next_col = col + dirC[i];
            if(!IsVaildCoord(next_row, next_col)) continue;
            if(visited[next_row][next_col]) continue;
            if(board[next_row][next_col] != State::Empty) continue;
            board[next_row][next_col] = State::Virus;
            visited[next_row][next_col] = true;
            q.push({next_row, next_col});
        }
    }
}

int CountSafeSpace(const vector<vector<State>>& board)
{
    int result = 0;
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            if(board[i][j] == State::Empty)
                ++result;
        }
    }
    return result;
}

void Solution()
{
    Input();
    vector<pair<int, int>> walls(3);
    int result = 0;
    for(int i = 0; i < N * M; ++i)
    {
        walls[0].first = i / M;
        walls[0].second = i % M;
        if(initial_board[walls[0].first][walls[0].second] != State::Empty) continue;
        for(int j = i + 1; j < N * M; ++j)
        {
            walls[1].first = j / M;
            walls[1].second = j % M;
            if(initial_board[walls[1].first][walls[1].second] != State::Empty) continue;
            for(int k = j + 1; k < N * M; ++k)
            {
                walls[2].first = k / M;
                walls[2].second = k % M;
                if(initial_board[walls[2].first][walls[2].second] != State::Empty) continue;
                vector<vector<State>> simulated_board(initial_board);
                for(int l = 0; l < 3; ++l)
                {
                    simulated_board[walls[l].first][walls[l].second] = State::Wall;
                }
                Spread(simulated_board);
                result = max(result, CountSafeSpace(simulated_board));
            }
        }
    }
    cout << result << endl;
}
