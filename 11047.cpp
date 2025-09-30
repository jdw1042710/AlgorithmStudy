#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
long long K;
vector<long long> coins;

void Input();
void Solution();

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}

void Input()
{
    cin >> N >> K;
    cin.ignore();
    coins.clear();
    for(int i = 0; i < N; ++i)
    {
        long long num;
        cin >> num;
        cin.ignore();
        coins.push_back(num);

    }
}

void Solution()
{
    Input();
    int result = 0;
    long long curK = K;
    for(int i = N - 1; i >= 0; --i)
    {
        if(curK >= coins[i])
        {
            result += (curK / coins[i]);
            curK %= coins[i];
        }
    }
    cout << result << endl;
}