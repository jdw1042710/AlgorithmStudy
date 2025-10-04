#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef pair<int, int> pii;

int N, M;
pii tetrominos[19][4] = {
    // I자
    {{0, 0}, {0, 1}, {0, 2}, {0, 3}}, 
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}}, 
    // O자
    {{0, 0}, {0, 1}, {1, 0}, {1, 1}}, 
    // L자
    {{0, 0}, {0, 1}, {0, 2}, {1, 0}},
    {{0, 0}, {0, 1}, {0, 2}, {1, 2}},
    {{0, 0}, {1, 0}, {1, 1}, {1, 2}},
    {{0, 0}, {1, -2}, {1, -1}, {1, 0}},
    {{0, 0}, {0, 1}, {1, 1}, {2, 1}},
    {{0, 0}, {0, 1}, {1, 0}, {2, 0}},
    {{0, 0}, {1, 0}, {2, -1}, {2, 0}},
    {{0, 0}, {1, 0}, {2, 0}, {2, 1}},
    // S자
    {{0, 0}, {0, 1}, {1, 1}, {1, 2}},
    {{0, 0}, {0, 1}, {1, -1}, {1, 0}},
    {{0, 0}, {1, -1}, {1, 0}, {2, -1}},
    {{0, 0}, {1, 0}, {1, 1}, {2, 1}},
    // T자
    {{0, 0}, {0, 1}, {0, 2}, {1, 1}},
    {{0, 0}, {1, -1}, {1, 0}, {2, 0}},
    {{0, 0}, {1, -1}, {1, 0}, {1, 1}},
    {{0, 0}, {1, 0}, {1, 1}, {2, 0}},
};
vector<vector<int>> board;

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
    board = vector<vector<int>>(N, vector<int>(M, 0));
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            int num;
            cin >> num;
            board[i][j] = num;
        }
        cin.ignore();
    }
}

bool CheckValidCoord(int row, int col)
{
    return row >= 0 && row < N && col >= 0 && col < M;
}

void Solution()
{
    Input();
    int result = 0;
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            for(int k = 0; k < 19; ++k)
            {
                int sum = 0;
                for(int l = 0; l < 4; ++l)
                {
                    int curRow = i + tetrominos[k][l].first;
                    int curCol = j + tetrominos[k][l].second;
                    if(CheckValidCoord(curRow, curCol))
                    {
                        sum += board[curRow][curCol];
                    }
                    else
                    {
                        sum = 0;
                        break;
                    }
                }
                result = max(result, sum);
            }
        }
    }
    cout << result << endl;
}