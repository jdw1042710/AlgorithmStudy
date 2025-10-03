#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
const int C = 10007;
vector<int> cache;

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
    cache = vector<int>(N + 1, -1);
}

int GetTile(int n)
{
    if(n < 0) return 0;
    if(n < 1) return 1;
    int& ret = cache[n];
    if(ret != -1) return ret;
    ret = GetTile(n - 1) + 2 * GetTile(n - 2);
    ret %= C;
    return ret;
}

void Solution()
{
    Input();
    cout << GetTile(N) << endl;
}