#include <iostream>
#include <vector>

using namespace std;

int M;
const long long MOD = 1000000007ll;
vector<long long> N, S;

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
    cin >> M;
    cin.ignore();
    N = vector<long long>(M);
    S = vector<long long>(M);
    for(int i = 0; i < M; ++i)
    {
        cin >> N[i] >> S[i];
        cin.ignore();
    }
}

long long Pow(long long X, long long exp)
{
    long long result = 1;
    while(exp)
    {
        if(exp % 2 == 1)
        {
            result *= X;
            result %= MOD;
        }
        X *= X;
        X %= MOD;
        exp /= 2;
    }
    return result;
}

long long GetInverseElement(long long B, long long X)
{
    return Pow(B, X - 2) % X;
}

void Solution()
{
    Input();
    vector<long long> invN(M), avg(M);
    long long result = 0;
    for(int i = 0; i < M; ++i)
    {
        invN[i] = GetInverseElement(N[i], MOD);
        avg[i] = (S[i] * invN[i]) % MOD;
        result += avg[i];
        result %= MOD;
    }
    cout << result << endl;
}
