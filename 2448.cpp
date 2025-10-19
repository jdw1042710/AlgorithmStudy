#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<char>> board;
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
    cin >> N;
    cin.ignore();
    board = vector<vector<char>>(N, vector<char>(2 * N - 1 , ' '));
}

// 3 -> 3 X 5
// 6 -> 6 X 11 (2 * 6 - 1)
// 12 -> 12 X 23 (12 * 2 - 1)
// 24 -> 24 X 47 (24 * 2 - 1)

void PrintStars(int row, int col, int size)
{
    if (size == 3)
    {
        //   *   
        //  * * 
        // *****
        board[row][col + 2] = '*';
        for(int i = 1; i < 5; i += 2)
            board[row + 1][col + i] = '*';
        for(int i = 0; i < 5; ++i)
            board[row + 2][col + i] = '*';
        return;
    }
    // if N == 24
    // row, col + 12
    // row + 12, col
    // row + 12, col + 24
    // if N == 12
    // row, col + 6
    // row + 6, col
    // row + 6, col + 12
    int next_size = size / 2;
    PrintStars(row, col + next_size, next_size);
    PrintStars(row + next_size, col, next_size);
    PrintStars(row + next_size, col + size, next_size);
}

void Solution()
{
    Input();
    PrintStars(0, 0, N);
    for(const auto& row : board)
    {
        for(const auto& ch : row)
        {
            cout << ch;
        }
        cout << '\n';
    }
}