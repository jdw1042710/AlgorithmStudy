
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct INFO
{
    int ry, rx, by, bx, count;
    INFO() {}
    INFO(int _ry, int _rx, int _by, int _bx, int _count) : ry(_ry), rx(_rx), by(_by), bx(_bx), count(_count) {}
};


int N, M;
vector<vector<char>> board;
INFO start;

void Input();
void Solution();

pair<int, int> MoveBall(pair<int, int> curPos, pair<int, int> dir, const vector<vector<char>>& board)
{
    int next_y = curPos.first;
    int next_x = curPos.second;
    int dy = dir.first;
    int dx = dir.second;
    while(true)
    {
        char val = board[next_y][next_x];
        if(val != '#' && val != 'O')
        {
            next_y += dy; next_x += dx;
        }
        else
        {
            if(val == '#')
            {
                next_y -= dy; next_x -= dx;
            }
            break;
        }
    }
    return {next_y, next_x};
}

int BFS();

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    Solution();
}

void Solution()
{
    Input();
    cout << BFS();
}

void Input()
{
    cin >> N >> M;
    cin.ignore();
    for(int i = 0; i < N; ++i)
    {
        board.push_back(vector<char>());
        for(int j = 0; j < M; ++j)
        {
            char val;
            cin >> val;
            if(val == 'R')
            {
                start.ry = i;
                start.rx = j;
            }
            if(val == 'B')
            {
                start.by = i;
                start.bx = j;
            }
            board[i].push_back(val);
        }
        cin.ignore();
    }
    start.count = 0;
}

int BFS()
{
    const int dy[] = {0, 1, 0, -1};
    const int dx[] = {1, 0, -1, 0}; 
    bool visited[10][10][10][10] = {false};
    queue<INFO> q;

    q.push(start);
    visited[start.ry][start.rx][start.by][start.bx] = true;

    int ret = -1;
    while(!q.empty())
    {
        int cur_ry = q.front().ry;
        int cur_rx = q.front().rx;
        int cur_by = q.front().by;
        int cur_bx = q.front().bx;
        int cur_count = q.front().count;
        q.pop();

        if(cur_count > 10) break;

        if(board[cur_ry][cur_rx] == 'O' && board[cur_by][cur_bx] != 'O')
        {
            ret = cur_count;
            break;
        }

        for(int dir = 0; dir < 4; ++dir)
        {
            INFO nextInfo;
            pair<int, int> nextPos;
            nextPos = MoveBall({cur_ry, cur_rx}, {dy[dir], dx[dir]}, board);
            nextInfo.ry = nextPos.first;
            nextInfo.rx = nextPos.second;
            nextPos = MoveBall({cur_by, cur_bx}, {dy[dir], dx[dir]}, board);
            nextInfo.by = nextPos.first;
            nextInfo.bx = nextPos.second;
            if(nextInfo.ry == nextInfo.by
               && nextInfo.rx == nextInfo.bx 
               && board[nextInfo.ry][nextInfo.rx] != 'O')
            {
                int r_dist = abs(cur_ry - nextInfo.ry) + abs(cur_rx - nextInfo.rx);
                int b_dist = abs(cur_by - nextInfo.by) + abs(cur_bx - nextInfo.bx);
                if(r_dist > b_dist)
                {
                    nextInfo.ry -= dy[dir]; nextInfo.rx -= dx[dir];
                }
                else
                {
                    nextInfo.by -= dy[dir]; nextInfo.bx -= dx[dir];
                }
            }
            nextInfo.count = cur_count + 1;

            if(!visited[nextInfo.ry][nextInfo.rx][nextInfo.by][nextInfo.bx])
            {
                visited[nextInfo.ry][nextInfo.rx][nextInfo.by][nextInfo.bx] = true;
                q.push(nextInfo);
            }
        }
    }
    
    return ret;
}