#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
const int INF = 101;
vector<vector<int>> graph;
vector<bool> diagonals;
vector<bool> invDiagonals;

void Solution();
int PlaceBishop(int row, int col);

int GetDiagIndex(int row, int col)
{
    return (N - 1) - row + col;
}
int GetInvDiagIndex(int row, int col)
{
    return row + col;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;
    cin.ignore();

    Solution();
}

void Solution()
{
    for(int i = 0; i < N; ++i)
    {
        graph.push_back(vector<int>());
        for(int j = 0; j < N; ++j)
        {
            int val;
            cin >> val;
            graph[i].push_back(val);
        }
        cin.ignore();
    }
    diagonals = vector<bool>(2 * N - 1, false);
    invDiagonals = vector<bool>(2 * N - 1, false);
    cout << PlaceBishop(0, 0) + PlaceBishop(0, 1);
}

int PlaceBishop(int row, int col)
{
    if(col >= N) 
    {
        ++row;
        col = col % 2 ? 0 : 1;
    }
    if(row >= N) return 0;
    int ret = 0;
    if(graph[row][col] 
        && !diagonals[GetDiagIndex(row, col)]
        && !invDiagonals[GetInvDiagIndex(row, col)])
    {
        diagonals[GetDiagIndex(row, col)] = invDiagonals[GetInvDiagIndex(row, col)] = true;
        ret = max(ret, 1 + PlaceBishop(row, col + 2));
        diagonals[GetDiagIndex(row, col)] = invDiagonals[GetInvDiagIndex(row, col)] = false;
    }
    ret = max(ret, PlaceBishop(row, col + 2));
    return ret;
}