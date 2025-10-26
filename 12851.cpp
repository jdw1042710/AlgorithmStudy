#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <cmath>

using namespace std;

int N, K;

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
    cin >> N >> K;
    cin.ignore();
}

void Solution()
{
    Input();
    const int Max_Bound = max(N, K) + 2;
    vector<int> costs(Max_Bound, -1);
    vector<int> counts(Max_Bound, 0);
    queue<int> q;
    costs[N] = 0;
    counts[N] = 1;
    q.push(N);
    vector<std::function<int(int)>> moves;
    moves.push_back([](int cur) { return cur + 1; });
    moves.push_back([](int cur) { return cur - 1; });
    moves.push_back([](int cur) { return cur * 2; });
    
    while(!q.empty())
    {
        int pos = q.front();
        int cost = costs[pos];
        q.pop();
        for(const auto& move : moves)
        {
            int next_pos = move(pos);
            int next_cost = cost + 1;
            if(next_pos < 0 || next_pos >= Max_Bound) continue;
            if(costs[next_pos]  == -1)
            {
                costs[next_pos] = next_cost;
                counts[next_pos] = counts[pos];
                q.push(next_pos);
            }
            else if(costs[next_pos] == next_cost)
            {
                counts[next_pos] += counts[pos];
            }
            
        }
    }
    cout << costs[K] << '\n' << counts[K] << endl;
}
