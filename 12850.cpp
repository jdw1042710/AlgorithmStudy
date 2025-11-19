#include <iostream>
#include <vector>

using namespace std;

long long D;
const long long MOD = 1'000'000'007LL;
vector<vector<long long>> graph;


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
    cin >> D;
    cin.ignore();
    graph = {
        {0, 1, 1, 0, 0, 0, 0, 0},
        {1, 0, 0, 1, 0, 0, 0, 0},
        {1, 0, 0, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1, 0},
        {0, 0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 1, 0, 1},
        {0, 0, 0, 0, 0, 1, 1, 0}
    };
}

vector<vector<long long>> operator*(const vector<vector<long long>>& matA, const vector<vector<long long>>& matB)
{
    vector<vector<long long>> ret(matA.size(), vector<long long>(matB[0].size(), 0));
    for(size_t i = 0; i < matA.size(); ++i)
    {
        for(size_t j = 0; j < matB.size(); ++j)
        {
            for(size_t k = 0; k < matB.size(); ++k)
            {
                ret[i][j] += (matA[i][k] * matB[k][j]) % MOD;
                ret[i][j] %= MOD;
            }
        }
    }
    return ret;
}

vector<vector<long long>> PowMatrix(vector<vector<long long>>& matrix, long long n)
{
    if(n == 1)  return matrix;
    vector<vector<long long>> half = PowMatrix(matrix, n / 2);
    if(n % 2)
    {
        return matrix * half * half;
    }
    else
    {
        return half * half;
    }
}

void Solution()
{
    Input();
    vector<vector<long long>> result = PowMatrix(graph, D);
    cout << result[7][7] << endl;
}