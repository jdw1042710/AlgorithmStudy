
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<vector<long long>> board;

void Solution();
long long DFS(int depth);

void PrintBoard(const vector<vector<long long>>& board)
{
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    string temp;
    getline(cin, temp);
}

void ShiftBoard(int dir, vector<vector<long long>>& board)
{
    for(int i = 0; i < N; ++i)
    {
        queue<long long> q;
        for(int j = 0; j < N; ++j)
        {
            long long nextNum = 0;
            switch (dir)
            {
            case 0:
                nextNum = board[i][N - 1 - j];
                board[i][N - 1 - j] = 0;
                break;
            case 1:
                nextNum = board[N - 1 - j][i];
                board[N - 1 - j][i] = 0;
                break;
            case 2:
                nextNum = board[i][j];
                board[i][j] = 0;
                break;
            case 3:
                nextNum = board[j][i];
                board[j][i] = 0;
                break;
            default:
                break;
            }
            if(nextNum == 0) continue;
            q.push(nextNum);
        }

        for(int j = 0; i < N; ++j)
        {
            if(q.empty()) break;
            long long a = 0, b = 0;
            a = q.front();
            q.pop();
            if(!q.empty() && a == q.front())
            {
                b = q.front();
                q.pop();
            }
            switch (dir)
            {
                case 0:
                board[i][N - 1 - j] = a + b;
                break;
            case 1:
                board[N - 1 - j][i] = a + b;
                break;
            case 2:
                board[i][j] = a + b;
                break;
            case 3:
                board[j][i] = a + b;
                break;
            default:
                break;
            }
        }
    }
}
void CopyBoard(vector<vector<long long>>& a, const vector<vector<long long>>& b)
{
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            a[i][j] = b[i][j];
        }
    }
}

int GetMaxElement(const vector<vector<long long>>& board)
{
    long long ret = 0;
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            ret = max(ret, board[i][j]);
        }
    }
    return ret;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;
    cin.ignore();
    for(int i = 0; i < N; ++i)
    {
        board.push_back(vector<long long>());
        for(int j = 0; j < N; ++j)
        {
            long long num;
            cin >> num;
            board[i].push_back(num);
        }
        cin.ignore();
    }
    Solution();
}

void Solution()
{
    cout << DFS(0);
}

long long DFS(int depth)
{
    if(depth == 5) return GetMaxElement(board);
    vector<vector<long long>> exBoard = vector<vector<long long>>(N, vector<long long>(N));
    long long ret = 0;
    for(int dir = 0; dir < 4; ++dir)
    {
        CopyBoard(exBoard, board);
        ShiftBoard(dir, board);
        // cout << "Depth: " << depth << ", Shift:" << dir << endl;
        // PrintBoard(board);
        ret = max(ret, DFS(depth + 1));
        CopyBoard(board, exBoard);
    }
    return ret;
}