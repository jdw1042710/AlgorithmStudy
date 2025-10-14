#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<long long> squares;

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
    for(int i = 1; i * i <= N; ++i)
    {
        long long sqr = i * i;
        squares.push_back(sqr);
    }

}

void Solution()
{
    Input();
    int result = -1;
    vector<bool> visited(N + 1, false);
    queue<pair<int, int>> q;
    visited[N] = true;
    q.push({N, 0});
    while(!q.empty() && result == -1)
    {
        int num = q.front().first;
        int count = q.front().second;
        q.pop();
        for(int i = squares.size() - 1; i >= 0; --i)
        {
            int sqr = squares[i];
            if(sqr > num) continue;
            int next_num = num - sqr;
            int next_count = count + 1;
            if(visited[next_num]) continue;
            if(next_num == 0)
            {
                result = next_count;
                break;
            }
            visited[next_num] = true;
            q.push({next_num, next_count});
        }
    }
    cout << result << endl;
}