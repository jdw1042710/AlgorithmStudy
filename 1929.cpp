#include <iostream>
#include <vector>

using namespace std;

void Input();
void Solution();


int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}


void Solution()
{
    long long M, N;
    cin >> M >> N;
    vector<bool> isPrime(N + 1, true);
    isPrime[1] = false; 
    for(int i = 2; i * i <= N; ++i)
    {
        if(!isPrime[i]) continue;
        for(int j = i * i; j <= N; j += i)
            isPrime[j] = false;
    }
    for(int i = M; i <= N; ++i)
    {
        if(isPrime[i])
            cout << i << '\n';
    }
}
