#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
const int INF = 987654321;
// vector<vector<int>> board;
// vector<vector<pair<int, int>>> cache;
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
    // board = vector<vector<int>>(N, vector<int>(3, 0));
    // cache = vector<vector<pair<int, int>>>(N, vector<pair<int, int>>(3, {-1, -1}));
    // for(int i = 0; i < N; ++i)
    // {
    //     for(int j = 0; j < 3; ++j)
    //     {
    //         int val;
    //         cin >> val;
    //         board[i][j] = val;
    //     }
    //     cin.ignore();
    // }

}

// pair<int, int> Travel(int row, int col)
// {
//     if(col < 0 || col >= 3) return {-INF, INF};
//     if(row == N) return {0, 0};
//     pair<int, int>& ret = cache[row][col];
//     if(ret.first != -1) return ret;
//     ret = {0, INF};
//     for(int i = -1; i < 2; ++i)
//     {
//         pair<int, int> result = Travel(row + 1, col + i);
//         ret.first = max(ret.first, board[row][col] + result.first);
//         ret.second = min(ret.second, board[row][col] + result.second);
//     }
//     return ret;
// }

void Solution()
{
    Input();
    // pair<int, int> result = {0, INF};
    // for(int i = 0; i < 3; ++i)
    // {
    //     pair<int, int> ret = Travel(0, i);
    //     result.first = max(result.first, ret.first);
    //     result.second = min(result.second, ret.second);
    // }
    vector<int> max_result(3, 0);
    vector<int> min_result(3, 0);

    for(int i = 0; i < 3; ++i)
    {
        int num;
        cin >> num;
        max_result[i] = min_result[i] = num;
    }
    cin.ignore();

    vector<int> input(3, 0), temp;
    for(int i = 1; i < N; ++i)
    {
        for(int j = 0; j < 3; ++j)
            cin >> input[j];
        
        cin.ignore();

        temp = max_result;
        for(int j = 0; j < 3; ++j)
        {
            for(int k = -1; k < 2; ++k)
            {
                if(j + k < 0 || j + k > 2) continue;
                max_result[j] = max(max_result[j], input[j] + temp[j + k]);
            }

        }
        temp = min_result;
        min_result = vector<int>(3, INF);
        for(int j = 0; j < 3; ++j)
        {

            for(int k = -1; k < 2; ++k)
            {
                if(j + k < 0 || j + k > 2) continue;
                min_result[j] = min(min_result[j], input[j] + temp[j + k]);
            }
        }
    }
    pair<int, int> result = {0, INF};
    for(int i = 0; i < 3; ++i)
    {
        result.first = max(result.first, max_result[i]);
        result.second = min(result.second, min_result[i]);
    }
    cout << result.first << ' ' << result.second << endl;
}