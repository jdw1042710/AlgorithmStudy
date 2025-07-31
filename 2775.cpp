#include <iostream>
#include <vector>

using namespace std;


void Solution();

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}

void Solution()
{
    vector<vector<long long>> cache(15, vector<long long>(15, 1));
    for(int i = 1; i < 15; ++i)
    {
        cache[0][i] = i;
    }
    for(int i = 1; i < 15; ++i)
    {
        for(int j = 2; j < 15; ++j)
        {
            cache[i][j] = cache[i][j - 1] + cache[i - 1][j];
        }
    }
    int T;
    cin >> T;
    cin.ignore();
    for(int i = 0; i < T; ++i)
    {
        int K, N;
        cin >> K;
        cin.ignore();
        cin >> N;
        cin.ignore();
        cout << cache[K][N] << endl;
    }
}
