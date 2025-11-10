#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long A, B;
const long long INF = 1000000001ll;

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
    cin >> A >> B;
}

long long GetStep(long long start)
{
    long long ret = -1;
    queue<pair<long long, long long>> q;
    q.push({start, 1});
    while(!q.empty())
    {
        long long cur = q.front().first;
        long long step = q.front().second;
        q.pop();
        if(cur == B)
        {
            ret = step;
            break;
        }
        if(cur * 2 <= B)
        {
            q.push({cur * 2, step + 1});
        }
        if(cur * 10 + 1 <= B)
        {
            q.push({cur * 10 + 1, step + 1});
        }
    }

    return ret;
}

void Solution()
{
    Input();
    long long result = GetStep(A);
    cout << result << endl;
}