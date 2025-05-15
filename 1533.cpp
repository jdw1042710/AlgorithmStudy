#include <iostream>
#include <string>
#include <vector>

using namespace std;


long long N, S, E, T, MOD = 1000003;
vector<vector<long long>> graph;

void Input();
void Solution();

// long long print[50][50]
// void PrintMat(const vector<vector<long long>>& mat)
// {
//     for(int i = 0; i < 5 * N; ++i)
//     {
//         for(int j = 0; j < 5 * N; ++j)
//         {
//             print[i][j] = mat[i][j];
//         }
//     }

// }

vector<vector<long long>> multiply(const vector<vector<long long>>& lhs, const vector<vector<long long>>& rhs)
{
    int n = lhs.size();
    vector<vector<long long>> ret(n, vector<long long>(n, 0));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            for(int k = 0; k < n; ++k)
            {
                ret[i][j] += lhs[i][k] * rhs[k][j];
            }
            ret[i][j] %= MOD;
        }
    }
    return ret;
}

vector<vector<long long>> pow(vector<vector<long long>>& mat, int t)
{
    vector<vector<long long>> ret = vector<vector<long long>>(5 * N, vector<long long>(5 * N, 0));
    for(int i = 0; i < 5 * N; ++ i) ret[i][i] = 1;
    while(t > 0)
    {
        if(t % 2)
        {
            ret = multiply(ret, mat);
        }
        mat = multiply(mat, mat);
		t /= 2;
    }
    return ret;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    Solution();

    return 0;
}

void Input()
{
    cin >> N >> S >> E >> T;
    --S; --E;
    cin.ignore();
    graph = vector<vector<long long>>(5 * N, vector<long long>(5 * N, 0));
    for(int i = 0; i < N; ++i)
    {
        string temp;
        getline(cin, temp);
        for(int j = 0; j < N; ++j)
        {
            int time = temp[j] - '0';
            if(time != 0)
            {
                graph[i * 5 + time - 1][j * 5] = 1;
            }
        }
        for(int k = 0; k < 4; ++k) 
        {
            graph [i * 5 + k][i * 5 + k + 1] = 1 ;
        }
    }
}

void Solution()
{
    Input();
    vector<vector<long long>> result = pow(graph, T);
    cout << result[S * 5][E * 5];
}