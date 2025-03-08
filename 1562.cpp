#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
const long long denom = 1000 * 1000 * 1000;

long long cache[100][10][1 << 10];

void Solution();
long long CountStairNum(int index, int num, int state);

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> N;
    Solution();
    return 0;
}

void Solution()
{
    long long result = 0;
    fill_n(cache[0][0], 100 * 10 * (1 << 10), -1);
    for(int i = 1; i < 10; ++i)
    {
        result += (CountStairNum(1, i, 1 << i) % denom) % denom;
        result %= denom;
    }
    cout << result << '\n';
}

long long CountStairNum(int index, int num, int state)
{
    if(num < 0 || num > 9) return 0;
    if(index == N) return state == ((1 << 10) - 1);
    long long& ret = cache[index][num][state];
    if(ret != -1) return ret;
    ret = 0;
    if (num > 0)
        ret += ((CountStairNum(index + 1, num - 1, state | (1 << (num - 1))) % denom) % denom);
    if (num < 9)
        ret += ((CountStairNum(index + 1, num + 1, state | (1 << (num + 1))) % denom) % denom);
    ret %= denom;
    return ret;
}
