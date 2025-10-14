#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, M;
long long B, maxB;
vector<vector<int>> blocks;

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
    cin >> N >> M >> B;
    cin.ignore();
    blocks = vector<vector<int>>(N, vector<int>(M, 0));
    maxB = B;
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            int h;
            cin >> h;
            blocks[i][j] = h;
            maxB += h;
        }
        cin.ignore();
    }

}

void Solution()
{
    Input();
    long long result_time = 500 * 500 * 256 * 2 + 1;
    long long result_height = -1;
    for(int h = 256; h >= 0; --h)
    {
        if(maxB < N * M * h) continue;
        long long acTime = 0;
        for(int i = 0; i < N; ++i)
        {
            for(int j = 0; j < M; ++j)
            {
                int diffH = blocks[i][j] - h;
                    acTime += (diffH > 0 ? diffH * 2 : -diffH);

            }
        }
        if(acTime < result_time)
        {
            result_time = acTime;
            result_height = h;
        }
    }
    cout << result_time << ' ' << result_height << endl;
}