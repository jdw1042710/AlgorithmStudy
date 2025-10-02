#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
const int INF = 1000001;
vector<vector<int>> cache;

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
    cache = vector<vector<int>>(N, vector<int>(N, INF));
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            int path;
            cin >> path;
            cache[i][j] = path == 0 ? INF : path;
        }
        cin.ignore();
    }
}

void Solution()
{
    Input();
    for(int k = 0; k < N; ++k)
    {
        for(int i = 0; i < N; ++i)
        {
            for(int j = 0; j < N; ++j)
            {
                cache[i][j] = min(cache[i][k] + cache[k][j], cache[i][j]);
            }
        }
    }

    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            cout << (cache[i][j] < INF ? 1 : 0) << ' ';
        }
        cout << '\n';
    }
}