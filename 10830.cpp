#include <iostream>
#include <vector>

using namespace std;

int N;
long long B;
vector<vector<int>> mat;

void Input();
void Solution();

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}

void Input()
{
    cin >> N >> B;
    cin.ignore();
    mat = vector<vector<int>>(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            int num;
            cin >> num;
            mat[i][j] = num;
        }
        cin.ignore();
    }
}

vector<vector<int>> MultMatrix(const vector<vector<int>>& M1, const vector<vector<int>>& M2)
{
    vector<vector<int>> newM(N, vector<int>(N, 0));

    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            for(int k = 0; k < N; ++k)
            {
                newM[i][j] += (M1[i][k] * M2[k][j]) % 1000;
                newM[i][j] %= 1000;
            }
        }
    }
    return newM;
}

void Solution()
{
    Input();
    vector<vector<int>> ans(N, vector<int>(N, 0));
    for(int i = 0; i < N; ++i) ans[i][i] = 1;
    vector<vector<int>> M(mat);
    long long exp = B;
    while(exp > 0)
    {
        if(exp % 2 == 1)
        {
            ans = MultMatrix(ans, M);
        }
        M = MultMatrix(M, M);
        exp /= 2;
    }

    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << endl;
}
