#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int R, C;
vector<vector<char>> board;
// vector<vector<vector<int>>> cache;
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
    cin >> R >> C;
    cin.ignore();
    board = vector<vector<char>>(R, vector<char>(C, 0));
    // cache = vector<vector<vector<int>>>(R, vector<vector<int>>(C, vector<int>((1 << 26) - 1, -1)));
    for(int i = 0; i < R; ++i)
    {
        for(int j = 0; j < C; ++j)
        {
            char val;
            cin >> val;
            board[i][j] = val;
        }
        cin.ignore();
    }

}

int dirR[4] = {0, 1, 0, -1};
int dirC[4] = {1, 0, -1, 0};
// int Travel(int row, int col, unsigned int visited)
// {
//     if(row < 0 || row >= R || col < 0 || col >= C) return 0;
//     unsigned int bitmask = (1 << (board[row][col] - 'A'));
//     if(visited & bitmask) return 0;
//     int& ret = cache[row][col][visited];
//     if(ret != -1) return ret;

//     visited |= bitmask;
//     for(int i = 0; i < 4; ++i)
//     {
//         int next_row = row + dirR[i];
//         int next_col = col + dirC[i];
//         ret = max(ret, 1 + Travel(next_row, next_col, visited));
//     }
//     return ret;
// }

int Travel(int row, int col, unsigned int visited)
{
    if(row < 0 || row >= R || col < 0 || col >= C) return 0;
    unsigned int bitmask = (1 << (board[row][col] - 'A'));
    if(visited & bitmask) return 0;
    
    int ret = 0;
    visited |= bitmask;
    for(int i = 0; i < 4; ++i)
    {
        int next_row = row + dirR[i];
        int next_col = col + dirC[i];
        ret = max(ret, 1 + Travel(next_row, next_col, visited));
    }
    return ret;
}

void Solution()
{
    Input();
    int result = Travel(0, 0, 0);
    cout << result << endl;
}