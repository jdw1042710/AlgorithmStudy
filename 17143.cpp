#include <iostream>
#include <vector>

using namespace std;

int R, C, M;
vector<vector<int>> board;

const int dirR[4] = {-1, 0, 1, 0};
const int dirC[4] = {0, 1, 0, -1};
struct Shark
{
    int row;
    int col;
    int speed;
    int dir;
    int size;

    bool isDead = false;

    Shark(int r, int c, int s, int d, int z)
    : row(r), col(c), speed(s), dir(d), size(z)
    {}

    void Move()
    {
        if(dir % 2 == 1)
            MoveLine(col, dirC[dir], C);
        else
            MoveLine(row, dirR[dir], R);
    }

    void MoveLine(int& pos, int sign, int boundary)
    {
        speed %= (boundary - 1) * 2;
        for(int i = 0; i < speed; ++i)
        {
            pos += sign;
            if(IsOutOfBoundary(pos, boundary))
            {
                pos = pos < 0 ? 1 : boundary - 2;
                sign *= -1;
                InvertDir();
            }
        }
    }

    bool IsOutOfBoundary(int num, int boundary)
    {
        return num < 0 || num >= boundary; 
    }

    void InvertDir()
    {
        dir += 2;
        dir %= 4;
    }
};
vector<Shark> sharks;

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
    cin >> R >> C >> M;
    cin.ignore();
    int id = 0;
    board = vector<vector<int>>(R, vector<int>(C, -1));
    for(int i = 0; i < M; ++i)
    {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        --r; --c; --d;
        if(d == 1 || d == 2)
            d = d == 1 ? 2 : 1;
        cin.ignore();
        Shark shark(r, c, s, d, z);
        sharks.push_back(shark);
        board[r][c] = id++;
    }
}

void Simulate()
{
    vector<vector<int>> newBoard(R, vector<int>(C, -1));
    for(size_t i = 0; i < sharks.size(); ++i)
    {
        Shark& shark = sharks[i];
        if(shark.isDead) continue;
        shark.Move();
        if(newBoard[shark.row][shark.col] != -1)
        {
            Shark& other = sharks[newBoard[shark.row][shark.col]];
            if(shark.size < other.size)
            {
                shark.isDead = true;
                continue;
            }
            else
            {
                other.isDead = true;
            }
        }
        newBoard[shark.row][shark.col] = i;
    }
    board = newBoard;
}

void Solution()
{
    Input();
    long long result = 0;
    for(int j = 0; j < C; ++j)
    {
        // cout << "iter :" << j << endl;
        for(int i = 0; i < R; ++i)
        {
            if(board[i][j] == -1) continue;
            Shark& shark = sharks[board[i][j]];
            board[i][j] = -1;
            shark.isDead = true;
            result += shark.size;
            break;
        }
        Simulate();
    }

    cout << result << endl;
}