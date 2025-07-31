#include <iostream>
#include <vector>

using namespace std;

const int INF = 5001;
vector<int> cache;

void Solution();

int DP(int n)
{
    if(n < 0) return INF;
    int& ret = cache[n];
    if(ret != INF) return ret;
    if(n == 3 || n == 5) 
    {
        ret = 1;
    }
    else
    {
        ret = min(DP(n - 3) + 1, DP(n - 5) + 1);
    }
    return ret;
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}

void Solution()
{
    int N;
    cin >> N;
    cache = vector<int>(N + 1, INF);
    int result = DP(N);
    cout << ((result < INF) ? result : -1) << endl;
}
