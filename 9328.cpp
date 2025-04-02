#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int T, H, W;
int dirX[4] = {-1, 0, 1, 0};
int dirY[4] = {0, -1, 0, 1};
vector<vector<int>> board;
vector<vector<bool>> visited;
map<int, queue<pair<int, int>>> doors = map<int, queue<pair<int, int>>>();
vector<bool> keys;

void Input();
void Solution();

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> T;
    cin.ignore();
    for(int i = 0; i < T; ++i)
    {
        Input();
        Solution();
    }
}

void Input()
{
    cin >> H >> W;
    cin.ignore();
    board = vector<vector<int>>(H + 2, vector<int>(W + 2, 0));
    visited = vector<vector<bool>>(H + 2, vector<bool>(W + 2, false));
    doors.clear();
    for(int i = 0; i < 26; ++i)
        doors[i] = queue<pair<int, int>>();
    keys = vector<bool>(26, false);

    string input;
    for(int i = 1; i <= H; ++i)
    {
        getline(cin, input);
        for(int j = 1; j <= W; ++j)
        {
            char value = input.at(j - 1);
                if(value == '*')
                    board[i][j] = 1;
                else if(value == '$')
                    board[i][j] = 2;
                else if (('A' <= value && value <= 'Z')
                        || ('a' <= value && value <= 'z'))
                    board[i][j] = value;
        }
    }
    getline(cin, input);
    if(input == "0") return;
    for(int i = 0; i < input.length(); ++i)
    {
        keys[input.at(i) -'a'] = true;
    }
}

void Solution()
{
    queue<pair<int, int>> next;
    next.push({0, 0});
    visited[0][0] = true;
    int result = 0;
    while(!next.empty())
    {
        int x = next.front().first, y = next.front().second;
        int value = board[x][y];
        next.pop();
        if(value == 2)
        {
            ++result;
        }

        if('a' <= value && value <= 'z')
        {
            keys[value - 'a'] = true;
            while(!doors[value - 'a'].empty())
            {
                int next_x = doors[value - 'a'].front().first, next_y = doors[value - 'a'].front().second;
                doors[value - 'a'].pop();
                if(visited[next_x][next_y]) continue;
                next.push({next_x, next_y});
                visited[next_x][next_y] = true;
            }
        }

        for(int i = 0; i < 4; ++i)
        {
            int next_x = x + dirX[i], next_y = y + dirY[i];
            if(next_x < 0 || next_x > H + 1 || next_y < 0 || next_y > W + 1) continue;
            if(board[next_x][next_y] == 1 || visited[next_x][next_y]) continue;
            if('A' <= board[next_x][next_y] && board[next_x][next_y] <= 'Z')
            {
                if(!keys[board[next_x][next_y] - 'A'])
                {
                    doors[board[next_x][next_y] - 'A'].push({next_x, next_y});
                    continue;
                }
            }
            next.push({next_x, next_y});
            visited[next_x][next_y] = true;
        }
    }
    cout << result << '\n';
}
